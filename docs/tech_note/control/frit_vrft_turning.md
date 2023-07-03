# データ駆動形コントローラチューニング

PID制御などでチューニングをする際に限界感度法やジーグラ・ニコルス法などによる調整や試行錯誤的に調整する方法がよく取られているが、このページでは一回の実験の入力信号と出力信号と望まれるフィードバックループの規範モデルを用いてチューニングを行う方法を説明する

## 前提
- $u_0$ 入力信号
- $y_0$ システムに$u_0$を与えたときの出力
- $T_d(s)$ チューニングするときの規範モデル  
    時定数0.5秒の1次遅れを規範モデルにする場合

    $$
    T_d(s) = \frac{1}{0.5s + 1}
    $$

- $C(s, \rho)$ コントローラ  
    $\rho$はコントローラのパラメータでPIDの場合$\rho = (Kp, Ki, Kd)$


## FRIT(Fictitious Reference Iterative Turning)
!!! memo
    Fictitious : 架空の  

疑似参照信号$\tilde{r}(s, \rho)$を以下のように定義する

$$
\begin{array}{lll}
\tilde{r}(s, \rho) = C^{-1}(s, \rho)u_0 + u_0 \\
J(\rho) = || y_0 - T_d(s)\tilde{r}(s, \rho) ||^2
\end{array}
$$

以下の評価関数の最小化問題について最適化を行いコントローラのパラメータ$\rho$を求める

$$
\underset{\rho}{\text{min}} || y_0 - T_d(s)\tilde{r}(s, \rho) ||^2
$$

## VRFT(Virtual Reference Feedback Turning)

プレフィルタ$L(s)$と規範モデルから以下を定義

$$
\begin{array}{lll}
u_f = L(s) u_0 \\
e_f = L(s) \left(\frac{1}{T_d(s)}y_0 - y_0 \right) 
\end{array}
$$

以下の評価関数の最小化問題について最適化を行いコントローラのパラメータ$\rho$を求める

$$
\underset{\rho}{\text{min}} || u_f - C(s, \rho)e_f ||^2
$$

## チューニングにおける注意点
### チューニングに使用する状態量の信号を得る時は開ループ・閉ループを問わない
FRIT, VRFTともに$u_0$,$y_0$は開ループ/閉ループのどちらで得ても問題ない

### 出力信号が十分にシステムの特性を励起している必要がある
$y0$には十分に高い周波数までの特性を含んでいる必要がある。例えば$y_0$がsin波であり単一周波数の特性しか含まないとなるとチューニングが正しく行われない可能性が高い

### 使えるソルバの違い
PIDコントローラの場合、最適化の際にFRITでは非線形最適化を行う必要がある。VRFTでは最小二乗法で最適化を行うことができる

### VRFTのプレフィルタ
シンプルに$L(s) = T_d(s)$とすることでもチューニングは可能である


## 参考文献
- [職場で使えるデータ駆動型PIDオートチューニング入門 : FRITとVRFT編 制御・AI・センシングシリーズ](https://www.amazon.co.jp/dp/B0C9MY8LNY?ref_=cm_sw_r_tw_ud_dp_817NX2TC35ZNNT16Z0CS)
- [データ駆動型制御器チューニング―FRITアプローチ―](https://www.jstage.jst.go.jp/article/sicejl/52/10/52_853/_article/-char/ja)
- M.C. Campi and A. Lecchini and S.M. Savaresi. (2002). Virtual reference feedback tuning: a direct method for the design of feedback controllers. Automatica, 38(8), 1337-1346