---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph.hpp
    title: graph.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: auxiliary_tree.hpp
    title: auxiliary_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lca_tree.test.cpp
    title: verify/lca_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lca_tree.hpp\"\n#include <cassert>\n#include <vector>\n\n\
    #line 2 \"graph.hpp\"\n\n#line 5 \"graph.hpp\"\n\ntemplate <typename T = long\
    \ long> struct Edge {\n    int id;\n    int from;\n    int to;\n    T cost;\n\
    \    bool operator<(const Edge& other) const { return cost < other.cost; }\n \
    \   bool operator>(const Edge& other) const { return cost > other.cost; }\n  \
    \  Edge& operator=(const T& x) {\n        to = x;\n        return *this;\n   \
    \ }\n    operator int() const { return to; }\n};\n\ntemplate <typename T = long\
    \ long> struct Graph {\n    int _n;\n    std::vector<std::vector<Edge<T>>> _graph;\n\
    \    const T INF = std::numeric_limits<T>::max() / 2;\n    std::vector<Edge<T>>\
    \ _edges;\n    Graph(int n) : _n(n) { _graph.resize(_n); }\n    std::vector<Edge<T>>&\
    \ operator[](int i) { return _graph[i]; }\n    int size() { return _n; }\n   \
    \ void add_edge(int u, int v, T cost) {\n        assert(0 <= u && u < _n);\n \
    \       assert(0 <= v && v < _n);\n        int id = (int)_edges.size();\n    \
    \    _graph[u].push_back({id, u, v, cost});\n        _graph[v].push_back({id,\
    \ v, u, cost});\n        _edges.push_back({id, u, v, cost});\n    }\n    void\
    \ add_edge_directed(int from, int to, T cost) {\n        assert(0 <= from && from\
    \ < _n);\n        assert(0 <= to && to < _n);\n        int id = (int)_edges.size();\n\
    \        _graph[from].push_back({(int)_edges.size(), from, to, cost});\n     \
    \   _edges.push_back({id, from, to, cost});\n    }\n    void add_edge(int u, int\
    \ v) { add_edge(u, v, 1); }\n    void add_edge_directed(int from, int to) { add_edge_directed(from,\
    \ to, 1); }\n    Edge<T> getEdge(int i) {\n        assert(0 <= i && i < (int)_edges.size());\n\
    \        return _edges[i];\n    }\n};\n#line 5 \"lca_tree.hpp\"\ntemplate <typename\
    \ T = long long> struct lca_tree : Graph<T> {\n   private:\n    int n, K;\n  \
    \  std::vector<std::vector<int>> parent;  // parent[v][k] := v \u306E 2^k \u5148\
    \u306E\u89AA\n    std::vector<int> depth;                // root \u304B\u3089\u306E\
    \u8DDD\u96E2\n    std::vector<T> cost;                   // root \u304B\u3089\u306E\
    \u30B3\u30B9\u30C8\n\n    void dfs(int pos, int par, int d, T c) {\n        if\
    \ (par != -1) parent[pos][0] = par;\n        depth[pos] = d;\n        cost[pos]\
    \ = c;\n        for (auto edge : this->_graph[pos]) {\n            if (edge.to\
    \ == par) continue;\n            dfs(edge.to, pos, d + 1, c + edge.cost);\n  \
    \      }\n    }\n\n   public:\n    lca_tree(int n) : n(n), Graph<T>(n) {}\n  \
    \  void build(int root = 0) {\n        K = 0;\n        while ((1 << K) < n) K++;\n\
    \        parent.assign(n + 1, std::vector<int>(K, n));\n        depth.assign(n,\
    \ -1);\n        cost.assign(n, -1);\n        dfs(root, -1, 0, 0);\n        for\
    \ (int i = 0; i < K - 1; ++i) {\n            for (int v = 0; v < n; ++v) {\n \
    \               parent[v][i + 1] = parent[parent[v][i]][i];\n            }\n \
    \       }\n    }\n    int lca(int a, int b) {\n        if (depth[a] > depth[b])\
    \ std::swap(a, b);\n        int diff = depth[b] - depth[a];\n        for (int\
    \ i = K - 1; i >= 0; i--) {\n            int len = 1 << i;\n            if (diff\
    \ >= len) {\n                diff -= len;\n                b = parent[b][i];\n\
    \            }\n        }\n        if (a == b) return a;\n        for (int i =\
    \ K - 1; i >= 0; i--) {\n            int na = parent[a][i];\n            int nb\
    \ = parent[b][i];\n            if (na != nb) a = na, b = nb;\n        }\n    \
    \    return parent[a][0];\n    }\n\n    // \u30CE\u30FC\u30C9\u9593\u306E\u8DDD\
    \u96E2\uFF081\u9AA8\u683C)\n    int length(int a, int b) { return depth[a] + depth[b]\
    \ - 2 * depth[lca(a, b)]; }\n\n    // \u30CE\u30FC\u30C9\u9593\u306E\u8DDD\u96E2\
    \uFF08\u30B3\u30B9\u30C8\uFF09\n    T dist(int a, int b) { return cost[a] + cost[b]\
    \ - 2 * cost[lca(a, b)]; }\n};\n"
  code: "#include <cassert>\n#include <vector>\n\n#include \"graph.hpp\"\ntemplate\
    \ <typename T = long long> struct lca_tree : Graph<T> {\n   private:\n    int\
    \ n, K;\n    std::vector<std::vector<int>> parent;  // parent[v][k] := v \u306E\
    \ 2^k \u5148\u306E\u89AA\n    std::vector<int> depth;                // root \u304B\
    \u3089\u306E\u8DDD\u96E2\n    std::vector<T> cost;                   // root \u304B\
    \u3089\u306E\u30B3\u30B9\u30C8\n\n    void dfs(int pos, int par, int d, T c) {\n\
    \        if (par != -1) parent[pos][0] = par;\n        depth[pos] = d;\n     \
    \   cost[pos] = c;\n        for (auto edge : this->_graph[pos]) {\n          \
    \  if (edge.to == par) continue;\n            dfs(edge.to, pos, d + 1, c + edge.cost);\n\
    \        }\n    }\n\n   public:\n    lca_tree(int n) : n(n), Graph<T>(n) {}\n\
    \    void build(int root = 0) {\n        K = 0;\n        while ((1 << K) < n)\
    \ K++;\n        parent.assign(n + 1, std::vector<int>(K, n));\n        depth.assign(n,\
    \ -1);\n        cost.assign(n, -1);\n        dfs(root, -1, 0, 0);\n        for\
    \ (int i = 0; i < K - 1; ++i) {\n            for (int v = 0; v < n; ++v) {\n \
    \               parent[v][i + 1] = parent[parent[v][i]][i];\n            }\n \
    \       }\n    }\n    int lca(int a, int b) {\n        if (depth[a] > depth[b])\
    \ std::swap(a, b);\n        int diff = depth[b] - depth[a];\n        for (int\
    \ i = K - 1; i >= 0; i--) {\n            int len = 1 << i;\n            if (diff\
    \ >= len) {\n                diff -= len;\n                b = parent[b][i];\n\
    \            }\n        }\n        if (a == b) return a;\n        for (int i =\
    \ K - 1; i >= 0; i--) {\n            int na = parent[a][i];\n            int nb\
    \ = parent[b][i];\n            if (na != nb) a = na, b = nb;\n        }\n    \
    \    return parent[a][0];\n    }\n\n    // \u30CE\u30FC\u30C9\u9593\u306E\u8DDD\
    \u96E2\uFF081\u9AA8\u683C)\n    int length(int a, int b) { return depth[a] + depth[b]\
    \ - 2 * depth[lca(a, b)]; }\n\n    // \u30CE\u30FC\u30C9\u9593\u306E\u8DDD\u96E2\
    \uFF08\u30B3\u30B9\u30C8\uFF09\n    T dist(int a, int b) { return cost[a] + cost[b]\
    \ - 2 * cost[lca(a, b)]; }\n};"
  dependsOn:
  - graph.hpp
  isVerificationFile: false
  path: lca_tree.hpp
  requiredBy:
  - auxiliary_tree.hpp
  timestamp: '2024-02-17 20:02:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lca_tree.test.cpp
documentation_of: lca_tree.hpp
layout: document
redirect_from:
- /library/lca_tree.hpp
- /library/lca_tree.hpp.html
title: lca_tree.hpp
---
