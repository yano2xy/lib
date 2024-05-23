#include <cassert>
#include <vector>

template <class T = long long> struct cumsum_2d {
   private:
    bool is_built = false;
    std::vector<std::vector<T> > data;
    void build() {
        for (int i = 1; i < (int)data.size(); i++) {
            for (int j = 1; j < (int)data[i].size(); j++) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
        is_built = true;
    }

   public:
    cumsum_2d(int H, int W) : data(H + 3, vector<T>(W + 3, 0)) {}
    void add(int x, int y, T z) {
        assert(!is_built);
        ++x, ++y;
        if (x >= (int)data.size() || y >= (int)data[0].size()) return;
        data[x][y] += z;
    }

    void imos(int x1, int x2, int y1, int y2, T z = 1) {
        assert(!is_built);
        add(x1, y1, z);
        add(x1, y2, -z);
        add(x2, y1, -z);
        add(x2, y2, z);
    }

    T get(int x, int y) {
        if (!is_built) build();
        return data[x + 1][y + 1];
    }

    T query(int x1, int x2, int y1, int y2) {
        if (!is_built) build();
        return (data[x2][y2] - data[x1][y2] - data[x2][y1] + data[x1][y1]);
    }
};
/**
 * @brief 2D Cumulative Sum (二次元累積和/2次元imos法)
 * @docs docs/cumsum_2d.md

*/
// [x1, x2) × [y1, y2)