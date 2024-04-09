#pragma once

#include "./shape.hpp"
#include <algorithm>
#include <optional>
#include <vector>

namespace cpp_robotics {

/// @cond
namespace detail {
static double distance_sq(const Vector2d &begin, const Vector2d &end, const Vector2d &p) {
    const double l2 = (begin - end).norm_sq();

    if (l2 == 0.0) {
        return (begin - p).norm_sq();
    }

    const double t = std::clamp<double>((p - begin).dot(end - begin) / l2, 0.0, 1.0);

    const Vector2d projection = begin + t * (end - begin);

    return (p - projection).norm_sq();
}
} // namespace detail
/// @endcond

////////////////////////////// intersect //////////////////////////////
////////// Vector2d vs //////////
bool intersect(const Vector2d &a, const Vector2d &b) {
    return (a == b);
}

bool intersect(const Vector2d &a, const Line &b) {
    return approx_zero(detail::distance_sq(b.p0, b.p1, a));
}

bool intersect(const Vector2d &a, const Rect &b) {
    const auto tv = b.size / 2;
    return ((b.center.x - tv.x < a.x && a.x < b.center.x + tv.x) &&
            (b.center.y - tv.y < a.y && a.y < b.center.y + tv.y));
}

bool intersect(const Vector2d &a, const Circle &b) {
    return (b.center - a).norm_sq() <= square(b.r);
}

bool intersect(const Vector2d &a, const Triangle &b) {
    // 三角形の辺ベクトル
    Vector2d edge0 = b.p1 - b.p0;
    Vector2d edge1 = b.p2 - b.p1;
    Vector2d edge2 = b.p0 - b.p2;

    // 点aから三角形の各頂点へのベクトル
    Vector2d v0 = a - b.p0;
    Vector2d v1 = a - b.p1;
    Vector2d v2 = a - b.p2;

    // 外積を計算して点が各辺の内側にあるか確認
    bool has_neg = (edge0.cross(v0) < 0) || (edge1.cross(v1) < 0) || (edge2.cross(v2) < 0);
    bool has_pos = (edge0.cross(v0) > 0) || (edge1.cross(v1) > 0) || (edge2.cross(v2) > 0);

    // 点が三角形の辺上にある場合も内部とみなされるため、等号を含める
    return !(has_neg && has_pos);
}

bool intersect(const Vector2d &a, const Quad &b) {
    // 2つの三角形に分割
    Triangle t0(b.p0, b.p1, b.p2);
    Triangle t1(b.p0, b.p2, b.p3);
    return intersect(a, t0) || intersect(a, t1);
}

////////// Line vs //////////
bool intersect(const Line &a, const Vector2d &b) {
    return intersect(b, a);
}

bool intersect(const Line &a, const Line &b) {
    const Vector2d r = a.p1 - a.p0;
    const Vector2d s = b.p1 - b.p0;
    const Vector2d qp = b.p0 - a.p0;
    const double rxs = r.x * s.y - r.y * s.x;
    const double qpxr = qp.x * r.y - qp.y * r.x;
    const double qpxs = qp.x * s.y - qp.y * s.x;

    if (approx_zero(rxs)) {
        if (approx_zero(qpxr) && approx_zero(qpxs)) {
            const double qpr = qp.dot(r);
            const double q2pr = (b.p1 - a.p0).dot(r);
            const double pqs = (a.p0 - b.p0).dot(s);
            const double p2qs = (a.p1 - b.p0).dot(s);

            const double rr = r.dot(r);
            const bool rrIsZero = approx_zero(rr);
            const double ss = s.dot(s);
            const bool ssIsZero = approx_zero(ss);

            if (rrIsZero && ssIsZero && approx_zero(qp.dot(qp))) {
                // The two lines are both zero length and in the same position
                return true;
            }

            if (((not rrIsZero) && ((0 <= qpr && qpr <= rr) || (0 <= q2pr && q2pr <= rr))) || ((not ssIsZero) && ((0 <= pqs && pqs <= ss) || (0 <= p2qs && p2qs <= ss)))) {
                // Two lines are overlapping
                return true;
            }

            // Two lines are collinear but disjoint.
            return false;
        }

        // Two lines are parallel and non-intersecting.
        return false;
    } else {
        const double t = qpxs / rxs;
        const double u = qpxr / rxs;
        if ((0.0 <= t && t <= 1.0) && (0.0 <= u && u <= 1.0)) {
            // An intersection was found
            return true;
        }

        // Two line segments are not parallel but do not intersect
        return false;
    }
}

bool intersect(const Line &a, const Circle &b) {
    const Vector2d ab = a.p1 - a.p0;
    const Vector2d ac = b.center - a.p0;
    const Vector2d bc = b.center - a.p1;
    const double e = ac.dot(ab);
    const double rr = b.r * b.r;

    if (e <= 0.0) {
        return ac.dot(ac) <= rr;
    }

    const double f = ab.dot(ab);

    if (e >= f) {
        return bc.dot(bc) <= rr;
    }

    return (ac.dot(ac) - e * e / f) <= rr;
}

// bool intersect(const Line& a, const Rect& b)
// {
//     return false; // Todo
// }

// bool intersect(const Line& a, const Quad& b)
// {
//     return false; // Todo
// }

// bool intersect(const Line& a, const Triangle& b)
// {
//     return false; // Todo
// }

////////// Rect vs //////////
bool intersect(const Rect &a, const Vector2d &b) {
    return intersect(b, a);
}

// bool intersect(const Rect& a, const Line& b)
// {
//     return false; // Todo
// }

// bool intersect(const Rect& a, const Rect& b)
// {
//     return false; // Todo
// }

// bool intersect(const Rect& a, const Quad& b)
// {
//     return false; // Todo
// }

// bool intersect(const Rect& a, const Triangle& b)
// {
//     return false; // Todo
// }

// bool intersect(const Rect& a, const Circle& b)
// {
//     return false; // Todo
// }

////////// Ciecle vs //////////
bool intersect(const Circle &a, const Vector2d &b) {
    return intersect(b, a);
}

// bool intersect(const Circle& a, const Line& b)
// {
//     return false; // Todo
// }

// bool intersect(const Circle& a, const Rect& b)
// {
//     return false; // Todo
// }

// bool intersect(const Circle& a, const Quad& b)
// {
//     return false; // Todo
// }

// bool intersect(const Circle& a, const Triangle& b)
// {
//     return false; // Todo
// }

// bool intersect(const Circle& a, const Circle& b)
// {
//     return false; // Todo
// }

////////////////////////////// intersect_at //////////////////////////////
std::optional<std::vector<Vector2d>> intersect_at(const Vector2d &a, const Vector2d &b) {
    if (a == b)
        return std::vector<Vector2d>{a};
    return std::nullopt;
}

std::optional<std::vector<Vector2d>> intersect_at(const Vector2d &a, const Line &b) {
    double l = detail::distance_sq(b.p0, b.p1, a);
    if (approx_zero(l))
        return std::vector<Vector2d>{a};
    return std::nullopt;
}

std::optional<std::vector<Vector2d>> intersect_at(const Vector2d &a, const Rect &b) {
    for (auto &line : b.outline()) {
        auto v = intersect_at(a, line);
        if (v)
            return v;
    }
    return std::nullopt;
}

std::optional<std::vector<Vector2d>> intersect_at(const Vector2d &a, const Circle &b) {
    if (approx_eq((b.center - a).norm(), b.r))
        return std::vector<Vector2d>{a};
    return std::nullopt;
}

std::optional<std::vector<Vector2d>> intersect_at(const Line &a, const Vector2d &b) {
    return intersect_at(b, a);
}

std::optional<std::vector<Vector2d>> intersect_at(const Line &a, const Line &b) {
    const Vector2d r = a.p1 - a.p0;
    const Vector2d s = b.p1 - b.p0;
    const Vector2d qp = b.p0 - a.p0;
    const double rxs = r.x * s.y - r.y * s.x;
    const double qpxr = qp.x * r.y - qp.y * r.x;
    const double qpxs = qp.x * s.y - qp.y * s.x;
    const bool rxs_is_zero = approx_zero(rxs);

    if (rxs_is_zero && approx_zero(qpxr)) {
        const double qpr = qp.dot(r);
        const double pqs = (a.p0 - b.p0).dot(s);
        if ((0 <= qpr && qpr <= r.dot(r)) || (0 <= pqs && pqs <= s.dot(s))) {
            // Two lines are overlapping
            return std::nullopt;
        }
        // Two lines are collinear but disjoint.
        return std::nullopt;
    }

    if (rxs_is_zero && !approx_zero(qpxr)) {
        // Two lines are parallel and non-intersecting.
        return std::nullopt;
    }

    const double t = qpxs / rxs;
    const double u = qpxr / rxs;
    if ((!rxs_is_zero) && (0.0 <= t && t <= 1.0) && (0.0 <= u && u <= 1.0)) {
        // An intersection was found
        return std::vector<Vector2d>{(a.p0 + t * r)};
    }

    // Two line segments are not parallel but do not intersect
    return std::nullopt;
}

// std::optional<std::vector<Vector2d>> intersect_at(const Line& a, const Circle& b)
// {
//     return std::nullopt; // Todo
// }

std::optional<std::vector<Vector2d>> intersect_at(const Rect &a, const Vector2d &b) {
    return intersect_at(b, a);
}

std::optional<std::vector<Vector2d>> intersect_at(const Circle &a, const Vector2d &b) {
    return intersect_at(b, a);
}

// std::optional<std::vector<Vector2d>> intersect_at(const Circle& a, const Line& b)
// {
//     return intersect_at(b, a);
// }

} // namespace cpp_robotics