# リンクロボットの運動モデルの導出

ニュートン・オイラー法による導出

## パラメータ

${}^i\Omega_i$ 各リンクの角速度  
${}^i\dot{\Omega}_i$ 各リンクの角速度  
${}^iV_i$ 各リンクの速度  
${}^i\dot{V}_i$ 各リンクの加速度  

${}^i\dot{Vc}_i$ 各リンクの重心の加速度  

${}^iR_{i+i}$ 座標$i$から$i+1$への変換行列  

${}^iFc_i$ 力  
${}^iNc_i$ トルク  

${}^iF_i$ 力  
${}^iN_i$ トルク  






## 順方向計算


## 逆方向計算

$$
{}^iF_i = {}^i_{i+1}R^{i+1}F_{i+1} + {}^iFc_{i} \\
{}^iN_i = {}^iNc_i + {}^i_{i+1}R^{i+1} N_{i+1} + {}^iPc_i \times {}^iFc_{i}+{}^iP_{i+1} \times {}^i_{i+1}R^{i+1} {}^{i+1}F_{i+1}
$$
