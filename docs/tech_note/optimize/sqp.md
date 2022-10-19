# SQP(逐次二次計画法)

NLPに対して現在の解付近で問題を二次近似し、その二次計画問題の解を探索方向として反復計算を行う手法の総称  
QPへの近似とその解法によっていくつかの種類に分かれる   
ここでは準ニュートン法によるものとSLSQPについて解説する  

## 準ニュートン法
まずは純粋なSQPについて考えてみる。与えられる問題は以下の形式である

```math
\underset{x}{\text{min}} \space f(x)\\
\text{s.t.} \space  g_i(x) = 0, \space i = 0, \dots , m_e\\
\text{　　　} \space  g_i(x) \leq 0, \space i = m_e+1, \dots , l\\

x \in \R^n
```

サブ問題としてQPに近似すると以下の形を取る

```math
f(x) \approx \dfrac{1}{2}x^TQx + c^Tx\\
```

ここで任意の目的関数のヘッシアン$`Q`$について半正定値性が保証されないためパウエルの修正BFGS法により近似した行列を使用する。

探索方向の決定のために目的変数を探索方向に取りQP問題を定式化する。

```math
\underset{d}{\text{min}} \dfrac{1}{2}d^TQd + c^Td\\
\text{s.t.} \space \nabla g_i(x)^Td + g_i(x) = 0, \space i = 0, \dots , m_e\\
\text{　　　} \space \nabla g_i(x)^Td + g_i(x) \leq 0, \space i = m_e+1, \dots , l\\
```

探索方向が決定したらメリット関数の直線探索によりステップ幅を決定し、変数を更新する。
その後BFGSによるヘッシアンの更新を行う。

以上の操作を収束するまで行う。

## SLSQP

SLSQPでは準ニュートン法で説明したサブ問題であるQPを制約付きの最小二乗法に変形して解いている。これにあたってB行列を修正コレスキー分解する
```math
B = LDL^T
```

分解した行列を使って以下の最小二乗法を解く
```math
\underset{d}{\text{min}} || D^\frac{1}{2}L^Td + D^{-\frac{1}{2}}L^{-1}\nabla f(x) ||\\
\text{s.t.} \space \nabla g_i(x)^Td + g_i(x) = 0, \space i = 0, \dots , m_e\\
\text{　　　} \space \nabla g_i(x)^Td + g_i(x) \leq 0, \space i = m_e+1, \dots , l\\

```

### 最小二乗法問題からQP問題への変換


> Kraft, D. A software package for sequential quadratic
   programming. 1988. Tech. Rep. DFVLR-FB 88-28, DLR German Aerospace
   Center -- Institute for Flight Mechanics, Koln, Germany.



## 参考文献
- [しっかり学ぶ数理最適化](https://sites.google.com/view/introduction-to-optimization/main)
- [SQPとSLSQPの違いについて](https://stats.stackexchange.com/questions/268290/in-mathematical-optimization-are-sequential-quadratic-programming-and-sequentia)

- [fmincon SQP アルゴリズム](https://jp.mathworks.com/help/optim/ug/constrained-nonlinear-optimization-algorithms.html#bsgppl4)  
    基本的な実装はこのページのfmincon アクティブ セット アルゴリズムを参照