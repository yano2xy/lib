---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: segtree_2d.hpp
    title: 2D Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068
  bundledCode: "#line 1 \"verify/segtree_2d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n\n#line 2 \"segtree_2d.hpp\"\n\n#include <vector>\n\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()>\nstruct segtree_2d {\n   private:\n    int id(int h, int w) const\
    \ { return h * 2 * W + w; }\n    void init(int h, int w) {\n        H = W = 1;\n\
    \        while (H < h)\n            H <<= 1;\n        while (W < w)\n        \
    \    W <<= 1;\n        seg.assign(4 * H * W, e());\n    }\n    void build() {\n\
    \        // w in [W, 2W)\n        for (int w = W; w < 2 * W; w++) {\n        \
    \    for (int h = H - 1; h; h--) {\n                seg[id(h, w)] = op(seg[id(2\
    \ * h + 0, w)], seg[id(2 * h + 1, w)]);\n            }\n        }\n        //\
    \ h in [0, 2H)\n        for (int h = 0; h < 2 * H; h++) {\n            for (int\
    \ w = W - 1; w; w--) {\n                seg[id(h, w)] = op(seg[id(h, 2 * w + 0)],\
    \ seg[id(h, 2 * w + 1)]);\n            }\n        }\n    }\n    T _inner_query(int\
    \ h, int w1, int w2) {\n        T res = e();\n        for (; w1 < w2; w1 >>= 1,\
    \ w2 >>= 1) {\n            if (w1 & 1) res = op(res, seg[id(h, w1)]), w1++;\n\
    \            if (w2 & 1) --w2, res = op(res, seg[id(h, w2)]);\n        }\n   \
    \     return res;\n    }\n\n   public:\n    int H, W;\n    std::vector<T> seg;\n\
    \n    segtree_2d(int h, int w) {\n        init(h, w);\n        build();\n    }\n\
    \    segtree_2d(const std::vector<std::vector<T>>& A) {\n        int h = A.size(),\
    \ w = A[0].size();\n        init(h, w);\n        for (int i = 0; i < h; i++) {\n\
    \            for (int j = 0; j < w; j++) {\n                seg[id(i + H, j +\
    \ W)] = A[i][j];\n            }\n        }\n        build();\n    }\n    T get(int\
    \ h, int w) const { return seg[id(h + H, w + W)]; }\n    void set(int h, int w,\
    \ const T& x) {\n        h += H, w += W;\n        seg[id(h, w)] = x;\n       \
    \ for (int i = h >> 1; i; i >>= 1) {\n            seg[id(i, w)] = op(seg[id(2\
    \ * i + 0, w)], seg[id(2 * i + 1, w)]);\n        }\n        for (; h; h >>= 1)\
    \ {\n            for (int j = w >> 1; j; j >>= 1) {\n                seg[id(h,\
    \ j)] = op(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);\n            }\n   \
    \     }\n    }\n    T prod(int h1, int w1, int h2, int w2) {\n        if (h1 >=\
    \ h2 || w1 >= w2) return e();\n        T res = e();\n        h1 += H, h2 += H,\
    \ w1 += W, w2 += W;\n        for (; h1 < h2; h1 >>= 1, h2 >>= 1) {\n         \
    \   if (h1 & 1) res = op(res, _inner_query(h1, w1, w2)), h1++;\n            if\
    \ (h2 & 1) --h2, res = op(res, _inner_query(h2, w1, w2));\n        }\n       \
    \ return res;\n    }\n};\n/**\n * @brief 2D Segment Tree\n * @docs docs/segtree_2d.md\n\
    \ */\n#line 4 \"verify/segtree_2d.test.cpp\"\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n#define rep(i, n) for (int i = 0; i < (n); i++)\nusing ll =\
    \ long long;\n\nll op(ll a, ll b) {\n    return min(a, b);\n}\nll INF = 1e18;\n\
    ll e() {\n    return INF;\n}\n\nint main() {\n    while (true) {\n        int\
    \ r, c, Q;\n        cin >> r >> c >> Q;\n        if (r == 0) return 0;\n\n   \
    \     // vector A(r, vector<ll>(c, INF));\n        //  rep(i, r) rep(j, c) cin\
    \ >> A[i][j];\n        // segtree_2d<ll, op, e> seg(A);\n        segtree_2d<ll,\
    \ op, e> seg(r, c);\n        rep(i, r) rep(j, c) {\n            ll a;\n      \
    \      cin >> a;\n            seg.set(i, j, a);\n        }\n\n        while (Q--)\
    \ {\n            int h1, w1, h2, w2;\n            cin >> h1 >> w1 >> h2 >> w2;\n\
    \            h2++, w2++;\n            cout << seg.prod(h1, w1, h2, w2) << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1068\"\
    \n\n#include \"../lib/segtree_2d.hpp\"\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n#define rep(i, n) for (int i = 0; i < (n); i++)\nusing ll = long long;\n\
    \nll op(ll a, ll b) {\n    return min(a, b);\n}\nll INF = 1e18;\nll e() {\n  \
    \  return INF;\n}\n\nint main() {\n    while (true) {\n        int r, c, Q;\n\
    \        cin >> r >> c >> Q;\n        if (r == 0) return 0;\n\n        // vector\
    \ A(r, vector<ll>(c, INF));\n        //  rep(i, r) rep(j, c) cin >> A[i][j];\n\
    \        // segtree_2d<ll, op, e> seg(A);\n        segtree_2d<ll, op, e> seg(r,\
    \ c);\n        rep(i, r) rep(j, c) {\n            ll a;\n            cin >> a;\n\
    \            seg.set(i, j, a);\n        }\n\n        while (Q--) {\n         \
    \   int h1, w1, h2, w2;\n            cin >> h1 >> w1 >> h2 >> w2;\n          \
    \  h2++, w2++;\n            cout << seg.prod(h1, w1, h2, w2) << '\\n';\n     \
    \   }\n    }\n    return 0;\n}"
  dependsOn:
  - segtree_2d.hpp
  isVerificationFile: true
  path: verify/segtree_2d.test.cpp
  requiredBy: []
  timestamp: '2023-12-20 21:56:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segtree_2d.test.cpp
layout: document
redirect_from:
- /verify/verify/segtree_2d.test.cpp
- /verify/verify/segtree_2d.test.cpp.html
title: verify/segtree_2d.test.cpp
---
