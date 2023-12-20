#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include "../lib/segtree_2d.hpp"

#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

ll op(ll a, ll b) {
    return min(a, b);
}
ll INF = 1e18;
ll e() {
    return INF;
}

int main() {
    while (true) {
        int r, c, Q;
        cin >> r >> c >> Q;
        if (r == 0) return 0;

        // vector A(r, vector<ll>(c, INF));
        //  rep(i, r) rep(j, c) cin >> A[i][j];
        // segtree_2d<ll, op, e> seg(A);
        segtree_2d<ll, op, e> seg(r, c);
        rep(i, r) rep(j, c) {
            ll a;
            cin >> a;
            seg.set(i, j, a);
        }

        while (Q--) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            h2++, w2++;
            cout << seg.prod(h1, w1, h2, w2) << '\n';
        }
    }
    return 0;
}