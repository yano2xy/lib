---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/rerooting.test.cpp
    title: verify/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/rerooting.md
    document_title: rerooting
    links: []
  bundledCode: "#line 2 \"rerooting.hpp\"\n\n#include <functional>\n#include <vector>\n\
    \ntemplate <typename S>\nstruct rerooting {\n   private:\n    int n;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<std::vector<S>> dp;\n    using TF = std::function<S(S, int,\
    \ int)>;\n    using TM = std::function<S(S, S)>;\n    using TG = std::function<S(S,\
    \ int)>;\n    using Id = std::function<S()>;\n    TF f;\n    TM merge;\n    TG\
    \ g;\n    Id id;\n\n    S dfs1(int pos, int par) {\n        S val = id();\n  \
    \      for (int i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] ==\
    \ par) continue;\n            dp[pos][i] = dfs1(G[pos][i], pos);\n           \
    \ val = merge(val, f(dp[pos][i], G[pos][i], pos));\n        }\n        return\
    \ g(val, pos);\n    }\n\n    void dfs2(int pos, int par, S dp_par) {\n       \
    \ for (int i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] == par)\
    \ {\n                dp[pos][i] = dp_par;\n                break;\n          \
    \  }\n        }\n        std::vector<S> pR(G[pos].size() + 1, id());\n       \
    \ for (int i = G[pos].size(); i > 0; --i)\n            pR[i - 1] = merge(pR[i],\
    \ f(dp[pos][i - 1], G[pos][i - 1], pos));\n        S pL = id();\n        for (int\
    \ i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] != par) {\n    \
    \            S val = merge(pL, pR[i + 1]);\n                dfs2(G[pos][i], pos,\
    \ g(val, pos));\n            }\n            pL = merge(pL, f(dp[pos][i], G[pos][i],\
    \ pos));\n        }\n    }\n\n   public:\n    rerooting(int n, TF f, TM merge,\
    \ TG g, Id id) : n(n), f(f), merge(merge), g(g), id(id) {\n        G.resize(n);\n\
    \        dp.resize(n);\n    }\n\n    void add_edge(int a, int b) {\n        G[a].emplace_back(b);\n\
    \        G[b].emplace_back(a);\n    }\n\n    std::vector<S> solve() {\n      \
    \  std::vector<S> ret(n);\n        for (int i = 0; i < n; ++i)\n            dp[i].resize(G[i].size());\n\
    \        dfs1(0, -1);\n        dfs2(0, -1, id());\n        for (int i = 0; i <\
    \ n; ++i) {\n            S v = id();\n            for (int j = 0; j < G[i].size();\
    \ ++j) {\n                v = merge(v, f(dp[i][j], G[i][j], i));\n           \
    \ }\n            ret[i] = g(v, i);\n        }\n        return ret;\n    }\n};\n\
    /*\n * @brief rerooting\n * @docs docs/rerooting.md\n */\n"
  code: "#pragma once\n\n#include <functional>\n#include <vector>\n\ntemplate <typename\
    \ S>\nstruct rerooting {\n   private:\n    int n;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<std::vector<S>> dp;\n    using TF = std::function<S(S, int,\
    \ int)>;\n    using TM = std::function<S(S, S)>;\n    using TG = std::function<S(S,\
    \ int)>;\n    using Id = std::function<S()>;\n    TF f;\n    TM merge;\n    TG\
    \ g;\n    Id id;\n\n    S dfs1(int pos, int par) {\n        S val = id();\n  \
    \      for (int i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] ==\
    \ par) continue;\n            dp[pos][i] = dfs1(G[pos][i], pos);\n           \
    \ val = merge(val, f(dp[pos][i], G[pos][i], pos));\n        }\n        return\
    \ g(val, pos);\n    }\n\n    void dfs2(int pos, int par, S dp_par) {\n       \
    \ for (int i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] == par)\
    \ {\n                dp[pos][i] = dp_par;\n                break;\n          \
    \  }\n        }\n        std::vector<S> pR(G[pos].size() + 1, id());\n       \
    \ for (int i = G[pos].size(); i > 0; --i)\n            pR[i - 1] = merge(pR[i],\
    \ f(dp[pos][i - 1], G[pos][i - 1], pos));\n        S pL = id();\n        for (int\
    \ i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i] != par) {\n    \
    \            S val = merge(pL, pR[i + 1]);\n                dfs2(G[pos][i], pos,\
    \ g(val, pos));\n            }\n            pL = merge(pL, f(dp[pos][i], G[pos][i],\
    \ pos));\n        }\n    }\n\n   public:\n    rerooting(int n, TF f, TM merge,\
    \ TG g, Id id) : n(n), f(f), merge(merge), g(g), id(id) {\n        G.resize(n);\n\
    \        dp.resize(n);\n    }\n\n    void add_edge(int a, int b) {\n        G[a].emplace_back(b);\n\
    \        G[b].emplace_back(a);\n    }\n\n    std::vector<S> solve() {\n      \
    \  std::vector<S> ret(n);\n        for (int i = 0; i < n; ++i)\n            dp[i].resize(G[i].size());\n\
    \        dfs1(0, -1);\n        dfs2(0, -1, id());\n        for (int i = 0; i <\
    \ n; ++i) {\n            S v = id();\n            for (int j = 0; j < G[i].size();\
    \ ++j) {\n                v = merge(v, f(dp[i][j], G[i][j], i));\n           \
    \ }\n            ret[i] = g(v, i);\n        }\n        return ret;\n    }\n};\n\
    /*\n * @brief rerooting\n * @docs docs/rerooting.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: rerooting.hpp
  requiredBy: []
  timestamp: '2023-10-12 22:54:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/rerooting.test.cpp
documentation_of: rerooting.hpp
layout: document
redirect_from:
- /library/rerooting.hpp
- /library/rerooting.hpp.html
title: rerooting
---
# rerooting

## コンストラクタ

```cpp
rerooting<S> G(int n, TG f, TM merge, TG g, S id)
```

$n$ 頂点の全方位木DPクラスを作成する。  

- $S$ : 各DP値の型  

頂点 $v$ および、その子頂点 $c_1, \dots, c_m$ について、$dp[v]$ の遷移が以下の式で与えられるとき、コンストラクは関数 $f, merge, g$および単位元 $id$ をオラクルとして受け取る。    

$dp[v] = g(merge({f(dp[c_1], c_1, v), \dots, f(dp[c_m], c_m, v)}), v)$ 

```cpp
// 各子ノードに対して、マージ前の前処理を行う
S f(S x, int pos, int par)

// マージ処理
S merge(S x, S y)

// マージ後の値をdp値として確定させるための仕上げ処理
S g(S x, int pos)
```

## add_edge

```cpp
void G(int a, int b)
```
双方向の辺 $(a, b)$ を追加する。  

このクラスでは辺のコストは管理しないため、必要な場合はクラスの外で管理する。  

## solve

```cpp
vector<S> solve()
```
各頂点 $0, 1, ..., n-1$ について、この順でdp値の配列を取得する。  

**計算量**

- $O(n)$
