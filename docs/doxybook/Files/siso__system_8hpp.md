---
title: include/cpp_robotics/system/siso_system.hpp

---

# include/cpp_robotics/system/siso_system.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/)**  |
| struct | **[cpp_robotics::SisoFeedbackSystem::func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/)**  |




## Source code

```cpp
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

    SisoFeedbackSystem() = default;
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

static void set_system(SisoFeedbackSystem::func_list_t &fn, TransferFunction &system)
{
    // fn.system_obj = system;
    fn.system_reset = [&](){ return system.set_state_zero(); };
    fn.system = [&](double u){ return system.responce(u); };
}


}
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900