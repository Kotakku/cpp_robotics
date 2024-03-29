# 伝達関数

伝達関数とは1入力1出力システムの入出力関係を表す関数の一種である。
システムの全ての変数の初期値を0として入力信号と出力信号のラプラス変換を$X(s)$,$Y(s)$とすると 

$$
G(s) = \frac{Y(s)}{X(s)}
$$

で表される。

時間領域の微分方程式等で表されるモデルをラプラス変換により複素平面に写像を取る。
周波数領域の周波数伝達関数は安定性などの解析・評価に用いられる。
特性の評価方法としてボード線図やナイキスト線図を用いたものがある。

伝達関数は分母分子の係数を行列に配置することで可制御正準形の状態空間表現に変換することができる。

## 伝達関数例
| 説明 | 伝達関数 | 離散伝達関数(双一次変換) | 
| :----: | :--------: | :------------: | 
| 積分要素 |  $\dfrac{1}{s}$   | $\dfrac{T}{2} \dfrac{z+1}{z-1}$ | 
| 微分要素 | $s$ | - |
| 無駄時間要素 | $e^{-s\tau}$ | - |
| 1次遅れ | $\dfrac{\omega}{s + \omega}$ | $\dfrac{T\omega z + T\omega}{(T\omega + 2)z + (T\omega - 2)}$ |
| 2次遅れ | $\dfrac{\omega^2}{s^2 + 2\zeta\omega s + \omega^2}$ | $\dfrac{(T^2\omega^2)z^2 + (2T^2\omega^2)z + (T^2\omega^2)}{(4+ 4T\zeta \omega +T^2\omega^2)z^2 + (-8+2T^2\omega^2)z + (4-4T\zeta \omega + T^2\omega^2)}$ |

## 周波数と時定数
伝達関数やボード線図で議論するときは周波数の単位が\[rad/s\]であることが多い。\[Hz\]との関係は

$$
\omega = 2\pi f
$$

時定数と周波数の関係は

$$
\tau = \frac{1}{\omega}
$$

## 参考文献