#pragma once

#include <algorithm>
#include <vector>

struct lowlink {
   protected:
    int n;
    std::vector<int> used, ord, low;
    std::vector<std::vector<int>> G;
    int dfs(int pos, int k, int par = -1) {
        used[pos] = 1;
        ord[pos] = k++;
        low[pos] = ord[pos];
        bool is_articulation = false;
        int cnt = 0;
        for (auto &to : G[pos]) {
            if (!used[to]) {
                ++cnt;
                k = dfs(to, k, pos);
                low[pos] = std::min(low[pos], low[to]);
                is_articulation |= ~par && low[to] >= ord[pos];
                if (ord[pos] < low[to]) bridge.emplace_back(std::minmax(pos, (int)to));
            } else if (to != par) {
                low[pos] = std::min(low[pos], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if (is_articulation) articulation.push_back(pos);
        return k;
    }

   public:
    std::vector<int> articulation;
    std::vector<std::pair<int, int>> bridge;
    lowlink(int n) : n(n) { G.assign(n, std::vector<int>()); }
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int size() const { return n; }
    void build() {
        used.assign(n, 0);
        ord.assign(n, 0);
        low.assign(n, 0);
        int k = 0;
        for (int i = 0; i < n; i++)
            if (!used[i]) k = dfs(i, k);
    }
};
/*
 * @brief Lowlink
 * @docs docs/lowlink.md
 */