#pragma once

#include <functional>
#include <any>
#include "../controller/pid.hpp"
#include "../controller/nctf.hpp"
#include "./transfer_function.hpp"

/*

x_r  +                        x
----->*-->| C |-->| G |---*--->
     -|                   |
      ---------<-----------

x_r: 目標値
x: 状態
C: 制御器
G: プラント

*/

namespace cpp_robotics
{

class SisoFeedbackSystem
{
public:
    struct func_list_t
    {
        // C
        std::function<void(void)> controller_reset;
        std::function<double(double)> controller;
        // std::any controller_obj;

        // G
        std::function<void(void)> system_reset;
        std::function<double(double)> system;
        // std::any system_obj;
    };

    SisoFeedbackSystem(func_list_t fn): func_list_(fn) {}

    void reset()
    {
        u_ = 0;
        y_ = 0;
        func_list_.controller_reset();
        func_list_.system_reset();
    }

    double control(double target)
    {
        u_ = func_list_.controller(target - y_);
        y_ = func_list_.system(u_);
        return y_;
    }

    double u() const { return u_; }
    double y() const { return y_; }

    std::function<double(double)> make_control_function()
    {
        return [this](double target){ return control(target); };
    }

    operator std::function<double(double)>()
    {
        return make_control_function();
    }

private:
    double u_ = 0;
    double y_ = 0;

    func_list_t func_list_;
};

template<class CONTROLLER_T, class SYSTEM_T>
static SisoFeedbackSystem make_feedback_system(CONTROLLER_T &controller, SYSTEM_T &system)
{
    SisoFeedbackSystem::func_list_t fn;
    set_controller(fn, controller);
    set_system(fn, system);

    return SisoFeedbackSystem(fn);
}

static void set_controller(SisoFeedbackSystem::func_list_t &fn, PIDController &controller)
{
    // fn.controller_obj = controller;
    fn.controller_reset = [&](){ controller.reset(); };
    fn.controller = [&](double e){ return controller.calculate(e); };
}

static void set_controller(SisoFeedbackSystem::func_list_t &fn, NctfController &controller)
{
    // fn.controller_obj = controller;
    fn.controller_reset = [&](){ controller.reset(); };
    fn.controller = [&](double e){ return controller.control(e); };
}

template<size_t NUM, size_t DEN>
static void set_system(SisoFeedbackSystem::func_list_t &fn, TransferFunction<NUM, DEN> &system)
{
    // fn.system_obj = system;
    fn.system_reset = [&](){ return system.set_state_zero(); };
    fn.system = [&](double u){ return system.responce(u); };
}


}