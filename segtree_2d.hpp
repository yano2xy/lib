#pragma once

#include <vector>

template <class T, T (*op)(T, T), T (*e)()>
struct segtree_2d {
   private:
    int id(int h, int w) const { return h * 2 * W + w; }
    void init(int h, int w) {
        H = W = 1;
        while (H < h)
            H <<= 1;
        while (W < w)
            W <<= 1;
        seg.assign(4 * H * W, e());
    }
    void build() {
        // w in [W, 2W)
        for (int w = W; w < 2 * W; w++) {
            for (int h = H - 1; h; h--) {
                seg[id(h, w)] = op(seg[id(2 * h + 0, w)], seg[id(2 * h + 1, w)]);
            }
        }
        // h in [0, 2H)
        for (int h = 0; h < 2 * H; h++) {
            for (int w = W - 1; w; w--) {
                seg[id(h, w)] = op(seg[id(h, 2 * w + 0)], seg[id(h, 2 * w + 1)]);
            }
        }
    }
    T _inner_query(int h, int w1, int w2) {
        T res = e();
        for (; w1 < w2; w1 >>= 1, w2 >>= 1) {
            if (w1 & 1) res = op(res, seg[id(h, w1)]), w1++;
            if (w2 & 1) --w2, res = op(res, seg[id(h, w2)]);
        }
        return res;
    }

   public:
    int H, W;
    std::vector<T> seg;

    segtree_2d(int h, int w) {
        init(h, w);
        build();
    }
    segtree_2d(const std::vector<std::vector<T>>& A) {
        int h = A.size(), w = A[0].size();
        init(h, w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                seg[id(i + H, j + W)] = A[i][j];
            }
        }
        build();
    }
    T get(int h, int w) const { return seg[id(h + H, w + W)]; }
    void set(int h, int w, const T& x) {
        h += H, w += W;
        seg[id(h, w)] = x;
        for (int i = h >> 1; i; i >>= 1) {
            seg[id(i, w)] = op(seg[id(2 * i + 0, w)], seg[id(2 * i + 1, w)]);
        }
        for (; h; h >>= 1) {
            for (int j = w >> 1; j; j >>= 1) {
                seg[id(h, j)] = op(seg[id(h, 2 * j + 0)], seg[id(h, 2 * j + 1)]);
            }
        }
    }
    T prod(int h1, int w1, int h2, int w2) {
        if (h1 >= h2 || w1 >= w2) return e();
        T res = e();
        h1 += H, h2 += H, w1 += W, w2 += W;
        for (; h1 < h2; h1 >>= 1, h2 >>= 1) {
            if (h1 & 1) res = op(res, _inner_query(h1, w1, w2)), h1++;
            if (h2 & 1) --h2, res = op(res, _inner_query(h2, w1, w2));
        }
        return res;
    }
};
/**
 * @brief 2D Segment Tree
 * @docs docs/segtree_2d.md
 */