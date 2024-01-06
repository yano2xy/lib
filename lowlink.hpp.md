---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: bcc_graph.hpp
    title: bcc_graph (Bi-Connected Components)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lowlink_articulation.test.cpp
    title: verify/lowlink_articulation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/lowlink_bridge.test.cpp
    title: verify/lowlink_bridge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/lowlink.md
    document_title: Lowlink
    links: []
  bundledCode: "#line 2 \"lowlink.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \nstruct lowlink {\n   protected:\n    int n;\n    std::vector<int> used, ord,\
    \ low;\n    std::vector<std::vector<int>> G;\n    int dfs(int pos, int k, int\
    \ par = -1) {\n        used[pos] = 1;\n        ord[pos] = k++;\n        low[pos]\
    \ = ord[pos];\n        bool is_articulation = false;\n        int cnt = 0;\n \
    \       for (auto &to : G[pos]) {\n            if (!used[to]) {\n            \
    \    ++cnt;\n                k = dfs(to, k, pos);\n                low[pos] =\
    \ std::min(low[pos], low[to]);\n                is_articulation |= ~par && low[to]\
    \ >= ord[pos];\n                if (ord[pos] < low[to]) bridge.emplace_back(std::minmax(pos,\
    \ (int)to));\n            } else if (to != par) {\n                low[pos] =\
    \ std::min(low[pos], ord[to]);\n            }\n        }\n        is_articulation\
    \ |= par == -1 && cnt > 1;\n        if (is_articulation) articulation.push_back(pos);\n\
    \        return k;\n    }\n\n   public:\n    std::vector<int> articulation;\n\
    \    std::vector<std::pair<int, int>> bridge;\n    lowlink(int n) : n(n) { G.assign(n,\
    \ std::vector<int>()); }\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n    int size() const { return n; }\n    void\
    \ build() {\n        used.assign(n, 0);\n        ord.assign(n, 0);\n        low.assign(n,\
    \ 0);\n        int k = 0;\n        for (int i = 0; i < n; i++)\n            if\
    \ (!used[i]) k = dfs(i, k);\n    }\n};\n/*\n * @brief Lowlink\n * @docs docs/lowlink.md\n\
    \ */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\nstruct lowlink\
    \ {\n   protected:\n    int n;\n    std::vector<int> used, ord, low;\n    std::vector<std::vector<int>>\
    \ G;\n    int dfs(int pos, int k, int par = -1) {\n        used[pos] = 1;\n  \
    \      ord[pos] = k++;\n        low[pos] = ord[pos];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        for (auto &to : G[pos]) {\n        \
    \    if (!used[to]) {\n                ++cnt;\n                k = dfs(to, k,\
    \ pos);\n                low[pos] = std::min(low[pos], low[to]);\n           \
    \     is_articulation |= ~par && low[to] >= ord[pos];\n                if (ord[pos]\
    \ < low[to]) bridge.emplace_back(std::minmax(pos, (int)to));\n            } else\
    \ if (to != par) {\n                low[pos] = std::min(low[pos], ord[to]);\n\
    \            }\n        }\n        is_articulation |= par == -1 && cnt > 1;\n\
    \        if (is_articulation) articulation.push_back(pos);\n        return k;\n\
    \    }\n\n   public:\n    std::vector<int> articulation;\n    std::vector<std::pair<int,\
    \ int>> bridge;\n    lowlink(int n) : n(n) { G.assign(n, std::vector<int>());\
    \ }\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n\
    \    }\n    int size() const { return n; }\n    void build() {\n        used.assign(n,\
    \ 0);\n        ord.assign(n, 0);\n        low.assign(n, 0);\n        int k = 0;\n\
    \        for (int i = 0; i < n; i++)\n            if (!used[i]) k = dfs(i, k);\n\
    \    }\n};\n/*\n * @brief Lowlink\n * @docs docs/lowlink.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: lowlink.hpp
  requiredBy:
  - bcc_graph.hpp
  timestamp: '2024-01-06 18:15:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lowlink_articulation.test.cpp
  - verify/lowlink_bridge.test.cpp
documentation_of: lowlink.hpp
layout: document
redirect_from:
- /library/lowlink.hpp
- /library/lowlink.hpp.html
title: Lowlink
---
# LowLink

無向グラフにおける間接点および橋を $O(V+E)$で求めるアルゴリズム（データ構造） 

## コンストラクタ

```cpp
lowlink lk(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## add_edge

```cpp
void lk.add_edge(int u, int v)
```

頂点 $u$, $v$ の間に双方向の辺をはる   

**計算量**

- $O(1)$

## size

```cpp
int lk.size()
```

lowlinkのグラフの頂点数 $n$ を返す  

**計算量** 

- $O(1)$

## build

```cpp
void kl.build()
```

lowlinkにより、間接点および橋を検出して列挙する  

build後、klの以下のメンバに間接点および橋が格納される  

***間接点(articulation point)***  
~~~cpp
std::vector<int> kl.articulation
~~~

***橋(bridge)***  
~~~cpp
std::vector<std::pair<int,int>> kl.bridge
~~~

辺 $(u, v)$ は、常に $u \leq v$であることが保証される

**計算量**

- $O(E+V)$