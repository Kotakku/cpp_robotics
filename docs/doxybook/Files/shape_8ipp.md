---
title: include/cpp_robotics/geometry/shape.ipp

---

# include/cpp_robotics/geometry/shape.ipp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
namespace cpp_robotics
{

constexpr Quad Rect::as_quad() const
{
    return Quad{vertex()};
}

constexpr Quad Rect::get_rotated(float angle) const
{
    const Vector2d tv(size.x / 2, size.y / 2);
    return Quad
    {
        center() + tv.get_rotated(angle),  center() + tv.nxy().get_rotated(angle),
        center() + -tv.get_rotated(angle), center() + tv.xny().get_rotated(angle)
    };
}

}
```


-------------------------------

Updated on 2022-09-30 at 00:12:50 +0900
