#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../dsu.hpp"

int main() {
    int n, Q;
    cin >> n >> Q;
    dsu un(n);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            un.merge(u, v);
        } else {
            cout << un.same(u, v) << '\n';
        }
    }
}