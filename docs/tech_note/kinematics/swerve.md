# 独立4輪ステア移動機構

図の右上のホイールについての速度ベクトルを考えると

$$
\vec{v_1} = \left( 
    \dot{x} -r \dot{\theta}\sin{\theta}, 
    \dot{y} +r \dot{\theta}\cos{\theta}
\right)
$$

この時図の右上のホイールの操舵角度は

$$
\theta_1 = \tan^{-1}\dfrac{\dot{y} +r \dot{\theta}\cos{\theta}}{\dot{x} -r \dot{\theta}\sin{\theta}}
$$

4輪分を上記のように導出すると以下のようになる

$$
\begin{array}{}
\vec{v_1} = \left( 
    \dot{x} -r \dot{\theta}\sin{\theta}, 
    \dot{y} +r \dot{\theta}\cos{\theta}
\right)\\
\vec{v_2} = \left( 
    \dot{x} -r \dot{\theta}\cos{\theta}, 
    \dot{y} -r \dot{\theta}\sin{\theta}
\right)\\
\vec{v_3} = \left( 
    \dot{x} +r \dot{\theta}\sin{\theta}, 
    \dot{y} -r \dot{\theta}\cos{\theta}
\right)\\
\vec{v_4} = \left( 
    \dot{x} +r \dot{\theta}\cos{\theta}, 
    \dot{y} +r \dot{\theta}\sin{\theta}
\right)
\end{array}
$$

$$
\begin{array}{}
\theta_1 = \tan^{-1}\dfrac{\dot{y} +r \dot{\theta}\cos{\theta}}{\dot{x} -r \dot{\theta}\sin{\theta}}\\
\theta_2 = \tan^{-1}\dfrac{\dot{y} -r \dot{\theta}\sin{\theta}}{\dot{x} -r \dot{\theta}\cos{\theta}}\\
\theta_3 = \tan^{-1}\dfrac{\dot{y} -r \dot{\theta}\cos{\theta}}{\dot{x} +r \dot{\theta}\sin{\theta}}\\
\theta_4 = \tan^{-1}\dfrac{\dot{y} +r \dot{\theta}\sin{\theta}}{\dot{x} +r \dot{\theta}\cos{\theta}}\\
\end{array}
$$

制御する際には操舵角の角度制御の目標値に$\theta_j$を与え、ホイールの速度制御の目標値に$|\vec{v_j}|$を与える。

!!! note
    Todo: 図を載せる

## 参考文献
- [ロボコンにおける自動走行ロボットの足回りの研究](https://ir.library.osaka-u.ac.jp/repo/ouka/all/60351/28-34-工-田中.pdf)  
    独立4輪ステア移動機構の逆運動学についてこのページと参考文献で$v_1$についての$\cos, \sin$が異なっている箇所が存在するが導出を考えると参考文献の方に誤植があると考えられる