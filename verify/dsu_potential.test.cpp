#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"

#include <bits/stdc++.h>
using namespace std;

#include "../dsu_potential.hpp"

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (m == 0) break;
        dsu_potential un(n);
        while (m--) {
            char c;
            cin >> c;
            if (c == '!') {
                int a, b, w;
                cin >> a >> b >> w;
                --a, --b;
                un.merge(a, b, w);
            } else {
                int a, b;
                cin >> a >> b;
                --a, --b;
                if (un.same(a, b)) cout << un.diff(a, b) << '\n';
                else cout << "UNKNOWN\n";
            }
        }
    }
}
