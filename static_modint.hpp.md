---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: static_modint
    links: []
  bundledCode: "#line 2 \"static_modint.hpp\"\n\n#ifndef _LIB_STATIC_MODINT_HPP\n\
    #define _LIB_STATIC_MODINT_HPP 1\n\n#include <cassert>\n#include <iostream>\n\n\
    template <unsigned int m>\nstruct static_modint {\n    using mint = static_modint;\n\
    \n   private:\n    unsigned int _v;\n    static constexpr bool prime = []() ->\
    \ bool {\n        if (m == 1) return 0;\n        if (m == 2 || m == 7 || m ==\
    \ 61) return 1;\n        if (m % 2 == 0) return 0;\n        unsigned int d = m\
    \ - 1;\n        while (d % 2 == 0)\n            d /= 2;\n        for (unsigned\
    \ int a : {2, 7, 61}) {\n            unsigned int t = d;\n            mint y =\
    \ mint(a).pow(t);\n            while (t != m - 1 && y != 1 && y != m - 1) {\n\
    \                y *= y;\n                t <<= 1;\n            }\n          \
    \  if (y != m - 1 && t % 2 == 0) return 0;\n        }\n        return 1;\n   \
    \ }();\n    static constexpr std::pair<unsigned int, unsigned int> inv_gcd(unsigned\
    \ int a, unsigned int b) {\n        if (a == 0) return {b, 0};\n        unsigned\
    \ int s = b, t = a, m0 = 0, m1 = 1;\n        while (t) {\n            const unsigned\
    \ int u = s / t;\n            s -= t * u;\n            m0 -= m1 * u;\n       \
    \     std::swap(s, t);\n            std::swap(m0, m1);\n        }\n        if\
    \ (m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n\n   public:\n    static\
    \ constexpr unsigned int mod() { return m; }\n    static constexpr mint raw(unsigned\
    \ int v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n \
    \   constexpr static_modint() : _v(0) {}\n    template <class T>\n    constexpr\
    \ static_modint(T v) {\n        if constexpr (std::is_signed_v<T>) {\n       \
    \     long long x = (long long)(v % (long long)(m));\n            if (x < 0) x\
    \ += m;\n            _v = (unsigned int)(x);\n        } else {\n            _v\
    \ = (unsigned int)(v % m);\n        }\n    }\n    constexpr unsigned int val()\
    \ const { return _v; }\n\n    constexpr mint& operator++() { return *this += 1;\
    \ }\n    constexpr mint& operator--() { return *this -= 1; }\n    constexpr mint\
    \ operator++(int) {\n        mint res = *this;\n        ++*this;\n        return\
    \ res;\n    }\n    constexpr mint operator--(int) {\n        mint res = *this;\n\
    \        --*this;\n        return res;\n    }\n    constexpr mint& operator+=(mint\
    \ rhs) {\n        if (_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n    \
    \    return *this;\n    }\n    constexpr mint& operator-=(mint rhs) {\n      \
    \  if (_v < rhs._v) _v += m;\n        _v -= rhs._v;\n        return *this;\n \
    \   }\n    constexpr mint& operator*=(mint rhs) {\n        unsigned long long\
    \ z = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % m);\n       \
    \ return *this;\n    }\n    constexpr mint& operator/=(mint rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    constexpr mint operator+() const { return *this;\
    \ }\n    constexpr mint operator-() const { return mint{} - *this; }\n\n    constexpr\
    \ mint pow(unsigned long long n) const {\n        assert(0 <= n);\n        mint\
    \ x = *this, r = 1;\n        while (n) {\n            if (n & 1) r *= x;\n   \
    \         x *= x;\n            n >>= 1;\n        }\n        return r;\n    }\n\
    \    constexpr mint inv() const {\n        if constexpr (prime) {\n          \
    \  assert(_v);\n            return pow(m - 2);\n        } else {\n           \
    \ auto eg = inv_gcd(_v, m);\n            assert(eg.first == 1);\n            return\
    \ eg.second;\n        }\n    }\n\n    friend constexpr mint operator+(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend constexpr mint\
    \ operator-(const mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n \
    \   friend constexpr mint operator*(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) *= rhs; }\n    friend constexpr mint operator/(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) /= rhs; }\n    friend constexpr bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend constexpr\
    \ bool operator!=(const mint& lhs, const mint& rhs) { return lhs._v != rhs._v;\
    \ }\n};\nusing modint998244353 = static_modint<998244353>;\nusing modint1000000007\
    \ = static_modint<1000000007>;\n\n#endif  // _LIB_STATIC_MODINT_HPP\n/**\n * @brief\
    \ static_modint\n */\n"
  code: "#pragma once\n\n#ifndef _LIB_STATIC_MODINT_HPP\n#define _LIB_STATIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n\ntemplate <unsigned int m>\n\
    struct static_modint {\n    using mint = static_modint;\n\n   private:\n    unsigned\
    \ int _v;\n    static constexpr bool prime = []() -> bool {\n        if (m ==\
    \ 1) return 0;\n        if (m == 2 || m == 7 || m == 61) return 1;\n        if\
    \ (m % 2 == 0) return 0;\n        unsigned int d = m - 1;\n        while (d %\
    \ 2 == 0)\n            d /= 2;\n        for (unsigned int a : {2, 7, 61}) {\n\
    \            unsigned int t = d;\n            mint y = mint(a).pow(t);\n     \
    \       while (t != m - 1 && y != 1 && y != m - 1) {\n                y *= y;\n\
    \                t <<= 1;\n            }\n            if (y != m - 1 && t % 2\
    \ == 0) return 0;\n        }\n        return 1;\n    }();\n    static constexpr\
    \ std::pair<unsigned int, unsigned int> inv_gcd(unsigned int a, unsigned int b)\
    \ {\n        if (a == 0) return {b, 0};\n        unsigned int s = b, t = a, m0\
    \ = 0, m1 = 1;\n        while (t) {\n            const unsigned int u = s / t;\n\
    \            s -= t * u;\n            m0 -= m1 * u;\n            std::swap(s,\
    \ t);\n            std::swap(m0, m1);\n        }\n        if (m0 < 0) m0 += b\
    \ / s;\n        return {s, m0};\n    }\n\n   public:\n    static constexpr unsigned\
    \ int mod() { return m; }\n    static constexpr mint raw(unsigned int v) {\n \
    \       mint x;\n        x._v = v;\n        return x;\n    }\n\n    constexpr\
    \ static_modint() : _v(0) {}\n    template <class T>\n    constexpr static_modint(T\
    \ v) {\n        if constexpr (std::is_signed_v<T>) {\n            long long x\
    \ = (long long)(v % (long long)(m));\n            if (x < 0) x += m;\n       \
    \     _v = (unsigned int)(x);\n        } else {\n            _v = (unsigned int)(v\
    \ % m);\n        }\n    }\n    constexpr unsigned int val() const { return _v;\
    \ }\n\n    constexpr mint& operator++() { return *this += 1; }\n    constexpr\
    \ mint& operator--() { return *this -= 1; }\n    constexpr mint operator++(int)\
    \ {\n        mint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr mint operator--(int) {\n        mint res = *this;\n        --*this;\n\
    \        return res;\n    }\n    constexpr mint& operator+=(mint rhs) {\n    \
    \    if (_v >= m - rhs._v) _v -= m;\n        _v += rhs._v;\n        return *this;\n\
    \    }\n    constexpr mint& operator-=(mint rhs) {\n        if (_v < rhs._v) _v\
    \ += m;\n        _v -= rhs._v;\n        return *this;\n    }\n    constexpr mint&\
    \ operator*=(mint rhs) {\n        unsigned long long z = _v;\n        z *= rhs._v;\n\
    \        _v = (unsigned int)(z % m);\n        return *this;\n    }\n    constexpr\
    \ mint& operator/=(mint rhs) { return *this = *this * rhs.inv(); }\n\n    constexpr\
    \ mint operator+() const { return *this; }\n    constexpr mint operator-() const\
    \ { return mint{} - *this; }\n\n    constexpr mint pow(unsigned long long n) const\
    \ {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n        while (n)\
    \ {\n            if (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n\
    \        }\n        return r;\n    }\n    constexpr mint inv() const {\n     \
    \   if constexpr (prime) {\n            assert(_v);\n            return pow(m\
    \ - 2);\n        } else {\n            auto eg = inv_gcd(_v, m);\n           \
    \ assert(eg.first == 1);\n            return eg.second;\n        }\n    }\n\n\
    \    friend constexpr mint operator+(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) += rhs; }\n    friend constexpr mint operator-(const mint& lhs, const\
    \ mint& rhs) { return mint(lhs) -= rhs; }\n    friend constexpr mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend constexpr\
    \ mint operator/(const mint& lhs, const mint& rhs) { return mint(lhs) /= rhs;\
    \ }\n    friend constexpr bool operator==(const mint& lhs, const mint& rhs) {\
    \ return lhs._v == rhs._v; }\n    friend constexpr bool operator!=(const mint&\
    \ lhs, const mint& rhs) { return lhs._v != rhs._v; }\n};\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    \n#endif  // _LIB_STATIC_MODINT_HPP\n/**\n * @brief static_modint\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: static_modint.hpp
  requiredBy: []
  timestamp: '2023-12-30 14:39:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: static_modint.hpp
layout: document
redirect_from:
- /library/static_modint.hpp
- /library/static_modint.hpp.html
title: static_modint
---
