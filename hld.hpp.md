---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/hld.md
    document_title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"hld.hpp\"\n\n#include <vector>\n\ntemplate <typename G>\
    \ struct HLD {\n   private:\n    void dfs_sz(int cur) {\n        size[cur] = 1;\n\
    \        for (auto& dst : g[cur]) {\n            if (dst == par[cur]) {\n    \
    \            if (g[cur].size() >= 2 && int(dst) == int(g[cur][0])) std::swap(g[cur][0],\
    \ g[cur][1]);\n                else continue;\n            }\n            depth[dst]\
    \ = depth[cur] + 1;\n            par[dst] = cur;\n            dfs_sz(dst);\n \
    \           size[cur] += size[dst];\n            if (size[dst] > size[g[cur][0]])\
    \ {\n                swap(dst, g[cur][0]);\n            }\n        }\n    }\n\n\
    \    void dfs_hld(int cur) {\n        down[cur] = id++;\n        for (auto dst\
    \ : g[cur]) {\n            if (dst == par[cur]) continue;\n            nxt[dst]\
    \ = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n            dfs_hld(dst);\n\
    \        }\n        up[cur] = id;\n    }\n\n    // [u, v)\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(down[u],\
    \ down[nxt[u]]);\n            u = par[nxt[u]];\n        }\n        if (u != v)\
    \ res.emplace_back(down[u], down[v] + 1);\n        return res;\n    }\n\n    //\
    \ (u, v]\n    std::vector<std::pair<int, int>> descend(int u, int v) const {\n\
    \        if (u == v) return {};\n        if (nxt[u] == nxt[v]) return {{down[u]\
    \ + 1, down[v]}};\n        auto res = descend(u, par[nxt[v]]);\n        res.emplace_back(down[nxt[v]],\
    \ down[v]);\n        return res;\n    }\n\n   public:\n    G& g;\n    int id;\n\
    \    std::vector<int> size, depth, down, up, nxt, par;\n    HLD(G& _g, int root\
    \ = 0) : g(_g), id(0), size(g.size(), 0), depth(g.size(), 0), down(g.size(), -1),\
    \ up(g.size(), -1), nxt(g.size(), root), par(g.size(), root) { build(root); }\n\
    \    void build(int root) { dfs_sz(root), dfs_hld(root); }\n\n    int vid(int\
    \ i) const { return down[i]; }\n    // std::pair<int, int> idx(int i) const {\
    \ return std::make_pair(down[i], up[i]); }\n\n    template <typename F> void path_query(int\
    \ u, int v, const F& f, bool isEdge = false) {\n        int l = lca(u, v);\n \
    \       for (auto&& [a, b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n\
    \            s > t ? f(t, s) : f(s, t);\n        }\n        if (!isEdge) f(down[l],\
    \ down[l] + 1);\n        for (auto&& [a, b] : descend(l, v)) {\n            int\
    \ s = a, t = b + 1;\n            s > t ? f(t, s) : f(s, t);\n        }\n    }\n\
    \n    template <typename F> void path_noncommutative_query(int u, int v, const\
    \ F& f, bool isEdge = false) {\n        int l = lca(u, v);\n        for (auto&&\
    \ [a, b] : ascend(u, l)) f(a + 1, b);\n        if (!isEdge) f(down[l], down[l]\
    \ + 1);\n        for (auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n \
    \   template <typename F> void subtree_query(int u, const F& f, bool isEdge =\
    \ false) { f(down[u] + int(isEdge), up[u]); }\n\n    int lca(int a, int b) {\n\
    \        while (nxt[a] != nxt[b]) {\n            if (down[a] < down[b]) std::swap(a,\
    \ b);\n            a = par[nxt[a]];\n        }\n        return depth[a] < depth[b]\
    \ ? a : b;\n    }\n\n    int dist(int a, int b) { return depth[a] + depth[b] -\
    \ depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\
    \u8EFD\u5206\u89E3)\n * @docs docs/hld.md\n */\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <typename G> struct HLD {\n\
    \   private:\n    void dfs_sz(int cur) {\n        size[cur] = 1;\n        for\
    \ (auto& dst : g[cur]) {\n            if (dst == par[cur]) {\n               \
    \ if (g[cur].size() >= 2 && int(dst) == int(g[cur][0])) std::swap(g[cur][0], g[cur][1]);\n\
    \                else continue;\n            }\n            depth[dst] = depth[cur]\
    \ + 1;\n            par[dst] = cur;\n            dfs_sz(dst);\n            size[cur]\
    \ += size[dst];\n            if (size[dst] > size[g[cur][0]]) {\n            \
    \    swap(dst, g[cur][0]);\n            }\n        }\n    }\n\n    void dfs_hld(int\
    \ cur) {\n        down[cur] = id++;\n        for (auto dst : g[cur]) {\n     \
    \       if (dst == par[cur]) continue;\n            nxt[dst] = (int(dst) == int(g[cur][0])\
    \ ? nxt[cur] : int(dst));\n            dfs_hld(dst);\n        }\n        up[cur]\
    \ = id;\n    }\n\n    // [u, v)\n    std::vector<std::pair<int, int>> ascend(int\
    \ u, int v) const {\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (nxt[u] != nxt[v]) {\n            res.emplace_back(down[u], down[nxt[u]]);\n\
    \            u = par[nxt[u]];\n        }\n        if (u != v) res.emplace_back(down[u],\
    \ down[v] + 1);\n        return res;\n    }\n\n    // (u, v]\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};\n        auto res =\
    \ descend(u, par[nxt[v]]);\n        res.emplace_back(down[nxt[v]], down[v]);\n\
    \        return res;\n    }\n\n   public:\n    G& g;\n    int id;\n    std::vector<int>\
    \ size, depth, down, up, nxt, par;\n    HLD(G& _g, int root = 0) : g(_g), id(0),\
    \ size(g.size(), 0), depth(g.size(), 0), down(g.size(), -1), up(g.size(), -1),\
    \ nxt(g.size(), root), par(g.size(), root) { build(root); }\n    void build(int\
    \ root) { dfs_sz(root), dfs_hld(root); }\n\n    int vid(int i) const { return\
    \ down[i]; }\n    // std::pair<int, int> idx(int i) const { return std::make_pair(down[i],\
    \ up[i]); }\n\n    template <typename F> void path_query(int u, int v, const F&\
    \ f, bool isEdge = false) {\n        int l = lca(u, v);\n        for (auto&& [a,\
    \ b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n            s > t ?\
    \ f(t, s) : f(s, t);\n        }\n        if (!isEdge) f(down[l], down[l] + 1);\n\
    \        for (auto&& [a, b] : descend(l, v)) {\n            int s = a, t = b +\
    \ 1;\n            s > t ? f(t, s) : f(s, t);\n        }\n    }\n\n    template\
    \ <typename F> void path_noncommutative_query(int u, int v, const F& f, bool isEdge\
    \ = false) {\n        int l = lca(u, v);\n        for (auto&& [a, b] : ascend(u,\
    \ l)) f(a + 1, b);\n        if (!isEdge) f(down[l], down[l] + 1);\n        for\
    \ (auto&& [a, b] : descend(l, v)) f(a, b + 1);\n    }\n\n    template <typename\
    \ F> void subtree_query(int u, const F& f, bool isEdge = false) { f(down[u] +\
    \ int(isEdge), up[u]); }\n\n    int lca(int a, int b) {\n        while (nxt[a]\
    \ != nxt[b]) {\n            if (down[a] < down[b]) std::swap(a, b);\n        \
    \    a = par[nxt[a]];\n        }\n        return depth[a] < depth[b] ? a : b;\n\
    \    }\n\n    int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a,\
    \ b)] * 2; }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\u8EFD\u5206\
    \u89E3)\n * @docs docs/hld.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: hld.hpp
  requiredBy: []
  timestamp: '2024-02-12 18:07:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hld.hpp
