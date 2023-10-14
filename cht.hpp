#pragma once

#include <deque>
#include <utility>

template <typename T = long long>
struct cht {
    using Line = std::pair<T, T>;
    std::deque<Line> d;
    void add(T a, T b) {
        Line x = make_pair(a, b);
        while ((int)d.size() >= 2) {
            Line y = d[(int)d.size() - 1];
            Line z = d[(int)d.size() - 2];
            if ((x.second - y.second) * (z.first - y.first) >= (y.first - x.first) * (y.second - z.second)) break;
            d.pop_back();
        }
        d.push_back(x);
    }
    T get(T x) {
        while ((int)d.size() >= 2) {
            T a = d[0].first * x + d[0].second;
            T b = d[1].first * x + d[1].second;
            if (a <= b) break;
            d.pop_front();
        }
        return d[0].first * x + d[0].second;
    }
};
/*
 * @brief cht (Convex Hull Trick)
 * @docs docs/cht.md
 */