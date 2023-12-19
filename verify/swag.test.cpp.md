---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: swag.hpp
    title: SWAG (Sliding Window Aggregation)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"verify/swag.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    #line 2 \"swag.hpp\"\n\n#line 6 \"swag.hpp\"\n\ntemplate <class T, T (*op)(T,\
    \ T), T (*e)()>\nstruct swag {\n    struct prod_stack {\n        bool left;\n\
    \        std::stack<T> st, prd;\n        prod_stack() : left(false) {}\n     \
    \   prod_stack(bool left) : left(left) {}\n        void push(T x) {\n        \
    \    T p = prod();\n            st.push(x);\n            if (left) prd.push(op(x,\
    \ p));\n            else prd.push(op(p, x));\n        }\n        void pop() {\n\
    \            assert(!empty());\n            st.pop(), prd.pop();\n        }\n\
    \        T top() {\n            assert(!empty());\n            return st.top();\n\
    \        }\n        T prod() { return empty() ? e() : prd.top(); }\n        int\
    \ size() { return prd.size(); }\n        bool empty() { return prd.empty(); }\n\
    \    };\n\n    prod_stack front_st, back_st;\n    swag() : front_st(true), back_st(false)\
    \ {}\n    void push(T x) { back_st.push(x); }\n    void balance() {\n        while\
    \ (!back_st.empty()) {\n            front_st.push(back_st.top());\n          \
    \  back_st.pop();\n        }\n    }\n    void pop() {\n        assert(!empty());\n\
    \        if (front_st.empty()) balance();\n        front_st.pop();\n    }\n  \
    \  void front() {\n        assert(!empty());\n        if (front_st.empty()) balance();\n\
    \        return front_st.top();\n    }\n    T prod() { return op(front_st.prod(),\
    \ back_st.prod()); }\n    int size() { return front_st.size() + back_st.size();\
    \ }\n    bool empty() { return size() == 0; }\n};\n/*\n * @brief SWAG (Sliding\
    \ Window Aggregation)\n * @docs docs/swag.md\n */\n#line 8 \"verify/swag.test.cpp\"\
    \n\nint mod = 998244353;\n\nstruct F {\n    ll a, b;\n    F() : a(1), b(0) {}\n\
    \    F(ll a, ll b) : a(a), b(b) {}\n};\n\nF op(F f, F g) {\n    return F(f.a *\
    \ g.a % mod, ((g.a * f.b) % mod + g.b) % mod);\n}\nF e() {\n    return F();\n\
    }\n\nint main() {\n    int Q;\n    cin >> Q;\n    swag<F, op, e> sw;\n    while\
    \ (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    ll a, b;\n            cin >> a >> b;\n            sw.push(F(a, b));\n   \
    \     }\n        if (t == 1) {\n            sw.pop();\n        }\n        if (t\
    \ == 2) {\n            ll x;\n            cin >> x;\n            auto f = sw.prod();\n\
    \            ll ans = (f.a * x % mod + f.b) % mod;\n            cout << ans <<\
    \ '\\n';\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    #include \"../lib/swag.hpp\"\n\nint mod = 998244353;\n\nstruct F {\n    ll a,\
    \ b;\n    F() : a(1), b(0) {}\n    F(ll a, ll b) : a(a), b(b) {}\n};\n\nF op(F\
    \ f, F g) {\n    return F(f.a * g.a % mod, ((g.a * f.b) % mod + g.b) % mod);\n\
    }\nF e() {\n    return F();\n}\n\nint main() {\n    int Q;\n    cin >> Q;\n  \
    \  swag<F, op, e> sw;\n    while (Q--) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            ll a, b;\n            cin >> a >> b;\n   \
    \         sw.push(F(a, b));\n        }\n        if (t == 1) {\n            sw.pop();\n\
    \        }\n        if (t == 2) {\n            ll x;\n            cin >> x;\n\
    \            auto f = sw.prod();\n            ll ans = (f.a * x % mod + f.b) %\
    \ mod;\n            cout << ans << '\\n';\n        }\n    }\n\n    return 0;\n\
    }\n"
  dependsOn:
  - swag.hpp
  isVerificationFile: true
  path: verify/swag.test.cpp
  requiredBy: []
  timestamp: '2023-12-20 00:00:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/swag.test.cpp
layout: document
redirect_from:
- /verify/verify/swag.test.cpp
- /verify/verify/swag.test.cpp.html
title: verify/swag.test.cpp
---
