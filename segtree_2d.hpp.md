---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/segtree_2d.test.cpp
    title: verify/segtree_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segtree_2d.md
    document_title: 2D Segment Tree
    links: []
  bundledCode: "#line 2 \"segtree_2d.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)()>\nstruct segtree_2d {\n   private:\n    int id(int\
    \ h, int w) const { return h * 2 * W + w; }\n    void init(int h, int w) {\n \
    \       H = W = 1;\n        while (H < h)\n            H <<= 1;\n        while\
    \ (W < w)\n            W <<= 1;\n        seg.assign(4 * H * W, e());\n    }\n\
    \    void build() {\n        // w in [W, 2W)\n        for (int w = W; w < 2 *\
    \ W; w++) {\n            for (int h = H - 1; h; h--) {\n                seg[id(h,\
    \ w)] = op(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);\n            }\n   \
    \     }\n        // h in [0, 2H)\n        for (int h = 0; h < 2 * H; h++) {\n\
    \            for (int w = W - 1; w; w--) {\n                seg[id(h, w)] = op(seg[id(h,\
    \ 2 * w + 0)], seg[id(h, 2 * w + 1)]);\n            }\n        }\n    }\n    T\
    \ _inner_query(int h, int w1, int w2) {\n        T res = e();\n        for (;\
    \ w1 < w2; w1 >>= 1, w2 >>= 1) {\n            if (w1 & 1) res = op(res, seg[id(h,\
    \ w1)]), w1++;\n            if (w2 & 1) --w2, res = op(res, seg[id(h, w2)]);\n\
    \        }\n        return res;\n    }\n\n   public:\n    int H, W;\n    std::vector<T>\
    \ seg;\n\n    segtree_2d(int h, int w) {\n        init(h, w);\n        build();\n\
    \    }\n    segtree_2d(const std::vector<std::vector<T>>& A) {\n        int h\
    \ = A.size(), w = A[0].size();\n        init(h, w);\n        for (int i = 0; i\
    \ < h; i++) {\n            for (int j = 0; j < w; j++) {\n                seg[id(i\
    \ + H, j + W)] = A[i][j];\n            }\n        }\n        build();\n    }\n\
    \    T get(int h, int w) const { return seg[id(h + H, w + W)]; }\n    void set(int\
    \ h, int w, const T& x) {\n        h += H, w += W;\n        seg[id(h, w)] = x;\n\
    \        for (int i = h >> 1; i; i >>= 1) {\n            seg[id(i, w)] = op(seg[id(2\
    \ * i + 0, w)], seg[id(2 * i + 1, w)]);\n        }\n        for (; h; h >>= 1)\
    \ {\n            for (int j = w >> 1; j; j >>= 1) {\n                seg[id(h,\
    \ j)] = op(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);\n            }\n   \
    \     }\n    }\n    T prod(int h1, int w1, int h2, int w2) {\n        if (h1 >=\
    \ h2 || w1 >= w2) return e();\n        T res = e();\n        h1 += H, h2 += H,\
    \ w1 += W, w2 += W;\n        for (; h1 < h2; h1 >>= 1, h2 >>= 1) {\n         \
    \   if (h1 & 1) res = op(res, _inner_query(h1, w1, w2)), h1++;\n            if\
    \ (h2 & 1) --h2, res = op(res, _inner_query(h2, w1, w2));\n        }\n       \
    \ return res;\n    }\n};\n/**\n * @brief 2D Segment Tree\n * @docs docs/segtree_2d.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class T, T (*op)(T, T), T\
    \ (*e)()>\nstruct segtree_2d {\n   private:\n    int id(int h, int w) const {\
    \ return h * 2 * W + w; }\n    void init(int h, int w) {\n        H = W = 1;\n\
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
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: segtree_2d.hpp
  requiredBy: []
  timestamp: '2023-12-20 21:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/segtree_2d.test.cpp
documentation_of: segtree_2d.hpp
layout: document
redirect_from:
- /library/segtree_2d.hpp
- /library/segtree_2d.hpp.html
title: 2D Segment Tree
---
# segtree_2d (2D Segment Tree)

- モノイドに対して使用可能
- 二次元配列に対して、1点更新と区間積の取得を $O(\log(H)\log(W))$ で実行する

## コンストラクタ

```cpp
segtree_2d<S, op, e> seg(h, w)
```
- op はモノイド演算
- e は単位減取得関数
- 二次元配列のサイズ $(h, w)$ を与えて初期化する

```cpp
segtree_2d<S, op, e> seg(A)
```

- または、二次元配列 $A$ によって初期化する

## get

~~~cpp
T seg.get()
~~~

- $seg[h][w]$ の値を取得する

***計算量***

- $O(1)$

## set

~~~cpp
void seg.set(int h, int w, T x)
~~~

- $seg[h][w]$ を $x$ に更新する

***計算量***

- $O(\log(H)\log(W))$

## prod

~~~cpp
T seg.prod(int h1, int w1, int h2, int w2)
~~~

- 半開区間 $[h1, h2) \times [w1, w2)$ に対して総積を取得する
