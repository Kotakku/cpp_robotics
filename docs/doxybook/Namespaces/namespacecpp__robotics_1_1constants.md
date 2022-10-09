---
title: cpp_robotics::constants
summary: 数学・物理定数 

---

# cpp_robotics::constants

数学・物理定数 

## Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr double | **[PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-pi)** <br>円周率  |
| constexpr double | **[HALF_PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-half-pi)** <br>円周率 / 2  |
| constexpr double | **[TWO_PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-two-pi)** <br>円周率 * 2  |
| constexpr double | **[DEG_TO_RAD](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-deg-to-rad)** <br>degree -> radians  |
| constexpr double | **[RAD_TO_DEG](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-rad-to-deg)** <br>radian -> degree  |
| constexpr double | **[EULER](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-euler)** <br>ネイピア数  |
| constexpr double | **[GRAVITY](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gravity)** <br>重力  |
| constexpr double | **[Nm2gfm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-nm2gfm)**  |
| constexpr double | **[gfm2Nm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gfm2nm)**  |
| constexpr double | **[mNm2gfcm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-mnm2gfcm)**  |
| constexpr double | **[gfcm2mNm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/#variable-gfcm2mnm)**  |



## Attributes Documentation

### variable PI

```cpp
constexpr double PI = 3.1415926535897932384626433832795;
```

円周率 

### variable HALF_PI

```cpp
constexpr double HALF_PI = PI / 2.0;
```

円周率 / 2 

### variable TWO_PI

```cpp
constexpr double TWO_PI = PI * 2.0;
```

円周率 * 2 

### variable DEG_TO_RAD

```cpp
constexpr double DEG_TO_RAD = PI / 180.0;
```

degree -> radians 

### variable RAD_TO_DEG

```cpp
constexpr double RAD_TO_DEG = 180.0 / PI;
```

radian -> degree 

### variable EULER

```cpp
constexpr double EULER = 2.718281828459045235360287471352;
```

ネイピア数 

### variable GRAVITY

```cpp
constexpr double GRAVITY = 9.807;
```

重力 

### variable Nm2gfm

```cpp
constexpr double Nm2gfm = (1/GRAVITY);
```


### variable gfm2Nm

```cpp
constexpr double gfm2Nm = GRAVITY;
```


### variable mNm2gfcm

```cpp
constexpr double mNm2gfcm = (Nm2gfm * 100);
```


### variable gfcm2mNm

```cpp
constexpr double gfcm2mNm = (gfm2Nm / 100);
```





-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900