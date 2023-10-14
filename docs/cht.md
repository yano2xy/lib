
# cht (Convex Hull Trick)

追加する直線の傾きaが単調減少 & 取得クエリのxが単調増加 の場合にのみ使用可能  

## コンストラクタ

~~~cpp
cht<ll> ch;
~~~

## add

~~~cpp
void ch.add(T a, T b)
~~~

直線 $ y = ax + b $ を追加する。  

## get

~~~cpp
T get(T x)
~~~

追加されている直線の集合を$F$として$min_{f \in F} f(x)$ を返す。  