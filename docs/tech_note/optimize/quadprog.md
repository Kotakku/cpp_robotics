# 二次計画法

以下の最適化問題を考える

$$
\begin{array}{}
\text{min} \space \dfrac{1}{2}x^TQx + c^T x\\
\text{s.t.} \space Ax = b, A_{eq}x \leq b_{eq} \\
x \in \mathbb{R}^n
\end{array}
$$

# 内点法による最適化
## KKT条件
与えられた問題に対するKKT条件は以下

$$
\begin{array}{l}
Qx+c + A^T\lambda + A_{eq}\lambda_{eq} = \bf{0} \\
\lambda_i s_i = \rho\\
Ax-b+s = \bf{0}\\
A_{eq}x-b_{eq} = \bf{0}\\
s > \bf{0}\\
\lambda > \bf{0}\\
\end{array}
$$

[KKT条件について](./kkt_condition.md)

## 探索方向の決定
KKT条件に対して各変数を微小変化させた場合を考える

$$
\begin{array}{cc}
x \leftarrow x + \Delta x\\
s \leftarrow s + \Delta s\\
\lambda \leftarrow \lambda + \Delta \lambda\\
\lambda_{eq} \leftarrow \lambda_{eq} + \Delta \lambda_{eq}\\
\end{array}
$$

KKT条件に以上を代入し微小変化量に対して連立方程式の形式にまとめる

$$
\begin{bmatrix}
Q    & \bf{0}    & A^T    & A_{eq}^T \\
A    & I         & \bf{0} & \bf{0} \\
0    & D_\lambda & D_s    & \bf{0} \\
A_eq & \bf{0}    & 0      & \bf{0} \\
\end{bmatrix}
\begin{bmatrix}
\Delta x \\
\Delta s \\
\Delta \lambda \\
\Delta \lambda_{eq} \\
\end{bmatrix}
= 
\begin{bmatrix}
Qx + c + A^T\lambda + A_{eq}^T \lambda_{eq}\\
Ax - b + s\\
-\rho I + \lambda \bigodot s \\
A_{eq} x - b_{eq}\\
\end{bmatrix}\\
\space\\
D_\lambda = \text{diag}(\lambda)\\
D_s = \text{diag}(s)\\
\lambda \bigodot s = \text{(要素積・アダマール積)}
$$

この方程式を解いて各変数を更新していく

# ActiveSet法による最適化

# ADMMによる最適化


## 参考文献
- [二次計画法のアルゴリズム](https://jp.mathworks.com/help/optim/ug/quadratic-programming-algorithms.html#bvjx020-1)
