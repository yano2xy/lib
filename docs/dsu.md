# dsu (UnionFind)

## コンストラクタ

```cpp
dsu un(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## merge

```cpp
int un.merge(int a, int b)
```

辺 $(a, b)$ を追加して、新しい代表元を返す。

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
