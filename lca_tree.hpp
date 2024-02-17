#include <cassert>
#include <vector>

#include "graph.hpp"
template <typename T = long long> struct lca_tree : Graph<T> {
   private:
    int n, K;
    std::vector<std::vector<int>> parent;  // parent[v][k] := v の 2^k 先の親
    std::vector<int> depth;                // root からの距離
    std::vector<T> cost;                   // root からのコスト

    void dfs(int pos, int par, int d, T c) {
        if (par != -1) parent[pos][0] = par;
        depth[pos] = d;
        cost[pos] = c;
        for (auto edge : this->_graph[pos]) {
            if (edge.to == par) continue;
            dfs(edge.to, pos, d + 1, c + edge.cost);
        }
    }

   public:
    lca_tree(int n) : n(n), Graph<T>(n) {}
    void build(int root = 0) {
        K = 0;
        while ((1 << K) < n) K++;
        parent.assign(n + 1, std::vector<int>(K, n));
        depth.assign(n, -1);
        cost.assign(n, -1);
        dfs(root, -1, 0, 0);
        for (int i = 0; i < K - 1; ++i) {
            for (int v = 0; v < n; ++v) {
                parent[v][i + 1] = parent[parent[v][i]][i];
            }
        }
    }
    int lca(int a, int b) {
        if (depth[a] > depth[b]) std::swap(a, b);
        int diff = depth[b] - depth[a];
        for (int i = K - 1; i >= 0; i--) {
            int len = 1 << i;
            if (diff >= len) {
                diff -= len;
                b = parent[b][i];
            }
        }
        if (a == b) return a;
        for (int i = K - 1; i >= 0; i--) {
            int na = parent[a][i];
            int nb = parent[b][i];
            if (na != nb) a = na, b = nb;
        }
        return parent[a][0];
    }

    // ノード間の距離（1骨格)
    int length(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }

    // ノード間の距離（コスト）
    T dist(int a, int b) { return cost[a] + cost[b] - 2 * cost[lca(a, b)]; }
};