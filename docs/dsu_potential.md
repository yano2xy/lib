# dsu_potential (ポテンシャル付き UnionFind)

拡張点が、連結成分の代表元を起点とした時のポテンシャルを保持するようなUnionFind木。

## コンストラクタ

```cpp
dsu_potential<T> un(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。
- $T$ として、int, long long を想定する。

**計算量**

- $O(n)$

## merge

```cpp
bool un.merge(int a, int b, T d)
```

頂点 $a$ から頂点 $b$ に、長さ $d$ の辺を追加する。

$a, b$ がすでに同じ連結成分で、かつ、ポテンシャルに矛盾がある場合falseを返す。  
それ以外の場合、trueを返す。

**計算量**

- ならし $O(\alpha(n))$

## same

```cpp
bool un.same(int a, int b)
```

頂点 $a, b$ が連結かどうかを判定する。

**計算量**

- ならし $O(\alpha(n))$

## leader

```cpp
int un.leader(int a)
```

頂点 $a$ の属する連結成分の代表元を返す。

**計算量**

- ならし $O(\alpha(n))$

## potential

```cpp
T potential(int a)
```

頂点 $a$ のポテンシャルを返す。

## diff

```cpp
T diff(int a, int b)
```

頂点 $a$ と頂点 $b$ とのポテンシャルの差（$b$ のポテンシャル $-$ $a$ のポテンシャル）を返す。

## size

```cpp
int un.size(int a)
```

頂点 $a$ の属する連結成分のサイズを返す。

**計算量**

- ならし $O(\alpha(n))$

## groups

```cpp
vector<vector<int>> un.groups()
```

各連結成分を返す。

返り値は「「一つの連結成分の頂点番号のリスト」のリスト」。
(内側外側限らず)vector内でどの順番で頂点が格納されているかは未定義。

**計算量**

- $O(n)$
