# Lagrange補完 （Lagrange Interpolation）

## 関数

~~~cpp
mint lagrange_interpolation(vector<mint> V, long long x, _NMAX=5100000)
~~~

未知の多項式 $f(t)=a_0 + a_1t + \dots + a_Nt^N$ について、  
$N+1$ 個の計算値 $f(x_0), \dots , f(x_{N})$ が既知の時、 $f(x)$ を求める。  

~~~cpp
vector<mint> V 
~~~

Vは既知の計算値 $f(x_0), \dots , f(x_{N})$ を要素とする要素数 $N+1$ のvector

この関数は、内部static処理として、2項係数計算のための階乗値の逆数を前計算する。  
多項式の次数 $N$ として考慮する最大値を `_NMAX` で指定する。  



## 計算量

- $N$次多項式に対して$O(N\log{mod})$