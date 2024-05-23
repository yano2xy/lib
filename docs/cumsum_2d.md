# cumsum_2d (2次元累積和/2次元imos法)

2次元の累積和を管理する。  
または、2次元のimos法を実行する。  

## コンストラクタ

~~~cpp
cumsum_2d<ll> cs(int H, int W)
~~~

- サイズ $H \times W$ の2次元配列を確保する

## add

~~~cpp
void cs.add(int x, int y, T z=1)
~~~

- 座標 $(x, y)$ に値 $z$ を加算する

## imos

~~~cpp
void cs.imos(int x1, int x2, int y1, int y2, T z=1)
~~~

- 領域 $[x1, x2) \times [y1, y2)$ に値 $z$ を加算する。
- 内部的には、imos法によりクエリ実行時に累積和が評価される。

## get

~~~cpp
T cs.get(int x, int y)
~~~

- build実行後の、座標 $(x, y)$ の値を取得する。

## query

~~~cpp
T cs.query(int x1, int x2, int y1, int y2)
~~~

- 領域 $[x1, x2) \times [y1, y2)$ の累積和を取得する

