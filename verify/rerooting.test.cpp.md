---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: rerooting.hpp
    title: rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"verify/rerooting.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"rerooting.hpp\"\
    \n\n#line 5 \"rerooting.hpp\"\n\ntemplate <typename S>\nstruct rerooting {\n \
    \  private:\n    int n;\n    std::vector<std::vector<int>> G;\n    std::vector<std::vector<S>>\
    \ dp;\n    using TF = std::function<S(S, int, int)>;\n    using TM = std::function<S(S,\
    \ S)>;\n    using TG = std::function<S(S, int)>;\n    using Id = std::function<S()>;\n\
    \    TF f;\n    TM merge;\n    TG g;\n    Id id;\n\n    S dfs1(int pos, int par)\
    \ {\n        S val = id();\n        for (int i = 0; i < G[pos].size(); ++i) {\n\
    \            if (G[pos][i] == par) continue;\n            dp[pos][i] = dfs1(G[pos][i],\
    \ pos);\n            val = merge(val, f(dp[pos][i], G[pos][i], pos));\n      \
    \  }\n        return g(val, pos);\n    }\n\n    void dfs2(int pos, int par, S\
    \ dp_par) {\n        for (int i = 0; i < G[pos].size(); ++i) {\n            if\
    \ (G[pos][i] == par) {\n                dp[pos][i] = dp_par;\n               \
    \ break;\n            }\n        }\n        std::vector<S> pR(G[pos].size() +\
    \ 1, id());\n        for (int i = G[pos].size(); i > 0; --i)\n            pR[i\
    \ - 1] = merge(pR[i], f(dp[pos][i - 1], G[pos][i - 1], pos));\n        S pL =\
    \ id();\n        for (int i = 0; i < G[pos].size(); ++i) {\n            if (G[pos][i]\
    \ != par) {\n                S val = merge(pL, pR[i + 1]);\n                dfs2(G[pos][i],\
    \ pos, g(val, pos));\n            }\n            pL = merge(pL, f(dp[pos][i],\
    \ G[pos][i], pos));\n        }\n    }\n\n   public:\n    rerooting(int n, TF f,\
    \ TM merge, TG g, Id id) : n(n), f(f), merge(merge), g(g), id(id) {\n        G.resize(n);\n\
    \        dp.resize(n);\n    }\n\n    void add_edge(int a, int b) {\n        G[a].emplace_back(b);\n\
    \        G[b].emplace_back(a);\n    }\n\n    std::vector<S> solve() {\n      \
    \  std::vector<S> ret(n);\n        for (int i = 0; i < n; ++i)\n            dp[i].resize(G[i].size());\n\
    \        dfs1(0, -1);\n        dfs2(0, -1, id());\n        for (int i = 0; i <\
    \ n; ++i) {\n            S v = id();\n            for (int j = 0; j < G[i].size();\
    \ ++j) {\n                v = merge(v, f(dp[i][j], G[i][j], i));\n           \
    \ }\n            ret[i] = g(v, i);\n        }\n        return ret;\n    }\n};\n\
    /*\n * @brief rerooting\n * @docs docs/rerooting.md\n */\n#line 7 \"verify/rerooting.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    map<pair<int, int>, int> es;\n\
    \n    auto f = [&](int x, int pos, int par) -> int { return x + es[{pos, par}];\
    \ };\n    auto merge = [&](int x, int y) -> int { return max(x, y); };\n    auto\
    \ g = [&](int x, int pos) -> int { return x; };\n    auto id = [&]() { return\
    \ 0; };\n    rerooting<int> G(n, f, merge, g, id);\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        int a, b, w;\n        cin >> a >> b >> w;\n        G.add_edge(a,\
    \ b);\n        es[{a, b}] = w;\n        es[{b, a}] = w;\n    }\n\n    auto V =\
    \ G.solve();\n    for (auto v : V)\n        cout << v << '\\n';\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../rerooting.hpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    map<pair<int, int>, int> es;\n\
    \n    auto f = [&](int x, int pos, int par) -> int { return x + es[{pos, par}];\
    \ };\n    auto merge = [&](int x, int y) -> int { return max(x, y); };\n    auto\
    \ g = [&](int x, int pos) -> int { return x; };\n    auto id = [&]() { return\
    \ 0; };\n    rerooting<int> G(n, f, merge, g, id);\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        int a, b, w;\n        cin >> a >> b >> w;\n        G.add_edge(a,\
    \ b);\n        es[{a, b}] = w;\n        es[{b, a}] = w;\n    }\n\n    auto V =\
    \ G.solve();\n    for (auto v : V)\n        cout << v << '\\n';\n}"
  dependsOn:
  - rerooting.hpp
  isVerificationFile: true
  path: verify/rerooting.test.cpp
  requiredBy: []
  timestamp: '2023-10-12 23:05:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/rerooting.test.cpp
layout: document
redirect_from:
- /verify/verify/rerooting.test.cpp
- /verify/verify/rerooting.test.cpp.html
title: verify/rerooting.test.cpp
---
