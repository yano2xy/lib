# LowLink

無向グラフにおける間接点および橋を $O(V+E)$で求めるアルゴリズム（データ構造） 

## コンストラクタ

```cpp
lowlink lk(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## add_edge

```cpp
void lk.add_edge(int u, int v)
```

頂点 $u$, $v$ の間に双方向の辺をはる   

**計算量**

- $O(1)$

## size

```cpp
int lk.size()
```

lowlinkのグラフの頂点数 $n$ を返す  

**計算量** 

- $O(1)$

## build

```cpp
void kl.build()
```

lowlinkにより、間接点および橋を検出して列挙する  

build後、klの以下のメンバに間接点および橋が格納される  

***間接点(articulation point)***  
~~~cpp
std::vector<int> kl.articulation
~~~

***橋(bridge)***  
~~~cpp
std::vector<std::pair<int,int>> kl.bridge
~~~

辺 $(u, v)$ は、常に $u \leq v$であることが保証される

**計算量**

- $O(E+V)$