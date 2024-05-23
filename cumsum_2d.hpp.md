---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/cumsum_2d.md
    document_title: "2D Cumulative Sum (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C/2\u6B21\
      \u5143imos\u6CD5)"
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
    \ - data[x2][y1] + data[x1][y1]);\n    }\n};\n/**\n * @brief 2D Cumulative Sum\
    \ (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C/2\u6B21\u5143imos\u6CD5)\n * @docs docs/cumsum_2d.md\n\
    \n*/\n// [x1, x2) \xD7 [y1, y2)\n"
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
    \ - data[x1][y2] - data[x2][y1] + data[x1][y1]);\n    }\n};\n/**\n * @brief 2D\
    \ Cumulative Sum (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C/2\u6B21\u5143imos\u6CD5\
    )\n * @docs docs/cumsum_2d.md\n\n*/\n// [x1, x2) \xD7 [y1, y2)"
  dependsOn: []
  isVerificationFile: false
  path: cumsum_2d.hpp
  requiredBy: []
  timestamp: '2024-05-23 15:29:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cumsum_2d.hpp
layout: document
redirect_from:
- /library/cumsum_2d.hpp
- /library/cumsum_2d.hpp.html
title: "2D Cumulative Sum (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C/2\u6B21\u5143imos\u6CD5\
  )"
---
# cumsum_2d (2次元累積和/2次元imos法)

2次元の累積和を管理する。  
または、2次元のimos法を実行する。  

## コンストラクタ

~~~cpp
cumsum_2d<ll> cs(int H, int W)
~~~

- サイズ $H \times W$ の2次元配列を確保する

## add

~~~cpp
void cs.add(int x, int y, T z=1)
~~~

- 座標 $(x, y)$ に値 $z$ を加算する

## imos

~~~cpp
void cs.imos(int x1, int x2, int y1, int y2, T z=1)
~~~

- 領域 $[x1, x2) \times [y1, y2)$ に値 $z$ を加算する。
- 内部的には、imos法によりクエリ実行時に累積和が評価される。

## get

~~~cpp
T cs.get(int x, int y)
~~~

- build実行後の、座標 $(x, y)$ の値を取得する。

## query

~~~cpp
T cs.query(int x1, int x2, int y1, int y2)
~~~

- 領域 $[x1, x2) \times [y1, y2)$ の累積和を取得する

