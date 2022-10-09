---
title: cpp_robotics::Singleton
summary: シングルトンなオブジェクトを生成する 

---

# cpp_robotics::Singleton



シングルトンなオブジェクトを生成する  [More...](#detailed-description)


`#include <singleton.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using T | **[class_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/#using-class-t)**  |
| using std::shared_ptr< [class_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/#using-class-t) > | **[shared_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/#using-shared-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [shared_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/#using-shared-t) | **[get_shared_instance](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/#function-get-shared-instance)**()<br>シングルトンなオブジェクトをstd::shared_ptrで返す  |

## Detailed Description

```cpp
template <class T >
class cpp_robotics::Singleton;
```

シングルトンなオブジェクトを生成する 

**Template Parameters**: 

  * **T** シングルトンで生成したいオブジェクトの型 

## Public Types Documentation

### using class_t

```cpp
using cpp_robotics::Singleton< T >::class_t =  T;
```


### using shared_t

```cpp
using cpp_robotics::Singleton< T >::shared_t =  std::shared_ptr<class_t>;
```


## Public Functions Documentation

### function get_shared_instance

```cpp
static inline shared_t get_shared_instance()
```

シングルトンなオブジェクトをstd::shared_ptrで返す 

**Return**: shared_t オブジェクトのshared_ptr 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900