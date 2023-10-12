# rerooting

## コンストラクタ

```cpp
rerooting<S> G(int n, TG f, TM merge, TG g, S id)
```

$n$ 頂点の全方位木DPクラスを作成する。  

- $S$ : 各DP値の型  

頂点 $v$ および、その子頂点 $c_1, \dots, c_m$ について、$dp[v]$ の遷移が以下の式で与えられるとき、コンストラクは関数 $f, merge, g$および単位元 $id$ をオラクルとして受け取る。    

$dp[v] = g(merge({f(dp[c_1], c_1, v), \dots, f(dp[c_m], c_m, v)}), v)$ 

```cpp
// 各子ノードに対して、マージ前の前処理を行う
S f(S x, int pos, int par)

// マージ処理
S merge(S x, S y)

// マージ後の値をdp値として確定させるための仕上げ処理
S g(S x, int pos)
```

## add_edge

```cpp
void G(int a, int b)
```
双方向の辺 $(a, b)$ を追加する。  

このクラスでは辺のコストは管理しないため、必要な場合はクラスの外で管理する。  

## solve

```cpp
vector<S> solve()
```
各頂点 $0, 1, ..., n-1$ について、この順でdp値の配列を取得する。  

**計算量**

- $O(n)$
