#pragma once

#include <algorithm>
#include <vector>

#include "lowlink.hpp"

struct bcc_graph : lowlink {
    using lk = lowlink;

   private:
    std::vector<int> used;
    std::vector<std::vector<std::pair<int, int>>> bc;
    std::vector<std::pair<int, int>> tmp;
    void dfs(int pos, int par = -1) {
        used[pos] = 1;
        for (auto &to : G[pos]) {
            if (to == par) continue;
            if (!used[to] || ord[to] < ord[pos]) {
                tmp.emplace_back(std::minmax(pos, to));
            }
            if (!used[to]) {
                dfs(to, pos);
                if (low[to] >= ord[pos]) {
                    bc.emplace_back();
                    while (1) {
                        auto [u, v] = tmp.back();
                        bc.back().emplace_back(u, v);
                        tmp.pop_back();
                        if (u == std::min(pos, to) && v == std::max(pos, to)) {
                            break;
                        }
                    }
                }
            }
        }
    }

   public:
    bcc_graph(int n) : lk(n) {}
    std::vector<std::vector<std::pair<int, int>>> bcc() {
        lk::build();
        used.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }
        return bc;
    }
};
/*
 * @brief bcc_graph (Bi-Connected Components)
 * @docs docs/bcc_graph.md
 */