---
title: cpp_robotics::SisoFeedbackSystem
summary: コントローラとシステムからなるSISOのフィードバックシステム 

---

# cpp_robotics::SisoFeedbackSystem



コントローラとシステムからなるSISOのフィードバックシステム 


`#include <siso_system.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-sisofeedbacksystem)**() =default |
| | **[SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-sisofeedbacksystem)**([func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/) fn) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-reset)**() |
| double | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-control)**(double target) |
| double | **[u](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-u)**() const |
| double | **[y](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-y)**() const |
| std::function< double(double)> | **[make_control_function](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-make-control-function)**() |
| | **[operator std::function< double](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/#function-operator-stdfunction<-double)**(double ) |

## Public Functions Documentation

### function SisoFeedbackSystem

```cpp
SisoFeedbackSystem() =default
```


### function SisoFeedbackSystem

```cpp
inline SisoFeedbackSystem(
    func_list_t fn
)
```


### function reset

```cpp
inline void reset()
```


### function control

```cpp
inline double control(
    double target
)
```


### function u

```cpp
inline double u() const
```


### function y

```cpp
inline double y() const
```


### function make_control_function

```cpp
inline std::function< double(double)> make_control_function()
```


### function operator std::function< double

```cpp
inline operator std::function< double(
    double 
)
```


-------------------------------

Updated on 2022-10-05 at 01:02:06 +0900