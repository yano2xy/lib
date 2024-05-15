#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include <bits/stdc++.h>
using namespace std;

#include "../chromatic_number.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    Graph<int> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G.add_edge(a, b);
    }
    cout << chromatic_number(G) << '\n';
    return 0;
}