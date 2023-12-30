#pragma once

#ifndef _LIB_DYNAMIC_MODINT_HPP
#define _LIB_DYNAMIC_MODINT_HPP 1

#include <cassert>
#include <iostream>

struct barrett {
    unsigned int _m;
    unsigned long long im;
    barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
        unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

template <int id>
struct dynamic_modint {
    using mint = dynamic_modint;

   private:
    unsigned int _v;
    static barrett bt;
    static unsigned int umod() { return bt.umod(); }

    static std::pair<unsigned int, unsigned int> inv_gcd(unsigned int a, unsigned int b) {
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
    static int mod() { return (int)bt.umod(); }
    static void set_mod(int m) {
        assert(0 <= m);
        bt = barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T>
    dynamic_modint(T v) {
        if (std::is_signed_v<T>) {
            long long x = (long long)(v % (long long)(mod()));
            if (x < 0) x += mod();
            _v = (unsigned int)(x);
        } else {
            _v = (unsigned int)(v % mod());
        }
    }
    unsigned int val() const { return _v; }

    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) {
        mint res = *this;
        ++*this;
        return res;
    }
    mint operator--(int) {
        mint res = *this;
        --*this;
        return res;
    }
    mint& operator+=(mint rhs) {
        if (_v >= mod() - rhs._v) _v -= mod();
        _v += rhs._v;
        return *this;
    }
    mint& operator-=(mint rhs) {
        if (_v < rhs._v) _v += mod();
        _v -= rhs._v;
        return *this;
    }
    mint& operator*=(mint rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(mint rhs) { return *this *= rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint{} - *this; }

    mint pow(unsigned long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }
    friend bool operator==(const mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }
};
template <int id>
barrett dynamic_modint<id>::bt(998244353);
using modint = dynamic_modint<-1>;

#endif  // _LIB_DYNAMIC_MODINT_HPP
/**
 * @brief dyanamic_modint
 */
