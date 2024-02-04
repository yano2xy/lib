---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: wavelet_matrix.hpp
    title: wavelet matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
  bundledCode: "#line 1 \"verify/wavelet_matrix_prev_next_value.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\n\
    \n#include <bits/stdc++.h>\n// clang-format off\nusing namespace std;\n#define\
    \ rep(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T,class S> inline bool\
    \ chmax(T &a,const S &b) {return (a<b? a=b,1:0);}\ntemplate <class T,class S>\
    \ inline bool chmin(T &a,const S &b) {return (a>b? a=b,1:0);}\nusing ll = long\
    \ long;\n// clang-format on\n\n#line 5 \"wavelet_matrix.hpp\"\n\nstruct bit_vector\
    \ {\n    using u32 = unsigned int;\n    std::vector<std::pair<u32, u32>> dat;\n\
    \    bit_vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n    void set(int\
    \ i) { dat[i >> 5].first |= u32(1) << (i & 31); }\n    void build() {\n      \
    \  for (int i = 0; i < (int)dat.size() - 1; i++) dat[i + 1].second = dat[i].second\
    \ + __builtin_popcount(dat[i].first);\n    }\n    int rank(int k, bool f = 1)\
    \ {\n        auto [a, b] = dat[k >> 5];\n        int ret = b + __builtin_popcount(a\
    \ & ((u32(1) << (k & 31)) - 1));\n        return (f ? ret : k - ret);\n    }\n\
    };\n\ntemplate <typename T, bool COMPRESS> struct wavelet_matrix {\n    int N,\
    \ lg;\n    std::vector<int> mid;\n    std::vector<bit_vector> bv;\n    std::vector<T>\
    \ key;\n    bool set_log;\n    std::vector<std::vector<T>> cumsum;\n    T INF\
    \ = std::numeric_limits<T>::max() / 2;\n\n    wavelet_matrix() {}\n    wavelet_matrix(std::vector<T>\
    \ A, int log = -1) { build(A, A, log); }\n    void build(std::vector<T> A, std::vector<T>\
    \ SUM_data = {}, int log = -1) {\n        N = (int)A.size(), lg = log, set_log\
    \ = (log != -1);\n        bool MAKE_SUM = !(SUM_data.empty());\n        std::vector<T>&\
    \ S = SUM_data;\n        if (COMPRESS) {\n            assert(!set_log);\n    \
    \        key.reserve(N);\n            std::vector<int> I(N);\n            std::iota(I.begin(),\
    \ I.end(), 0);\n            std::sort(I.begin(), I.end(), [&](int i, int j) {\
    \ return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n            for (auto&& i\
    \ : I) {\n                if (key.empty() || key.back() != A[i]) key.emplace_back(A[i]);\n\
    \                A[i] = (int)key.size() - 1;\n            }\n            key.shrink_to_fit();\n\
    \        }\n        if (lg == -1) lg = std::__lg(std::max<long long>(*max_element(A.begin(),\
    \ A.end()), 1)) + 1;\n        mid.resize(lg);\n        bv.assign(lg, bit_vector(N));\n\
    \        if (MAKE_SUM) cumsum.assign(1 + lg, std::vector<T>(N + 1, T(0)));\n \
    \       S.resize(N);\n        std::vector<T> A0(N), A1(N);\n        std::vector<T>\
    \ S0(N), S1(N);\n        for (int d = lg - 1; d >= -1; --d) {\n            int\
    \ p0 = 0, p1 = 0;\n            if (MAKE_SUM) {\n                for (int i = 0;\
    \ i < N; i++) {\n                    cumsum[d + 1][i + 1] = cumsum[d + 1][i] +\
    \ S[i];\n                }\n            }\n            if (d == -1) break;\n \
    \           for (int i = 0; i < N; i++) {\n                bool f = (A[i] >> d\
    \ & 1);\n                if (!f) {\n                    if (MAKE_SUM) S0[p0] =\
    \ S[i];\n                    A0[p0++] = A[i];\n                }\n           \
    \     if (f) {\n                    if (MAKE_SUM) S1[p1] = S[i];\n           \
    \         bv[d].set(i), A1[p1++] = A[i];\n                }\n            }\n \
    \           mid[d] = p0;\n            bv[d].build();\n            swap(A, A0),\
    \ swap(S, S0);\n            for (int i = 0; i < p1; i++) A[p0 + i] = A1[i], S[p0\
    \ + i] = S1[i];\n        }\n    }\n\n    int count(int L, int R, T lower, T upper,\
    \ T xor_val = 0) { return prefix_count(L, R, upper, xor_val) - prefix_count(L,\
    \ R, lower, xor_val); }\n    int count(std::vector<std::pair<int, int>> segments,\
    \ T lower, T upper, T xor_val = 0) {\n        int res = 0;\n        for (auto&&\
    \ [L, R] : segments) res += count(L, R, lower, upper, xor_val);\n        return\
    \ res;\n    }\n\n    T kth_smallest(int L, int R, int k, T xor_val = 0) {\n  \
    \      if (xor_val != 0) assert(set_log);\n        assert(0 <= k && k < R - L);\n\
    \        int cnt = 0;\n        T ret = 0;\n        for (int d = lg - 1; d >= 0;\
    \ --d) {\n            bool f = (xor_val >> d) & 1;\n            int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n            int c = (f ? (R - L) - (r0 - l0) : (r0\
    \ - l0));\n            if (cnt + c > k) {\n                if (!f) L = l0, R =\
    \ r0;\n                if (f) L += mid[d] - l0, R += mid[d] - r0;\n          \
    \  } else {\n                cnt += c, ret |= T(1) << d;\n                if (!f)\
    \ L += mid[d] - l0, R += mid[d] - r0;\n                if (f) L = l0, R = r0;\n\
    \            }\n        }\n        if (COMPRESS) ret = key[ret];\n        return\
    \ ret;\n    }\n    T kth_smallest(std::vector<std::pair<int, int>> segments, int\
    \ k, T xor_val = 0) {\n        int total_len = 0;\n        for (auto&& [L, R]\
    \ : segments) total_len += R - L;\n        assert(0 <= k && k < total_len);\n\
    \        int cnt = 0;\n        T ret = 0;\n        for (int d = lg - 1; d >= 0;\
    \ --d) {\n            bool f = (xor_val >> d) & 1;\n            int c = 0;\n \
    \           for (auto&& [L, R] : segments) {\n                int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n                c += (f ? (R - L) - (r0 - l0) :\
    \ (r0 - l0));\n            }\n            if (cnt + c > k) {\n               \
    \ for (auto&& [L, R] : segments) {\n                    int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n                    if (!f) L = l0, R = r0;\n  \
    \                  if (f) L += mid[d] - l0, R += mid[d] - r0;\n              \
    \  }\n            } else {\n                cnt += c, ret |= T(1) << d;\n    \
    \            for (auto&& [L, R] : segments) {\n                    int l0 = bv[d].rank(L,\
    \ 0), r0 = bv[d].rank(R, 0);\n                    if (!f) L += mid[d] - l0, R\
    \ += mid[d] - r0;\n                    if (f) L = l0, R = r0;\n              \
    \  }\n            }\n        }\n        if (COMPRESS) ret = key[ret];\n      \
    \  return ret;\n    }\n    T kth_largest(int L, int R, int k, T xor_val = 0) {\
    \ return kth_smallest(L, R, R - L - k - 1, xor_val); }\n    T kth_largest(std::vector<std::pair<int,\
    \ int>> segments, int k, T xor_val = 0) { return kth_smallest(segments, k, xor_val);\
    \ }\n\n    T prev_value(int L, int R, T upper) {\n        int cnt = prefix_count(L,\
    \ R, upper);\n        return cnt == 0 ? INF : kth_smallest(L, R, cnt - 1);\n \
    \   }\n    T next_value(int L, int R, T lower) {\n        int cnt = prefix_count(L,\
    \ R, lower);\n        return cnt == R - L ? INF : kth_smallest(L, R, cnt);\n \
    \   }\n\n    // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067\
    \u4E2D\u592E\u5024\u3002\n    // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\u592E\u5024\
    \u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n    T median(bool UPPER, int\
    \ L, int R, T xor_val = 0) {\n        int n = R - L;\n        int k = (UPPER ?\
    \ n / 2 : (n - 1) / 2);\n        return kth_smallest(L, R, k, xor_val);\n    }\n\
    \    T median(bool UPPER, std::vector<std::pair<int, int>> segments, T xor_val\
    \ = 0) {\n        int n = 0;\n        for (auto&& [L, R] : segments) n += R -\
    \ L;\n        int k = (UPPER ? n / 2 : (n - 1) / 2);\n        return kth_smallest(segments,\
    \ k, xor_val);\n    }\n\n    T sum(int L, int R, int k1, int k2, T xor_val = 0)\
    \ {\n        T add = prefix_sum(L, R, k2, xor_val);\n        T sub = prefix_sum(L,\
    \ R, k1, xor_val);\n        return add - sub;\n    }\n    T sum_all(int L, int\
    \ R) { return get(lg, L, R); }\n    T sum_all(std::vector<std::pair<int, int>>\
    \ segments) {\n        T sm = T(0);\n        for (auto&& [L, R] : segments) {\n\
    \            sm = sm + get(lg, L, R);\n        }\n        return sm;\n    }\n\n\
    \    // check(cnt, prefix sum) \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\
    \u6700\u5927\u306E (cnt, sum)\n    template <typename F> std::pair<int, T> max_right(F\
    \ check, int L, int R, T xor_val = 0) {\n        assert(check(0, T(0)));\n   \
    \     if (xor_val != 0) assert(set_log);\n        if (check(R - L, get(lg, L,\
    \ R))) return {R - L, get(lg, L, R)};\n        int cnt = 0;\n        T sm = T(0);\n\
    \        for (int d = lg - 1; d >= 0; --d) {\n            bool f = (xor_val >>\
    \ d) & 1;\n            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n   \
    \         int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n            T s = (f\
    \ ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));\n            if\
    \ (check(cnt + c, sm + s)) {\n                cnt += c, sm = sm + s;\n       \
    \         if (f) L = l0, R = r0;\n                if (!f) L += mid[d] - l0, R\
    \ += mid[d] - r0;\n            } else {\n                if (!f) L = l0, R = r0;\n\
    \                if (f) L += mid[d] - l0, R += mid[d] - r0;\n            }\n \
    \       }\n        int k = binary_search([&](int k) -> bool { return check(cnt\
    \ + k, sm + get(0, L, L + k)); }, 0, R - L);\n        cnt += k;\n        sm =\
    \ sm + get(0, L, L + k);\n        return {cnt, sm};\n    }\n\n   private:\n  \
    \  inline T get(int d, int L, int R) {\n        assert(!cumsum.empty());\n   \
    \     return cumsum[d][R] - cumsum[d][L];\n    }\n\n    int prefix_count(int L,\
    \ int R, T x, T xor_val = 0) {\n        if (xor_val != 0) assert(set_log);\n \
    \       x = (COMPRESS ? distance(key.begin(), lower_bound(key.begin(), key.end(),\
    \ x)) : x);\n        if (x == 0) return 0;\n        if (x >= (1 << lg)) return\
    \ R - L;\n        int cnt = 0;\n        for (int d = lg - 1; d >= 0; --d) {\n\
    \            bool add = (x >> d) & 1;\n            bool f = ((xor_val) >> d) &\
    \ 1;\n            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n        \
    \    int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));\n            if (add) {\n\
    \                cnt += kf;\n                if (f) {\n                    L =\
    \ l0, R = r0;\n                }\n                if (!f) {\n                \
    \    L += mid[d] - l0, R += mid[d] - r0;\n                }\n            } else\
    \ {\n                if (!f) L = l0, R = r0;\n                if (f) L += mid[d]\
    \ - l0, R += mid[d] - r0;\n            }\n        }\n        return cnt;\n   \
    \ }\n    std::pair<T, T> kth_value_and_sum(int L, int R, int k, T xor_val = 0)\
    \ {\n        assert(!cumsum.empty());\n        if (xor_val != 0) assert(set_log);\n\
    \        assert(0 <= k && k <= R - L);\n        if (k == R - L) {\n          \
    \  return {INF, sum_all(L, R)};\n        }\n        int cnt = 0;\n        T sm\
    \ = T(0);\n        T ret = 0;\n        for (int d = lg - 1; d >= 0; --d) {\n \
    \           bool f = (xor_val >> d) & 1;\n            int l0 = bv[d].rank(L, 0),\
    \ r0 = bv[d].rank(R, 0);\n            int c = (f ? (R - L) - (r0 - l0) : (r0 -\
    \ l0));\n            if (cnt + c > k) {\n                if (!f) L = l0, R = r0;\n\
    \                if (f) L += mid[d] - l0, R += mid[d] - r0;\n            } else\
    \ {\n                T s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d,\
    \ l0, r0));\n                cnt += c, ret |= T(1) << d, sm = sm + s;\n      \
    \          if (!f) L += mid[d] - l0, R += mid[d] - r0;\n                if (f)\
    \ L = l0, R = r0;\n            }\n        }\n        sm = sm + get(0, L, L + k\
    \ - cnt);\n        if (COMPRESS) ret = key[ret];\n        return {ret, sm};\n\
    \    }\n    std::pair<T, T> kth_value_and_sum(std::vector<std::pair<int, int>>\
    \ segments, int k, T xor_val = 0) {\n        assert(!cumsum.empty());\n      \
    \  if (xor_val != 0) assert(set_log);\n        int total_len = 0;\n        for\
    \ (auto&& [L, R] : segments) total_len += R - L;\n        assert(0 <= k && k <=\
    \ total_len);\n        if (k == total_len) {\n            return {INF, sum_all(segments)};\n\
    \        }\n        int cnt = 0;\n        T sm = T(0);\n        T ret = 0;\n \
    \       for (int d = lg - 1; d >= 0; --d) {\n            bool f = (xor_val >>\
    \ d) & 1;\n            int c = 0;\n            for (auto&& [L, R] : segments)\
    \ {\n                int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n     \
    \           c += (f ? (R - L) - (r0 - l0) : (r0 - l0));\n            }\n     \
    \       if (cnt + c > k) {\n                for (auto&& [L, R] : segments) {\n\
    \                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n     \
    \               if (!f) L = l0, R = r0;\n                    if (f) L += mid[d]\
    \ - l0, R += mid[d] - r0;\n                }\n            } else {\n         \
    \       cnt += c, ret |= T(1) << d;\n                for (auto&& [L, R] : segments)\
    \ {\n                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);\n \
    \                   T s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d,\
    \ l0, r0));\n                    sm = sm + s;\n                    if (!f) L +=\
    \ mid[d] - l0, R += mid[d] - r0;\n                    if (f) L = l0, R = r0;\n\
    \                }\n            }\n        }\n        for (auto&& [L, R] : segments)\
    \ {\n            int t = std::min(R - L, k - cnt);\n            sm = sm + get(0,\
    \ L, L + t);\n            cnt += t;\n        }\n        if (COMPRESS) ret = key[ret];\n\
    \        return {ret, sm};\n    }\n    T prefix_sum(int L, int R, int k, T xor_val\
    \ = 0) { return kth_value_and_sum(L, R, k, xor_val).second; }\n    T prefix_sum(std::vector<std::pair<int,\
    \ int>> segments, int k, T xor_val = 0) { return kth_value_and_sum(segments, k,\
    \ xor_val).second; }\n};\n/*\n * @brief wavelet matrix\n * @docs docs/wavelet_matrix.md\n\
    \ */\n#line 13 \"verify/wavelet_matrix_prev_next_value.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vector<int> A(n);\n    rep(i, n) cin >> A[i];\n\
    \    wavelet_matrix<int, false> wm(A);\n    int Q;\n    cin >> Q;\n    while (Q--)\
    \ {\n        int l, r, D;\n        cin >> l >> r >> D;\n        r++;\n       \
    \ auto prev = wm.prev_value(l, r, D);\n        auto next = wm.next_value(l, r,\
    \ D);\n        ll ans = 1001001001;\n        if (prev != wm.INF) chmin(ans, abs(D\
    \ - prev));\n        if (next != wm.INF) chmin(ans, abs(D - next));\n        cout\
    \ << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n\n#include <bits/stdc++.h>\n// clang-format off\nusing namespace std;\n#define\
    \ rep(i, n) for (int i = 0; i < (n); i++)\ntemplate <class T,class S> inline bool\
    \ chmax(T &a,const S &b) {return (a<b? a=b,1:0);}\ntemplate <class T,class S>\
    \ inline bool chmin(T &a,const S &b) {return (a>b? a=b,1:0);}\nusing ll = long\
    \ long;\n// clang-format on\n\n#include \"../lib/wavelet_matrix.hpp\"\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vector<int> A(n);\n    rep(i, n) cin >> A[i];\n\
    \    wavelet_matrix<int, false> wm(A);\n    int Q;\n    cin >> Q;\n    while (Q--)\
    \ {\n        int l, r, D;\n        cin >> l >> r >> D;\n        r++;\n       \
    \ auto prev = wm.prev_value(l, r, D);\n        auto next = wm.next_value(l, r,\
    \ D);\n        ll ans = 1001001001;\n        if (prev != wm.INF) chmin(ans, abs(D\
    \ - prev));\n        if (next != wm.INF) chmin(ans, abs(D - next));\n        cout\
    \ << ans << '\\n';\n    }\n}"
  dependsOn:
  - wavelet_matrix.hpp
  isVerificationFile: true
  path: verify/wavelet_matrix_prev_next_value.test.cpp
  requiredBy: []
  timestamp: '2024-02-04 23:21:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/wavelet_matrix_prev_next_value.test.cpp
layout: document
redirect_from:
- /verify/verify/wavelet_matrix_prev_next_value.test.cpp
- /verify/verify/wavelet_matrix_prev_next_value.test.cpp.html
title: verify/wavelet_matrix_prev_next_value.test.cpp
---
