# 伝達関数

伝達関数とは1入力1出力システムの入出力関係を表す関数の一種である。
システムの全ての変数の初期値を0として入力信号と出力信号のラプラス変換を$`X(s)`$,$`Y(s)`$とすると 

```math
G(s) = \frac{Y(s)}{X(s)}
```

で表される。

時間領域の微分方程式等で表されるモデルをラプラス変換により複素平面に写像を取る。
周波数領域の周波数伝達関数は安定性などの解析・評価に用いられる。
特性の評価方法としてボード線図やナイキスト線図を用いたものがある。

伝達関数は分母分子の係数を行列に配置することで可制御正準形の状態空間表現に変換することができる。

## 伝達関数例
### 積分要素
```math
G(s) = \frac{1}{s}
```

### 微分要素
```math
G(s) = s
```

### 1次遅れ要素
```math
G(s) = \frac{1}{Ts + 1}
```

### 2次遅れ要素
```math
G(s) = \frac{\omega^2}{s^2 + 2\zeta\omega + \omega^2}
```

### 無駄時間要素
```math
G(s) = e^{-sT}
```