---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph.hpp
    title: graph.hpp
  - icon: ':heavy_check_mark:'
    path: lca_tree.hpp
    title: lca_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"auxiliary_tree.hpp\"\n\n#include <algorithm>\n#include <stack>\n\
    #include <vector>\n\n#line 2 \"graph.hpp\"\n\n#include <cassert>\n#line 5 \"graph.hpp\"\
    \n\ntemplate <typename T = long long> struct Edge {\n    int id;\n    int from;\n\
    \    int to;\n    T cost;\n    bool operator<(const Edge& other) const { return\
    \ cost < other.cost; }\n    bool operator>(const Edge& other) const { return cost\
    \ > other.cost; }\n    Edge& operator=(const T& x) {\n        to = x;\n      \
    \  return *this;\n    }\n    operator int() const { return to; }\n};\n\ntemplate\
    \ <typename T = long long> struct Graph {\n    int _n;\n    std::vector<std::vector<Edge<T>>>\
    \ _graph;\n    const T INF = std::numeric_limits<T>::max() / 2;\n    std::vector<Edge<T>>\
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
    \        return _edges[i];\n    }\n};\n#line 3 \"lca_tree.hpp\"\n\n#line 5 \"\
    lca_tree.hpp\"\ntemplate <typename T = long long> struct lca_tree : Graph<T> {\n\
    \   private:\n    int n, K;\n    std::vector<std::vector<int>> parent;  // parent[v][k]\
    \ := v \u306E 2^k \u5148\u306E\u89AA\n    std::vector<int> depth;            \
    \    // root \u304B\u3089\u306E\u8DDD\u96E2\n    std::vector<T> cost;        \
    \           // root \u304B\u3089\u306E\u30B3\u30B9\u30C8\n\n    void dfs(int pos,\
    \ int par, int d, T c) {\n        if (par != -1) parent[pos][0] = par;\n     \
    \   depth[pos] = d;\n        cost[pos] = c;\n        for (auto edge : this->_graph[pos])\
    \ {\n            if (edge.to == par) continue;\n            dfs(edge.to, pos,\
    \ d + 1, c + edge.cost);\n        }\n    }\n\n   public:\n    lca_tree(int n)\
    \ : n(n), Graph<T>(n) {}\n    void build(int root = 0) {\n        K = 0;\n   \
    \     while ((1 << K) < n) K++;\n        parent.assign(n + 1, std::vector<int>(K,\
    \ n));\n        depth.assign(n, -1);\n        cost.assign(n, -1);\n        dfs(root,\
    \ -1, 0, 0);\n        for (int i = 0; i < K - 1; ++i) {\n            for (int\
    \ v = 0; v < n; ++v) {\n                parent[v][i + 1] = parent[parent[v][i]][i];\n\
    \            }\n        }\n    }\n    int lca(int a, int b) {\n        if (depth[a]\
    \ > depth[b]) std::swap(a, b);\n        int diff = depth[b] - depth[a];\n    \
    \    for (int i = K - 1; i >= 0; i--) {\n            int len = 1 << i;\n     \
    \       if (diff >= len) {\n                diff -= len;\n                b =\
    \ parent[b][i];\n            }\n        }\n        if (a == b) return a;\n   \
    \     for (int i = K - 1; i >= 0; i--) {\n            int na = parent[a][i];\n\
    \            int nb = parent[b][i];\n            if (na != nb) a = na, b = nb;\n\
    \        }\n        return parent[a][0];\n    }\n\n    // \u30CE\u30FC\u30C9\u9593\
    \u306E\u8DDD\u96E2\uFF081\u9AA8\u683C)\n    int length(int a, int b) { return\
    \ depth[a] + depth[b] - 2 * depth[lca(a, b)]; }\n\n    // \u30CE\u30FC\u30C9\u9593\
    \u306E\u8DDD\u96E2\uFF08\u30B3\u30B9\u30C8\uFF09\n    T dist(int a, int b) { return\
    \ cost[a] + cost[b] - 2 * cost[lca(a, b)]; }\n};\n#line 9 \"auxiliary_tree.hpp\"\
    \n\nstruct auxiliary_tree : lca_tree<int> {\n    int n;\n    std::vector<int>\
    \ in, out;\n    auxiliary_tree(int n) : n(n), lca_tree<int>(n) {}\n    void build()\
    \ {\n        lca_tree::build();\n        in.assign(n, -1);\n        out.assign(n,\
    \ -1);\n        int id = 0;\n        auto dfs = [&](auto dfs, int pos, int par\
    \ = -1) -> void {\n            in[pos] = id++;\n            for (auto &e : (*this)[pos])\
    \ {\n                if (e.to == par) continue;\n                dfs(dfs, e.to,\
    \ pos);\n            }\n            out[pos] = id;\n        };\n        dfs(dfs,\
    \ 0);\n    };\n    std::pair<int, std::vector<std::vector<int>>> generate(std::vector<int>\
    \ V) {\n        auto order = [&](int a, int b) { return in[a] < in[b]; };\n  \
    \      std::sort(V.begin(), V.end(), order);\n        for (int i = 0; i < V.size()\
    \ - 1; i++) V.push_back(lca(V[i], V[i + 1]));\n        std::sort(V.begin(), V.end(),\
    \ order);\n        V.erase(unique(V.begin(), V.end()), V.end());\n        std::vector<std::vector<int>>\
    \ G(n);\n        std::stack<int> st;\n        for (int v : V) {\n            while\
    \ (st.size()) {\n                int p = st.top();\n                if (in[p]\
    \ < in[v] && in[v] < out[p]) break;\n                st.pop();\n            }\n\
    \            if (st.size()) {\n                G[st.top()].push_back(v);\n   \
    \             G[v].push_back(st.top());\n            }\n            st.push(v);\n\
    \        }\n        return {V[0], G};\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <stack>\n#include <vector>\n\
    \n#include \"graph.hpp\"\n#include \"lca_tree.hpp\"\n\nstruct auxiliary_tree :\
    \ lca_tree<int> {\n    int n;\n    std::vector<int> in, out;\n    auxiliary_tree(int\
    \ n) : n(n), lca_tree<int>(n) {}\n    void build() {\n        lca_tree::build();\n\
    \        in.assign(n, -1);\n        out.assign(n, -1);\n        int id = 0;\n\
    \        auto dfs = [&](auto dfs, int pos, int par = -1) -> void {\n         \
    \   in[pos] = id++;\n            for (auto &e : (*this)[pos]) {\n            \
    \    if (e.to == par) continue;\n                dfs(dfs, e.to, pos);\n      \
    \      }\n            out[pos] = id;\n        };\n        dfs(dfs, 0);\n    };\n\
    \    std::pair<int, std::vector<std::vector<int>>> generate(std::vector<int> V)\
    \ {\n        auto order = [&](int a, int b) { return in[a] < in[b]; };\n     \
    \   std::sort(V.begin(), V.end(), order);\n        for (int i = 0; i < V.size()\
    \ - 1; i++) V.push_back(lca(V[i], V[i + 1]));\n        std::sort(V.begin(), V.end(),\
    \ order);\n        V.erase(unique(V.begin(), V.end()), V.end());\n        std::vector<std::vector<int>>\
    \ G(n);\n        std::stack<int> st;\n        for (int v : V) {\n            while\
    \ (st.size()) {\n                int p = st.top();\n                if (in[p]\
    \ < in[v] && in[v] < out[p]) break;\n                st.pop();\n            }\n\
    \            if (st.size()) {\n                G[st.top()].push_back(v);\n   \
    \             G[v].push_back(st.top());\n            }\n            st.push(v);\n\
    \        }\n        return {V[0], G};\n    }\n};"
  dependsOn:
  - graph.hpp
  - lca_tree.hpp
  isVerificationFile: false
  path: auxiliary_tree.hpp
  requiredBy: []
  timestamp: '2024-02-17 20:02:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: auxiliary_tree.hpp
layout: document
redirect_from:
- /library/auxiliary_tree.hpp
- /library/auxiliary_tree.hpp.html
title: auxiliary_tree.hpp
---
