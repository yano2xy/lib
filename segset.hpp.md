---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/segset.md
    document_title: segset
    links: []
  bundledCode: "#line 2 \"segset.hpp\"\n\n#include <algorithm>\n#include <cassert>\n\
    #include <set>\n\ntemplate <class T> struct segset {\n   private:\n    std::set<std::pair<T,\
    \ T>> s;\n    T sz;\n    const T INF = std::numeric_limits<T>::max() / 2;\n\n\
    \   public:\n    segset() : sz(T(0)) {\n        s.emplace(-INF, -INF);\n     \
    \   s.emplace(INF, INF);\n    }\n\n    bool insert(T x) { return insert(x, x +\
    \ 1); }\n    bool insert(T l, T r) {\n        assert(l <= --r);\n        auto\
    \ it = prev(s.lower_bound({l + 1, l + 1}));\n        if (it->first <= l && r <=\
    \ it->second) return T(0);\n        T dcnt = T(0);\n        if (it->first <= l\
    \ && l <= it->second + 1) {\n            l = it->first;\n            dcnt += it->second\
    \ - it->first + 1;\n            it = s.erase(it);\n        } else ++it;\n    \
    \    while (r > it->second) {\n            dcnt += it->second - it->first + 1;\n\
    \            it = s.erase(it);\n        }\n        if (it->first - 1 <= r && r\
    \ <= it->second) {\n            dcnt += it->second - it->first + 1;\n        \
    \    r = it->second;\n            s.erase(it);\n        }\n        s.emplace(l,\
    \ r);\n        sz += r - l + 1 - dcnt;\n        return sz > 0;\n    }\n    bool\
    \ erase(T x) { return erase(x, x + 1); }\n    bool erase(T l, T r) {\n       \
    \ assert(l <= --r);\n        auto it = prev(s.lower_bound({l + 1, l + 1}));\n\
    \        if (it->first <= l and r <= it->second) {\n            if (it->first\
    \ < l) s.emplace(it->first, l - 1);\n            if (r < it->second) s.emplace(r\
    \ + 1, it->second);\n            s.erase(it);\n            return r - l + 1;\n\
    \        }\n\n        T cnt = T(0);\n        if (it->first <= l and l <= it->second)\
    \ {\n            cnt += it->second - l + 1;\n            if (it->first < l) s.emplace(it->first,\
    \ l - 1);\n            it = s.erase(it);\n        } else ++it;\n        while\
    \ (it->second <= r) {\n            cnt += it->second - it->first + 1;\n      \
    \      it = s.erase(it);\n        }\n        if (it->first <= r and r <= it->second)\
    \ {\n            cnt += r - it->first + 1;\n            if (r < it->second) s.emplace(r\
    \ + 1, it->second);\n            s.erase(it);\n        }\n        sz -= cnt;\n\
    \        return cnt > 0;\n    }\n    bool contains(T x) {\n        auto [l, r]\
    \ = *prev(s.lower_bound({x + 1, x + 1}));\n        return l <= x && x <= r;\n\
    \    }\n    T size() { return sz; }\n\n    std::set<std::pair<T, T>> segments()\
    \ const {\n        auto ret = s;\n        ret.erase(ret.begin());\n        ret.erase(prev(ret.end()));\n\
    \        for (auto& [l, r] : ret) ++r;\n        return ret;\n    }\n\n    T mex(T\
    \ x = 0) const {\n        auto [l, r] = *prev(s.lower_bound({x + 1, x + 1}));\n\
    \        if (l <= x && x <= r) return r + 1;\n        else return x;\n    }\n\
    };\n/*\n * @brief segset\n * @docs docs/segset.md\n */\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <cassert>\n#include <set>\n\
    \ntemplate <class T> struct segset {\n   private:\n    std::set<std::pair<T, T>>\
    \ s;\n    T sz;\n    const T INF = std::numeric_limits<T>::max() / 2;\n\n   public:\n\
    \    segset() : sz(T(0)) {\n        s.emplace(-INF, -INF);\n        s.emplace(INF,\
    \ INF);\n    }\n\n    bool insert(T x) { return insert(x, x + 1); }\n    bool\
    \ insert(T l, T r) {\n        assert(l <= --r);\n        auto it = prev(s.lower_bound({l\
    \ + 1, l + 1}));\n        if (it->first <= l && r <= it->second) return T(0);\n\
    \        T dcnt = T(0);\n        if (it->first <= l && l <= it->second + 1) {\n\
    \            l = it->first;\n            dcnt += it->second - it->first + 1;\n\
    \            it = s.erase(it);\n        } else ++it;\n        while (r > it->second)\
    \ {\n            dcnt += it->second - it->first + 1;\n            it = s.erase(it);\n\
    \        }\n        if (it->first - 1 <= r && r <= it->second) {\n           \
    \ dcnt += it->second - it->first + 1;\n            r = it->second;\n         \
    \   s.erase(it);\n        }\n        s.emplace(l, r);\n        sz += r - l + 1\
    \ - dcnt;\n        return sz > 0;\n    }\n    bool erase(T x) { return erase(x,\
    \ x + 1); }\n    bool erase(T l, T r) {\n        assert(l <= --r);\n        auto\
    \ it = prev(s.lower_bound({l + 1, l + 1}));\n        if (it->first <= l and r\
    \ <= it->second) {\n            if (it->first < l) s.emplace(it->first, l - 1);\n\
    \            if (r < it->second) s.emplace(r + 1, it->second);\n            s.erase(it);\n\
    \            return r - l + 1;\n        }\n\n        T cnt = T(0);\n        if\
    \ (it->first <= l and l <= it->second) {\n            cnt += it->second - l +\
    \ 1;\n            if (it->first < l) s.emplace(it->first, l - 1);\n          \
    \  it = s.erase(it);\n        } else ++it;\n        while (it->second <= r) {\n\
    \            cnt += it->second - it->first + 1;\n            it = s.erase(it);\n\
    \        }\n        if (it->first <= r and r <= it->second) {\n            cnt\
    \ += r - it->first + 1;\n            if (r < it->second) s.emplace(r + 1, it->second);\n\
    \            s.erase(it);\n        }\n        sz -= cnt;\n        return cnt >\
    \ 0;\n    }\n    bool contains(T x) {\n        auto [l, r] = *prev(s.lower_bound({x\
    \ + 1, x + 1}));\n        return l <= x && x <= r;\n    }\n    T size() { return\
    \ sz; }\n\n    std::set<std::pair<T, T>> segments() const {\n        auto ret\
    \ = s;\n        ret.erase(ret.begin());\n        ret.erase(prev(ret.end()));\n\
    \        for (auto& [l, r] : ret) ++r;\n        return ret;\n    }\n\n    T mex(T\
    \ x = 0) const {\n        auto [l, r] = *prev(s.lower_bound({x + 1, x + 1}));\n\
    \        if (l <= x && x <= r) return r + 1;\n        else return x;\n    }\n\
    };\n/*\n * @brief segset\n * @docs docs/segset.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: segset.hpp
  requiredBy: []
  timestamp: '2024-01-02 19:52:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: segset.hpp
