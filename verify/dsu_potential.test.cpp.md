---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dsu_potential.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D UnionFind"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"verify/dsu_potential.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"dsu_potential.hpp\"\
    \n\n#line 5 \"dsu_potential.hpp\"\n\ntemplate <typename T = long long>\nstruct\
    \ dsu_potential {\n   public:\n    int _n;\n    std::vector<int> data;\n    std::vector<T>\
    \ diff_potential;\n\n    dsu_potential() : _n(0) {}\n    dsu_potential(int n)\
    \ : _n(n), data(n, -1), diff_potential(n, 0) {}\n\n    bool merge(int a, int b,\
    \ T d) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n\
    \        if (same(a, b)) return (d == diff(a, b));\n        int x = leader(a),\
    \ y = leader(b);\n        d += potential(a) - potential(b);\n        if (-data[x]\
    \ < -data[y]) std::swap(x, y), d = -d;\n        data[x] += data[y];\n        data[y]\
    \ = x;\n        diff_potential[y] = d;\n        return true;\n    }\n\n    bool\
    \ same(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <=\
    \ b && b < _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int\
    \ a) {\n        assert(0 <= a && a < _n);\n        if (data[a] < 0) return a;\n\
    \        int r = leader(data[a]);\n        diff_potential[a] += diff_potential[data[a]];\n\
    \        return data[a] = r;\n    }\n\n    T potential(int a) {\n        assert(0\
    \ <= a && a < _n);\n        leader(a);\n        return diff_potential[a];\n  \
    \  }\n\n    T diff(int a, int b) {\n        assert(0 <= a && a < _n);\n      \
    \  assert(0 <= b && b < _n);\n        assert(leader(a) == leader(b));\n      \
    \  return potential(b) - potential(a);\n    }\n\n    int size(int a) {\n     \
    \   assert(0 <= a && a < _n);\n        return -data[leader(a)];\n    }\n\n   \
    \ auto groups() {\n        std::vector<int> leaders(_n), group_size(_n);\n   \
    \     for (int i = 0; i < _n; i++) {\n            leaders[i] = leader(i);\n  \
    \          group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ ret(_n);\n        for (int i = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n    /*\n        @brief \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
    \ UnionFind\n        @docs docs/dsu_potential.md\n    */\n};\n#line 7 \"verify/dsu_potential.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    while (true) {\n        cin >> n >> m;\n\
    \        if (m == 0) break;\n        dsu_potential un(n);\n        while (m--)\
    \ {\n            char c;\n            cin >> c;\n            if (c == '!') {\n\
    \                int a, b, w;\n                cin >> a >> b >> w;\n         \
    \       --a, --b;\n                un.merge(a, b, w);\n            } else {\n\
    \                int a, b;\n                cin >> a >> b;\n                --a,\
    \ --b;\n                if (un.same(a, b)) cout << un.diff(a, b) << '\\n';\n \
    \               else cout << \"UNKNOWN\\n\";\n            }\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../dsu_potential.hpp\"\
    \n\nint main() {\n    int n, m;\n    while (true) {\n        cin >> n >> m;\n\
    \        if (m == 0) break;\n        dsu_potential un(n);\n        while (m--)\
    \ {\n            char c;\n            cin >> c;\n            if (c == '!') {\n\
    \                int a, b, w;\n                cin >> a >> b >> w;\n         \
    \       --a, --b;\n                un.merge(a, b, w);\n            } else {\n\
    \                int a, b;\n                cin >> a >> b;\n                --a,\
    \ --b;\n                if (un.same(a, b)) cout << un.diff(a, b) << '\\n';\n \
    \               else cout << \"UNKNOWN\\n\";\n            }\n        }\n    }\n\
    }\n"
  dependsOn:
  - dsu_potential.hpp
  isVerificationFile: true
  path: verify/dsu_potential.test.cpp
  requiredBy: []
  timestamp: '2023-09-24 14:48:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dsu_potential.test.cpp
layout: document
redirect_from:
- /verify/verify/dsu_potential.test.cpp
- /verify/verify/dsu_potential.test.cpp.html
title: verify/dsu_potential.test.cpp
---
