---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/swag.test.cpp
    title: verify/swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/swag.md
    document_title: SWAG (Sliding Window Aggregation)
    links: []
  bundledCode: "#line 2 \"swag.hpp\"\n\n#include <cassert>\n#include <functional>\n\
    #include <stack>\n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct swag {\n\
    \    struct prod_stack {\n        bool left;\n        std::stack<T> st, prd;\n\
    \        prod_stack() : left(false) {}\n        prod_stack(bool left) : left(left)\
    \ {}\n        void push(T x) {\n            T p = prod();\n            st.push(x);\n\
    \            if (left) prd.push(op(x, p));\n            else prd.push(op(p, x));\n\
    \        }\n        void pop() {\n            assert(!empty());\n            st.pop(),\
    \ prd.pop();\n        }\n        T top() {\n            assert(!empty());\n  \
    \          return st.top();\n        }\n        T prod() { return empty() ? e()\
    \ : prd.top(); }\n        int size() { return prd.size(); }\n        bool empty()\
    \ { return prd.empty(); }\n    };\n\n    prod_stack front_st, back_st;\n    swag()\
    \ : front_st(true), back_st(false) {}\n    void push(T x) { back_st.push(x); }\n\
    \    void balance() {\n        while (!back_st.empty()) {\n            front_st.push(back_st.top());\n\
    \            back_st.pop();\n        }\n    }\n    void pop() {\n        assert(!empty());\n\
    \        if (front_st.empty()) balance();\n        front_st.pop();\n    }\n  \
    \  void front() {\n        assert(!empty());\n        if (front_st.empty()) balance();\n\
    \        return front_st.top();\n    }\n    T prod() { return op(front_st.prod(),\
    \ back_st.prod()); }\n    int size() { return front_st.size() + back_st.size();\
    \ }\n    bool empty() { return size() == 0; }\n};\n/*\n * @brief SWAG (Sliding\
    \ Window Aggregation)\n * @docs docs/swag.md\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <functional>\n#include <stack>\n\
    \ntemplate <class T, T (*op)(T, T), T (*e)()>\nstruct swag {\n    struct prod_stack\
    \ {\n        bool left;\n        std::stack<T> st, prd;\n        prod_stack()\
    \ : left(false) {}\n        prod_stack(bool left) : left(left) {}\n        void\
    \ push(T x) {\n            T p = prod();\n            st.push(x);\n          \
    \  if (left) prd.push(op(x, p));\n            else prd.push(op(p, x));\n     \
    \   }\n        void pop() {\n            assert(!empty());\n            st.pop(),\
    \ prd.pop();\n        }\n        T top() {\n            assert(!empty());\n  \
    \          return st.top();\n        }\n        T prod() { return empty() ? e()\
    \ : prd.top(); }\n        int size() { return prd.size(); }\n        bool empty()\
    \ { return prd.empty(); }\n    };\n\n    prod_stack front_st, back_st;\n    swag()\
    \ : front_st(true), back_st(false) {}\n    void push(T x) { back_st.push(x); }\n\
    \    void balance() {\n        while (!back_st.empty()) {\n            front_st.push(back_st.top());\n\
    \            back_st.pop();\n        }\n    }\n    void pop() {\n        assert(!empty());\n\
    \        if (front_st.empty()) balance();\n        front_st.pop();\n    }\n  \
    \  void front() {\n        assert(!empty());\n        if (front_st.empty()) balance();\n\
    \        return front_st.top();\n    }\n    T prod() { return op(front_st.prod(),\
    \ back_st.prod()); }\n    int size() { return front_st.size() + back_st.size();\
    \ }\n    bool empty() { return size() == 0; }\n};\n/*\n * @brief SWAG (Sliding\
    \ Window Aggregation)\n * @docs docs/swag.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: swag.hpp
  requiredBy: []
  timestamp: '2023-12-20 00:00:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/swag.test.cpp
documentation_of: swag.hpp
layout: document
redirect_from:
- /library/swag.hpp
- /library/swag.hpp.html
title: SWAG (Sliding Window Aggregation)
---
# swag (Sliding Window Aggregation)

- モノイドに対して使用可能
- スライド区間に対して、区間の伸縮(push, pop)および区間における総積の取得(prod)をならし計算量 $O(1)$ で実行する 

## コンストラクタ

~~~cpp
swag<S, op, e> sw;
~~~

- op はモノイド演算
- e は単位減取得関数

## push

~~~
void sw.push(T x)
~~~

- swの末尾に $x$ を追加する

## pop

~~~
void sw.pop()
~~~

- swの先頭の要素を削除する

## front

~~~
T sw.front()
~~~

- swの先頭の要素を取得する

## prod

~~~
T sw.prod()
~~~

- swの中の要素のモノイド演算の総積を取得する
- swが空の場合、単位元 $e()$ を返す