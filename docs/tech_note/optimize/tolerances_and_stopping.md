# 許容誤差・停止条件

最適化を行う上でイテレーションの停止条件を判断するために許容誤差を設定する。
この許容誤差には最適性・関数値・ステップ・制約に対して監視され、また、それぞれの許容誤差は問題設定によって相対許容誤差か絶対許容誤差化が異なる。

## 絶対許容誤差と相対許容誤差
### 絶対許容誤差
各イテレーションで評価された値に対して課される許容誤差   
関数評価値の場合  

$$
(f(x_{i+1}) - f(x_i)) < AbsTolerance 
$$

ステップの場合  

$$
|x_{i+1} - x_{i}| < AbsTolerance
$$

### 相対許容誤差
イテレーションによる値の変化量に対して課される許容誤差  
関数評価値の場合

$$
(f(x_{i+1}) - f(x_i)) < RelTolerance \times (1 + f(x_i))
$$

ステップの場合  

$$
|x_{i+1} - x_{i}| < RelTolerance \times (1 + |x_i|)
$$

| 問題 | アルゴリズム | 最適性の許容誤差 | 関数評価値の許容誤差 | ステップの許容誤差 | 制約の許容誤差 | 備考|
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 制約なし非線形最適化 | (fminsearch) | - | Abs | Abs | - | 同時に満たした時終了とする |
|   | 準ニュートン法 | Rel | - | Rel | - |  |
| 制約付き非線形最適化 | 内点法 | Rel | - | Rel | Rel | |
|  | 有効制約法 | Abs | Abs | Abs | Abs | |
|  | 逐次二次最適化(SQP) | Rel | - | Rel | Rel | | 

Abs: 絶対許容誤差  
Rel: 相対許容誤差  


## 参考文献
- [許容誤差と停止条件](https://jp.mathworks.com/help/optim/ug/tolerances-and-stopping-criteria.html)
- [許容誤差の詳細](https://jp.mathworks.com/help/optim/ug/tolerance-details.html)