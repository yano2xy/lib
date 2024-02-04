#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"

#include <bits/stdc++.h>
// clang-format off
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a<b? a=b,1:0);}
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a>b? a=b,1:0);}
using ll = long long;
// clang-format on

#include "../lib/wavelet_matrix.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    wavelet_matrix<int, false> wm(A);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r, D;
        cin >> l >> r >> D;
        r++;
        auto prev = wm.prev_value(l, r, D);
        auto next = wm.next_value(l, r, D);
        ll ans = 1001001001;
        if (prev != wm.INF) chmin(ans, abs(D - prev));
        if (next != wm.INF) chmin(ans, abs(D - next));
        cout << ans << '\n';
    }
}