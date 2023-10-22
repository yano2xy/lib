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
  bundledCode: "#line 2 \"lagrange_interpolation.hpp\"\n\n#include <cassert>\n#include\
    \ <vector>\n\ntemplate <typename mint>\nmint lagrange_interpolation(const std::vector<mint>&\
    \ y, long long x, int _NMAX = 5100000) {\n    int N = (int)y.size() - 1;\n   \
    \ assert(N <= _NMAX);\n    if (x <= N) return y[x];\n    static std::vector<mint>\
    \ ifact = [&] {\n        std::vector<mint> fact(_NMAX), ifact(_NMAX);\n      \
    \  fact[0] = 1;\n        for (int i = 1; i <= N; ++i)\n            fact[i] = fact[i\
    \ - 1] * i;\n        ifact[N] = fact[N].inv();\n        for (int i = N; i >= 1;\
    \ --i)\n            ifact[i - 1] = ifact[i] * i;\n        return ifact;\n    }();\n\
    \n    mint ret = 0;\n    std::vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n    for\
    \ (int i = 0; i < N; i++)\n        dp[i + 1] = dp[i] * (x - i);\n    for (int\
    \ i = N; i > 0; i--)\n        pd[i - 1] = pd[i] * (x - i);\n    for (int i = 0;\
    \ i <= N; i++) {\n        mint tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N\
    \ - i];\n        ret += ((N - i) & 1) ? -tmp : tmp;\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ mint>\nmint lagrange_interpolation(const std::vector<mint>& y, long long x,\
    \ int _NMAX = 5100000) {\n    int N = (int)y.size() - 1;\n    assert(N <= _NMAX);\n\
    \    if (x <= N) return y[x];\n    static std::vector<mint> ifact = [&] {\n  \
    \      std::vector<mint> fact(_NMAX), ifact(_NMAX);\n        fact[0] = 1;\n  \
    \      for (int i = 1; i <= N; ++i)\n            fact[i] = fact[i - 1] * i;\n\
    \        ifact[N] = fact[N].inv();\n        for (int i = N; i >= 1; --i)\n   \
    \         ifact[i - 1] = ifact[i] * i;\n        return ifact;\n    }();\n\n  \
    \  mint ret = 0;\n    std::vector<mint> dp(N + 1, 1), pd(N + 1, 1);\n    for (int\
    \ i = 0; i < N; i++)\n        dp[i + 1] = dp[i] * (x - i);\n    for (int i = N;\
    \ i > 0; i--)\n        pd[i - 1] = pd[i] * (x - i);\n    for (int i = 0; i <=\
    \ N; i++) {\n        mint tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N - i];\n\
    \        ret += ((N - i) & 1) ? -tmp : tmp;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2023-10-22 11:06:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/lagrange_interpolation.hpp
- /library/lagrange_interpolation.hpp.html
title: lagrange_interpolation.hpp
---
