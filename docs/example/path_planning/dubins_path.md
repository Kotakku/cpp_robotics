# Dubins曲線

{{ include_example("example/path_planning/dubins_path.cpp") }}

(4, 3)地点-45度の方向からスタートして(1,1)に45度の方向に到達する経路を生成します。  
曲線の箇所は曲率が1になるように設定します。

出力
```
RSR
1.45579
2.55239
3.2566
```

![](../fig/dubins_path.png)