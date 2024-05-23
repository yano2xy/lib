#include <vector>
using namespace std;

#include "graph.hpp"

template <class T> int chromatic_number(Graph<T> &G) {
    int n = (int)G.size();
    vector<int> es(n);
    for (int i = 0; i < n; i++)
        for (auto e : G[i]) es[i] |= 1 << e.to;

    vector<int> ind(1 << n);
    ind[0] = 1;
    for (int S = 1; S < (1 << n); S++) {
        int u = __builtin_ctz(S);
        ind[S] = ind[S ^ (1 << u)] + ind[(S ^ (1 << u)) & ~es[u]];
    }
    vector<int> cnt((1 << n) + 1);
    for (int i = 0; i < (1 << n); i++) {
        cnt[ind[i]] += __builtin_parity(i) ? -1 : 1;
    }
    vector<pair<unsigned, int>> hist;
    for (int i = 1; i <= (1 << n); i++) {
        if (cnt[i]) hist.emplace_back(i, cnt[i]);
    }
    constexpr int mods[] = {1000000007, 1000000103, 1000000123};
    int ret = n;
    for (int k = 0; k < 3; k++) {
        auto buf = hist;
        for (int c = 1; c < ret; c++) {
            int64_t sum = 0;
            for (auto &[i, x] : buf) {
                sum += (x = int64_t(x) * i % mods[k]);
            }
            if (sum % mods[k]) ret = c;
        }
    }
    return ret;
}
/**
 * @brief Chromatic Number (彩色数)
 * @docs docs/chromatic_number.md
 */