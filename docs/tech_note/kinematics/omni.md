# オムニ移動機構

## 3輪オムニ
図の上のホイールについて

$$
v_1 = - \dot{x} \sin \alpha + \dot{y} \cos \alpha + L \dot{\theta}
$$

3輪分を上記のように導出すると以下のようになる

$$
\begin{bmatrix}
v_1 \\
v_2 \\
v_3 \\
\end{bmatrix}
=
\begin{bmatrix}
-\sin \alpha & \cos\alpha & L \\
-\sin \left( \alpha + \dfrac{2}{3}\pi \right) & \cos \left( \alpha + \dfrac{2}{3}\pi \right) & L \\
-\sin \left( \alpha - \dfrac{2}{3}\pi \right) & \cos \left( \alpha - \dfrac{2}{3}\pi \right) & L \\
\end{bmatrix}
\begin{bmatrix}
\dot{x} \\
\dot{y} \\
\dot{\theta}
\end{bmatrix}
$$

!!! note
    Todo: 図を載せる

## 4輪オムニ
各車輪ごとに考えることは3輪オムニと変わらない

$$
\begin{bmatrix}
v_1 \\
v_2 \\
v_3 \\
v_4 \\
\end{bmatrix}
=
\begin{bmatrix}
-\sin \alpha & \cos\alpha & L \\
-\sin \left( \alpha + \dfrac{\pi}{2} \right) & \cos \left( \alpha + \dfrac{\pi}{2} \right) & L \\
-\sin \left( \alpha + \pi \right) & \cos \left( \alpha + \pi \right) & L \\
-\sin \left( \alpha + \dfrac{3\pi}{2} \right) & \cos \left( \alpha + \dfrac{3\pi}{2} \right) & L \\
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