#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include "../lib/swag.hpp"

int mod = 998244353;

struct F {
    ll a, b;
    F() : a(1), b(0) {}
    F(ll a, ll b) : a(a), b(b) {}
};

F op(F f, F g) {
    return F(f.a * g.a % mod, ((g.a * f.b) % mod + g.b) % mod);
}
F e() {
    return F();
}

int main() {
    int Q;
    cin >> Q;
    swag<F, op, e> sw;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            sw.push(F(a, b));
        }
        if (t == 1) {
            sw.pop();
        }
        if (t == 2) {
            ll x;
            cin >> x;
            auto f = sw.prod();
            ll ans = (f.a * x % mod + f.b) % mod;
            cout << ans << '\n';
        }
    }

    return 0;
}
