---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dsu.test.cpp
    title: verify/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dsu.md
    document_title: dsu (UnionFind)
    links: []
  bundledCode: "#line 2 \"dsu.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nstruct dsu {\n    int _n;\n    std::vector<int> data;\n\n\
    \    dsu() : _n(0) {}\n    dsu(int n) : _n(n), data(n, -1) {}\n\n    bool merge(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return x;\n    }\n\n    int same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (data[a] < 0) return a;\n \
    \       return data[a] = leader(data[a]);\n    }\n\n    int size(int a) {\n  \
    \      assert(0 <= a && a < _n);\n        return -data[leader(a)];\n    }\n\n\
    \    auto gropus() {\n        std::vector<int> leaders(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leaders[i] = leader(i);\n\
    \            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ ret(_n);\n        for (int i = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n};\n/*\n * @brief dsu (UnionFind)\n * @docs docs/dsu.md\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \nstruct dsu {\n    int _n;\n    std::vector<int> data;\n\n    dsu() : _n(0) {}\n\
    \    dsu(int n) : _n(n), data(n, -1) {}\n\n    bool merge(int a, int b) {\n  \
    \      assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        int\
    \ x = leader(a), y = leader(b);\n        if (x == y) return false;\n        if\
    \ (-data[x] < -data[y]) std::swap(x, y);\n        data[x] += data[y];\n      \
    \  data[y] = x;\n        return x;\n    }\n\n    int same(int a, int b) {\n  \
    \      assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return\
    \ leader(a) == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0\
    \ <= a && a < _n);\n        if (data[a] < 0) return a;\n        return data[a]\
    \ = leader(data[a]);\n    }\n\n    int size(int a) {\n        assert(0 <= a &&\
    \ a < _n);\n        return -data[leader(a)];\n    }\n\n    auto gropus() {\n \
    \       std::vector<int> leaders(_n), group_size(_n);\n        for (int i = 0;\
    \ i < _n; i++) {\n            leaders[i] = leader(i);\n            group_size[leaders[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> ret(_n);\n        for (int i\
    \ = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n\
    \        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n};\n/*\n * @brief dsu (UnionFind)\n * @docs docs/dsu.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: dsu.hpp
  requiredBy: []
  timestamp: '2023-09-24 12:47:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dsu.test.cpp
documentation_of: dsu.hpp
layout: document
redirect_from:
- /library/dsu.hpp
- /library/dsu.hpp.html
title: dsu (UnionFind)
---
# dsu (UnionFind)

## コンストラクタ

```cpp
dsu un(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## merge

```cpp
int un.merge(int a, int b)
```

辺 $(a, b)$ を追加して、新しい代表元を返す。

**計算量**

- ならし $O(\alpha(n))$

## same

```cpp
bool un.same(int a, int b)
```

頂点 $a, b$ が連結かどうかを判定する。

**計算量**

- ならし $O(\alpha(n))$

## leader

```cpp
int un.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返す。

**計算量**

- ならし $O(\alpha(n))$

## size

```cpp
int un.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返す。

**計算量**

- ならし $O(\alpha(n))$

## groups

```cpp
vector<vector<int>> un.groups()
```

各連結成分を返す。

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」。
(内側外側限らず)vector内でどの順番で頂点が格納されているかは未定義。

**計算量**

- $O(n)$
