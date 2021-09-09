#pragma once
#ifndef __HEADER_GUARD_TDELTA__
#define __HEADER_GUARD_TDELTA__

namespace tmath {

template <class T1, class T2> class Differential final {
    T1 last;
    const T2 period;

  public:
    Differential(const T1 &_last, const T1 &_period = 1.0f)
        : last(_last), period(_period) {}
    T2 operator()(const T2 &now) {
        const float result = (now - last) / period;
        last = now;
        return result;
    }
    void reset(const T1 &x) { last = x; }
};

template <class T1, class T2> class Integral final {
    T1 sum;
    const T2 period;

  public:
    Integral(const T1 &_sum, const T1 &_period = 1.0f)
        : sum(_sum), period(_period) {}
    T2 operator()(const T2 &now) { return sum += now * period; }
    void reset(const T1 &x) { sum = x; }
};
} // namespace tmath

#endif /*__HEADER_GUARD_TDELTA__*/
