# mergesort_tree

数列 $A=(A_1, A_2, \dots, A_n)$ に対し、以下のクエリ $(L, R, X)$ に $O(\log ^2(n))$ で回答する。  
- $A_i \leq X$ をみたすような $i \in [L, R)$ の個数


## コンストラクタ

```cpp
mergesort_tree seg(const vector<T>& a)
```

- 数列 $a$ に対して、mergesort_tree を初期化する   

**計算量**

- $O(n\log(n))$

## count

```cpp
int count(int lq, int rq, T x)
```

$A_i < x$ を満たすような $i \in [iq, ir)$ の個数を求める

**計算量**

- $O(\log ^2(n))$

## count

```cpp
int count(int lq, int rq, T lx, T rx)
```

$A_i \in [lx, rx)$ を満たすような $i \in [iq, ir)$ の個数を求める

**計算量**

- $O(\log ^2(n))$