#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

struct bit_vector {
    using u32 = unsigned int;
    std::vector<std::pair<u32, u32>> dat;
    bit_vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }
    void set(int i) { dat[i >> 5].first |= u32(1) << (i & 31); }
    void build() {
        for (int i = 0; i < (int)dat.size() - 1; i++) dat[i + 1].second = dat[i].second + __builtin_popcount(dat[i].first);
    }
    int rank(int k, bool f = 1) {
        auto [a, b] = dat[k >> 5];
        int ret = b + __builtin_popcount(a & ((u32(1) << (k & 31)) - 1));
        return (f ? ret : k - ret);
    }
};

template <typename T, bool COMPRESS> struct wavelet_matrix {
    int N, lg;
    std::vector<int> mid;
    std::vector<bit_vector> bv;
    std::vector<T> key;
    bool set_log;
    std::vector<std::vector<T>> cumsum;
    T INF = std::numeric_limits<T>::max() / 2;

    wavelet_matrix() {}
    wavelet_matrix(std::vector<T> A, int log = -1) { build(A, A, log); }
    void build(std::vector<T> A, std::vector<T> SUM_data = {}, int log = -1) {
        N = (int)A.size(), lg = log, set_log = (log != -1);
        bool MAKE_SUM = !(SUM_data.empty());
        std::vector<T>& S = SUM_data;
        if (COMPRESS) {
            assert(!set_log);
            key.reserve(N);
            std::vector<int> I(N);
            std::iota(I.begin(), I.end(), 0);
            std::sort(I.begin(), I.end(), [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
            for (auto&& i : I) {
                if (key.empty() || key.back() != A[i]) key.emplace_back(A[i]);
                A[i] = (int)key.size() - 1;
            }
            key.shrink_to_fit();
        }
        if (lg == -1) lg = std::__lg(std::max<long long>(*max_element(A.begin(), A.end()), 1)) + 1;
        mid.resize(lg);
        bv.assign(lg, bit_vector(N));
        if (MAKE_SUM) cumsum.assign(1 + lg, std::vector<T>(N + 1, T(0)));
        S.resize(N);
        std::vector<T> A0(N), A1(N);
        std::vector<T> S0(N), S1(N);
        for (int d = lg - 1; d >= -1; --d) {
            int p0 = 0, p1 = 0;
            if (MAKE_SUM) {
                for (int i = 0; i < N; i++) {
                    cumsum[d + 1][i + 1] = cumsum[d + 1][i] + S[i];
                }
            }
            if (d == -1) break;
            for (int i = 0; i < N; i++) {
                bool f = (A[i] >> d & 1);
                if (!f) {
                    if (MAKE_SUM) S0[p0] = S[i];
                    A0[p0++] = A[i];
                }
                if (f) {
                    if (MAKE_SUM) S1[p1] = S[i];
                    bv[d].set(i), A1[p1++] = A[i];
                }
            }
            mid[d] = p0;
            bv[d].build();
            swap(A, A0), swap(S, S0);
            for (int i = 0; i < p1; i++) A[p0 + i] = A1[i], S[p0 + i] = S1[i];
        }
    }

    int count(int L, int R, T lower, T upper, T xor_val = 0) { return prefix_count(L, R, upper, xor_val) - prefix_count(L, R, lower, xor_val); }
    int count(std::vector<std::pair<int, int>> segments, T lower, T upper, T xor_val = 0) {
        int res = 0;
        for (auto&& [L, R] : segments) res += count(L, R, lower, upper, xor_val);
        return res;
    }

    T kth_smallest(int L, int R, int k, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        assert(0 <= k && k < R - L);
        int cnt = 0;
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (cnt + c > k) {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                cnt += c, ret |= T(1) << d;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
                if (f) L = l0, R = r0;
            }
        }
        if (COMPRESS) ret = key[ret];
        return ret;
    }
    T kth_smallest(std::vector<std::pair<int, int>> segments, int k, T xor_val = 0) {
        int total_len = 0;
        for (auto&& [L, R] : segments) total_len += R - L;
        assert(0 <= k && k < total_len);
        int cnt = 0;
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int c = 0;
            for (auto&& [L, R] : segments) {
                int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                c += (f ? (R - L) - (r0 - l0) : (r0 - l0));
            }
            if (cnt + c > k) {
                for (auto&& [L, R] : segments) {
                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                    if (!f) L = l0, R = r0;
                    if (f) L += mid[d] - l0, R += mid[d] - r0;
                }
            } else {
                cnt += c, ret |= T(1) << d;
                for (auto&& [L, R] : segments) {
                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                    if (!f) L += mid[d] - l0, R += mid[d] - r0;
                    if (f) L = l0, R = r0;
                }
            }
        }
        if (COMPRESS) ret = key[ret];
        return ret;
    }
    T kth_largest(int L, int R, int k, T xor_val = 0) { return kth_smallest(L, R, R - L - k - 1, xor_val); }
    T kth_largest(std::vector<std::pair<int, int>> segments, int k, T xor_val = 0) { return kth_smallest(segments, k, xor_val); }

    T prev_value(int L, int R, T upper) {
        int cnt = prefix_count(L, R, upper);
        return cnt == 0 ? INF : kth_smallest(L, R, cnt - 1);
    }
    T next_value(int L, int R, T lower) {
        int cnt = prefix_count(L, R, lower);
        return cnt == R - L ? INF : kth_smallest(L, R, cnt);
    }

    // xor した結果で、[L, R) の中で中央値。
    // LOWER = true：下側中央値、false：上側中央値
    T median(bool UPPER, int L, int R, T xor_val = 0) {
        int n = R - L;
        int k = (UPPER ? n / 2 : (n - 1) / 2);
        return kth_smallest(L, R, k, xor_val);
    }
    T median(bool UPPER, std::vector<std::pair<int, int>> segments, T xor_val = 0) {
        int n = 0;
        for (auto&& [L, R] : segments) n += R - L;
        int k = (UPPER ? n / 2 : (n - 1) / 2);
        return kth_smallest(segments, k, xor_val);
    }

    T sum(int L, int R, int k1, int k2, T xor_val = 0) {
        T add = prefix_sum(L, R, k2, xor_val);
        T sub = prefix_sum(L, R, k1, xor_val);
        return add - sub;
    }
    T sum_all(int L, int R) { return get(lg, L, R); }
    T sum_all(std::vector<std::pair<int, int>> segments) {
        T sm = T(0);
        for (auto&& [L, R] : segments) {
            sm = sm + get(lg, L, R);
        }
        return sm;
    }

    // check(cnt, prefix sum) が true となるような最大の (cnt, sum)
    template <typename F> std::pair<int, T> max_right(F check, int L, int R, T xor_val = 0) {
        assert(check(0, T(0)));
        if (xor_val != 0) assert(set_log);
        if (check(R - L, get(lg, L, R))) return {R - L, get(lg, L, R)};
        int cnt = 0;
        T sm = T(0);
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            T s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
            if (check(cnt + c, sm + s)) {
                cnt += c, sm = sm + s;
                if (f) L = l0, R = r0;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            }
        }
        int k = binary_search([&](int k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0, R - L);
        cnt += k;
        sm = sm + get(0, L, L + k);
        return {cnt, sm};
    }

   private:
    inline T get(int d, int L, int R) {
        assert(!cumsum.empty());
        return cumsum[d][R] - cumsum[d][L];
    }

    int prefix_count(int L, int R, T x, T xor_val = 0) {
        if (xor_val != 0) assert(set_log);
        x = (COMPRESS ? distance(key.begin(), lower_bound(key.begin(), key.end(), x)) : x);
        if (x == 0) return 0;
        if (x >= (1 << lg)) return R - L;
        int cnt = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool add = (x >> d) & 1;
            bool f = ((xor_val) >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int kf = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (add) {
                cnt += kf;
                if (f) {
                    L = l0, R = r0;
                }
                if (!f) {
                    L += mid[d] - l0, R += mid[d] - r0;
                }
            } else {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            }
        }
        return cnt;
    }
    std::pair<T, T> kth_value_and_sum(int L, int R, int k, T xor_val = 0) {
        assert(!cumsum.empty());
        if (xor_val != 0) assert(set_log);
        assert(0 <= k && k <= R - L);
        if (k == R - L) {
            return {INF, sum_all(L, R)};
        }
        int cnt = 0;
        T sm = T(0);
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
            int c = (f ? (R - L) - (r0 - l0) : (r0 - l0));
            if (cnt + c > k) {
                if (!f) L = l0, R = r0;
                if (f) L += mid[d] - l0, R += mid[d] - r0;
            } else {
                T s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
                cnt += c, ret |= T(1) << d, sm = sm + s;
                if (!f) L += mid[d] - l0, R += mid[d] - r0;
                if (f) L = l0, R = r0;
            }
        }
        sm = sm + get(0, L, L + k - cnt);
        if (COMPRESS) ret = key[ret];
        return {ret, sm};
    }
    std::pair<T, T> kth_value_and_sum(std::vector<std::pair<int, int>> segments, int k, T xor_val = 0) {
        assert(!cumsum.empty());
        if (xor_val != 0) assert(set_log);
        int total_len = 0;
        for (auto&& [L, R] : segments) total_len += R - L;
        assert(0 <= k && k <= total_len);
        if (k == total_len) {
            return {INF, sum_all(segments)};
        }
        int cnt = 0;
        T sm = T(0);
        T ret = 0;
        for (int d = lg - 1; d >= 0; --d) {
            bool f = (xor_val >> d) & 1;
            int c = 0;
            for (auto&& [L, R] : segments) {
                int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                c += (f ? (R - L) - (r0 - l0) : (r0 - l0));
            }
            if (cnt + c > k) {
                for (auto&& [L, R] : segments) {
                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                    if (!f) L = l0, R = r0;
                    if (f) L += mid[d] - l0, R += mid[d] - r0;
                }
            } else {
                cnt += c, ret |= T(1) << d;
                for (auto&& [L, R] : segments) {
                    int l0 = bv[d].rank(L, 0), r0 = bv[d].rank(R, 0);
                    T s = (f ? get(d, L + mid[d] - l0, R + mid[d] - r0) : get(d, l0, r0));
                    sm = sm + s;
                    if (!f) L += mid[d] - l0, R += mid[d] - r0;
                    if (f) L = l0, R = r0;
                }
            }
        }
        for (auto&& [L, R] : segments) {
            int t = std::min(R - L, k - cnt);
            sm = sm + get(0, L, L + t);
            cnt += t;
        }
        if (COMPRESS) ret = key[ret];
        return {ret, sm};
    }
    T prefix_sum(int L, int R, int k, T xor_val = 0) { return kth_value_and_sum(L, R, k, xor_val).second; }
    T prefix_sum(std::vector<std::pair<int, int>> segments, int k, T xor_val = 0) { return kth_value_and_sum(segments, k, xor_val).second; }
};
/*
 * @brief wavelet matrix
 * @docs docs/wavelet_matrix.md
 */
