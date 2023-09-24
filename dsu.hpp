#pragma once

#include <algorithm>
#include <cassert>
#include <vector>

struct dsu {
    int _n;
    std::vector<int> data;

    dsu() : _n(0) {}
    dsu(int n) : _n(n), data(n, -1) {}

    bool merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-data[x] < -data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return x;
    }

    int same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (data[a] < 0) return a;
        return data[a] = leader(data[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -data[leader(a)];
    }

    auto gropus() {
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
/*
 * @brief dsu (UnionFind)
 * @docs docs/dsu.md
 */