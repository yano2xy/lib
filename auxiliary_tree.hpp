#pragma once

#include <algorithm>
#include <stack>
#include <vector>

#include "graph.hpp"
#include "lca_tree.hpp"

struct auxiliary_tree : lca_tree<int> {
    int n;
    std::vector<int> in, out;
    auxiliary_tree(int n) : n(n), lca_tree<int>(n) {}
    void build() {
        lca_tree::build();
        in.assign(n, -1);
        out.assign(n, -1);
        int id = 0;
        auto dfs = [&](auto dfs, int pos, int par = -1) -> void {
            in[pos] = id++;
            for (auto &e : (*this)[pos]) {
                if (e.to == par) continue;
                dfs(dfs, e.to, pos);
            }
            out[pos] = id;
        };
        dfs(dfs, 0);
    };
    std::pair<int, std::vector<std::vector<int>>> generate(std::vector<int> V) {
        auto order = [&](int a, int b) { return in[a] < in[b]; };
        std::sort(V.begin(), V.end(), order);
        for (int i = 0; i < V.size() - 1; i++) V.push_back(lca(V[i], V[i + 1]));
        std::sort(V.begin(), V.end(), order);
        V.erase(unique(V.begin(), V.end()), V.end());
        std::vector<std::vector<int>> G(n);
        std::stack<int> st;
        for (int v : V) {
            while (st.size()) {
                int p = st.top();
                if (in[p] < in[v] && in[v] < out[p]) break;
                st.pop();
            }
            if (st.size()) {
                G[st.top()].push_back(v);
                G[v].push_back(st.top());
            }
            st.push(v);
        }
        return {V[0], G};
    }
};