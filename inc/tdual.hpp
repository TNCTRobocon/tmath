#pragma once

namespace tmath {

template <class T> struct dual final {
    T re, im;

    constexpr dual() = default;
    constexpr dual(const T &_re, const T &_im) : re(_re), im(_im) {}
    constexpr dual(const dual<T> &) = default;
    constexpr dual(dual<T> &&) = default;
};

template <class T1> constexpr auto operator+(const dual<T1> &x) {
    return dual<decltype(+x.re)>(+x.re, +x.im);
}

template <class T1, class T2> constexpr auto operator-(const dual<T1> &x) {
    return dual<decltype(-x.re)>(-x.re, -x.im);
}

template <class T1, class T2> constexpr auto operator~(const dual<T1> &x) {
    return dual<decltype(-x.re)>(x.re, -x.im);
}

template <class T1, class T2>
constexpr auto operator+(const dual<T1> &x, const dual<T2> &y) {
    return dual<decltype(x.re + y.re)>(x.re + y.re, x.im + y.im);
}

template <class T1, class T2>
constexpr auto operator-(const dual<T1> &x, const dual<T2> &y) {
    return dual<decltype(x.re - y.re)>(x.re - y.re, x.im - y.im);
}

template <class T1, class T2>
constexpr auto operator*(const dual<T1> &x, const dual<T2> &y) {
    return dual<decltype(x.re * y.re)>(x.re * y.re, x.re * y.im + x.im * y.re);
}

template <class T1, class T2>
constexpr auto operator/(const dual<T1> &x, const dual<T2> &y) {
    return dual<decltype(x.re / y.re)>(
        x.re * y.re, (-x.re * y.im + x.im * y.re) / (y.re * y.re));
}

template <class T1, class T2>
constexpr const dual<T1> &operator+=(dual<T1> &x, const dual<T2> &y) {
    x.re += y.re, x.im += y.im;
    return x;
}

template <class T1, class T2>
constexpr const dual<T1> &operator-=(dual<T1> &x, const dual<T2> &y) {
    x.re -= y.re, x.im -= y.im;
    return x;
}

template <class T1, class T2>
constexpr const dual<T1> &operator*=(dual<T1> &x, const dual<T2> &y) {
    const T1 re = x.re * y.re, im = x.re * y.im + x.im * y.re;
    x.re = re, x.im = im;
    return x;
}

template <class T1, class T2>
constexpr const dual<T1> &operator/=(dual<T1> &x, const dual<T2> &y) {
    const T1 re = x.re / y.re,
             im = (-x.re * y.im + x.im * y.re) / (y.re * y.re);
    x.re = re, x.im = im;
    return x;
}

} // namespace tmath