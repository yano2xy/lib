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
    document_title: dsu (disjoint set union)
    links: []
  bundledCode: "#line 2 \"dsu.hpp\"\n\nstruct dsu {\n    vector<int> data;\n\n   \
    \ dsu() = default;\n\n    explicit dsu(size_t sz) : data(sz, -1) {}\n\n    bool\
    \ merge(int x, int y) {\n        x = find(x), y = find(y);\n        if (x == y)\
    \ return false;\n        if (data[x] > data[y]) swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ k) {\n        if (data[k] < 0) return k;\n        return data[k] = find(data[k]);\n\
    \    }\n\n    int size(int k) { return -data[find(k)]; }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n\n    vector<vector<int> > groups()\
    \ {\n        int n = (int)data.size();\n        vector<vector<int> > ret(n);\n\
    \        for (int i = 0; i < n; i++) {\n            ret[find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<int>\
    \ &v) { return v.empty(); }), end(ret));\n        return ret;\n    }\n};\n/*\n\
    \ * @brief dsu (disjoint set union)\n * @docs docs/dsu.md\n */\n"
  code: "#pragma once\n\nstruct dsu {\n    vector<int> data;\n\n    dsu() = default;\n\
    \n    explicit dsu(size_t sz) : data(sz, -1) {}\n\n    bool merge(int x, int y)\
    \ {\n        x = find(x), y = find(y);\n        if (x == y) return false;\n  \
    \      if (data[x] > data[y]) swap(x, y);\n        data[x] += data[y];\n     \
    \   data[y] = x;\n        return true;\n    }\n\n    int find(int k) {\n     \
    \   if (data[k] < 0) return k;\n        return data[k] = find(data[k]);\n    }\n\
    \n    int size(int k) { return -data[find(k)]; }\n\n    bool same(int x, int y)\
    \ { return find(x) == find(y); }\n\n    vector<vector<int> > groups() {\n    \
    \    int n = (int)data.size();\n        vector<vector<int> > ret(n);\n       \
    \ for (int i = 0; i < n; i++) {\n            ret[find(i)].emplace_back(i);\n \
    \       }\n        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<int>\
    \ &v) { return v.empty(); }), end(ret));\n        return ret;\n    }\n};\n/*\n\
    \ * @brief dsu (disjoint set union)\n * @docs docs/dsu.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: dsu.hpp
  requiredBy: []
  timestamp: '2023-09-24 11:38:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dsu.test.cpp
documentation_of: dsu.hpp
layout: document
redirect_from:
- /library/dsu.hpp
- /library/dsu.hpp.html
title: dsu (disjoint set union)
---
# DSU

無向グラフに対して、

- 辺の追加
- $2$ 頂点が連結かの判定

をならし $O(\alpha(n))$ 時間で処理することが出来ます。

また、内部的に各連結成分ごとに代表となる頂点を $1$ つ持っています。辺の追加により連結成分がマージされる時、新たな代表元は元の連結成分の代表元のうちどちらかになります。

## コンストラクタ

```cpp
dsu d(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作ります。

**制約**

- $0 \leq n \leq 10^8$

**計算量**

- $O(n)$

## merge

```cpp
int d.merge(int a, int b)
```

辺 $(a, b)$ を足します。

$a, b$ が連結だった場合はその代表元、非連結だった場合は新たな代表元を返します。

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- ならし $O(\alpha(n))$

## same

```cpp
bool d.same(int a, int b)
```

頂点 $a, b$ が連結かどうかを返します。

**制約**

- $0 \leq a < n$
- $0 \leq b < n$

**計算量**

- ならし $O(\alpha(n))$

## leader

```cpp
int d.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返します。

**制約**

- $0 \leq a < n$

**計算量**

- ならし $O(\alpha(n))$

## size

```cpp
int d.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返します。

**制約**

- $0 \leq a < n$

**計算量**

- ならし $O(\alpha(n))$

## groups

```cpp
vector<vector<int>> d.groups()
```

グラフを連結成分に分け、その情報を返します。

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」です。
(内側外側限らず)vector内でどの順番で頂点が格納されているかは未定義です。

**計算量**

- $O(n)$
