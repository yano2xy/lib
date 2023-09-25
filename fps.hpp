#pragma once

#include <atcoder/all>
#include <vector>

template <typename mint>
std::vector<mint> multiply_garner(const std::vector<mint> &f, const std::vector<mint> &g) {
    int n = (int)f.size(), m = (int)g.size();
    if (!n || !m) return {};
    static const long long nttprimes[] = {754974721, 167772161, 469762049};
    using mint0 = atcoder::static_modint<754974721>;
    using mint1 = atcoder::static_modint<167772161>;
    using mint2 = atcoder::static_modint<469762049>;
    std::vector<mint0> f0(n), g0(m);
    std::vector<mint1> f1(n), g1(m);
    std::vector<mint2> f2(n), g2(m);
    for (int i = 0; i < n; i++)
        f0[i] = f[i].val(), f1[i] = f[i].val(), f2[i] = f[i].val();
    for (int i = 0; i < m; i++)
        g0[i] = g[i].val(), g1[i] = g[i].val(), g2[i] = g[i].val();
    auto c0 = atcoder::convolution(f0, g0);
    auto c1 = atcoder::convolution(f1, g1);
    auto c2 = atcoder::convolution(f2, g2);
    static const long long m01 = 1LL * nttprimes[0] * nttprimes[1];
    static const long long m0_inv_m1 = mint1(nttprimes[0]).inv().val();
    static const long long m01_inv_m2 = mint2(m01).inv().val();
    const int mod = mint::mod();
    auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint {
        int r0 = x0.val(), r1 = x1.val(), r2 = x2.val();
        int v1 = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];
        auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);
        return mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val());
    };
    int sz = (int)c0.size();
    std::vector<mint> c(sz);
    for (int i = 0; i < sz; i++)
        c[i] = garner(c0[i], c1[i], c2[i]);
    return c;
}

template <typename T = long long>
std::vector<T> multiply_naive(const std::vector<T> &f, const std::vector<T> &g) {
    int n = (int)f.size(), m = (int)g.size();
    std::vector<T> ret(n + m - 1);
    if (n < m) {
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                ret[i + j] += f[i] * g[j];
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ret[i + j] += f[i] * g[j];
    }
    return ret;
}

// F*g (F: fps, g: sparse fps)
template <typename T>
std::vector<T> multiply_sparse(const std::vector<T> &f, std::vector<std::pair<int, T>> g) {
    int n = (int)f.size();
    std::vector<T> ret(n);
    for (auto &&[d, c] : g) {
        for (int i = 0; i + d < n; i++) {
            ret[i + d] += f[i] * c;
        }
    }
    return ret;
}

// F/g (F: fps, g: sparse fps)
// gの定数項は非零であること
template <typename T>
std::vector<T> divide_sparse(const std::vector<T> &f, std::vector<std::pair<int, T>> g) {
    assert(!g.empty() && g.front().first == 0 && g.front().second != T(0));
    int n = (int)f.size(), m = (int)g.size();
    std::vector<T> ret(f.begin(), f.end());
    T c0inv = T(1) / g.front().second;
    for (int i = 0; i < n; i++)
        ret[i] *= c0inv;
    if ((int)g.size() == 1) return ret;
    for (auto &&[d, c] : g)
        c *= c0inv;
    int d1 = g[1].first;
    for (int i = 0; i + d1 < n; ++i) {
        for (int j = 1; j < m; ++j) {
            auto &&[d, c] = g[j];
            if (i + d >= n) break;
            ret[i + d] -= ret[i] * c;
        }
    }
    return ret;
}

template <typename T>
struct FormalPowerSeries : std::vector<T> {
    using std::vector<T>::vector;
    using FPS = FormalPowerSeries;

    bool is_ntt_mod() const {
        if (typeid(T) == typeid(atcoder::modint998244353)) return true;
        return false;
    }

