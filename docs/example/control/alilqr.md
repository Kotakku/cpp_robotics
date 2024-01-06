# AL-iLQR

AL-iLQRを用いて非線形モデルの最適制御を行います。  
制約として入力量のbox制約を指定しています。

## 差動二輪
{{ include_example("example/controller/alilqr_diffbot_example.cpp") }}
![title](../fig/alilqr_diffbot_example.png)

## Cartpole
{{ include_example("example/controller/alilqr_cartpole_example.cpp") }}
![title](../fig/alilqr_cartpole_example.png)