#pragma once

#ifndef _LIB_STATIC_MODINT_HPP
#define _LIB_STATIC_MODINT_HPP 1

#include <cassert>
#include <iostream>

template <unsigned int m>
struct static_modint {
    using mint = static_modint;

   private:
    unsigned int _v;
    static constexpr bool prime = []() -> bool {
        if (m == 1) return 0;
        if (m == 2 || m == 7 || m == 61) return 1;
        if (m % 2 == 0) return 0;
        unsigned int d = m - 1;
        while (d % 2 == 0)
            d /= 2;
        for (unsigned int a : {2, 7, 61}) {
            unsigned int t = d;
            mint y = mint(a).pow(t);
            while (t != m - 1 && y != 1 && y != m - 1) {
                y *= y;
                t <<= 1;
            }
            if (y != m - 1 && t % 2 == 0) return 0;
        }
        return 1;
    }();
    static constexpr std::pair<unsigned int, unsigned int> inv_gcd(unsigned int a, unsigned int b) {
        if (a == 0) return {b, 0};
        unsigned int s = b, t = a, m0 = 0, m1 = 1;
        while (t) {
            const unsigned int u = s / t;
            s -= t * u;
            m0 -= m1 * u;
            std::swap(s, t);
            std::swap(m0, m1);
        }
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }

   public:
    static constexpr unsigned int mod() { return m; }
    static constexpr mint raw(unsigned int v) {
        mint x;
        x._v = v;
        return x;
    }

    constexpr static_modint() : _v(0) {}
    template <class T>
    constexpr static_modint(T v) {
        if constexpr (std::is_signed_v<T>) {
            long long x = (long long)(v % (long long)(m));
            if (x < 0) x += m;
            _v = (unsigned int)(x);
        } else {
            _v = (unsigned int)(v % m);
        }
    }
    constexpr unsigned int val() const { return _v; }

    constexpr mint& operator++() { return *this += 1; }
    constexpr mint& operator--() { return *this -= 1; }
    constexpr mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }
    constexpr mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    constexpr mint& operator+=(mint rhs) {
        if (_v >= m - rhs._v) _v -= m;
        _v += rhs._v;
        return *this;
    }
    constexpr mint& operator-=(mint rhs) {
        if (_v < rhs._v) _v += m;
        _v -= rhs._v;
        return *this;
    }
    constexpr mint& operator*=(mint rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % m);
        return *this;
    }
    constexpr mint& operator/=(mint rhs) { return *this = *this * rhs.inv(); }

    constexpr mint operator+() const { return *this; }
    constexpr mint operator-() const { return mint{} - *this; }

    constexpr mint pow(unsigned long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr mint inv() const {
        if constexpr (prime) {
            assert(_v);
            return pow(m - 2);
        } else {
            auto eg = inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend constexpr mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend constexpr mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend constexpr mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend constexpr mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend constexpr bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend constexpr bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
};
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;

#endif  // _LIB_STATIC_MODINT_HPP
/**
 * @brief static_modint
 */
