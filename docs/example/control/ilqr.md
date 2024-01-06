# iLQR

!!! example "ソースコード"
    [example/controller/ilqr_linear_example.cpp](https://github.com/Kotakku/cpp_robotics/blob/develop/example/controller/ilqr_linear_example.cpp)  
    [example/controller/ilqr_diffbot_example.cpp](https://github.com/Kotakku/cpp_robotics/blob/develop/example/controller/ilqr_diffbot_example.cpp)

iLQRを用いて線形/非線形モデルの最適制御を行います。  

!!! warning
    cpp_roboticsに実装しているiLQRでは制約が扱えません

## double-integrator
![title](../fig/ilqr_linear_example.png)

## 差動二輪
![title](../fig/ilqr_diffbot_example.png)