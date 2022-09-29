# 多項式補間
ロボットアームなどをなめらかに動かしたい時に目標値をなめらかに動かすことで実現しようとした時になるべく簡単に参照軌道を作りたいことがある。簡単に実装するなら多項式で軌道を作るのが簡単である。

## 1次式

境界条件数2

始点位置$`P_0`$, 終点位置$`P_1`$, 間隔$`T`$のとき

```math
f(t) = a_0 + a_1 t
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& \dfrac{P_1 - P_0}{T}

\end{array}
```

## 2次式

境界条件数3

始点$`(P_0, v_0)`$, 終点位置$`(P_1)`$, 間隔$`T`$のとき

```math
f(t) = a_0 + a_1 t + a_2 t^2
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& v_0\\
a_2 &=& \dfrac{1}{T^2}\left\{ (P_1 - P_0) - v_0T \right\}\\

\end{array}
```

始点$`(P_0, v_0)`$, 終点位置$`(v_1)`$, 間隔$`T`$のとき

```math
f(t) = a_0 + a_1 t + a_2 t^2
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& v_0\\
a_2 &=& \dfrac{1}{2T}(v_1 - v_0)\\

\end{array}
```

## 3次式

境界条件数4

始点$`(P_0, v_0)`$, 終点位置$`(P_1, v_1)`$, 間隔$`T`x$のとき

```math
f(t) = a_0 + a_1 t + a_2 t^2 + a_3 t^3
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& v_0\\
a_2 &=& \dfrac{1}{T^2}\left\{ 3(P_1 - P_0) - (v_1 + 2v_0)T \right\}\\
a_3 &=& \dfrac{1}{T^3}\left\{ -2(P_1 - P_0) - (v_1 + v_0)T \right\}

\end{array}
```

## 4次式

境界条件数5

始点$`(P_0, v_0, acc_0)`$, 終点位置$`(v_1, acc_1)`$, 間隔$`T`$のとき

```math
f(t) = a_0 + a_1 t + a_2 t^2 + a_3 t^3 + a_4 t^4
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& v_0\\
a_2 &=& \dfrac{1}{2} acc_0\\

a_3 &=& \dfrac{1}{3T^2}\left\{ 3(v_1 - v_0) - (acc_1 + 2acc_0)T \right\}\\

a_4 &=& \dfrac{1}{4T^3}\left\{ -2(v_1 - v_0) + (acc_1 + acc_0)T \right\}\\

\end{array}
```

始点$`(P_0, v_0, acc_0)`$, 終点位置$`(P_1, v_1)`$, 間隔$`T`$のとき

始点$`(P_0, v_0, acc_0)`$, 終点位置$`(P_1, acc_1)`$, 間隔$`T`$のとき

## 5次式

境界条件数6

始点$`(P_0, v_0, acc_0)`$, 終点位置$`(P_1, v_1, acc_1)`$, 間隔$`T`$のとき

```math
f(t) = a_0 + a_1 t + a_2 t^2 + a_3 t^3 + a_4 t^4 + a_5 t^5
```

```math
\begin{array}{rcl}
a_0 &=& P_0\\
a_1 &=& v_0\\
a_2 &=& \dfrac{1}{2} acc_0\\
a_3 &=& \dfrac{1}{2T^3}\left\{ 20(P_1 - P_0) - (8v_1 + 12v_0)T + (acc_1 - 3acc_0)T^2 \right\}\\

a_4 &=& \dfrac{1}{2T^4}\left\{ -30(P_1 - P_0) + (14v_1 + 16v_0)T -    (2acc_1 - 3acc_0)T^2 \right\}\\

a_5 &=& \dfrac{1}{2T^5}\left\{ 12(P_1 - P_0) - 6(v_1 + v_0)T +    (acc_1 - acc_0)T^2 \right\}
\end{array}
```

## 参考文献
- [ロボット工学の基礎（第2版）](https://www.morikita.co.jp/books/book/2321)