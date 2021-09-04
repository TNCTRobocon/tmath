#pragma once
#ifndef __HEADER_GUARD_TMATH__
#define __HEADER_GUARD_TMATH__

#include <algorithm>
#include <cmath>
namespace tmath {

template <class T> struct vec2 final {
    T x, y;
    constexpr vec2(const T &_x, const T &_y) : x(_x), y(_y) {}
    constexpr vec2(const vec2<T> &) = default;
    template <class T2> constexpr const vec2<T> &operator=(const vec2<T> &rls) {
        x = rls.x, y = rls.y;
        return *this;
    }
};

// 単項演算子
template <class T> constexpr static inline auto operator+(const vec2<T> &l) {
    return vec2<T>(l.x, l.y);
}

template <class T> constexpr static inline auto operator-(const vec2<T> &l) {
    return vec2<T>(-l.x, -l.y);
}

template <class T> constexpr static inline bool operator!(const vec2<T> &l) {
    return !l.x && !l.y;
}

// ベクトル通しの演算
#define VECTOR2_OP(op)                                                         \
    template <class T1, class T2>                                              \
    constexpr static inline auto operator op(const vec2<T1> &l,                \
                                             const vec2<T2> &r) {              \
        return vec2<decltype(l.x op r.x)>(l.x op r.x, l.y op r.y);             \
    }

VECTOR2_OP(+);
VECTOR2_OP(-);
VECTOR2_OP(*);
VECTOR2_OP(/);
VECTOR2_OP(&);
VECTOR2_OP(|);
VECTOR2_OP(^);
VECTOR2_OP(%);

#undef VECTOR2_OP

// ベクトルとスカラーの演算
template <class T1, class T2>
constexpr static inline auto operator*(const T1 &l, const vec2<T2> &r) {
    return vec2<decltype(l * r.x)>(l * r.x, l * r.y);
}

template <class T1, class T2>
constexpr static inline auto operator*(const vec2<T1> &l, const T2 &r) {
    return vec2<decltype(l.x * r)>(l.x * r, l.y * r);
}

template <class T1, class T2>
constexpr static inline auto operator/(const vec2<T1> &l, const T2 &r) {
    return vec2<decltype(l.x / r)>(l.x / r, l.y / r);
}

// ベクトル固有の演算
template <class T> constexpr static inline auto sum(const vec2<T> &l) {
    return l.x + l.y;
}

template <class T> constexpr static inline auto max(const vec2<T> &l) {
    return std::max(l.x, l.y);
}

template <class T> constexpr static inline auto min(const vec2<T> &l) {
    return std::min(l.x, l.y);
}

template <class T> constexpr static inline auto abs(const vec2<T> &l) {
    return sqrt(l.x, l.y);
}

template <class T1, class T2>
constexpr static inline auto dot(const vec2<T1> &l, const vec2<T2> &r) {
    return l.x * r.x + l.y * r.y;
}

template <class T1, class T2>
constexpr static inline auto cross(const vec2<T1> &l, const vec2<T2> &r) {
    return l.x * r.y - l.y * r.x;
}

template <class T1, class T2>
constexpr auto distance2(const vec2<T1> &l, const vec2<T2> &r) {
    const auto d = l - r;
    return sum(d * d);
}

template <class T1, class T2>
constexpr auto distance(const vec2<T1> &l, const vec2<T2> &r) {
    return abs(l - r);
}

template <class T> constexpr auto normalize(const vec2<T> &l) {
    return l / abs(l);
}

} // namespace tmath
#endif