---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: dyanamic_modint
    links: []
  bundledCode: "#line 2 \"dynamic_modint.hpp\"\n\n#ifndef _LIB_DYNAMIC_MODINT_HPP\n\
    #define _LIB_DYNAMIC_MODINT_HPP 1\n\n#include <cassert>\n#include <iostream>\n\
    \nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n    barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod()\
    \ const { return _m; }\n    unsigned int mul(unsigned int a, unsigned int b) const\
    \ {\n        unsigned long long z = a;\n        z *= b;\n        unsigned long\
    \ long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned\
    \ int v = (unsigned int)(z - x * _m);\n        if (_m <= v) v += _m;\n       \
    \ return v;\n    }\n};\n\ntemplate <int id>\nstruct dynamic_modint {\n    using\
    \ mint = dynamic_modint;\n\n   private:\n    unsigned int _v;\n    static barrett\
    \ bt;\n    static unsigned int umod() { return bt.umod(); }\n\n    static std::pair<unsigned\
    \ int, unsigned int> inv_gcd(unsigned int a, unsigned int b) {\n        if (a\
    \ == 0) return {b, 0};\n        unsigned int s = b, t = a, m0 = 0, m1 = 1;\n \
    \       while (t) {\n            const unsigned int u = s / t;\n            s\
    \ -= t * u;\n            m0 -= m1 * u;\n            std::swap(s, t);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 < 0) m0 += b / s;\n      \
    \  return {s, m0};\n    }\n\n   public:\n    static int mod() { return (int)bt.umod();\
    \ }\n    static void set_mod(int m) {\n        assert(0 <= m);\n        bt = barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T>\n    dynamic_modint(T v) {\n        if (std::is_signed_v<T>) {\n        \
    \    long long x = (long long)(v % (long long)(mod()));\n            if (x < 0)\
    \ x += mod();\n            _v = (unsigned int)(x);\n        } else {\n       \
    \     _v = (unsigned int)(v % mod());\n        }\n    }\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() { return *this += 1; }\n    mint&\
    \ operator--() { return *this -= 1; }\n    mint operator++(int) {\n        mint\
    \ res = *this;\n        ++*this;\n        return res;\n    }\n    mint operator--(int)\
    \ {\n        mint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    mint& operator+=(mint rhs) {\n        if (_v >= umod() - rhs._v) _v -= umod();\n\
    \        _v += rhs._v;\n        return *this;\n    }\n    mint& operator-=(mint\
    \ rhs) {\n        if (_v < rhs._v) _v += umod();\n        _v -= rhs._v;\n    \
    \    return *this;\n    }\n    mint& operator*=(mint rhs) {\n        _v = bt.mul(_v,\
    \ rhs._v);\n        return *this;\n    }\n    mint& operator/=(mint rhs) { return\
    \ *this = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint{} - *this; }\n\n    mint pow(unsigned\
    \ long long n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n\
    \        while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n  \
    \          n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const\
    \ {\n        auto eg = inv_gcd(_v, mod());\n        assert(eg.first == 1);\n \
    \       return (int)eg.second;\n    }\n\n    friend mint operator+(const mint&\
    \ lhs, const mint& rhs) { return mint(lhs) += rhs; }\n    friend mint operator-(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) -= rhs; }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const\
    \ mint& lhs, const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n};\ntemplate <int\
    \ id>\nbarrett dynamic_modint<id>::bt(998244353);\nusing modint = dynamic_modint<-1>;\n\
    \n#endif  // _LIB_DYNAMIC_MODINT_HPP\n/**\n * @brief dyanamic_modint\n */\n"
  code: "#pragma once\n\n#ifndef _LIB_DYNAMIC_MODINT_HPP\n#define _LIB_DYNAMIC_MODINT_HPP\
    \ 1\n\n#include <cassert>\n#include <iostream>\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n    unsigned int umod() const { return _m; }\n \
    \   unsigned int mul(unsigned int a, unsigned int b) const {\n        unsigned\
    \ long long z = a;\n        z *= b;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned int v = (unsigned\
    \ int)(z - x * _m);\n        if (_m <= v) v += _m;\n        return v;\n    }\n\
    };\n\ntemplate <int id>\nstruct dynamic_modint {\n    using mint = dynamic_modint;\n\
    \n   private:\n    unsigned int _v;\n    static barrett bt;\n    static unsigned\
    \ int umod() { return bt.umod(); }\n\n    static std::pair<unsigned int, unsigned\
    \ int> inv_gcd(unsigned int a, unsigned int b) {\n        if (a == 0) return {b,\
    \ 0};\n        unsigned int s = b, t = a, m0 = 0, m1 = 1;\n        while (t) {\n\
    \            const unsigned int u = s / t;\n            s -= t * u;\n        \
    \    m0 -= m1 * u;\n            std::swap(s, t);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 < 0) m0 += b / s;\n        return {s, m0};\n    }\n\
    \n   public:\n    static int mod() { return (int)bt.umod(); }\n    static void\
    \ set_mod(int m) {\n        assert(0 <= m);\n        bt = barrett(m);\n    }\n\
    \    static mint raw(int v) {\n        mint x;\n        x._v = v;\n        return\
    \ x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class T>\n    dynamic_modint(T\
    \ v) {\n        if (std::is_signed_v<T>) {\n            long long x = (long long)(v\
    \ % (long long)(mod()));\n            if (x < 0) x += mod();\n            _v =\
    \ (unsigned int)(x);\n        } else {\n            _v = (unsigned int)(v % mod());\n\
    \        }\n    }\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ { return *this += 1; }\n    mint& operator--() { return *this -= 1; }\n    mint\
    \ operator++(int) {\n        mint res = *this;\n        ++*this;\n        return\
    \ res;\n    }\n    mint operator--(int) {\n        mint res = *this;\n       \
    \ --*this;\n        return res;\n    }\n    mint& operator+=(mint rhs) {\n   \
    \     if (_v >= umod() - rhs._v) _v -= umod();\n        _v += rhs._v;\n      \
    \  return *this;\n    }\n    mint& operator-=(mint rhs) {\n        if (_v < rhs._v)\
    \ _v += umod();\n        _v -= rhs._v;\n        return *this;\n    }\n    mint&\
    \ operator*=(mint rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n\
    \    }\n    mint& operator/=(mint rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint{} - *this; }\n\n    mint pow(unsigned long long n) const {\n        assert(0\
    \ <= n);\n        mint x = *this, r = 1;\n        while (n) {\n            if\
    \ (n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n    \
    \    return r;\n    }\n    mint inv() const {\n        auto eg = inv_gcd(_v, mod());\n\
    \        assert(eg.first == 1);\n        return (int)eg.second;\n    }\n\n   \
    \ friend mint operator+(const mint& lhs, const mint& rhs) { return mint(lhs) +=\
    \ rhs; }\n    friend mint operator-(const mint& lhs, const mint& rhs) { return\
    \ mint(lhs) -= rhs; }\n    friend mint operator*(const mint& lhs, const mint&\
    \ rhs) { return mint(lhs) *= rhs; }\n    friend mint operator/(const mint& lhs,\
    \ const mint& rhs) { return mint(lhs) /= rhs; }\n    friend bool operator==(const\
    \ mint& lhs, const mint& rhs) { return lhs._v == rhs._v; }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) { return lhs._v != rhs._v; }\n};\ntemplate <int\
    \ id>\nbarrett dynamic_modint<id>::bt(998244353);\nusing modint = dynamic_modint<-1>;\n\
    \n#endif  // _LIB_DYNAMIC_MODINT_HPP\n/**\n * @brief dyanamic_modint\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: dynamic_modint.hpp
  requiredBy: []
  timestamp: '2023-12-30 14:39:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic_modint.hpp
layout: document
redirect_from:
- /library/dynamic_modint.hpp
- /library/dynamic_modint.hpp.html
title: dyanamic_modint
---
