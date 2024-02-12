# HLD (Heavy Light Decomposition - 重軽分解)

- HL分解を行う。
- `Graph<T>` に依存する
- 頂点属性および辺属性のパスクエリに対応できる
- 頂点属性および辺属性の部分木クエリに対応できる

## 辺属性のクエリに対応する場合の注意

- 辺属性のクエリに対応する際は、各辺の情報は頂点に持たせる
- 正確には、辺 $(u, v)$ の情報は、頂点 $u$ と $v$ のうち、`root`を根としてdfs順に深い方、つまり $id$ (`hld.vid(int i)`で取得可能) が大きい方の頂点で管理する
- このとき、辺属性クエリの実行時には、上記の意味で対応する各頂点の区間に対して、$F$ が実行される

***例: 5頂点の木***
~~~
5
0 1
1 2
2 3
1 4
~~~
- 上記の木は、HL分解によって2つの区間 $[0, 1, 2, 3, 4)$, $[4, 5)$ に分解される
- パス $(3, 4)$ （つまりパス `3-2-1-4`）については、各パスの情報は頂点 $2, 3, 4$ が持っているとみなして、処理区間を決定する
- つまり、`path_query(3, 4, f, true)` は区間 $[2, 4), [4, 5)$ を処理するということ
  - 頂点属性クエリ `path_query(3, 4, f, false)` では 区間 $[1, 4), [4, 5)$ が処理される



## コンストラクタ

```cpp
HLD hld(Graph<T> G, root=0)
```

- Tree $G$ を、根が $root$ の根つき木とみなしてHL分解する

**計算量**

- $O(n)$

## vid

```cpp
int hld.vid(int u)
```

頂点 $u$ の idを返す。

**計算量**

- $O(1)$

## path_query

```cpp
void hld.path_query(int u, int v, const F& f, bool isEdge=false)
```

- 頂点 $u$ から 頂点 $v$ へのパスを、$O(log(N))$ 個の区間に分解し、各区間に対して $F$を適用する
- $F$ は半開区間 $[l, r)$ に対する処理を実行する関数 `f(int l, int r) -> void` である
- 辺属性のクエリを処理する場合は、`isEdge=true` を指定する 

**計算量** 

- $O(log(n))$

## path_noncommutative_query

```cpp
void hld.path_nocommutative_query(int u, int v, const F& f, bool isEdge=false)
```

- 非可換なパスクエリに対応する
- パスを区間に分割するのは `path_query`と同様だが、分割後の各区間の向きと処理順まで考慮される。
  - 木を根方向に遡るような区間では、$r<l$ であるような区間 $(r, l]$ が $F$ に渡されて処理される。   

**計算量**

- $O(log(n))$

## subtree_query

```cpp
void hld.subtree_query(int u, const F& f, bool isEdge=false)
```

- 頂点 $u$ の部分木に対するクエリに対応する

**計算量**

- $O(log(n))$

## lca

```cpp
int hld.lca(int u, int v)
```

頂点 $u$ と $v$ の LCA であるような頂点を返す

**計算量**

- $O(log(n))$

## dist

```cpp
int hld.dist(int u, int v)
```

頂点 $u$ と 頂点 $v$ のパスの1骨格の距離（各辺の長さを1とみなしたときの距離）を返す

**計算量**

- $O(log(n))$