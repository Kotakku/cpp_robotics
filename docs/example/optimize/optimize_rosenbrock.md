# Rosenbrock関数の最適化

!!! example "ソースコード"
    [example/optimize/optimize_rosenbrock.cpp](https://github.com/Kotakku/cpp_robotics/blob/develop/optimize/system/optimize_rosenbrock.cpp)

連続関数の最適化のベンチマークでよく登場するRosenbrock関数を使って最適化を行います。  
解の初期値x= (0,0)から最適解はx = (1, 1)を見つけることができています。

出力
```
optimize Rosenbrock function with quasi newton method
ans: 1 1
itr: 20
```