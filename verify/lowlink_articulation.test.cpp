#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <bits/stdc++.h>
using namespace std;

#include "../lowlink.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    lowlink G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G.add_edge(s, t);
    }
    G.build();
    sort(G.articulation.begin(), G.articulation.end());
    for (auto v : G.articulation) cout << v << '\n';
    return 0;
}
