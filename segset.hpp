#pragma once

#include <algorithm>
#include <cassert>
#include <set>

template <class T> struct segset {
   private:
    std::set<std::pair<T, T>> s;
    T sz;
    const T INF = std::numeric_limits<T>::max() / 2;

   public:
    segset() : sz(T(0)) {
        s.emplace(-INF, -INF);
        s.emplace(INF, INF);
    }

    bool insert(T x) { return insert(x, x + 1); }
    bool insert(T l, T r) {
        assert(l <= --r);
        auto it = prev(s.lower_bound({l + 1, l + 1}));
        if (it->first <= l && r <= it->second) return T(0);
        T dcnt = T(0);
        if (it->first <= l && l <= it->second + 1) {
            l = it->first;
            dcnt += it->second - it->first + 1;
            it = s.erase(it);
        } else ++it;
        while (r > it->second) {
            dcnt += it->second - it->first + 1;
            it = s.erase(it);
        }
        if (it->first - 1 <= r && r <= it->second) {
            dcnt += it->second - it->first + 1;
            r = it->second;
            s.erase(it);
        }
        s.emplace(l, r);
        sz += r - l + 1 - dcnt;
        return sz > 0;
    }
    bool erase(T x) { return erase(x, x + 1); }
    bool erase(T l, T r) {
        assert(l <= --r);
        auto it = prev(s.lower_bound({l + 1, l + 1}));
        if (it->first <= l and r <= it->second) {
            if (it->first < l) s.emplace(it->first, l - 1);
            if (r < it->second) s.emplace(r + 1, it->second);
            s.erase(it);
            return r - l + 1;
        }

        T cnt = T(0);
        if (it->first <= l and l <= it->second) {
            cnt += it->second - l + 1;
            if (it->first < l) s.emplace(it->first, l - 1);
            it = s.erase(it);
        } else ++it;
        while (it->second <= r) {
            cnt += it->second - it->first + 1;
            it = s.erase(it);
        }
        if (it->first <= r and r <= it->second) {
            cnt += r - it->first + 1;
            if (r < it->second) s.emplace(r + 1, it->second);
            s.erase(it);
        }
        sz -= cnt;
        return cnt > 0;
    }
    bool contains(T x) {
        auto [l, r] = *prev(s.lower_bound({x + 1, x + 1}));
        return l <= x && x <= r;
    }
    T size() { return sz; }

    std::set<std::pair<T, T>> segments() const {
        auto ret = s;
        ret.erase(ret.begin());
        ret.erase(prev(ret.end()));
        for (auto& [l, r] : ret) ++r;
        return ret;
    }

    T mex(T x = 0) const {
        auto [l, r] = *prev(s.lower_bound({x + 1, x + 1}));
        if (l <= x && x <= r) return r + 1;
        else return x;
    }
};
/*
 * @brief segset
 * @docs docs/segset.md
 */