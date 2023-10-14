---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/cht.md
    document_title: cht (Convex Hull Trick)
    links: []
  bundledCode: "#line 2 \"cht.hpp\"\n\n#include <deque>\n#include <utility>\n\ntemplate\
    \ <typename T = long long>\nstruct cht {\n    using Line = std::pair<T, T>;\n\
    \    std::deque<Line> d;\n    void add(T a, T b) {\n        Line x = make_pair(a,\
    \ b);\n        while ((int)d.size() >= 2) {\n            Line y = d[(int)d.size()\
    \ - 1];\n            Line z = d[(int)d.size() - 2];\n            if ((x.second\
    \ - y.second) * (z.first - y.first) >= (y.first - x.first) * (y.second - z.second))\
    \ break;\n            d.pop_back();\n        }\n        d.push_back(x);\n    }\n\
    \    T get(T x) {\n        while ((int)d.size() >= 2) {\n            T a = d[0].first\
    \ * x + d[0].second;\n            T b = d[1].first * x + d[1].second;\n      \
    \      if (a <= b) break;\n            d.pop_front();\n        }\n        return\
    \ d[0].first * x + d[0].second;\n    }\n};\n/*\n * @brief cht (Convex Hull Trick)\n\
    \ * @docs docs/cht.md\n */\n"
  code: "#pragma once\n\n#include <deque>\n#include <utility>\n\ntemplate <typename\
    \ T = long long>\nstruct cht {\n    using Line = std::pair<T, T>;\n    std::deque<Line>\
    \ d;\n    void add(T a, T b) {\n        Line x = make_pair(a, b);\n        while\
    \ ((int)d.size() >= 2) {\n            Line y = d[(int)d.size() - 1];\n       \
    \     Line z = d[(int)d.size() - 2];\n            if ((x.second - y.second) *\
    \ (z.first - y.first) >= (y.first - x.first) * (y.second - z.second)) break;\n\
    \            d.pop_back();\n        }\n        d.push_back(x);\n    }\n    T get(T\
    \ x) {\n        while ((int)d.size() >= 2) {\n            T a = d[0].first * x\
    \ + d[0].second;\n            T b = d[1].first * x + d[1].second;\n          \
    \  if (a <= b) break;\n            d.pop_front();\n        }\n        return d[0].first\
    \ * x + d[0].second;\n    }\n};\n/*\n * @brief cht (Convex Hull Trick)\n * @docs\
    \ docs/cht.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: cht.hpp
  requiredBy: []
  timestamp: '2023-10-14 17:50:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cht.hpp
layout: document
redirect_from:
- /library/cht.hpp
- /library/cht.hpp.html
title: cht (Convex Hull Trick)
---

# cht (Convex Hull Trick)

追加する直線の傾きaが単調減少 & 取得クエリのxが単調増加 の場合にのみ使用可能  

## コンストラクタ

~~~cpp
cht<ll> ch;
~~~

## add

~~~cpp
void ch.add(T a, T b)
~~~

直線 $ y = ax + b $ を追加する。  

## get

~~~cpp
T get(T x)
~~~

追加されている直線の集合を$F$として$min_{f \in F} f(x)$ を返す。  