# SQP(逐次二次計画法)

NLPに対して現在の解付近で問題を二次近似し、その二次計画問題の解を探索方向として反復計算を行う手法の総称  
QPへの近似とその解法によっていくつかの種類に分かれる   
ここでは準ニュートン法によるものとSLSQPについて解説する  

## 準ニュートン法
まずは純粋なSQPについて考えてみる。与えられる問題は以下の形式である

```math
\text{Todo}
```

サブ問題としてQPに近似すると以下の形を取る

```math
\text{Todo}
```

ここで任意の目的関数のヘッシアン$`H`$について半正定値性が保証されないためパウエルの修正BFGS法により近似した行列に置き換える。

```math
\text{Todo}
```

!!! note
    ここで任意の目的関数に対してBFGS法を適用すると正定値性が保証されないためパウエルの修正BFGS法を使用する


この問題について変数を見ると$`\Delta x`$, $`\Delta s`$, $`\Delta \lambda`$,である。この変数についてまとめると以下の連立方程式ができる。


!!! note
    ここで$`f(x)`$は定数として扱うことができるので省略している

これで探索方向とラグランジュ定数とスラック変数が求まるので探索方向に直線探索、BFGSによるB行列の更新を行う操作を$`\Delta x`$が十分に小さくなるまで行う。

## SLSQP

SLSQPではサブ問題である以下のQPを制約付きの最小二乗法によって解いている。
```math
```

B行列を以下の用に分解する
```math
B = LDL^T
```

分解した行列を使って以下の最小二乗法を解く
```math
\text{min} ||  ||
```


> Kraft, D. A software package for sequential quadratic
   programming. 1988. Tech. Rep. DFVLR-FB 88-28, DLR German Aerospace
   Center -- Institute for Flight Mechanics, Koln, Germany.



## 参考文献
- [しっかり学ぶ数理最適化](https://sites.google.com/view/introduction-to-optimization/main)
- [SQPとSLSQPの違いについて](https://stats.stackexchange.com/questions/268290/in-mathematical-optimization-are-sequential-quadratic-programming-and-sequentia)

- [fmincon SQP アルゴリズム](https://jp.mathworks.com/help/optim/ug/constrained-nonlinear-optimization-algorithms.html#bsgppl4)  
    基本的な実装はこのページのfmincon アクティブ セット アルゴリズムを参照