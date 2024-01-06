---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/bcc_graph.md
    document_title: bcc_graph (Bi-Connected Components)
    links: []
  bundledCode: "#line 2 \"bcc_graph.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    \n#line 2 \"lowlink.hpp\"\n\n#line 5 \"lowlink.hpp\"\n\nstruct lowlink {\n   protected:\n\
    \    int n;\n    std::vector<int> used, ord, low;\n    std::vector<std::vector<int>>\
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
    \    }\n};\n/*\n * @brief Lowlink\n * @docs docs/lowlink.md\n */\n#line 7 \"bcc_graph.hpp\"\
    \n\nstruct bcc_graph : lowlink {\n    using lk = lowlink;\n\n   private:\n   \
    \ std::vector<int> used;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\
    \    std::vector<std::pair<int, int>> tmp;\n    void dfs(int pos, int par = -1)\
    \ {\n        used[pos] = 1;\n        for (auto &to : G[pos]) {\n            if\
    \ (to == par) continue;\n            if (!used[to] || ord[to] < ord[pos]) {\n\
    \                tmp.emplace_back(std::minmax(pos, to));\n            }\n    \
    \        if (!used[to]) {\n                dfs(to, pos);\n                if (low[to]\
    \ >= ord[pos]) {\n                    bc.emplace_back();\n                   \
    \ while (1) {\n                        auto [u, v] = tmp.back();\n           \
    \             bc.back().emplace_back(u, v);\n                        tmp.pop_back();\n\
    \                        if (u == std::min(pos, to) && v == std::max(pos, to))\
    \ {\n                            break;\n                        }\n         \
    \           }\n                }\n            }\n        }\n    }\n\n   public:\n\
    \    bcc_graph(int n) : lk(n) {}\n    std::vector<std::vector<std::pair<int, int>>>\
    \ bcc() {\n        lk::build();\n        used.assign(n, 0);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (!used[i]) dfs(i);\n        }\n       \
    \ return bc;\n    }\n};\n/*\n * @brief bcc_graph (Bi-Connected Components)\n *\
    \ @docs docs/bcc_graph.md\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\n#include \"lowlink.hpp\"\
    \n\nstruct bcc_graph : lowlink {\n    using lk = lowlink;\n\n   private:\n   \
    \ std::vector<int> used;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\
    \    std::vector<std::pair<int, int>> tmp;\n    void dfs(int pos, int par = -1)\
    \ {\n        used[pos] = 1;\n        for (auto &to : G[pos]) {\n            if\
    \ (to == par) continue;\n            if (!used[to] || ord[to] < ord[pos]) {\n\
    \                tmp.emplace_back(std::minmax(pos, to));\n            }\n    \
    \        if (!used[to]) {\n                dfs(to, pos);\n                if (low[to]\
    \ >= ord[pos]) {\n                    bc.emplace_back();\n                   \
    \ while (1) {\n                        auto [u, v] = tmp.back();\n           \
    \             bc.back().emplace_back(u, v);\n                        tmp.pop_back();\n\
    \                        if (u == std::min(pos, to) && v == std::max(pos, to))\
    \ {\n                            break;\n                        }\n         \
    \           }\n                }\n            }\n        }\n    }\n\n   public:\n\
    \    bcc_graph(int n) : lk(n) {}\n    std::vector<std::vector<std::pair<int, int>>>\
    \ bcc() {\n        lk::build();\n        used.assign(n, 0);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (!used[i]) dfs(i);\n        }\n       \
    \ return bc;\n    }\n};\n/*\n * @brief bcc_graph (Bi-Connected Components)\n *\
    \ @docs docs/bcc_graph.md\n */"
  dependsOn:
  - lowlink.hpp
  isVerificationFile: false
  path: bcc_graph.hpp
  requiredBy: []
  timestamp: '2024-01-06 18:15:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bcc_graph.hpp
layout: document
redirect_from:
- /library/bcc_graph.hpp
- /library/bcc_graph.hpp.html
title: bcc_graph (Bi-Connected Components)
---
# bcc_graph (Bi-Conneced Components : 二重頂点連結成分分解)

二重頂点連結成分分解を行う  

## コンストラクタ

```cpp
bcc_graph G(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## add_edge

```cpp
void G.add_edge(int u, int v)
```

頂点 $u$, $v$ の間に双方向の辺をはる   

**計算量**

- $O(1)$

## size

```cpp
int G.size()
```

lowlinkのグラフの頂点数 $n$ を返す  

**計算量** 

- $O(1)$

## bcc

```cpp
std::vector<std::vector<std::pair<int,int>>> G.bcc()
```

グラフの BCC (Bi-Connected Components : 二重頂点連結成分分解) を返す  

BCC は、各連結成分のvectorである。  
各連結成分は、そこに含まれる辺のvectorである。  


