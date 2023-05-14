# メカナム移動機構

図の右上のホイールについてメカナムホイールの樽の軸方向のみに力が作用することに注意すると

$$
v_1 \cos \frac{\pi}{4} = - \dot{x} \cos \frac{\pi}{4} + \dot{y} \cos \frac{\pi}{4} + l \dot{\theta} \cos \left( \alpha - \frac{\pi}{4} \right)
$$

式整理して

$$
v_1 = - \dot{x} + \dot{y} + (a+b)\dot{\theta} 
$$

ここで右辺第3項の$\dot{\theta}$についての式変形について下記のようになる

$$
    \frac{l \cos \left( \alpha - \frac{\pi}{4} \right)}{\cos \frac{\pi}{4} } \dot{\theta}\\
$$

分子に加法定理を適用

$$
\begin{array}{cc}
    \frac{l \cos \left( \alpha - \frac{\pi}{4} \right)}{\cos \frac{\pi}{4} } \dot{\theta} \\
    \Leftrightarrow 
    \frac{l \left\{ \cos \alpha \cos \frac{\pi}{4} + \sin \alpha \sin \frac{\pi}{4} \right\}}
    {\cos \frac{\pi}{4} } \dot{\theta} \\
    \Leftrightarrow 
    \frac{l \left\{ \cos \alpha \cos \frac{\pi}{4} + \sin \alpha \cos \frac{\pi}{4} \right\}}
    {\cos \frac{\pi}{4} } \dot{\theta} \\
    \Leftrightarrow 
    l \left( \cos \alpha + \sin \alpha \right) \dot{\theta}\\
    \Leftrightarrow 
    l \left( \frac{a}{l} + \frac{b}{l} \right) \dot{\theta}\\
    \Leftrightarrow 
    \left(a +b \right) \dot{\theta}
\end{array}
$$

4輪分を上記のように導出すると以下のようになる

$$
\begin{bmatrix}
v_1 \\
v_2 \\
v_3 \\
v_4 \\
\end{bmatrix}
=
\begin{bmatrix}
-1 &  1 & (a+b) \\
-1 & -1 & (a+b) \\
 1 & -1 & (a+b) \\
 1 &  1 & (a+b) \\
\end{bmatrix}
\begin{bmatrix}
\dot{x} \\
\dot{y} \\
\dot{\theta}
\end{bmatrix}
$$

!!! note
    Todo: 図を載せる

## 参考文献
- [ロボコンにおける自動走行ロボットの足回りの研究](https://ir.library.osaka-u.ac.jp/repo/ouka/all/60351/28-34-工-田中.pdf)
    参考文献とはタイヤの回転方向の定義が異なるため逆運動学が異なることに注意