layout: document
redirect_from:
- /library/segset.hpp
- /library/segset.hpp.html
title: segset
---
# segset (SegmentSet)

区間をsetで管理するテク.  
区間insert/eraseができるsetを提供する.  

## コンストラクタ

```cpp
segment_set<T> st
```

- 型 $T$ のsetを作成する

**計算量**

- $O(1)$

## insert

```cpp
bool st.insert(T x)
bool st.insert(T l, T r)
```
- setに値 $x$ を挿入する
- setに半開区間 $[l, r)$ に含まれる値を全て追加する

新規に追加された値があった場合にtrueが、それ以外の場合falseが返る  

**計算量**

- ならし $O(\log(n))$

## erase

```cpp
bool st.erase(T x)
bool st.erase(T l, T r)
```
- setから値 $x$ を削除する
- setから半開区間 $[l, r)$ に含まれる値をすべて削除する

削除された値が一つでも存在する場合はtrueが、それ以外の場合falseが返る  

**計算量**

- $O(\log(n))$

## contains

```cpp
bool st.contains(T x)
```
- setに値 $x$ が含まれるか否かを判定する

**計算量**

- $O(\log(n))$

## size

```cpp
T st.size(T a)
```
- setに含まれる値の総数を返す

**計算量**

- $O(1)$

## segments

```cpp
set<pair<T,T>> un.segments()
```

- 全てのsegmentを返す
- 各セグメントは、 $pair<T,T>$ であり、半開区完 $[l, r)$ である  


**計算量**

- $O(n)$

## mex

```cpp
T st.mex(T x=0)
```

- 引数 $x$ 以上の値で、setに含まれないような最小の値(MEX)を返す

**計算量**

- $O(\log(n))$
