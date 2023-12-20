# swag (Sliding Window Aggregation)

- モノイドに対して使用可能
- スライド区間に対して、区間の伸縮(push, pop)および区間における総積の取得(prod)をならし計算量 $O(1)$ で実行する 

## コンストラクタ

~~~cpp
swag<S, op, e> sw;
~~~

- op はモノイド演算
- e は単位減取得関数

## push

~~~
void sw.push(T x)
~~~

- swの末尾に $x$ を追加する

## pop

~~~
void sw.pop()
~~~

- swの先頭の要素を削除する

## front

~~~
T sw.front()
~~~

- swの先頭の要素を取得する

## prod

~~~
T sw.prod()
~~~

- swの中の要素のモノイド演算の総積を取得する
- swが空の場合、単位元 $e()$ を返す