# iLQR/DDP/AL-iLQR

## iLQR
### 問題設定
ダイナミクス
$$
x_{k+1} = f_k(x_k, u_k)
$$

評価関数
$$
J = \phi(x_N) + \Sigma l_k(x_k, u_k)

\phi(x_N) = 
\Sigma l_k(x_k, u_k) =

$$

$$
\delta Q_k = 
$$

Qの1次近似
$$
Q_{xx}
Q_{uu}
Q_{ux}
Q_u
Q_x
$$

$$
\dealta u_k^*
$$

## DDP
iLQRではQを1次近似したがDDPでは2次近似したものを使う

## FDDP


## AL-iLQR
iLQR/DDPがダイナミクスのみの問題設定から出発するのに対して、制約を考えラグラジアンから出発するmodeified iLQRをベースとしたのがAL-iLQRである
AL-iLQRをベースとした制約付き起動最適化ソルバであるALTROに使用されている


## 参考文献
- [微分動的計画法](https://ja.wikipedia.org/wiki/%E5%BE%AE%E5%88%86%E5%8B%95%E7%9A%84%E8%A8%88%E7%94%BB%E6%B3%95)
- [LQR/iLQRを理解する](https://qiita.com/PozihameBaystar/items/45fa9fd96ae0a69ec31a)
- [Differential Dynamic Programming(DDP)/iterative LQR(iLQR)/Sequential LQR(SLQ)](https://blog.syundo.org/post/20180917-ddp-ilqr-slq/)
- [AL-iLQR Tutorial](https://bjack205.github.io/papers/AL_iLQR_Tutorial.pdf)
- [微分動的計画法の近年の動向：制約付き軌道計画問題へのアプローチ ](https://speakerdeck.com/ssryuki/a-survey-of-constrained-differential-dynamics-programming)