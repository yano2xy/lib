#pragma once

#include <cassert>
#include <vector>

template <typename mint>
mint lagrange_interpolation(const std::vector<mint>& y, long long x, int _NMAX = 5100000) {
    int N = (int)y.size() - 1;
    assert(N <= _NMAX);
    if (x <= N) return y[x];
    static std::vector<mint> ifact = [&] {
        std::vector<mint> fact(_NMAX), ifact(_NMAX);
        fact[0] = 1;
        for (int i = 1; i <= N; ++i)
            fact[i] = fact[i - 1] * i;
        ifact[N] = fact[N].inv();
        for (int i = N; i >= 1; --i)
            ifact[i - 1] = ifact[i] * i;
        return ifact;
    }();

    mint ret = 0;
    std::vector<mint> dp(N + 1, 1), pd(N + 1, 1);
    for (int i = 0; i < N; i++)
        dp[i + 1] = dp[i] * (x - i);
    for (int i = N; i > 0; i--)
        pd[i - 1] = pd[i] * (x - i);
    for (int i = 0; i <= N; i++) {
        mint tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N - i];
        ret += ((N - i) & 1) ? -tmp : tmp;
    }
    return ret;
}