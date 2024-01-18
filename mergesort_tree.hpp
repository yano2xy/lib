#pragma once

#include <algorithm>
#include <vector>

template <typename T> struct mergesort_tree {
   private:
    int n;
    std::vector<std::vector<T> > t;
    int _count(int ql, int qr, T x, int k = 0, int l = 0, int r = -1) const {
        if (r < 0) r = n;
        if (qr <= l || r <= ql) return 0;
        else if (ql <= l && r <= qr) return lower_bound(t[k].begin(), t[k].end(), x) - t[k].begin();
        else return _count(ql, qr, x, k * 2 + 1, l, (l + r) / 2) + _count(ql, qr, x, k * 2 + 2, (l + r) / 2, r);
    }

   public:
    mergesort_tree(const std::vector<T>& a) {
        n = 1;
        while (n < a.size()) n <<= 1;
        t.assign(2 * n - 1, {});
        for (int i = 0; i < a.size(); i++) t[i + n - 1].push_back(a[i]);
        for (int i = n - 2; i >= 0; i--) {
            t[i].resize(t[i * 2 + 1].size() + t[i * 2 + 2].size());
            std::merge(t[i * 2 + 1].begin(), t[i * 2 + 1].end(), t[i * 2 + 2].begin(), t[i * 2 + 2].end(), t[i].begin());
        }
    }
    int count(int ql, int qr, T x) const { return _count(ql, qr, x); }
    int count(int ql, int qr, T lx, T rx) const { return _count(ql, qr, rx) - _count(ql, qr, lx); }
};
/*
 * @brief mergesort_tree
 * @docs docs/mergesort_tree.md
 */