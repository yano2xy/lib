---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/fenwick_tree.md
    document_title: fenwick_tree (Binary Indexed Tree)
    links: []
  bundledCode: "#line 2 \"fenwick_tree.hpp\"\n\n#include <bits/stdc++.h>\n\n#line\
    \ 8 \"fenwick_tree.hpp\"\n\ntemplate <class T>\nstruct fenwick_tree {\n   public:\n\
    \    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n) {}\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p - 1] += x;\n            p += p\
    \ & -p;\n        }\n    }\n    T sum(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n   private:\n\
    \    int _n;\n    std::vector<T> data;\n    T sum(int r) {\n        T s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n/*\n * @brief fenwick_tree (Binary\
    \ Indexed Tree)\n * @docs docs/fenwick_tree.md\n */\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\n#include <cassert>\n#include\
    \ <numeric>\n#include <vector>\n\ntemplate <class T>\nstruct fenwick_tree {\n\
    \   public:\n    fenwick_tree() : _n(0) {}\n    fenwick_tree(int n) : _n(n), data(n)\
    \ {}\n    void add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n\
    \        while (p <= _n) {\n            data[p - 1] += x;\n            p += p\
    \ & -p;\n        }\n    }\n    T sum(int l, int r) {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n   private:\n\
    \    int _n;\n    std::vector<T> data;\n    T sum(int r) {\n        T s = 0;\n\
    \        while (r > 0) {\n            s += data[r - 1];\n            r -= r &\
    \ -r;\n        }\n        return s;\n    }\n};\n/*\n * @brief fenwick_tree (Binary\
    \ Indexed Tree)\n * @docs docs/fenwick_tree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: fenwick_tree.hpp
  requiredBy: []
  timestamp: '2023-12-29 15:27:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fenwick_tree.hpp
layout: document
redirect_from:
- /library/fenwick_tree.hpp
- /library/fenwick_tree.hpp.html
title: fenwick_tree (Binary Indexed Tree)
---
# fenwick_tree (Binary Indexed Tree)  

ACL (AtCoder Library) に準じる。  