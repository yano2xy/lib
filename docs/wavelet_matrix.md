# Wavelet Matrix

## コンストラクタ

~~~cpp
wavelet_matrix<T, true> wm(vector<T> A)
~~~

- $A$ はウェーブレット行列にのせる数列
- $A$ の要素を座標圧縮する場合は 型テンプレートで `true` を渡す

## count

~~~
int wm.count(int L, int R, int a, int b)
int wm.count(vector<pair<int,int>> segments, int a, int b)
~~~

- 区間 $[L, R)$ において、値が $[a, b)$ であるようなものの個数をかえす
- 複数の区間 $vector<pair<int,int>> segments$ を与えることも可能 

**計算量**

- $O(log(N))$
