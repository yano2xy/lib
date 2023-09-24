---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dsu.hpp
    title: dsu (UnionFind)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/dsu.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"dsu.hpp\"\n\n\
    #line 6 \"dsu.hpp\"\n\nstruct dsu {\n    int _n;\n    std::vector<int> data;\n\
    \n    dsu() : _n(0) {}\n    dsu(int n) : _n(n), data(n, -1) {}\n\n    bool merge(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        int x = leader(a), y = leader(b);\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return x;\n    }\n\n    int same(int\
    \ a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b <\
    \ _n);\n        return leader(a) == leader(b);\n    }\n\n    int leader(int a)\
    \ {\n        assert(0 <= a && a < _n);\n        if (data[a] < 0) return a;\n \
    \       return data[a] = leader(data[a]);\n    }\n\n    int size(int a) {\n  \
    \      assert(0 <= a && a < _n);\n        return -data[leader(a)];\n    }\n\n\
    \    auto gropus() {\n        std::vector<int> leaders(_n), group_size(_n);\n\
    \        for (int i = 0; i < _n; i++) {\n            leaders[i] = leader(i);\n\
    \            group_size[leaders[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ ret(_n);\n        for (int i = 0; i < _n; i++) {\n            ret[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            ret[leaders[i]].push_back(i);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<int>& v) { return v.empty(); }), ret.end());\n\n        return ret;\n\
    \    }\n};\n/*\n * @brief dsu (UnionFind)\n * @docs docs/dsu.md\n */\n#line 7\
    \ \"verify/dsu.test.cpp\"\n\nint main() {\n    int n, Q;\n    cin >> n >> Q;\n\
    \    dsu un(n);\n    while (Q--) {\n        int t, u, v;\n        cin >> t >>\
    \ u >> v;\n        if (t == 0) {\n            un.merge(u, v);\n        } else\
    \ {\n            cout << un.same(u, v) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../dsu.hpp\"\n\nint main()\
    \ {\n    int n, Q;\n    cin >> n >> Q;\n    dsu un(n);\n    while (Q--) {\n  \
    \      int t, u, v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n    \
    \        un.merge(u, v);\n        } else {\n            cout << un.same(u, v)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - dsu.hpp
  isVerificationFile: true
  path: verify/dsu.test.cpp
  requiredBy: []
  timestamp: '2023-09-24 12:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/dsu.test.cpp
- /verify/verify/dsu.test.cpp.html
title: verify/dsu.test.cpp
---
