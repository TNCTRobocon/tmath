#pragma once
#ifndef __HEADER_GUARD_TMATH__
#define __HEADER_GUARD_TMATH__

#include <algorithm>
#include <array>
#include <cmath>
namespace tmath {
template <class T, unsigned n> struct vec final {
    constexpr const static size_t size = n;
    std::array<T, n> values;
    //コンストラクタ&デストラクタ
    constexpr inline vec() = default;
    template <class T2>
    constexpr inline vec(const std::array<T2, n> &_values) : values(_values) {}
    constexpr inline vec(std::array<T, size> &&_values) : values(_values) {}
    template <class T2>
    constexpr inline vec(const vec<T2, n> &rls) : values(rls.values) {}
    ~vec() = default;
    //メソッド
    template <class F> constexpr inline auto fold(const F &func) const {
        T tmp = values[0];
        for (size_t i = 1; i < size; i++) {
            tmp = func(tmp, values[i]);
        }
        return tmp;
    }

    template <class F> constexpr inline auto map(const F &func) const {
        std::array<decltype(func(values[0])), size> result;
        for (size_t i = 0; i < size; i++) {
            result[i] = func(values[i]);
        }
        return vec<decltype(func(values[0])), size>(result);
    }

    //オペレータ
    constexpr const vec<T, size> operator=(const vec<T, size> &v) {
        for (size_t i = 0; i < size; i++) {
            values[i] = v.values[i];
        }
        return *this;
    }

    constexpr inline operator bool() {
        return fold([](const T &x, const T &y) { return x || y; });
    }
    constexpr inline T &operator[](size_t index) { return values[index]; }
    constexpr inline const T &operator[](size_t index) const {
        return values[index];
    }
};

template <class T> struct vec<T, 1> final {
    constexpr const static size_t size = 1;
    union {
        std::array<T, size> values;
        T x;
    };
    constexpr inline vec(const T &_x = 0) : values({_x}) {}
    template <class T2>
    constexpr inline vec(const std::array<T2, 1> &_values) : values(_values) {}
    constexpr inline vec(std::array<T, size> &&_values) : values(_values) {}
    template <class T2>
    constexpr inline vec(const vec<T2, 1> &rls) : values(rls.values) {}
    ~vec() = default;
    //メソッド
    template <class F> constexpr inline auto fold(const F &func) const {
        T tmp = values[0];
        for (size_t i = 1; i < size; i++) {
            tmp = func(tmp, values[i]);
        }
        return tmp;
    }

    template <class F> constexpr inline auto map(const F &func) const {
        std::array<decltype(func(values[0])), size> result;
        for (size_t i = 0; i < size; i++) {
            result[i] = func(values[i]);
        }
        return vec<decltype(func(values[0])), size>(result);
    }

    //オペレータ
    constexpr const vec<T, size> operator=(const vec<T, size> &v) {
        for (size_t i = 0; i < size; i++) {
            values[i] = v.values[i];
        }
        return *this;
    }

    constexpr inline operator bool() {
        return fold([](const T &x, const T &y) { return x || y; });
    }
    constexpr inline T &operator[](size_t index) { return values[index]; }
    constexpr inline const T &operator[](size_t index) const {
        return values[index];
    }
};

template <class T> struct vec<T, 2> final {
    constexpr const static size_t size = 2;
    union {
        std::array<T, size> values;
        struct {
            T x, y;
        };
    };

    constexpr inline vec(const T &_x = 0, const T &_y = 0) : values({_x, _y}) {}
    template <class T2>
    constexpr inline vec(const std::array<T2, size> &_values)
        : values(_values) {}
    template <class T2>
    constexpr inline vec(const vec<T2, size> &rls) : values(rls.values) {}
    constexpr inline vec(std::array<T, size> &&_values) : values(_values) {}
    ~vec() = default;
    //メソッド
    template <class F> constexpr inline auto fold(const F &func) const {
        T tmp = values[0];
        for (size_t i = 1; i < size; i++) {
            tmp = func(tmp, values[i]);
        }
        return tmp;
    }

    template <class F> constexpr inline auto map(const F &func) const {
        std::array<decltype(func(values[0])), size> result;
        for (size_t i = 0; i < size; i++) {
            result[i] = func(values[i]);
        }
        return vec<decltype(func(values[0])), size>(result);
    }

    //オペレータ
    constexpr const vec<T, size> operator=(const vec<T, size> &v) {
        for (size_t i = 0; i < size; i++) {
            values[i] = v.values[i];
        }
        return *this;
    }

    constexpr inline operator bool() {
        return fold([](const T &x, const T &y) { return x || y; });
    }
    constexpr inline T &operator[](size_t index) { return values[index]; }
    constexpr inline const T &operator[](size_t index) const {
        return values[index];
    }
};

template <class T> struct vec<T, 3> final {
    constexpr const static size_t size = 3;
    union {
        std::array<T, size> values;
        struct {
            T x, y, z;
        };
    };
    constexpr inline vec(const T &_x = 0, const T &_y = 0, const T &_z = 0)
        : values({_x, _y, _z}) {}
    template <class T2>
    constexpr inline vec(const std::array<T2, size> &_values)
        : values(_values) {}
    template <class T2>
    constexpr inline vec(const vec<T2, size> &rls) : values(rls.values) {}
    constexpr inline vec(std::array<T, size> &&_values) : values(_values) {}
    ~vec() = default;
    //メソッド
    template <class F> constexpr inline auto fold(const F &func) const {
        T tmp = values[0];
        for (size_t i = 1; i < size; i++) {
            tmp = func(tmp, values[i]);
        }
        return tmp;
    }

    template <class F> constexpr inline auto map(const F &func) const {
        std::array<decltype(func(values[0])), size> result;
        for (size_t i = 0; i < size; i++) {
            result[i] = func(values[i]);
        }
        return vec<decltype(func(values[0])), size>(result);
    }

    //オペレータ
    constexpr const vec<T, size> operator=(const vec<T, size> &v) {
        for (size_t i = 0; i < size; i++) {
            values[i] = v.values[i];
        }
        return *this;
    }

    constexpr inline operator bool() {
        return fold([](const T &x, const T &y) { return x || y; });
    }
    constexpr inline T &operator[](size_t index) { return values[index]; }
    constexpr inline const T &operator[](size_t index) const {
        return values[index];
    }
};

template <class T> struct vec<T, 4> final {
    constexpr const static size_t size = 4;
    union {
        std::array<T, size> values;
        struct {
            T x, y, z, w;
        };
    };
    constexpr vec(const T &_x = 0, const T &_y = 0, const T &_z = 0,
                  const T &_w = 0)
        : values({_x, _y, _z, _w}) {}
    template <class T2>
    constexpr inline vec(const std::array<T2, size> &_values)
        : values(_values) {}
    template <class T2>
    constexpr inline vec(const vec<T2, size> &rls) : values(rls.values) {}
    constexpr inline vec(std::array<T, size> &&_values) : values(_values) {}
    ~vec() = default;
    //メソッド
    template <class F> constexpr inline auto fold(const F &func) const {
        T tmp = values[0];
        for (size_t i = 1; i < size; i++) {
            tmp = func(tmp, values[i]);
        }
        return tmp;
    }

    template <class F> constexpr inline auto map(const F &func) const {
        std::array<decltype(func(values[0])), size> result;
        for (size_t i = 0; i < size; i++) {
            result[i] = func(values[i]);
        }
        return vec<decltype(func(values[0])), size>(result);
    }

    //オペレータ
    constexpr const vec<T, size> operator=(const vec<T, size> &v) {
        for (size_t i = 0; i < size; i++) {
            values[i] = v.values[i];
        }
        return *this;
    }

    constexpr inline operator bool() {
        return fold([](const T &x, const T &y) { return x || y; });
    }
    constexpr inline T &operator[](size_t index) { return values[index]; }
    constexpr inline const T &operator[](size_t index) const {
        return values[index];
    }
};

// 単項演算子
#define SINGLE_OP(op)                                                          \
    template <class T, unsigned n>                                             \
    constexpr static inline auto operator op(const vec<T, n> &v) {             \
        return v.map([](const T &x) { return op x; });                         \
    }

SINGLE_OP(+);
SINGLE_OP(-);
SINGLE_OP(~);

#undef SINGLE_OP

template <class T, unsigned n>
constexpr static inline bool operator!(const vec<T, n> &v) {
    return !v.fold([](const T &x, const T &y) { return x || y; });
}

// // ベクトル通しの演算
#define VECTOR_OP(op)                                                          \
    template <class T1, class T2, unsigned n>                                  \
    constexpr static inline auto operator op(const vec<T1, n> &l,              \
                                             const vec<T2, n> &r) {            \
        std::array<decltype(l.values[0] op r.values[0]), n> values;            \
        for (size_t i = 0; i < n; i++) {                                       \
            values[i] = l.values[i] op r.values[i];                            \
        }                                                                      \
        return vec<decltype(l.values[0] op r.values[0]), n>(values);           \
    }

VECTOR_OP(+);
VECTOR_OP(-);
VECTOR_OP(*);
VECTOR_OP(/);
VECTOR_OP(&);
VECTOR_OP(|);
VECTOR_OP(^);
VECTOR_OP(%);

#undef VECTOR_OP

#define SCALAR_OP_L(op)                                                        \
    template <class T1, class T2, unsigned n>                                  \
    constexpr static inline auto operator op(const vec<T1, n> &x,              \
                                             const T2 &y) {                    \
        std::array<decltype(x.values[0] op y), n> z;                           \
        for (size_t i = 0; i < n; i++) {                                       \
            z[i] = x.values[i] op y;                                           \
        }                                                                      \
        return vec<decltype(x.values[0] op y), n>(z);                          \
    }

#define SCALAR_OP_R(op)                                                        \
    template <class T1, class T2, unsigned n>                                  \
    constexpr static inline auto operator op(const T1 &x,                      \
                                             const vec<T2, n> &y) {            \
        std::array<decltype(x[0] op y.values[0]), n> z;                        \
        for (size_t i = 0; i < n; i++) {                                       \
            z[i] = x op y.values[i];                                           \
        }                                                                      \
        return vec<decltype(x[0] op y.values[0]), n>(z);                       \
    }

#define SCALAR_OP(op)                                                          \
    SCALAR_OP_R(op);                                                           \
    SCALAR_OP_L(op)

SCALAR_OP(*);
SCALAR_OP_L(/);
SCALAR_OP_L(<<);
SCALAR_OP_L(>>);

#undef SCALAR_OP
#undef SCALAR_OP_L
#undef SCALAR_OP_R

#define ASSIGN_OP_VECTOR(op)                                                   \
    template <class T1, class T2, unsigned n>                                  \
    constexpr static inline auto operator op(const vec<T1, n> &lhs,            \
                                             const vec<T2, n> &rhs) {          \
        for (size_t i = 0; i < n; i++) {                                       \
            lhs[i] op rhs[i];                                                  \
        }                                                                      \
        return lhs;                                                            \
    }

#define ASSIGN_OP_SCALAR(op)                                                   \
    template <class T1, class T2, unsigned n>                                  \
    constexpr static inline auto operator op(const vec<T1, n> &lhs,            \
                                             const T2 &rhs) {                  \
        for (size_t i = 0; i < n; i++) {                                       \
            lhs[i] op rhs;                                                     \
        }                                                                      \
        return lhs;                                                            \
    }

#define ASSIGN_OP(op)                                                          \
    ASSIGN_OP_VECTOR(op);                                                      \
    ASSIGN_OP_SCALAR(op)

ASSIGN_OP(+=);
ASSIGN_OP(-=);
ASSIGN_OP(*=);
ASSIGN_OP(/=);
ASSIGN_OP(%=);
ASSIGN_OP(&=);
ASSIGN_OP(|=);
ASSIGN_OP(^=);
ASSIGN_OP_SCALAR(<<=);
ASSIGN_OP_SCALAR(>>=);

#undef ASSIGN_OP
#undef ASSIGN_OP_SCALAR
#undef ASSIGN_OP_VECTOR

// ベクトル固有の演算
template <class T, unsigned n>
constexpr static inline auto sum(const vec<T, n> &v) {
    return v.fold([](const T &x, const T &y) { return x + y; });
}

template <class T, unsigned n>
constexpr static inline auto max(const vec<T, n> &v) {
    return v.fold([](const T &x, const T &y) { return std::max(x, y); });
}

template <class T, unsigned n>
constexpr static inline auto min(const vec<T, n> &v) {
    return v.fold([](const T &x, const T &y) { return std::min(x, y); });
}

template <class T1, class T2, unsigned n>
constexpr static inline auto dot(const vec<T1, n> &x, const vec<T2, n> &y) {
    return sum(x * y);
}

template <class T, unsigned n>
constexpr static inline auto distance(const vec<T, n> &v) {
    return std::sqrt(dot(v, v));
}

template <class T, unsigned n>
constexpr static inline auto distance2(const vec<T, n> &v) {
    return dot(v, v);
}

template <class T1, class T2>
constexpr static inline auto cross2d(const vec<T1, 2> &l, const vec<T2, 2> &r) {
    return l.x * r.y - l.y * r.x;
}

// map系統
#define MATH_FUNC_STD(func)                                                    \
    template <class T, unsigned n>                                             \
    constexpr static inline auto func(const vec<T, n> &v) {                    \
        return v.map([](const T &x) { return std::func(x); });                 \
    }
#define MATH_FUNC_STD2(func)                                                   \
    template <class T, unsigned n>                                             \
    constexpr static inline auto func(const vec<T, n> &x, const T &y) {        \
        return x.map([&y](const T &x) { return std::func(x, y); });              \
    }
//三角関数
MATH_FUNC_STD(sin);
MATH_FUNC_STD(cos);
MATH_FUNC_STD(tan);
MATH_FUNC_STD(asin);
MATH_FUNC_STD(acos);
MATH_FUNC_STD(atan);

//双曲線関数
MATH_FUNC_STD(sinh);
MATH_FUNC_STD(cosh);
MATH_FUNC_STD(tanh);
MATH_FUNC_STD(asinh);
MATH_FUNC_STD(acosh);
MATH_FUNC_STD(atanh);

//指数と対数
MATH_FUNC_STD(exp);
MATH_FUNC_STD(exp2);
MATH_FUNC_STD(log);
MATH_FUNC_STD(log2);
MATH_FUNC_STD(log10);

//その他
MATH_FUNC_STD(abs);
MATH_FUNC_STD(sqrt);
MATH_FUNC_STD2(pow);

//必要に応じて増やしてください。
#undef MATH_FUNC_STD2
#undef MATH_FUNC_STD

//別名の定義
template <class T> using vec1 = vec<T, 1>;
template <class T> using vec2 = vec<T, 2>;
template <class T> using vec3 = vec<T, 3>;
template <class T> using vec4 = vec<T, 4>;

} // namespace tmath
#endif
