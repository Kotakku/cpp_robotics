// #pragma once

// #include <memory>

// namespace cpp_robotics
// {

// template<class T>
// class State
// {
// public:
//     State() = delete;

//     State(const T &id):
//         id_(id) {}

//     virtual void entry() {}

//     virtual void update() {}

//     virtual void exit() {}

// private:
//     const T id_;
// };

// template<class T>
// class StateMachine
// {
// public:
    
//     StateMachine()
//     {

//     }

//     void update()
//     {
//         state_list_->update();
//     }

// private:
//     std::map<T, std::shared_ptr<State<T>>> state_list_;
// };

// }