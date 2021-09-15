namespace tmath {

// S...スカラー量
// V...ベクトル量

template <class S, class V> class delta final {
    const S period;
    V last;

  public:
    delta(const S &_period = 1.0, const V &_last = 0.0)
        : period(_period), last(_last) {}
    delta(const delta &) = default;
    ~delta() = default;
    // method
    V operator()(const V &now) {
        const float result = (now - last) / period;
        last = now;
        return result;
    }
    void reset(const V &x) { last = x; }
};

template <class S, class V> class sigma final {
    const S period;
    V sum;

  public:
    sigma(const S &_period = 1.0, const V &_sum = 0.0)
        : sum(_sum), period(_period) {}
    sigma(const sigma &) = default;
    ~sigma() = default;
    // method
    V operator()(const V &now) { return sum += now * period; }
    void reset(const V &x) { sum = x; }
};

template <class S> class clamp final {
    const S max, min;

  public:
    clamp(const S &_max, const S &_min) : max(_max), min(_min) {}
    clamp(const clamp &) = default;
    ~clamp() = default;
    // method
    S operator()(const S &x) {
        if (x > max) {
            return max;
        }
        if (x < min) {
            return min;
        }
        return x;
    }
};

template <class S, class V> class pid final {
    const S period;
    const S p, i, d;
    V sum, last;

  public:
    pid(S _period, S _p, S _i, S _d, V sum = 0, V last = 0)
        : period(_period), p(_p), i(_i), d(_d), sum(_sum), last(_last) {}
    pid(const pid &) = default;
    ~pid() = default;

    V operator()(const V &now) {
        V result = p * now + i * (sum += now) + d * (now - last);
        last = now;
        return result;
    }

    void reset(const V &_sum = 0, const V &_last = 0) {
        sum = _sum;
        last = _last;
    }
};

} // namespace tmath
