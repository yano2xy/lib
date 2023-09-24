---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dsu_potential.test.cpp
    title: verify/dsu_potential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/dsu_potential.md
    document_title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D UnionFind"
    links: []
  bundledCode: "#line 2 \"dsu_potential.hpp\"\n\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T = long long>\nstruct dsu_potential {\n   public:\n    int\
    \ _n;\n    std::vector<int> data;\n    std::vector<T> diff_potential;\n\n    dsu_potential()\
    \ : _n(0) {}\n    dsu_potential(int n) : _n(n), data(n, -1), diff_potential(n,\
    \ 0) {}\n\n    bool merge(int a, int b, T d) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        if (same(a, b)) return (d == diff(a,\
    \ b));\n        int x = leader(a), y = leader(b);\n        d += potential(a) -\
    \ potential(b);\n        if (-data[x] < -data[y]) std::swap(x, y), d = -d;\n \
    \       data[x] += data[y];\n        data[y] = x;\n        diff_potential[y] =\
    \ d;\n        return true;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (data[a] < 0) return a;\n        int r = leader(data[a]);\n\
    \        diff_potential[a] += diff_potential[data[a]];\n        return data[a]\
    \ = r;\n    }\n\n    T potential(int a) {\n        assert(0 <= a && a < _n);\n\
    \        leader(a);\n        return diff_potential[a];\n    }\n\n    T diff(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        assert(leader(a) == leader(b));\n        return potential(b) -\
    \ potential(a);\n    }\n\n    int size(int a) {\n        assert(0 <= a && a <\
    \ _n);\n        return -data[leader(a)];\n    }\n\n    auto groups() {\n     \
    \   std::vector<int> leaders(_n), group_size(_n);\n        for (int i = 0; i <\
    \ _n; i++) {\n            leaders[i] = leader(i);\n            group_size[leaders[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> ret(_n);\n        for (int i\
    \ = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n        }\n\
    \        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n    /*\n        @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    \ UnionFind\n        @docs docs/dsu_potential.md\n    */\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T = long long>\nstruct dsu_potential {\n   public:\n    int _n;\n    std::vector<int>\
    \ data;\n    std::vector<T> diff_potential;\n\n    dsu_potential() : _n(0) {}\n\
    \    dsu_potential(int n) : _n(n), data(n, -1), diff_potential(n, 0) {}\n\n  \
    \  bool merge(int a, int b, T d) {\n        assert(0 <= a && a < _n);\n      \
    \  assert(0 <= b && b < _n);\n        if (same(a, b)) return (d == diff(a, b));\n\
    \        int x = leader(a), y = leader(b);\n        d += potential(a) - potential(b);\n\
    \        if (-data[x] < -data[y]) std::swap(x, y), d = -d;\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        diff_potential[y] = d;\n        return\
    \ true;\n    }\n\n    bool same(int a, int b) {\n        assert(0 <= a && a <\
    \ _n);\n        assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n\
    \    }\n\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n       \
    \ if (data[a] < 0) return a;\n        int r = leader(data[a]);\n        diff_potential[a]\
    \ += diff_potential[data[a]];\n        return data[a] = r;\n    }\n\n    T potential(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        leader(a);\n        return\
    \ diff_potential[a];\n    }\n\n    T diff(int a, int b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        assert(leader(a) ==\
    \ leader(b));\n        return potential(b) - potential(a);\n    }\n\n    int size(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        return -data[leader(a)];\n\
    \    }\n\n    auto groups() {\n        std::vector<int> leaders(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leaders[i] = leader(i);\n\
    \            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ ret(_n);\n        for (int i = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n    /*\n        @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    \ UnionFind\n        @docs docs/dsu_potential.md\n    */\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu_potential.hpp
  requiredBy: []
  timestamp: '2023-09-24 14:48:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dsu_potential.test.cpp
documentation_of: dsu_potential.hpp
layout: document
redirect_from:
- /library/dsu_potential.hpp
- /library/dsu_potential.hpp.html
title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D UnionFind"
---
# dsu_potential (ポテンシャル付き UnionFind)

拡張点が、連結成分の代表元を起点とした時のポテンシャルを保持するようなUnionFind木。

## コンストラクタ

```cpp
dsu_potential<T> un(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。
- $T$ として、int, long long を想定する。

**計算量**

- $O(n)$

## merge

```cpp
bool un.merge(int a, int b, T d)
```

頂点 $a$ から頂点 $b$ に、長さ $d$ の辺を追加する。

$a, b$ がすでに同じ連結成分で、かつ、ポテンシャルに矛盾がある場合falseを返す。  
それ以外の場合、trueを返す。

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

## potential

```cpp
T potential(int a)
```

頂点 $a$ のポテンシャルを返す。

## diff

```cpp
T diff(int a, int b)
```

頂点 $a$ と頂点 $b$ とのポテンシャルの差（$b$ のポテンシャル $-$ $a$ のポテンシャル）を返す。

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
