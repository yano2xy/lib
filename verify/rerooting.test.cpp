#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <bits/stdc++.h>
using namespace std;

#include "../rerooting.hpp"

int main() {
    int n;
    cin >> n;
    map<pair<int, int>, int> es;

    auto f = [&](int x, int pos, int par) -> int { return x + es[{pos, par}]; };
    auto merge = [&](int x, int y) -> int { return max(x, y); };
    auto g = [&](int x, int pos) -> int { return x; };
    auto id = [&]() { return 0; };
    rerooting<int> G(n, f, merge, g, id);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G.add_edge(a, b);
        es[{a, b}] = w;
        es[{b, a}] = w;
    }

    auto V = G.solve();
    for (auto v : V)
        cout << v << '\n';
}