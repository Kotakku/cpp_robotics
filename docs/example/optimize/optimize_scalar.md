# スカラー関数の最適化

スカラー値関数の最適化に使える関数の例を示します。  
黄金探索は連続な下に凸の関数の効率的な最小化ができます
2つ目の出力ではsin関数のx=0周りでの数値微分を求めています。

{{ include_example("example/optimize/optimize_scalar.cpp") }}

出力
```
optimize_scalar
min x => (x+1)^2 = -1
sin'(0) = cos(0) = 1
```