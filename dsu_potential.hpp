#pragma once

#include <cassert>
#include <vector>

template <typename T = long long>
struct dsu_potential {
   public:
    int _n;
    std::vector<int> data;
    std::vector<T> diff_potential;

    dsu_potential() : _n(0) {}
    dsu_potential(int n) : _n(n), data(n, -1), diff_potential(n, 0) {}

    bool merge(int a, int b, T d) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        if (same(a, b)) return (d == diff(a, b));
        int x = leader(a), y = leader(b);
        d += potential(a) - potential(b);
        if (-data[x] < -data[y]) std::swap(x, y), d = -d;
        data[x] += data[y];
        data[y] = x;
        diff_potential[y] = d;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (data[a] < 0) return a;
        int r = leader(data[a]);
        diff_potential[a] += diff_potential[data[a]];
        return data[a] = r;
    }

    T potential(int a) {
        assert(0 <= a && a < _n);
        leader(a);
        return diff_potential[a];
    }

    T diff(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        assert(leader(a) == leader(b));
        return potential(b) - potential(a);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -data[leader(a)];
    }

    auto groups() {
        std::vector<int> leaders(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leaders[i] = leader(i);
            group_size[leaders[i]]++;
        }
        std::vector<std::vector<int>> ret(_n);
        for (int i = 0; i < _n; i++) {
            ret[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            ret[leaders[i]].push_back(i);
        }
        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const std::vector<int>& v) { return v.empty(); }), ret.end());

        return ret;
    }
};