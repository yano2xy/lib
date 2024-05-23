---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cumsum_2d.hpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class T = long long> struct cumsum_2d {\n   private:\n    bool is_built\
    \ = false;\n    std::vector<std::vector<T> > data;\n    void build() {\n     \
    \   for (int i = 1; i < (int)data.size(); i++) {\n            for (int j = 1;\
    \ j < (int)data[i].size(); j++) {\n                data[i][j] += data[i][j - 1]\
    \ + data[i - 1][j] - data[i - 1][j - 1];\n            }\n        }\n        is_built\
    \ = true;\n    }\n\n   public:\n    cumsum_2d(int H, int W) : data(H + 3, vector<T>(W\
    \ + 3, 0)) {}\n    void add(int x, int y, T z) {\n        assert(!is_built);\n\
    \        ++x, ++y;\n        if (x >= (int)data.size() || y >= (int)data[0].size())\
    \ return;\n        data[x][y] += z;\n    }\n\n    void imos(int x1, int x2, int\
    \ y1, int y2, T z = 1) {\n        assert(!is_built);\n        add(x1, y1, z);\n\
    \        add(x1, y2, -z);\n        add(x2, y1, -z);\n        add(x2, y2, z);\n\
    \    }\n\n    T get(int x, int y) {\n        if (!is_built) build();\n       \
    \ return data[x + 1][y + 1];\n    }\n\n    T query(int x1, int x2, int y1, int\
    \ y2) {\n        if (!is_built) build();\n        return (data[x2][y2] - data[x1][y2]\
    \ - data[x2][y1] + data[x1][y1]);\n    }\n};\n// [x1, x2) \xD7 [y1, y2)\n"
  code: "#include <cassert>\n#include <vector>\n\ntemplate <class T = long long> struct\
    \ cumsum_2d {\n   private:\n    bool is_built = false;\n    std::vector<std::vector<T>\
    \ > data;\n    void build() {\n        for (int i = 1; i < (int)data.size(); i++)\
    \ {\n            for (int j = 1; j < (int)data[i].size(); j++) {\n           \
    \     data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\n  \
    \          }\n        }\n        is_built = true;\n    }\n\n   public:\n    cumsum_2d(int\
    \ H, int W) : data(H + 3, vector<T>(W + 3, 0)) {}\n    void add(int x, int y,\
    \ T z) {\n        assert(!is_built);\n        ++x, ++y;\n        if (x >= (int)data.size()\
    \ || y >= (int)data[0].size()) return;\n        data[x][y] += z;\n    }\n\n  \
    \  void imos(int x1, int x2, int y1, int y2, T z = 1) {\n        assert(!is_built);\n\
    \        add(x1, y1, z);\n        add(x1, y2, -z);\n        add(x2, y1, -z);\n\
    \        add(x2, y2, z);\n    }\n\n    T get(int x, int y) {\n        if (!is_built)\
    \ build();\n        return data[x + 1][y + 1];\n    }\n\n    T query(int x1, int\
    \ x2, int y1, int y2) {\n        if (!is_built) build();\n        return (data[x2][y2]\
    \ - data[x1][y2] - data[x2][y1] + data[x1][y1]);\n    }\n};\n// [x1, x2) \xD7\
    \ [y1, y2)"
  dependsOn: []
  isVerificationFile: false
  path: cumsum_2d.hpp
  requiredBy: []
  timestamp: '2024-05-23 15:11:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cumsum_2d.hpp
layout: document
redirect_from:
- /library/cumsum_2d.hpp
- /library/cumsum_2d.hpp.html
title: cumsum_2d.hpp
---
