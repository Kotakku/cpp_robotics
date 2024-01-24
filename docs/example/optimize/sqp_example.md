# SQP(逐次二次計画法)

制約付き非線形最適化問題をSQPソルバを用いて解く例

制約として最適化変数のノルムが1以下になるように設定している。

![](../fig/sqp_example.png)

橙：最適化変数のパス  
青：制約の境界  
緑：目的関数が極小値となる座標

{{ include_example("example/optimize/sqp_example.cpp") }}
