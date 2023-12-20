# segtree_2d (2D Segment Tree)

- モノイドに対して使用可能
- 二次元配列に対して、1点更新と区間積の取得を $O(\log(H)\log(W))$ で実行する

## コンストラクタ

```cpp
segtree_2d<S, op, e> seg(h, w)
```
- op はモノイド演算
- e は単位減取得関数
- 二次元配列のサイズ $(h, w)$ を与えて初期化する

```cpp
segtree_2d<S, op, e> seg(A)
```

- または、二次元配列 $A$ によって初期化する

## get

~~~cpp
T seg.get()
~~~

- $seg[h][w]$ の値を取得する

***計算量***

- $O(1)$

## set

~~~cpp
void seg.set(int h, int w, T x)
~~~

- $seg[h][w]$ を $x$ に更新する

***計算量***

- $O(\log(H)\log(W))$

## prod

~~~cpp
T seg.prod(int h1, int w1, int h2, int w2)
~~~

- 半開区間 $[h1, h2) \times [w1, w2)$ に対して総積を取得する
