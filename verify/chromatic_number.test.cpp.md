---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: chromatic_number.hpp
    title: chromatic_number.hpp
  - icon: ':heavy_check_mark:'
    path: graph.hpp
    title: graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"verify/chromatic_number.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"chromatic_number.hpp\"\
    \nusing namespace std;\n\n#line 2 \"graph.hpp\"\n\n#line 5 \"graph.hpp\"\n\ntemplate\
    \ <typename T = long long> struct Edge {\n    int id;\n    int from;\n    int\
    \ to;\n    T cost;\n    bool operator<(const Edge& other) const { return cost\
    \ < other.cost; }\n    bool operator>(const Edge& other) const { return cost >\
    \ other.cost; }\n    Edge& operator=(const T& x) {\n        to = x;\n        return\
    \ *this;\n    }\n    operator int() const { return to; }\n};\n\ntemplate <typename\
    \ T = long long> struct Graph {\n    int _n;\n    std::vector<std::vector<Edge<T>>>\
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
    \        return _edges[i];\n    }\n};\n#line 5 \"chromatic_number.hpp\"\n\ntemplate\
    \ <class T> int chromatic_number(Graph<T> &G) {\n    int n = (int)G.size();\n\
    \    vector<int> es(n);\n    for (int i = 0; i < n; i++)\n        for (auto e\
    \ : G[i]) es[i] |= 1 << e.to;\n\n    vector<int> ind(1 << n);\n    ind[0] = 1;\n\
    \    for (int S = 1; S < (1 << n); S++) {\n        int u = __builtin_ctz(S);\n\
    \        ind[S] = ind[S ^ (1 << u)] + ind[(S ^ (1 << u)) & ~es[u]];\n    }\n \
    \   vector<int> cnt((1 << n) + 1);\n    for (int i = 0; i < (1 << n); i++) {\n\
    \        cnt[ind[i]] += __builtin_parity(i) ? -1 : 1;\n    }\n    vector<pair<unsigned,\
    \ int>> hist;\n    for (int i = 1; i <= (1 << n); i++) {\n        if (cnt[i])\
    \ hist.emplace_back(i, cnt[i]);\n    }\n    constexpr int mods[] = {1000000007,\
    \ 1000000103, 1000000123};\n    int ret = n;\n    for (int k = 0; k < 3; k++)\
    \ {\n        auto buf = hist;\n        for (int c = 1; c < ret; c++) {\n     \
    \       int64_t sum = 0;\n            for (auto &[i, x] : buf) {\n           \
    \     sum += (x = int64_t(x) * i % mods[k]);\n            }\n            if (sum\
    \ % mods[k]) ret = c;\n        }\n    }\n    return ret;\n}\n#line 7 \"verify/chromatic_number.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int n, m;\n    cin >> n >> m;\n\n    Graph<int> G(n);\n    for (int i = 0;\
    \ i < m; i++) {\n        int a, b;\n        cin >> a >> b;\n        G.add_edge(a,\
    \ b);\n    }\n    cout << chromatic_number(G) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../chromatic_number.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int n, m;\n    cin >> n >> m;\n\n    Graph<int> G(n);\n    for (int i = 0;\
    \ i < m; i++) {\n        int a, b;\n        cin >> a >> b;\n        G.add_edge(a,\
    \ b);\n    }\n    cout << chromatic_number(G) << '\\n';\n    return 0;\n}"
  dependsOn:
  - chromatic_number.hpp
  - graph.hpp
  isVerificationFile: true
  path: verify/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 02:16:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/verify/chromatic_number.test.cpp
- /verify/verify/chromatic_number.test.cpp.html
title: verify/chromatic_number.test.cpp
---