layout: document
redirect_from:
- /library/hld.hpp
- /library/hld.hpp.html
title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
---
# HLD (Heavy Light Decomposition - 重軽分解)

- HL分解を行う。
- `Graph<T>` に依存する
- 頂点属性および辺属性のパスクエリに対応できる
- 頂点属性および辺属性の部分木クエリに対応できる

## 辺属性のクエリに対応する場合の注意

- 辺属性のクエリに対応する際は、各辺の情報は頂点に持たせる
- 正確には、辺 $(u, v)$ の情報は、頂点 $u$ と $v$ のうち、`root`を根としてdfs順に深い方、つまり $id$ (`hld.vid(int i)`で取得可能) が大きい方の頂点で管理する
- このとき、辺属性クエリの実行時には、上記の意味で対応する各頂点の区間に対して、$F$ が実行される

***例: 5頂点の木***
~~~
5
0 1
1 2
2 3
1 4
~~~
- 上記の木は、HL分解によって2つの区間 $[0, 1, 2, 3, 4)$, $[4, 5)$ に分解される
- パス $(3, 4)$ （つまりパス `3-2-1-4`）については、各パスの情報は頂点 $2, 3, 4$ が持っているとみなして、処理区間を決定する
- つまり、`path_query(3, 4, f, true)` は区間 $[2, 4), [4, 5)$ を処理するということ
  - 頂点属性クエリ `path_query(3, 4, f, false)` では 区間 $[1, 4), [4, 5)$ が処理される



## コンストラクタ

```cpp
HLD hld(Graph<T> G, root=0)
```

- Tree $G$ を、根が $root$ の根つき木とみなしてHL分解する

**計算量**

- $O(n)$

## vid

```cpp
int hld.vid(int u)
```

頂点 $u$ の idを返す。

**計算量**

- $O(1)$

## path_query

```cpp
void hld.path_query(int u, int v, const F& f, bool isEdge=false)
```

- 頂点 $u$ から 頂点 $v$ へのパスを、$O(log(N))$ 個の区間に分解し、各区間に対して $F$を適用する
- $F$ は半開区間 $[l, r)$ に対する処理を実行する関数 `f(int l, int r) -> void` である
- 辺属性のクエリを処理する場合は、`isEdge=true` を指定する 

**計算量** 

- $O(log(n))$

## path_noncommutative_query

```cpp
void hld.path_nocommutative_query(int u, int v, const F& f, bool isEdge=false)
```

- 非可換なパスクエリに対応する

**計算量**

- $O(log(n))$

## subtree_query

```cpp
void hld.subtree_query(int u, const F& f, bool isEdge=false)
```

- 頂点 $u$ の部分木に対するクエリに対応する

**計算量**

- $O(log(n))$

## lca

```cpp
int hld.lca(int u, int v)
```

頂点 $u$ と $v$ の LCA であるような頂点を返す

**計算量**

- $O(log(n))$

## dist

```cpp
int hld.dist(int u, int v)
```

頂点 $u$ と 頂点 $v$ のパスの1骨格の距離（各辺の長さを1とみなしたときの距離）を返す

**計算量**

- $O(log(n))$