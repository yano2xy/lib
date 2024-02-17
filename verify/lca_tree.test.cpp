#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

#include "../lca_tree.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;
    lca_tree lt(n);
    rep(i, n - 1) {
        int p;
        cin >> p;
        lt.add_edge(i + 1, p);
    }
    lt.build();
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << lt.lca(u, v) << '\n';
    }

    return 0;
}