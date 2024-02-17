---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: lca_tree.hpp
    title: lca_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lca_tree.test.cpp
    title: verify/lca_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph.hpp\"\n\n#include <cassert>\n#include <vector>\n\n\
    template <typename T = long long> struct Edge {\n    int id;\n    int from;\n\
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
    \        return _edges[i];\n    }\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T = long long> struct Edge {\n    int id;\n    int from;\n    int to;\n    T\
    \ cost;\n    bool operator<(const Edge& other) const { return cost < other.cost;\
    \ }\n    bool operator>(const Edge& other) const { return cost > other.cost; }\n\
    \    Edge& operator=(const T& x) {\n        to = x;\n        return *this;\n \
    \   }\n    operator int() const { return to; }\n};\n\ntemplate <typename T = long\
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
    \        return _edges[i];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph.hpp
  requiredBy:
  - lca_tree.hpp
  timestamp: '2024-02-17 19:23:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lca_tree.test.cpp
documentation_of: graph.hpp
layout: document
redirect_from:
- /library/graph.hpp
- /library/graph.hpp.html
title: graph.hpp
---
