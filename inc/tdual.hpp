#pragma once

#include <functional>

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

template <class T> struct dual_func final {
    using func = std::function<T(const T &)>;
    func re, im;
    constexpr dual_func(func _re, func _im) : re(_re), im(_im) {}
    constexpr dual_func(const func &_re, const func &_im) : re(_re), im(_im) {}
    constexpr dual_func(func &&_re, func &&_im) : re(_re), im(_im) {}
    constexpr dual_func(const dual_func &) = default;
    constexpr dual_func(dual_func &&) = default;
    T operator()(const T &x) const { return re(x); }
};

template <class T> constexpr auto operator+(const dual_func<T> &x) { return x; }

template <class T> constexpr auto operator-(const dual_func<T> &x) {
    return dual_func<T>([=](const T &value) { return -x.re(value); },
                        [=](const T &value) { return -x.im(value); });
}

template <class T> constexpr auto operator~(const dual_func<T> &x) {
    return dual_func<T>(x.re, [=](const T &x) { return -x.im(x); });
}

template <class T>
constexpr auto operator+(const dual_func<T> &x, const dual_func<T> &y) {
    return dual_func<T>(
        [=](const T &value) { return x.re(value) + y.re(value); },
        [=](const T &value) { return x.im(value) + y.im(value); });
}

template <class T>
constexpr auto operator-(const dual_func<T> &x, const dual_func<T> &y) {
    return dual_func<T>(
        [=](const T &value) { return x.re(value) - y.re(value); },
        [=](const T &value) { return x.im(value) - y.im(value); });
}

template <class T>
constexpr auto operator*(const dual_func<T> &x, const dual_func<T> &y) {
    return dual_func<T>(
        [=](const T &value) { return x.re(value) * y.re(value); },
        [=](const T &value) {
            return x.re(value) * y.im(value) + x.im(value) * y.re(value);
        });
}

template <class T>
constexpr auto operator/(const dual_func<T> &x, const dual_func<T> &y) {
    return dual_func<T>(
        [=](const T &value) { return x.re(value) / y.re(value); },
        [=](const T &value) {
            return (-x.re(value) * y.im(value) - x.im(value) * y.re(value)) /
                   (y.re(value) * y.re(value));
        });
}

} // namespace tmath