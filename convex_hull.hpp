#pragma once

#include <algorithm>
#include <vector>

// [注意] 動作未確認
template <class T, class S> std::vector<std::pair<T, S>> convex_hull(std::vector<std::pair<T, S>> ps) {
    std::sort(ps.begin(), ps.end());
    int n = ps.size();
    if (n <= 2) return ps;
    // 上側凸包
    std::vector<std::pair<T, S>> stH;
    for (int i = n - 1; i >= 0; i--) {
        auto &[px, py] = ps[i];
        while (stH.size() >= 2) {
            auto &[ax, ay] = stH[stH.size() - 1];
            auto &[bx, by] = stH[stH.size() - 2];
            if ((ax - bx) * (py - by) > (ay - by) * (px - bx)) break;
            stH.pop_back();
        }
        stH.push_back(ps[i]);
    }
    // 下側凸包
    std::vector<std::pair<T, S>> stL;
    for (int i = 0; i < ps.size(); i++) {
        auto &[px, py] = ps[i];
        while (stL.size() >= 2) {
            auto &[ax, ay] = stL[stL.size() - 1];
            auto &[bx, by] = stL[stL.size() - 2];
            if ((ax - bx) * (py - by) > (ay - by) * (px - bx)) break;
            stL.pop_back();
        }
        stL.push_back(ps[i]);
    }

    std::reverse(stH.begin(), stH.end());
    for (int i = stL.size() - 2; i >= 1; i--) stH.push_back(stL[i]);
    return stH;
}