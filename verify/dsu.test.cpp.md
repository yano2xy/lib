---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dsu.hpp
    title: dsu (disjoint set union)
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
    struct dsu {\n    vector<int> data;\n\n    dsu() = default;\n\n    explicit dsu(size_t\
    \ sz) : data(sz, -1) {}\n\n    bool merge(int x, int y) {\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return false;\n        if (data[x] > data[y])\
    \ swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n        return\
    \ true;\n    }\n\n    int find(int k) {\n        if (data[k] < 0) return k;\n\
    \        return data[k] = find(data[k]);\n    }\n\n    int size(int k) { return\
    \ -data[find(k)]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n\n    vector<vector<int> > groups() {\n        int n = (int)data.size();\n\
    \        vector<vector<int> > ret(n);\n        for (int i = 0; i < n; i++) {\n\
    \            ret[find(i)].emplace_back(i);\n        }\n        ret.erase(remove_if(begin(ret),\
    \ end(ret), [&](const vector<int> &v) { return v.empty(); }), end(ret));\n   \
    \     return ret;\n    }\n};\n/*\n * @brief dsu (disjoint set union)\n * @docs\
    \ docs/dsu.md\n */\n#line 7 \"verify/dsu.test.cpp\"\n\nint main() {\n    int n,\
    \ Q;\n    cin >> n >> Q;\n    dsu un(n);\n    while (Q--) {\n        int t, u,\
    \ v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n            un.merge(u,\
    \ v);\n        } else {\n            cout << un.same(u, v) << '\\n';\n       \
    \ }\n    }\n}\n"
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
  timestamp: '2023-09-24 11:38:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/dsu.test.cpp
- /verify/verify/dsu.test.cpp.html
title: verify/dsu.test.cpp
---
