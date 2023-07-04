# スカラー関数の最適化

!!! example "ソースコード"
    [example/optimize/optmize_scalar.cpp](https://github.com/Kotakku/cpp_robotics/blob/develop/optimize/system/optmize_scalar.cpp)

スカラー値関数の最適化に使える関数の例を示します。  
黄金探索は連続な下に凸の関数の効率的な最小化ができます
2つ目の出力ではsin関数のx=0周りでの数値微分を求めています。

出力
```
optimize_scalar
min x => (x+1)^2 = -1
sin'(0) = cos(0) = 1
```