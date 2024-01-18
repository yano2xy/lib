---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/mergesort_tree.md
    document_title: mergesort_tree
    links: []
  bundledCode: "#line 2 \"mergesort_tree.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T> struct mergesort_tree {\n   private:\n    int n;\n   \
    \ std::vector<std::vector<T> > t;\n    int _count(int ql, int qr, T x, int k =\
    \ 0, int l = 0, int r = -1) const {\n        if (r < 0) r = n;\n        if (qr\
    \ <= l || r <= ql) return 0;\n        else if (ql <= l && r <= qr) return lower_bound(t[k].begin(),\
    \ t[k].end(), x) - t[k].begin();\n        else return _count(ql, qr, x, k * 2\
    \ + 1, l, (l + r) / 2) + _count(ql, qr, x, k * 2 + 2, (l + r) / 2, r);\n    }\n\
    \n   public:\n    mergesort_tree(const std::vector<T>& a) {\n        n = 1;\n\
    \        while (n < a.size()) n <<= 1;\n        t.assign(2 * n - 1, {});\n   \
    \     for (int i = 0; i < a.size(); i++) t[i + n - 1].push_back(a[i]);\n     \
    \   for (int i = n - 2; i >= 0; i--) {\n            t[i].resize(t[i * 2 + 1].size()\
    \ + t[i * 2 + 2].size());\n            std::merge(t[i * 2 + 1].begin(), t[i *\
    \ 2 + 1].end(), t[i * 2 + 2].begin(), t[i * 2 + 2].end(), t[i].begin());\n   \
    \     }\n    }\n    int count(int ql, int qr, T x) const { return _count(ql, qr,\
    \ x); }\n    int count(int ql, int qr, T lx, T rx) const { return _count(ql, qr,\
    \ rx) - _count(ql, qr, lx); }\n};\n/*\n * @brief mergesort_tree\n * @docs docs/mergesort_tree.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T> struct mergesort_tree {\n   private:\n    int n;\n    std::vector<std::vector<T>\
    \ > t;\n    int _count(int ql, int qr, T x, int k = 0, int l = 0, int r = -1)\
    \ const {\n        if (r < 0) r = n;\n        if (qr <= l || r <= ql) return 0;\n\
    \        else if (ql <= l && r <= qr) return lower_bound(t[k].begin(), t[k].end(),\
    \ x) - t[k].begin();\n        else return _count(ql, qr, x, k * 2 + 1, l, (l +\
    \ r) / 2) + _count(ql, qr, x, k * 2 + 2, (l + r) / 2, r);\n    }\n\n   public:\n\
    \    mergesort_tree(const std::vector<T>& a) {\n        n = 1;\n        while\
    \ (n < a.size()) n <<= 1;\n        t.assign(2 * n - 1, {});\n        for (int\
    \ i = 0; i < a.size(); i++) t[i + n - 1].push_back(a[i]);\n        for (int i\
    \ = n - 2; i >= 0; i--) {\n            t[i].resize(t[i * 2 + 1].size() + t[i *\
    \ 2 + 2].size());\n            std::merge(t[i * 2 + 1].begin(), t[i * 2 + 1].end(),\
    \ t[i * 2 + 2].begin(), t[i * 2 + 2].end(), t[i].begin());\n        }\n    }\n\
    \    int count(int ql, int qr, T x) const { return _count(ql, qr, x); }\n    int\
    \ count(int ql, int qr, T lx, T rx) const { return _count(ql, qr, rx) - _count(ql,\
    \ qr, lx); }\n};\n/*\n * @brief mergesort_tree\n * @docs docs/mergesort_tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: mergesort_tree.hpp
  requiredBy: []
  timestamp: '2024-01-18 22:36:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mergesort_tree.hpp
layout: document
redirect_from:
- /library/mergesort_tree.hpp
- /library/mergesort_tree.hpp.html
title: mergesort_tree
---
# mergesort_tree

数列 $A=(A_1, A_2, \dots, A_n)$ に対し、以下のクエリ $(L, R, X)$ に $O(\log ^2(n))$ で回答する。  
- $A_i \leq X$ をみたすような $i \in [L, R)$ の個数


## コンストラクタ

```cpp
mergesort_tree seg(const vector<T>& a)
```

- 数列 $a$ に対して、mergesort_tree を初期化する   

**計算量**

- $O(n\log(n))$

## count

```cpp
int count(int lq, int rq, T x)
```

$A_i < x$ を満たすような $i \in [iq, ir)$ の個数を求める

**計算量**

- $O(\log ^2(n))$

## count

```cpp
int count(int lq, int rq, T lx, T rx)
```

$A_i \in [lx, rx)$ を満たすような $i \in [iq, ir)$ の個数を求める

**計算量**

- $O(\log ^2(n))$