    bool is_arbitrary_mod() const {
        if (typeid(T) == typeid(atcoder::modint1000000007)) return true;
        return false;
    }

    // 最高次数の係数を非零にする
    void shrink() {
        while (this->size() && this->back() == T(0))
            this->pop_back();
    }

    // xを代入した値を求める
    T eval(T x) const {
        T r = 0, w = 1;
        for (auto &v : *this)
            r += w * v, w *= x;
        return r;
    }

    // 係数の演算

    FPS operator+=(const T &a) {
        if (this->empty()) this->resize(1);
        (*this)[0] += a;
        return *this;
    }

    FPS operator-=(const T &a) { return *this += (-a); }

    FPS operator*=(const T &a) {
        for (int k = 0; k < (int)this->size(); k++)
            (*this)[k] *= a;
        return *this;
    }

    // 演算 (fps vs fps)

    FPS operator-() const {
        FPS ret(this->size());
        for (int i = 0; i < (int)this->size(); i++)
            ret[i] = -(*this)[i];
        return ret;
    }

    FPS &operator+=(const FPS &f) {
        int n = (int)this->size(), m = (int)f.size();
        for (int i = 0; i < std::min(n, m); i++)
            (*this)[i] += f[i];
        return *this;
    }

    FPS &operator-=(const FPS &f) { return *this += (-f); }

    FPS &operator*=(const FPS &f) {
        if (this->empty() || f.empty()) {
            this->clear();
            return *this;
        }
        int n = (int)this->size();
        if (is_ntt_mod()) {
            auto v = atcoder::convolution(*this, f);
            *this = FPS(v.begin(), v.end());
        } else if (is_arbitrary_mod()) {
            auto v = multiply_garner(*this, f);
            *this = FPS(v.begin(), v.end());
        } else {
            assert(typeid(T) == typeid(int) || typeid(T) == typeid(long long));
            auto v = multiply_naive(*this, f);
            *this = FPS(v.begin(), v.end());
        }
        this->resize(n);

        return *this;
    }

    // 演算 (fps vs sfps)
    FPS &operator*=(const std::vector<std::pair<int, T>> &g) {
        if (this->empty() || g.empty()) {
            this->clear();
            return *this;
        }
        auto v = multiply_sparse(*this, g);
        return *this = FPS(v.begin(), v.end());
    }

    FPS &operator/=(const std::vector<std::pair<int, T>> &g) {
        if (this->empty()) {
            return *this;
        }
        auto v = divide_sparse(*this, g);
        return *this = FPS(v.begin(), v.end());
    }

    // fps vs fps
    FPS operator+(const T &a) const { return FPS(*this) += a; }
    friend FPS operator+(const T &a, const FPS &f) { return f + a; }
    FPS operator+(const FPS &f) const { return FPS(*this) += f; }
    FPS operator-(const T &a) const { return FPS(*this) -= a; }
    friend FPS operator-(const T &a, const FPS &f) { return -f + a; }
    FPS operator-(const FPS &f) const { return FPS(*this) -= f; }
    FPS operator*(const T &a) const { return FPS(*this) *= a; }
    friend FPS operator*(const T &a, const FPS &f) { return f * a; }
    FPS operator*(const FPS &f) const { return FPS(*this) *= f; }
    FPS operator/(const FPS &f) const { return FPS(*this) /= f; }

    // fps vs sfps
    FPS operator*(const std::vector<std::pair<int, T>> &g) const { return FPS(*this) *= g; }
    FPS operator/(const std::vector<std::pair<int, T>> &g) const { return FPS(*this) /= g; }

    FPS inv(int deg = -1) const {
        assert((*this)[0] != T(0));
        if (deg == -1) deg = (*this).size();
        FPS ret({T(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1)
            ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
        return ret.pre(deg);
    }
};
template <typename mint>
using fps = FormalPowerSeries<mint>;
template <typename mint>
using sfps = std::vector<std::pair<int, mint>>;