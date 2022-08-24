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