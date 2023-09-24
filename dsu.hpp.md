---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/dsu.test.cpp
    title: verify/dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dsu.hpp\"\n\n/*\n    dsu\n*/\nstruct dsu {\n    vector<int>\
    \ data;\n\n    dsu() = default;\n\n    explicit dsu(size_t sz) : data(sz, -1)\
    \ {}\n\n    bool merge(int x, int y) {\n        x = find(x), y = find(y);\n  \
    \      if (x == y) return false;\n        if (data[x] > data[y]) swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n        return true;\n   \
    \ }\n\n    int find(int k) {\n        if (data[k] < 0) return k;\n        return\
    \ data[k] = find(data[k]);\n    }\n\n    int size(int k) { return -data[find(k)];\
    \ }\n\n    bool same(int x, int y) { return find(x) == find(y); }\n\n    vector<vector<int>\
    \ > groups() {\n        int n = (int)data.size();\n        vector<vector<int>\
    \ > ret(n);\n        for (int i = 0; i < n; i++) {\n            ret[find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<int>\
    \ &v) { return v.empty(); }), end(ret));\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n/*\n    dsu\n*/\nstruct dsu {\n    vector<int> data;\n\n\
    \    dsu() = default;\n\n    explicit dsu(size_t sz) : data(sz, -1) {}\n\n   \
    \ bool merge(int x, int y) {\n        x = find(x), y = find(y);\n        if (x\
    \ == y) return false;\n        if (data[x] > data[y]) swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        return true;\n    }\n\n    int find(int\
    \ k) {\n        if (data[k] < 0) return k;\n        return data[k] = find(data[k]);\n\
    \    }\n\n    int size(int k) { return -data[find(k)]; }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n\n    vector<vector<int> > groups()\
    \ {\n        int n = (int)data.size();\n        vector<vector<int> > ret(n);\n\
    \        for (int i = 0; i < n; i++) {\n            ret[find(i)].emplace_back(i);\n\
    \        }\n        ret.erase(remove_if(begin(ret), end(ret), [&](const vector<int>\
    \ &v) { return v.empty(); }), end(ret));\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dsu.hpp
  requiredBy: []
  timestamp: '2023-09-24 10:35:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/dsu.test.cpp
documentation_of: dsu.hpp
layout: document
redirect_from:
- /library/dsu.hpp
- /library/dsu.hpp.html
title: dsu.hpp
---
