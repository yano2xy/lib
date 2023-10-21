---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"fps.hpp\"\n\n#include <atcoder/all>\n#include <vector>\n\
    \ntemplate <typename mint>\nstd::vector<mint> multiply_garner(const std::vector<mint>\
    \ &f, const std::vector<mint> &g) {\n    int n = (int)f.size(), m = (int)g.size();\n\
    \    if (!n || !m) return {};\n    static const long long nttprimes[] = {754974721,\
    \ 167772161, 469762049};\n    using mint0 = atcoder::static_modint<754974721>;\n\
    \    using mint1 = atcoder::static_modint<167772161>;\n    using mint2 = atcoder::static_modint<469762049>;\n\
    \    std::vector<mint0> f0(n), g0(m);\n    std::vector<mint1> f1(n), g1(m);\n\
    \    std::vector<mint2> f2(n), g2(m);\n    for (int i = 0; i < n; i++)\n     \
    \   f0[i] = f[i].val(), f1[i] = f[i].val(), f2[i] = f[i].val();\n    for (int\
    \ i = 0; i < m; i++)\n        g0[i] = g[i].val(), g1[i] = g[i].val(), g2[i] =\
    \ g[i].val();\n    auto c0 = atcoder::convolution(f0, g0);\n    auto c1 = atcoder::convolution(f1,\
    \ g1);\n    auto c2 = atcoder::convolution(f2, g2);\n    static const long long\
    \ m01 = 1LL * nttprimes[0] * nttprimes[1];\n    static const long long m0_inv_m1\
    \ = mint1(nttprimes[0]).inv().val();\n    static const long long m01_inv_m2 =\
    \ mint2(m01).inv().val();\n    const int mod = mint::mod();\n    auto garner =\
    \ [&](mint0 x0, mint1 x1, mint2 x2) -> mint {\n        int r0 = x0.val(), r1 =\
    \ x1.val(), r2 = x2.val();\n        int v1 = (m0_inv_m1 * (r1 + nttprimes[1] -\
    \ r0)) % nttprimes[1];\n        auto v2 = (mint2(r2) - r0 - mint2(nttprimes[0])\
    \ * v1) * mint2(m01_inv_m2);\n        return mint(r0 + 1LL * nttprimes[0] * v1\
    \ + m01 % mod * v2.val());\n    };\n    int sz = (int)c0.size();\n    std::vector<mint>\
    \ c(sz);\n    for (int i = 0; i < sz; i++)\n        c[i] = garner(c0[i], c1[i],\
    \ c2[i]);\n    return c;\n}\n\ntemplate <typename T = long long>\nstd::vector<T>\
    \ multiply_naive(const std::vector<T> &f, const std::vector<T> &g) {\n    int\
    \ n = (int)f.size(), m = (int)g.size();\n    std::vector<T> ret(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++)\n            for (int i\
    \ = 0; i < n; i++)\n                ret[i + j] += f[i] * g[j];\n    } else {\n\
    \        for (int i = 0; i < n; i++)\n            for (int j = 0; j < m; j++)\n\
    \                ret[i + j] += f[i] * g[j];\n    }\n    return ret;\n}\n\n// F*g\
    \ (F: fps, g: sparse fps)\ntemplate <typename T>\nstd::vector<T> multiply_sparse(const\
    \ std::vector<T> &f, std::vector<std::pair<int, T>> g) {\n    int n = (int)f.size();\n\
    \    std::vector<T> ret(n);\n    for (auto &&[d, c] : g) {\n        for (int i\
    \ = 0; i + d < n; i++) {\n            ret[i + d] += f[i] * c;\n        }\n   \
    \ }\n    return ret;\n}\n\n// F/g (F: fps, g: sparse fps)\n// g\u306E\u5B9A\u6570\
    \u9805\u306F\u975E\u96F6\u3067\u3042\u308B\u3053\u3068\ntemplate <typename T>\n\
    std::vector<T> divide_sparse(const std::vector<T> &f, std::vector<std::pair<int,\
    \ T>> g) {\n    assert(!g.empty() && g.front().first == 0 && g.front().second\
    \ != T(0));\n    int n = (int)f.size(), m = (int)g.size();\n    std::vector<T>\
    \ ret(f.begin(), f.end());\n    T c0inv = T(1) / g.front().second;\n    for (int\
    \ i = 0; i < n; i++)\n        ret[i] *= c0inv;\n    if ((int)g.size() == 1) return\
    \ ret;\n    for (auto &&[d, c] : g)\n        c *= c0inv;\n    int d1 = g[1].first;\n\
    \    for (int i = 0; i + d1 < n; ++i) {\n        for (int j = 1; j < m; ++j) {\n\
    \            auto &&[d, c] = g[j];\n            if (i + d >= n) break;\n     \
    \       ret[i + d] -= ret[i] * c;\n        }\n    }\n    return ret;\n}\n\ntemplate\
    \ <typename T>\nstruct FormalPowerSeries : std::vector<T> {\n    using std::vector<T>::vector;\n\
    \    using FPS = FormalPowerSeries;\n\n    bool is_ntt_mod() const {\n       \
    \ if (typeid(T) == typeid(atcoder::modint998244353)) return true;\n        return\
    \ false;\n    }\n\n    bool is_arbitrary_mod() const {\n        if (typeid(T)\
    \ == typeid(atcoder::modint1000000007)) return true;\n        return false;\n\
    \    }\n\n    // \u6700\u9AD8\u6B21\u6570\u306E\u4FC2\u6570\u3092\u975E\u96F6\u306B\
    \u3059\u308B\n    void shrink() {\n        while (this->size() && this->back()\
    \ == T(0))\n            this->pop_back();\n    }\n\n    // x\u3092\u4EE3\u5165\
    \u3057\u305F\u5024\u3092\u6C42\u3081\u308B\n    T eval(T x) const {\n        T\
    \ r = 0, w = 1;\n        for (auto &v : *this)\n            r += w * v, w *= x;\n\
    \        return r;\n    }\n\n    // \u524Dsz\u9805\u3092\u53D6\u308A\u51FA\u3059\
    \n    FPS pre(int sz) const {\n        FPS ret(begin(*this), begin(*this) + std::min((int)this->size(),\
    \ sz));\n        if ((int)ret.size() < sz) ret.resize(sz);\n        return ret;\n\
    \    }\n\n    // \u4FC2\u6570\u306E\u6F14\u7B97\n\n    FPS operator+=(const T\
    \ &a) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += a;\n\
    \        return *this;\n    }\n\n    FPS operator-=(const T &a) { return *this\
    \ += (-a); }\n\n    FPS operator*=(const T &a) {\n        for (int k = 0; k <\
    \ (int)this->size(); k++)\n            (*this)[k] *= a;\n        return *this;\n\
    \    }\n\n    // \u6F14\u7B97 (fps vs fps)\n\n    FPS operator-() const {\n  \
    \      FPS ret(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++)\n            ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    FPS\
    \ &operator+=(const FPS &f) {\n        int n = (int)this->size(), m = (int)f.size();\n\
    \        for (int i = 0; i < std::min(n, m); i++)\n            (*this)[i] += f[i];\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const FPS &f) { return *this\
    \ += (-f); }\n\n    FPS &operator*=(const FPS &f) {\n        if (this->empty()\
    \ || f.empty()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        int n = (int)this->size();\n        if (is_ntt_mod()) {\n   \
    \         auto v = atcoder::convolution(*this, f);\n            *this = FPS(v.begin(),\
    \ v.end());\n        } else if (is_arbitrary_mod()) {\n            auto v = multiply_garner(*this,\
    \ f);\n            *this = FPS(v.begin(), v.end());\n        } else {\n      \
    \      assert(typeid(T) == typeid(int) || typeid(T) == typeid(long long));\n \
    \           auto v = multiply_naive(*this, f);\n            *this = FPS(v.begin(),\
    \ v.end());\n        }\n        this->resize(n);\n\n        return *this;\n  \
    \  }\n\n    // \u6F14\u7B97 (fps vs sfps)\n    FPS &operator*=(const std::vector<std::pair<int,\
    \ T>> &g) {\n        if (this->empty() || g.empty()) {\n            this->clear();\n\
    \            return *this;\n        }\n        auto v = multiply_sparse(*this,\
    \ g);\n        return *this = FPS(v.begin(), v.end());\n    }\n\n    FPS &operator/=(const\
    \ std::vector<std::pair<int, T>> &g) {\n        if (this->empty()) {\n       \
    \     return *this;\n        }\n        auto v = divide_sparse(*this, g);\n  \
    \      return *this = FPS(v.begin(), v.end());\n    }\n\n    // fps vs fps\n \
    \   FPS operator+(const T &a) const { return FPS(*this) += a; }\n    friend FPS\
    \ operator+(const T &a, const FPS &f) { return f + a; }\n    FPS operator+(const\
    \ FPS &f) const { return FPS(*this) += f; }\n    FPS operator-(const T &a) const\
    \ { return FPS(*this) -= a; }\n    friend FPS operator-(const T &a, const FPS\
    \ &f) { return -f + a; }\n    FPS operator-(const FPS &f) const { return FPS(*this)\
    \ -= f; }\n    FPS operator*(const T &a) const { return FPS(*this) *= a; }\n \
    \   friend FPS operator*(const T &a, const FPS &f) { return f * a; }\n    FPS\
    \ operator*(const FPS &f) const { return FPS(*this) *= f; }\n    FPS operator/(const\
    \ FPS &f) const { return FPS(*this) /= f; }\n\n    // fps vs sfps\n    FPS operator*(const\
    \ std::vector<std::pair<int, T>> &g) const { return FPS(*this) *= g; }\n    FPS\
    \ operator/(const std::vector<std::pair<int, T>> &g) const { return FPS(*this)\
    \ /= g; }\n\n    // \u9006\u5143\n    FPS inv(int deg = -1) const {\n        assert(!this->empty()\
    \ && (*this)[0] != T(0));\n        if (deg == -1) deg = (int)(*this).size();\n\
    \        FPS ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<=\
    \ 1) {\n            ret.resize(i << 1);\n            ret = ret + ret - ret * ret\
    \ * (*this).pre(i << 1);\n        }\n        ret.resize(deg);\n        return\
    \ ret;\n    }\n\n    // -----\n    // f \u304C\u758E\u306A\u5834\u5408\u306E\u6F14\
    \u7B97\n    // -----\n\n    // \u9006\u5143(sparse)\n    FPS inv_sparse(int deg\
    \ = -1) const {\n        assert(!this->empty() && (*this)[0] != T(0));\n     \
    \   if (deg == -1) deg = (int)this->size();\n        // sfps\u306B\u5909\u63DB\
    \n        std::vector<std::pair<int, T>> sf;\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            if ((*this)[i] != T(0)) sf.emplace_back(i, (*this)[i]);\n\
    \        }\n        FPS ret(deg);\n        T invf0 = T(1) / (*this)[0];\n    \
    \    if (deg > 0) ret[0] = invf0;\n        for (int i = 1; i < deg; i++) {\n \
    \           for (auto &[j, c] : sf) {\n                if (i < j) break;\n   \
    \             ret[i] += ret[i - j] * c;\n            }\n            ret[i] *=\
    \ -invf0;\n        }\n        return ret;\n    }\n\n    // \u7D2F\u4E57(sparse)\
    \ \u203B k\u304C\u8CA0\u3067\u3082OK\n    FPS pow_sparse(long long k, int deg\
    \ = -1) const {\n        int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n        if (k == 0) {\n            FPS g(deg);\n            if (deg) g[0]\
    \ = 1;\n            return g;\n        }\n        int zero = 0;\n        while\
    \ (zero != n && (*this)[zero] == 0)\n            zero++;\n        if (zero ==\
    \ n || __int128_t(zero) * k >= deg) {\n            return FPS(deg, 0);\n     \
    \   }\n        if (zero != 0) {\n            FPS suf{this->begin() + zero, this->end()};\n\
    \            auto g = suf.pow_sparse(k, deg - zero * k);\n            FPS h(zero\
    \ * k, 0);\n            copy(g.begin(), g.end(), std::back_inserter(h));\n   \
    \         return h;\n        }\n\n        int mod = T::mod();\n        static\
    \ std::vector<T> invs{1, 1};\n        while ((int)invs.size() <= deg) {\n    \
    \        int i = invs.size();\n            invs.push_back((-invs[mod % i]) * (mod\
    \ / i));\n        }\n\n        std::vector<std::pair<int, T>> fs;\n        for\
    \ (int i = 1; i < n; i++) {\n            if ((*this)[i] != 0) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        FPS g(deg);\n        g[0] = (k >= 0) ? (*this)[0].pow(k)\
    \ : (*this)[0].inv().pow(-k);\n        T denom = (*this)[0].inv();\n        k\
    \ %= T::mod();\n        for (int i = 1; i < deg; i++) {\n            for (auto\
    \ &[j, c] : fs) {\n                if (i < j) break;\n                g[i] +=\
    \ c * g[i - j] * ((k + 1) * j - i);\n            }\n            g[i] *= denom\
    \ * invs[i];\n        }\n        return g;\n    }\n};\ntemplate <typename mint>\n\
    using fps = FormalPowerSeries<mint>;\ntemplate <typename mint>\nusing sfps = std::vector<std::pair<int,\
    \ mint>>;\n"
  code: "#pragma once\n\n#include <atcoder/all>\n#include <vector>\n\ntemplate <typename\
    \ mint>\nstd::vector<mint> multiply_garner(const std::vector<mint> &f, const std::vector<mint>\
    \ &g) {\n    int n = (int)f.size(), m = (int)g.size();\n    if (!n || !m) return\
    \ {};\n    static const long long nttprimes[] = {754974721, 167772161, 469762049};\n\
    \    using mint0 = atcoder::static_modint<754974721>;\n    using mint1 = atcoder::static_modint<167772161>;\n\
    \    using mint2 = atcoder::static_modint<469762049>;\n    std::vector<mint0>\
    \ f0(n), g0(m);\n    std::vector<mint1> f1(n), g1(m);\n    std::vector<mint2>\
    \ f2(n), g2(m);\n    for (int i = 0; i < n; i++)\n        f0[i] = f[i].val(),\
    \ f1[i] = f[i].val(), f2[i] = f[i].val();\n    for (int i = 0; i < m; i++)\n \
    \       g0[i] = g[i].val(), g1[i] = g[i].val(), g2[i] = g[i].val();\n    auto\
    \ c0 = atcoder::convolution(f0, g0);\n    auto c1 = atcoder::convolution(f1, g1);\n\
    \    auto c2 = atcoder::convolution(f2, g2);\n    static const long long m01 =\
    \ 1LL * nttprimes[0] * nttprimes[1];\n    static const long long m0_inv_m1 = mint1(nttprimes[0]).inv().val();\n\
    \    static const long long m01_inv_m2 = mint2(m01).inv().val();\n    const int\
    \ mod = mint::mod();\n    auto garner = [&](mint0 x0, mint1 x1, mint2 x2) -> mint\
    \ {\n        int r0 = x0.val(), r1 = x1.val(), r2 = x2.val();\n        int v1\
    \ = (m0_inv_m1 * (r1 + nttprimes[1] - r0)) % nttprimes[1];\n        auto v2 =\
    \ (mint2(r2) - r0 - mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\n        return\
    \ mint(r0 + 1LL * nttprimes[0] * v1 + m01 % mod * v2.val());\n    };\n    int\
    \ sz = (int)c0.size();\n    std::vector<mint> c(sz);\n    for (int i = 0; i <\
    \ sz; i++)\n        c[i] = garner(c0[i], c1[i], c2[i]);\n    return c;\n}\n\n\
    template <typename T = long long>\nstd::vector<T> multiply_naive(const std::vector<T>\
    \ &f, const std::vector<T> &g) {\n    int n = (int)f.size(), m = (int)g.size();\n\
    \    std::vector<T> ret(n + m - 1);\n    if (n < m) {\n        for (int j = 0;\
    \ j < m; j++)\n            for (int i = 0; i < n; i++)\n                ret[i\
    \ + j] += f[i] * g[j];\n    } else {\n        for (int i = 0; i < n; i++)\n  \
    \          for (int j = 0; j < m; j++)\n                ret[i + j] += f[i] * g[j];\n\
    \    }\n    return ret;\n}\n\n// F*g (F: fps, g: sparse fps)\ntemplate <typename\
    \ T>\nstd::vector<T> multiply_sparse(const std::vector<T> &f, std::vector<std::pair<int,\
    \ T>> g) {\n    int n = (int)f.size();\n    std::vector<T> ret(n);\n    for (auto\
    \ &&[d, c] : g) {\n        for (int i = 0; i + d < n; i++) {\n            ret[i\
    \ + d] += f[i] * c;\n        }\n    }\n    return ret;\n}\n\n// F/g (F: fps, g:\
    \ sparse fps)\n// g\u306E\u5B9A\u6570\u9805\u306F\u975E\u96F6\u3067\u3042\u308B\
    \u3053\u3068\ntemplate <typename T>\nstd::vector<T> divide_sparse(const std::vector<T>\
    \ &f, std::vector<std::pair<int, T>> g) {\n    assert(!g.empty() && g.front().first\
    \ == 0 && g.front().second != T(0));\n    int n = (int)f.size(), m = (int)g.size();\n\
    \    std::vector<T> ret(f.begin(), f.end());\n    T c0inv = T(1) / g.front().second;\n\
    \    for (int i = 0; i < n; i++)\n        ret[i] *= c0inv;\n    if ((int)g.size()\
    \ == 1) return ret;\n    for (auto &&[d, c] : g)\n        c *= c0inv;\n    int\
    \ d1 = g[1].first;\n    for (int i = 0; i + d1 < n; ++i) {\n        for (int j\
    \ = 1; j < m; ++j) {\n            auto &&[d, c] = g[j];\n            if (i + d\
    \ >= n) break;\n            ret[i + d] -= ret[i] * c;\n        }\n    }\n    return\
    \ ret;\n}\n\ntemplate <typename T>\nstruct FormalPowerSeries : std::vector<T>\
    \ {\n    using std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n\n\
    \    bool is_ntt_mod() const {\n        if (typeid(T) == typeid(atcoder::modint998244353))\
    \ return true;\n        return false;\n    }\n\n    bool is_arbitrary_mod() const\
    \ {\n        if (typeid(T) == typeid(atcoder::modint1000000007)) return true;\n\
    \        return false;\n    }\n\n    // \u6700\u9AD8\u6B21\u6570\u306E\u4FC2\u6570\
    \u3092\u975E\u96F6\u306B\u3059\u308B\n    void shrink() {\n        while (this->size()\
    \ && this->back() == T(0))\n            this->pop_back();\n    }\n\n    // x\u3092\
    \u4EE3\u5165\u3057\u305F\u5024\u3092\u6C42\u3081\u308B\n    T eval(T x) const\
    \ {\n        T r = 0, w = 1;\n        for (auto &v : *this)\n            r +=\
    \ w * v, w *= x;\n        return r;\n    }\n\n    // \u524Dsz\u9805\u3092\u53D6\
    \u308A\u51FA\u3059\n    FPS pre(int sz) const {\n        FPS ret(begin(*this),\
    \ begin(*this) + std::min((int)this->size(), sz));\n        if ((int)ret.size()\
    \ < sz) ret.resize(sz);\n        return ret;\n    }\n\n    // \u4FC2\u6570\u306E\
    \u6F14\u7B97\n\n    FPS operator+=(const T &a) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += a;\n        return *this;\n    }\n\n    FPS operator-=(const\
    \ T &a) { return *this += (-a); }\n\n    FPS operator*=(const T &a) {\n      \
    \  for (int k = 0; k < (int)this->size(); k++)\n            (*this)[k] *= a;\n\
    \        return *this;\n    }\n\n    // \u6F14\u7B97 (fps vs fps)\n\n    FPS operator-()\
    \ const {\n        FPS ret(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++)\n            ret[i] = -(*this)[i];\n        return ret;\n    }\n\n    FPS\
    \ &operator+=(const FPS &f) {\n        int n = (int)this->size(), m = (int)f.size();\n\
    \        for (int i = 0; i < std::min(n, m); i++)\n            (*this)[i] += f[i];\n\
    \        return *this;\n    }\n\n    FPS &operator-=(const FPS &f) { return *this\
    \ += (-f); }\n\n    FPS &operator*=(const FPS &f) {\n        if (this->empty()\
    \ || f.empty()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        int n = (int)this->size();\n        if (is_ntt_mod()) {\n   \
    \         auto v = atcoder::convolution(*this, f);\n            *this = FPS(v.begin(),\
    \ v.end());\n        } else if (is_arbitrary_mod()) {\n            auto v = multiply_garner(*this,\
    \ f);\n            *this = FPS(v.begin(), v.end());\n        } else {\n      \
    \      assert(typeid(T) == typeid(int) || typeid(T) == typeid(long long));\n \
    \           auto v = multiply_naive(*this, f);\n            *this = FPS(v.begin(),\
    \ v.end());\n        }\n        this->resize(n);\n\n        return *this;\n  \
    \  }\n\n    // \u6F14\u7B97 (fps vs sfps)\n    FPS &operator*=(const std::vector<std::pair<int,\
    \ T>> &g) {\n        if (this->empty() || g.empty()) {\n            this->clear();\n\
    \            return *this;\n        }\n        auto v = multiply_sparse(*this,\
    \ g);\n        return *this = FPS(v.begin(), v.end());\n    }\n\n    FPS &operator/=(const\
    \ std::vector<std::pair<int, T>> &g) {\n        if (this->empty()) {\n       \
    \     return *this;\n        }\n        auto v = divide_sparse(*this, g);\n  \
    \      return *this = FPS(v.begin(), v.end());\n    }\n\n    // fps vs fps\n \
    \   FPS operator+(const T &a) const { return FPS(*this) += a; }\n    friend FPS\
    \ operator+(const T &a, const FPS &f) { return f + a; }\n    FPS operator+(const\
    \ FPS &f) const { return FPS(*this) += f; }\n    FPS operator-(const T &a) const\
    \ { return FPS(*this) -= a; }\n    friend FPS operator-(const T &a, const FPS\
    \ &f) { return -f + a; }\n    FPS operator-(const FPS &f) const { return FPS(*this)\
    \ -= f; }\n    FPS operator*(const T &a) const { return FPS(*this) *= a; }\n \
    \   friend FPS operator*(const T &a, const FPS &f) { return f * a; }\n    FPS\
    \ operator*(const FPS &f) const { return FPS(*this) *= f; }\n    FPS operator/(const\
    \ FPS &f) const { return FPS(*this) /= f; }\n\n    // fps vs sfps\n    FPS operator*(const\
    \ std::vector<std::pair<int, T>> &g) const { return FPS(*this) *= g; }\n    FPS\
    \ operator/(const std::vector<std::pair<int, T>> &g) const { return FPS(*this)\
    \ /= g; }\n\n    // \u9006\u5143\n    FPS inv(int deg = -1) const {\n        assert(!this->empty()\
    \ && (*this)[0] != T(0));\n        if (deg == -1) deg = (int)(*this).size();\n\
    \        FPS ret({T(1) / (*this)[0]});\n        for (int i = 1; i < deg; i <<=\
    \ 1) {\n            ret.resize(i << 1);\n            ret = ret + ret - ret * ret\
    \ * (*this).pre(i << 1);\n        }\n        ret.resize(deg);\n        return\
    \ ret;\n    }\n\n    // -----\n    // f \u304C\u758E\u306A\u5834\u5408\u306E\u6F14\
    \u7B97\n    // -----\n\n    // \u9006\u5143(sparse)\n    FPS inv_sparse(int deg\
    \ = -1) const {\n        assert(!this->empty() && (*this)[0] != T(0));\n     \
    \   if (deg == -1) deg = (int)this->size();\n        // sfps\u306B\u5909\u63DB\
    \n        std::vector<std::pair<int, T>> sf;\n        for (int i = 0; i < (int)this->size();\
    \ i++) {\n            if ((*this)[i] != T(0)) sf.emplace_back(i, (*this)[i]);\n\
    \        }\n        FPS ret(deg);\n        T invf0 = T(1) / (*this)[0];\n    \
    \    if (deg > 0) ret[0] = invf0;\n        for (int i = 1; i < deg; i++) {\n \
    \           for (auto &[j, c] : sf) {\n                if (i < j) break;\n   \
    \             ret[i] += ret[i - j] * c;\n            }\n            ret[i] *=\
    \ -invf0;\n        }\n        return ret;\n    }\n\n    // \u7D2F\u4E57(sparse)\
    \ \u203B k\u304C\u8CA0\u3067\u3082OK\n    FPS pow_sparse(long long k, int deg\
    \ = -1) const {\n        int n = (int)this->size();\n        if (deg == -1) deg\
    \ = n;\n        if (k == 0) {\n            FPS g(deg);\n            if (deg) g[0]\
    \ = 1;\n            return g;\n        }\n        int zero = 0;\n        while\
    \ (zero != n && (*this)[zero] == 0)\n            zero++;\n        if (zero ==\
    \ n || __int128_t(zero) * k >= deg) {\n            return FPS(deg, 0);\n     \
    \   }\n        if (zero != 0) {\n            FPS suf{this->begin() + zero, this->end()};\n\
    \            auto g = suf.pow_sparse(k, deg - zero * k);\n            FPS h(zero\
    \ * k, 0);\n            copy(g.begin(), g.end(), std::back_inserter(h));\n   \
    \         return h;\n        }\n\n        int mod = T::mod();\n        static\
    \ std::vector<T> invs{1, 1};\n        while ((int)invs.size() <= deg) {\n    \
    \        int i = invs.size();\n            invs.push_back((-invs[mod % i]) * (mod\
    \ / i));\n        }\n\n        std::vector<std::pair<int, T>> fs;\n        for\
    \ (int i = 1; i < n; i++) {\n            if ((*this)[i] != 0) fs.emplace_back(i,\
    \ (*this)[i]);\n        }\n\n        FPS g(deg);\n        g[0] = (k >= 0) ? (*this)[0].pow(k)\
    \ : (*this)[0].inv().pow(-k);\n        T denom = (*this)[0].inv();\n        k\
    \ %= T::mod();\n        for (int i = 1; i < deg; i++) {\n            for (auto\
    \ &[j, c] : fs) {\n                if (i < j) break;\n                g[i] +=\
    \ c * g[i - j] * ((k + 1) * j - i);\n            }\n            g[i] *= denom\
    \ * invs[i];\n        }\n        return g;\n    }\n};\ntemplate <typename mint>\n\
    using fps = FormalPowerSeries<mint>;\ntemplate <typename mint>\nusing sfps = std::vector<std::pair<int,\
    \ mint>>;"
  dependsOn: []
  isVerificationFile: false
  path: fps.hpp
  requiredBy: []
  timestamp: '2023-10-21 15:56:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps.hpp
layout: document
redirect_from:
- /library/fps.hpp
- /library/fps.hpp.html
title: fps.hpp
---
