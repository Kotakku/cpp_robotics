# 二次計画法

以下の最適化問題を考える
```math
\text{min} \space \dfrac{1}{2}x^TQx + c^T x\\
\text{s.t.} \space Ax = b, A_{eq}x \leq b_{eq}, l_x \leq x \leq u_x \\
x \in \R^n
```

## 前処理

## 予測子修正子
与えられた問題に対するKKT条件は以下
```math
\begin{array}{l}
Qx+c -\bar{A}^T\lambda - 
\end{array}

```
[KKT条件について](./kkt_condition.md)


## 停止条件

## 実行不可能性の検出

## 参考文献
- [二次計画法のアルゴリズム](https://jp.mathworks.com/help/optim/ug/quadratic-programming-algorithms.html#bvjx020-1)
