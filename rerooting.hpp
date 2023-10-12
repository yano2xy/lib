#pragma once

#include <functional>
#include <vector>

template <typename S>
struct rerooting {
   private:
    int n;
    std::vector<std::vector<int>> G;
    std::vector<std::vector<S>> dp;
    using TF = std::function<S(S, int, int)>;
    using TM = std::function<S(S, S)>;
    using TG = std::function<S(S, int)>;
    using Id = std::function<S()>;
    TF f;
    TM merge;
    TG g;
    Id id;

    S dfs1(int pos, int par) {
        S val = id();
        for (int i = 0; i < G[pos].size(); ++i) {
            if (G[pos][i] == par) continue;
            dp[pos][i] = dfs1(G[pos][i], pos);
            val = merge(val, f(dp[pos][i], G[pos][i], pos));
        }
        return g(val, pos);
    }

    void dfs2(int pos, int par, S dp_par) {
        for (int i = 0; i < G[pos].size(); ++i) {
            if (G[pos][i] == par) {
                dp[pos][i] = dp_par;
                break;
            }
        }
        std::vector<S> pR(G[pos].size() + 1, id());
        for (int i = G[pos].size(); i > 0; --i)
            pR[i - 1] = merge(pR[i], f(dp[pos][i - 1], G[pos][i - 1], pos));
        S pL = id();
        for (int i = 0; i < G[pos].size(); ++i) {
            if (G[pos][i] != par) {
                S val = merge(pL, pR[i + 1]);
                dfs2(G[pos][i], pos, g(val, pos));
            }
            pL = merge(pL, f(dp[pos][i], G[pos][i], pos));
        }
    }

   public:
    rerooting(int n, TF f, TM merge, TG g, Id id) : n(n), f(f), merge(merge), g(g), id(id) {
        G.resize(n);
        dp.resize(n);
    }

    void add_edge(int a, int b) {
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    std::vector<S> solve() {
        std::vector<S> ret(n);
        for (int i = 0; i < n; ++i)
            dp[i].resize(G[i].size());
        dfs1(0, -1);
        dfs2(0, -1, id());
        for (int i = 0; i < n; ++i) {
            S v = id();
            for (int j = 0; j < G[i].size(); ++j) {
                v = merge(v, f(dp[i][j], G[i][j], i));
            }
            ret[i] = g(v, i);
        }
        return ret;
    }
};
/*
 * @brief rerooting
 * @docs docs/rerooting.md
 */