---
title: cpp_robotics::constants
summary: 数学・物理定数 

---

# cpp_robotics::constants

数学・物理定数 

## Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr float | **[PI](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-pi)** <br>円周率  |
| constexpr float | **[HALF_PI](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-half-pi)** <br>円周率 / 2  |
| constexpr float | **[TWO_PI](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-two-pi)** <br>円周率 * 2  |
| constexpr float | **[DEG_TO_RAD](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-deg-to-rad)** <br>degree -> radians  |
| constexpr float | **[RAD_TO_DEG](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-rad-to-deg)** <br>radian -> degree  |
| constexpr float | **[EULER](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-euler)** <br>ネイピア数  |
| constexpr float | **[GRAVITY](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gravity)** <br>重力  |
| constexpr float | **[Nm2gfm](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-nm2gfm)**  |
| constexpr float | **[gfm2Nm](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gfm2nm)**  |
| constexpr float | **[mNm2gfcm](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-mnm2gfcm)**  |
| constexpr float | **[gfcm2mNm](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gfcm2mnm)**  |



## Attributes Documentation

### variable PI

```cpp
constexpr float PI = 3.1415926535897932384626433832795;
```

円周率 

### variable HALF_PI

```cpp
constexpr float HALF_PI = PI / 2.0;
```

円周率 / 2 

### variable TWO_PI

```cpp
constexpr float TWO_PI = PI * 2.0;
```

円周率 * 2 

### variable DEG_TO_RAD

```cpp
constexpr float DEG_TO_RAD = PI / 180.0;
```

degree -> radians 

### variable RAD_TO_DEG

```cpp
constexpr float RAD_TO_DEG = 180.0 / PI;
```

radian -> degree 

### variable EULER

```cpp
constexpr float EULER = 2.718281828459045235360287471352;
```

ネイピア数 

### variable GRAVITY

```cpp
constexpr float GRAVITY = 9.807;
```

重力 

### variable Nm2gfm

```cpp
constexpr float Nm2gfm = (1/GRAVITY);
```


### variable gfm2Nm

```cpp
constexpr float gfm2Nm = GRAVITY;
```


### variable mNm2gfcm

```cpp
constexpr float mNm2gfcm = (Nm2gfm * 100);
```


### variable gfcm2mNm

```cpp
constexpr float gfcm2mNm = (gfm2Nm / 100);
```





-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900