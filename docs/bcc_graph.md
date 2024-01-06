# bcc_graph (Bi-Conneced Components : 二重頂点連結成分分解)

二重頂点連結成分分解を行う  

## コンストラクタ

```cpp
bcc_graph G(int n)
```

- $n$ 頂点 $0$ 辺の無向グラフを作る。

**計算量**

- $O(n)$

## add_edge

```cpp
void G.add_edge(int u, int v)
```

頂点 $u$, $v$ の間に双方向の辺をはる   

**計算量**

- $O(1)$

## size

```cpp
int G.size()
```

lowlinkのグラフの頂点数 $n$ を返す  

**計算量** 

- $O(1)$

## bcc

```cpp
std::vector<std::vector<std::pair<int,int>>> G.bcc()
```

グラフの BCC (Bi-Connected Components : 二重頂点連結成分分解) を返す  

BCC は、各連結成分のvectorである。  
各連結成分は、そこに含まれる辺のvectorである。  


