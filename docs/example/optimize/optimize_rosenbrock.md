# Rosenbrock関数の最適化

連続関数の最適化のベンチマークでよく登場するRosenbrock関数を使って最適化を行います。  
解の初期値x= (0,0)から最適解はx = (1, 1)を見つけることができています。

{{ include_example("example/optimize/optimize_rosenbrock.cpp") }}

出力
```
optimize Rosenbrock function with quasi newton method
ans: 1 1
itr: 20
```