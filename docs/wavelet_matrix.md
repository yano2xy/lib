# Wavelet Matrix

## コンストラクタ

~~~cpp
wavelet_matrix<T, true> wm(vector<T> A)
~~~

- $A$ はウェーブレット行列にのせる数列
- $A$ の要素を座標圧縮する場合は 型テンプレートで `true` を渡す

## count

~~~cpp
int wm.count(int L, int R, int lower, int upper)
int wm.count(vector<pair<int,int>> segments, int lower, int upper)
~~~

- 区間 $[L, R)$ において、値が $[lower, upper)$ であるようなものの個数をかえす

**計算量**

- $O(log(N))$

## kth_smallest

~~~cpp
T wm.kth_smallest(int L, int R, int k)
T wm.kth_smallest(vector<pair<int,int>> segments, int k)
~~~

- 区間 $[L, R)$ において、小さい方から $k$ 番目（0-indexed）の値を返す

**計算量**

- $O(log(N))$

## kth_largest

~~~cpp
T wm.kth_largest(int L, int R, int k)
T wm.kth_smallest(vector<pair<int,int>> segments, int k)
~~~

- 区間 $[L, R)$ において、大きい方から $k$ 番目（0-indexed）の値を返す

**計算量**

- $O(log(N))$

## prev_value

~~~cpp
T wm.prev_value(int L, int R, T upper)
~~~

- 区間 $[L, R)$ において、$upper$ **未満**であるような最後の値を返す
- 区間 $[L, R)$ においてそのような値が存在しない場合、 `wm.INF` を返す

**計算量**

- $O(log(N))$


## next_value

~~~cpp
T wm.next_value(int L, int R, T lower)
~~~

- 区間 $[L, R)$ において、$lower$ **以上**であるような最後の値を返す
- 区間 $[L, R)$ においてそのような値が存在しない場合、 `wm.INF` を返す

**計算量**

- $O(log(N))$