# カルマンフィルタ

カルマンフィルタとは線形の運動モデルと観測モデルから状態を推定するフィルタの一種である

## 離散化モデル
サンプリング周期で離散化した線形モデルが以下で与えられるとする。

$$
\begin{array}{lll}
x(t) = Fx(t-1) + Gu(t) + w(t) \\
z(t) = Hx(t) + v(t)
\end{array}
$$

ここで各変数は以下の通り  
$x \in \mathbb{R}^{n \times 1}$ : 状態量  
$u \in \mathbb{R}^{r \times 1}$ : 制御量  
$z \in \mathbb{R}^{p \times 1}$ : 観測量  
$F \in \mathbb{R}^{n \times n}$ : 状態遷移行列  
$G \in \mathbb{R}^{n \times r}$ : 制御行列  
$H \in \mathbb{R}^{p \times n}$ : 観測行列  

$Q \in \mathbb{R}^{n \times n}$ : システムノイズの共分散行列  
$w \in \mathbb{R}^{n \times 1}$ : システムノイズ $N[0, Q]$に従う  
$R \in \mathbb{R}^{p \times p}$ : 観測ノイズの共分散行列  
$v \in \mathbb{R}^{p \times 1}$ : 観測ノイズ $N[0, R]$に従う

## カルマンフィルタ
システムに与えた入力$u$と誤差がある観測量$z$から現在の状態量$\bar{x}$を推定する。

カルマンフィルタには大きく分けて予測ステップとフィルタリングステップに分けられる。

### 予測ステップ
#### 事前状態推定
システムのモデルを使って、前ステップの状態量と入力量から現在の状態量がどうなるかを計算する

$$
\bar{x} = F\bar{x} + Gu
$$

#### 事前誤差共分散行列の更新
事前状態推定で状態を更新したことによる状態の確かさを更新する

$$
P = FPF^T + Q
$$

### フィルタリングステップ
#### カルマンゲインの計算
状態の不確かさと観測の不確かさからカルマンゲインを計算する

$$
K = PH^T(HPH^T + R)^-1
$$

#### 状態推定
誤差付きの観測量とシステムのモデルから予測される観測量の差分をカルマンゲインで調整してフィードバックする

$$
\bar{x} = \bar{x} + K(z - H\bar{x})
$$

#### 事後誤差共分散行列の更新
状態推定の更新の分の状態量の不確かさを更新する

$$
P = (I -KH)P
$$

## 参考文献
- [カルマンフィルタってなに？](https://qiita.com/IshitaTakeshi/items/740ac7e9b549eee4cc04)
- [カルマンフィルター](https://ja.wikipedia.org/wiki/%E3%82%AB%E3%83%AB%E3%83%9E%E3%83%B3%E3%83%95%E3%82%A3%E3%83%AB%E3%82%BF%E3%83%BC)
- [裏口からのカルマンフィルタ入門 (YouTube)](https://www.youtube.com/watch?v=zVAq_3HClGs)