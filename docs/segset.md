# segset (SegmentSet)

区間をsetで管理するテク.  
区間insert/eraseができるsetを提供する.  

## コンストラクタ

```cpp
segment_set<T> st
```

- 型 $T$ のsetを作成する

**計算量**

- $O(1)$

## insert

```cpp
bool st.insert(T x)
bool st.insert(T l, T r)
```
- setに値 $x$ を挿入する
- setに半開区間 $[l, r)$ に含まれる値を全て追加する

新規に追加された値があった場合にtrueが、それ以外の場合falseが返る  

**計算量**

- ならし $O(\log(n))$

## erase

```cpp
bool st.erase(T x)
bool st.erase(T l, T r)
```
- setから値 $x$ を削除する
- setから半開区間 $[l, r)$ に含まれる値をすべて削除する

削除された値が一つでも存在する場合はtrueが、それ以外の場合falseが返る  

**計算量**

- $O(\log(n))$

## contains

```cpp
bool st.contains(T x)
```
- setに値 $x$ が含まれるか否かを判定する

**計算量**

- $O(\log(n))$

## size

```cpp
T st.size(T a)
```
- setに含まれる値の総数を返す

**計算量**

- $O(1)$

## segments

```cpp
set<pair<T,T>> un.segments()
```

- 全てのsegmentを返す
- 各セグメントは、 $pair<T,T>$ であり、半開区完 $[l, r)$ である  


**計算量**

- $O(n)$

## mex

```cpp
T st.mex(T x=0)
```

- 引数 $x$ 以上の値で、setに含まれないような最小の値(MEX)を返す

**計算量**

- $O(\log(n))$
