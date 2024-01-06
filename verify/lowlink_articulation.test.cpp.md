---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"verify/lowlink_articulation.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"lowlink.hpp\"\n\n#line 5\
    \ \"lowlink.hpp\"\n\nstruct lowlink {\n   protected:\n    int n;\n    std::vector<int>\
    \ used, ord, low;\n    std::vector<std::vector<int>> G;\n    int dfs(int pos,\
    \ int k, int par = -1) {\n        used[pos] = 1;\n        ord[pos] = k++;\n  \
    \      low[pos] = ord[pos];\n        bool is_articulation = false;\n        int\
    \ cnt = 0;\n        for (auto &to : G[pos]) {\n            if (!used[to]) {\n\
    \                ++cnt;\n                k = dfs(to, k, pos);\n              \
    \  low[pos] = std::min(low[pos], low[to]);\n                is_articulation |=\
    \ ~par && low[to] >= ord[pos];\n                if (ord[pos] < low[to]) bridge.emplace_back(std::minmax(pos,\
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
    \ */\n#line 7 \"verify/lowlink_articulation.test.cpp\"\n\nint main() {\n    int\
    \ V, E;\n    cin >> V >> E;\n    lowlink G(V);\n    for (int i = 0; i < E; i++)\
    \ {\n        int s, t;\n        cin >> s >> t;\n        G.add_edge(s, t);\n  \
    \  }\n    G.build();\n    sort(G.articulation.begin(), G.articulation.end());\n\
    \    for (auto v : G.articulation) cout << v << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../lowlink.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    lowlink G(V);\n    for\
    \ (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n     \
    \   G.add_edge(s, t);\n    }\n    G.build();\n    sort(G.articulation.begin(),\
    \ G.articulation.end());\n    for (auto v : G.articulation) cout << v << '\\n';\n\
    \    return 0;\n}\n"
  dependsOn:
  - lowlink.hpp
  isVerificationFile: true
  path: verify/lowlink_articulation.test.cpp
  requiredBy: []
  timestamp: '2024-01-06 18:15:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lowlink_articulation.test.cpp
layout: document
redirect_from:
- /verify/verify/lowlink_articulation.test.cpp
- /verify/verify/lowlink_articulation.test.cpp.html
title: verify/lowlink_articulation.test.cpp
---
