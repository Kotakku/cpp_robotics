# スプライン曲線
## 補間曲線の種類

ロボットの移動やアクチュエータの軌道を作ろうとした時にいくつかの通過点だけを指定して曲線的に補間させて軌道を生成する。補間曲線として以下のようなものがある 

- Bezier曲線(ベジエ曲線)
- Hermite曲線(エルミート曲線)
- Catmull-Rom曲線(キャットムル-ロム曲線?)
- Cubic-Spline曲線(3次スプライン曲線)

この記事では二次元平面上での曲線について述べていく

## Bezier曲線

N個の制御点を使って曲線を作る特徴として 

- 一般に0点目, N-1点目しか通過しない

よって二点間の補間と捉えてもほとんど間違いないだろう

### N次ベジエ曲線

N個の制御点からなるベジエ曲線であるN次ベジエ曲線は次式で表される

```math
P(t) =\sum_{i = 0}^{N-1}B_i J_{N-1, i}(t)
```

ここで $`Bn`$: 制御点の二次元座標($`n`$ = 0, 1⋯$`N`$ − 1) $`JN`$ − 1, $`i`$($`t`$): バーンスタイン基底関数

### バーンスタイン基底関数

```math
J_{n, i}(t) = \left(\begin{array}{c}n\\i\end{array} \right)t^i(1-t)^{n-i}
```

ここで二項係数

```math
\left(\begin{array}{c}n\\i\end{array} \right) = \frac{n!}{i!(n-i)!}
```

二項係数がぱっと出てこないときは[パスカルの三角形](https://www.google.com/search?q=%E3%83%91%E3%82%B9%E3%82%AB%E3%83%AB%E3%81%AE%E4%B8%89%E8%A7%92%E5%BD%A2)を考えると早いかもしれない。$`n`$と$`i`$が与えられたとき上から*n*+1段目の(左から)*i* + 1個目が係数になる

他の曲線との比較のためにN=4とすることが多いのでN=4について書き下すと係数は

```math
\begin{array}{l}
J_{3, 0}(t) = (1-t)^3\\
J_{3, 1}(t) = 3(1-t)^2t\\
J_{3, 2}(t) = 3(1-t)t^2\\
J_{3, 3}(t) = t^3
\end{array}
```

よってベジエ曲線

```math
P(t)=(1-t)^3 B_0 +  3(1-t)^2t B_1 +  3(1-t)t^2 B_2 + t^3 B_3 \quad \quad t \in [0, 1]
```

## Hermite曲線

ベジエ曲線と同様二点間の曲線補間法である。特徴として 

- 始点と終点の位置と速度ベクトルを指定する

始点と終点の位置と速度をそれぞれ次のように置く *P*0, *P*1: 始点と終点の座標 *v*0, *v*1: 始点と終点の速度ベクトル (いずれも二次元のベクトルである)

3次式を以下のように置く
```math
\begin{array}{l}
f_x(t) = a_x t^3 + b_x t^2 + c_x t + d_x\\
f_y(t) = a_y t^3 + b_y t^2 + c_y t + d_y \quad \quad t \in [0, 1]
\end{array}
```

また*P*0等についても*P*0*x*, *P*0*y*が存在する

今、xとyについて操作は同じなのでここからは式を見やすくするためにxyの添字は省略する

*f*(*t*)を微分すると

```math
f(x) = at^3 + bt^2 + ct + d\\
f'(x) = 3at^2 + 2bt + c
```

aからdを求めていく。 与えられたパラメータより  

```math
\begin{array}{l}
f(0) = P_0\\
f(1) = P_1\\
f'(0) = v_0\\
f'(1) = v_1
\end{array}
```

よってt=0に着目すると

```math
d = P_0\\
c = v_0
```

またt=1において

```math
\begin{array}{l}
f(1) = a + b + c + d = P_1 より\\
c = v_0, d=P_0を代入して\\
a + b = P_1 - P_0 - v_0\\
\\
f'(1) = 3a + 2b + c = v_1 より\\
c = v_0を代入して\\
3a + 2b = v_1 - v_0
\end{array}
```

それぞれの式を①,②として②−2×①でaを求めてからbについても解くと

```math
a = 2P_0 - 2P_1 + v_0 + v_1\\
b = -3P_0 + 3P_1 - 2v_0 - v_1
```

よって

```math
\begin{array}{l}
a = 2P_0 - 2P_1 + v_0 + v_1\\
b = -3P_0 + 3P_1 - 2v_0 - v_1\\
c = v_0\\
d = P_0
\end{array}
```

a〜dをx,yそれぞれについて求めて*fx*(*t*),*fy*(*t*)に代入することでHermite曲線を描画できる

メモ書きとして残しておくがtの次数ではなく*P*0, *P*1, *v*0, *v*1についてくくると以下のようになる

```math
\begin{array}{l}
f(t) = \\
(2t^3 - 3t^2 + 1)P_0\\
(-2t^3 + 3t^2)P_1\\
(t^3 -2t^2 + t)v_0\\
(t^3 - t^2)v_1\\

\end{array}
```

## Catmull-Rom曲線

実際問題二点間の補間だけだと足りないことが多いと思う そこでHermite曲線をつなげて作られるCatmull-Rom曲線を考える。特徴は 

- N個(N > 1)の点をすべて通過する曲線を作れる
- Herimite曲線で使った速度ベクトルを必要としない

(本当はHermite曲線とは別にCatmull-曲線ができて同じ3次式だから変換できるよね、の流れな気がするけど文献を見つけられなかった)

i番目の終点をi+1番目の始点にすることで繋がった曲線にはなるが滑らかに繋がった曲線にするための拘束が必要になる

N点からなる曲線のうち端点以外の補間について考える i番目の点における速度を両隣の座標から作ることで滑らかにつなぐ

```math
v_i = \frac{1}{2}(P_{i+1} - P_{i-1})
```

曲線の端点(*i* = 0, *N* − 1)ではこの式が使えないので自身の座標と隣の座標で速度ベクトルを作る

```math
\begin{array}{l}
v_0 = P_1 - P_0\\
v_{N-1} = P_{N-1} - P_{N-2}
\end{array}
```

### tensionについて

!!! info
    Todo

### パラメータ区分について

!!! info
    Todo

## Cubic-Spline曲線

自分が高専ロボコンで参照軌道はこのスプライン曲線だった。

特徴として 

- 入力はCatmull-Romと同じ通過点のみだがより滑らかである
- (もしかしたら少し重い?)

3次スプライン曲線では以下の条件に従うような曲線を方程式を解くことによって求める

```math
\begin{array}{l}
S_j(x_j) = y_j\\
S_j(x_{j+1}) = S_{j+1}(x_{j+1}) = y_{j+1}\\
S'_j(x_{j+1}) = S'_{j+1}(x_{j+1})\\
S''_j(x_{j+1}) = S''_{j+1}(x_{j+1})\\
S'_0(x_{0}) = S'_{n-1}(x_{n}) = 0
\end{array}
```

これらは

- 多項式*S*に*x*を入力すると*y*を出力する
- 多項式*S*のが繋がっていて制御点を通る
- 区間のつなぎ目で速度が連続である
- 区間のつなぎ目で加速度が連続である
- 端点では加速度は0である ことを示す。

## Hermite曲線のパラメータからBezier曲線のパラメータを求める

ベジエ曲線は入力パラメータとして通過しない座標を与えるためパラメータから曲線を想像しづらいためエルミート曲線の入力パラメータから4次ベジエ曲線のパラメータを求める実装がされているコードを見かけることがある。その実装の導出をしていく。

まずそれぞれのパラメータを Bezier曲線: *B*0, *B*1, *B*2, *B*3(制御点) Hermite曲線: *P*0, *P*1, *v*0, *v*1(始点と終点の座標と速度ベクトル) とする。

次にそれぞれ式を書き下し、tの次数ごとに括ると

```math
\begin{array}{l}
P_{bezier}(t) = \\
(-B_0 + 3 B_1 -3 B_2 + B_3)t^3 +\\
(3 B_0 -6 B_1 + 3 B_2)t^2 + \\
(-3 B_0 + 3 B_1)t^1 +\\
(B_0)t^0\\
\end{array}
```

```math
\begin{array}{l}
P_{herimite}(t) = \\
(2 P _0 - 2 P_1 + v_0 + v_1)t^3\\
(-3 P_0 + 3 P_1 -2 v_0  - v_1)t^2\\
(v_0)t^1\\
(P_0)t^0
\end{array}
```

*Pbezier*(*t*) = *Pherimite*(*t*)として恒等式を解くと (*t*0について)

```math
B_0 = P_0
```

(*t*1について)

```math
v_0 = -3 B_0 + 3 B_1\\
B_1 = P_0 + \frac{1}{3}v_0
```

(*t*2について)

```math
-3 P_0 + 3 P_1 -2 v_0  - v_1 = 3 P_0 -6(P_0 + \frac{1}{3} v_0) + 3 B_2\\
B_2 = P_1 - \frac{1}{3} v_1
```

(*t*3について)

```math
2 P _0 - 2 P_1 + v_0 + v_1 = - P_0 + 3(P_0 + \frac{1}{3}v_0) - 3(P_1 - \frac{1}{3}v_1) + B_3\\
B_3 = P_1
```

よって

```math
\begin{array}{l}
B_0 = P_0\\  
B_1 = P_0 + \frac{1}{3}v_0\\
B_2 = P_1 - \frac{1}{3} v_1\\
B_3 = P_1
\end{array}
```

とするとHermite曲線の入力をBezier曲線で扱うことができる。 実装するに当たって

```math
\begin{array}{l}
BP_1 = P_0 + \frac{1}{3}v_0\\
BP_2 = P_1 - \frac{1}{3} v_1
\end{array}
```

と一時変数を宣言していることもある

## Catmull-Rom曲線のパラメータからBezier曲線のパラメータを求める

Hermite曲線のパラメータとして求めていれば代入するだけ

```math
\begin{array}{l}
BP_1 = P_i + \frac{1}{6}(P_{i+1} - P_{i-1})\\
BP_2 = P_{i+1} - \frac{1}{6} (P_{i+2} - P_{i})
\end{array}
```

i=0のとき

```math
\begin{array}{l}
BP_1 = P_0 + \frac{1}{3}(P_1 - P_0)\\
BP_2 = P_{i+1} - \frac{1}{6} (P_{i+2} - P_{i}) (変わらず)
\end{array}
```

i = N-1のとき

```math
\begin{array}{l}
BP_1 = P_i + \frac{1}{6}(P_{i+1} - P_{i-1})  (変わらず)\\
BP_2 = P_{N-1} - \frac{1}{3} (P_{N-1} - P_{N-2})
\end{array}
```

## 任意の三次方程式からBezier曲線のパラメータを求める

任意の三次方程式

```math
f(t) = a t^3 + b t^2 + c t + d
```

についてBezier曲線と恒等式としてパラメータを求める(Hermite->Bezierの時と同じ)

```math
\begin{array}{l}
P_{bezier}(t) = \\
(-B_0 + 3 B_1 -3 B_2 + B_3)t^3 +\\
(3 B_0 -6 B_1 + 3 B_2)t^2 + \\
(-3 B_0 + 3 B_1)t^1 +\\
(B_0)t^0\\
\end{array}
```

よって

```math
\begin{array}{l}
a = B_0 + 3 B_1 -3 B_2 + B_3\\
b = 3 B_0 -6 B_1 + 3 B_2\\
c = -3 B_0 + 3 B_1\\
d = B_0
\end{array}
```

これを解くと

```math
\begin{array}{l}
B_0 = d\\
B_1 = d + \frac{1}{3}c\\
B_2 = \frac{1}{3}b + \frac{2}{3}c + d\\
B_3 = a + b + c + d
\end{array}
```

## 位置・速度・加速度

Bezier曲線の定義よりパラメータとバーンスタイン基底関数による重みをそれぞれ

```math
B = \left[B_0, B_1, B_2, B_3\right]
```

```math
W = \left[
\begin{array}{c}
-t^3 + 3t^2 - 3t + 1\\
3t^3 -6 t^2 +3 t\\
-3 t^3 + t^2\\
t^3
\end{array}
\right]
```

とベクトル表記した場合、位置は次式で表すことができる。

```math
P(t) = B \cdot W
```

ここで*W*を係数と*tn*に分解すると次のようになる

```math
W = W_m T =  
\left [\begin{array}{c}
-1 & 3 & -3 & 1\\
3 & -6 & 3 & 0\\
-3 & 1 & 0 & 0\\
1 & 0 & 0 & 0
\end{array}
\right ]

\left [\begin{array}{c}
t^3\\
t^2\\
t\\
1
\end{array}
\right ]
```

これを使うと位置の式は次のように表すことができる

```math
P(t) = B  W_m T =
\left[B_0, B_1, B_2, B_3\right]

\left [\begin{array}{c}
-1 & 3 & -3 & 1\\
3 & -6 & 3 & 0\\
-3 & 1 & 0 & 0\\
1 & 0 & 0 & 0
\end{array}
\right ]

\left [\begin{array}{c}
t^3\\
t^2\\
t\\
1
\end{array}
\right ]
```

*T*の要素を*t*で1回微分、2回微分してすることで速度、加速度も表現可能である 速度を得たい場合

```math
T = 
\left [\begin{array}{c}
3t^2\\
2t\\
1\\
0
\end{array}
\right ]
```

加速度を得たい場合

```math
T = 
\left [\begin{array}{c}
6t\\
2\\
0\\
0
\end{array}
\right ]
```

## De Casteljau法によるBezier曲線の分割

解析的に連続な関数として曲線が得られても実用上は直線近似して使うみたいなのは そんなとき媒介変数*t*で等分することをまず思いつくだろうが曲率が小さいところで無駄に分割されるかもしれないし、曲率が大きいところで分割が足りずに上手く曲線近似できないかもしれない。直線近似するためには曲率によって分割する区分の長さを変えたほうが近似度から考えると合理的だろう。

Bezier曲線

```math
P(t) =\sum_{i = 0}^{N-1}B_i J_{N-1, i}(t) \quad \quad t \in [0, 1]
```

を*t*0で2つの区間に分割する

```math
P_0(t) = \sum_{i = 0}^{N-1}B_{0i} J_{N-1, i}\left(\frac{t}{t_0}\right) \quad \quad t \in [0, t_0]
```

```math
P_1(t) = \sum_{i = 0}^{N-1}B_{1i} J_{N-1, i}\left( \frac{t-t_0}{1-t_0} \right) \quad \quad t \in [t_0, 1]
```

今、見やすさのために*n* = *N* − 1としておく

```math
P_0(t) = \sum_{i = 0}^{n}B_{0i} J_{n, i}\left(\frac{t}{t_0}\right) \quad \quad t \in [0, t_0]
```

```math
P_1(t) = \sum_{i = 0}^{n}B_{1i} J_{n, i}\left( \frac{t-t_0}{1-t_0} \right) \quad \quad t \in [t_0, 1]
```

このとき*B*0*n*, *B*1*n*の計算は以下のように再帰的に与えられる

```math
\begin{array}{l}
B_i^{(0)} := B_i \quad \quad \quad i = 0, 1 \cdots n\\
B_i^{(j)} := B_i^{(j-1)}(1-t_0) + B_{i+1}^{(j-1)}t_0 i \quad \quad i = 0, 1 \cdots (n-j), \quad  j = 1, 2 \cdots n\\
\end{array}
```

と定義したとき

```math
\begin{array}{l}
B_{0n} = B_0^{(i)}\\
B_{1n}= B_i^{(n-1)}
\end{array}
```

*N* = 4について線形補間関数*lerp*(*a*, *b*, *t*)を定義した上で書き下してみる

```math
lerp(a, b, t) := a(1-t) + bt \quad \quad t \in [0, 1]
```

として分割前の係数*B* = [*B*0, *B*1, *B*2, *B*3],分割後の係数をそれぞれ*SB*0 = [*B*00, *B*01, *B*02, *B*03],*SB*1 = [*B*10, *B*11, *B*12, *B*13]として*t*0で*B*を分割すると

```math
SB_0 = 
\left[ \begin{array}{l}
B_0\\
lerp(B_0, B_1, t_0)\\
lerp(lerp(B_0, B_1, t_0), lerp(B_1, B_2, t_0), t_0)\\
lerp(lerp(lerp(B_0, B_1, t_0), lerp(B_1, B_2, t_0), t_0), lerp(lerp(B_1, B_2, t_0), lerp(B_2, B_3, t_0), t_0), t_0)
\end{array} \right]
```

```math
SB_1 = 
\left[ \begin{array}{l}
lerp(lerp(lerp(B_0, B_1, t_0), lerp(B_1, B_2, t_0), t_0), lerp(lerp(B_1, B_2, t_0), lerp(B_2, B_3, t_0), t_0), t_0)\\
lerp(lerp(B_1, B_2, t_0), lerp(B_2, B_3, t_0), t_0)\\
lerp(B_2, B_3, t_0)\\
B_3
\end{array} \right]
```

## 曲線の長さ

Bezier曲線の長さを求める方法について考えてみる Bezier曲線でない曲線についてはBezier曲線に変換できるのでここでは考えないものとする

### 大体の長さを求めてみる

厳密に考えずにある程度の長さを求めることを考える 下の図よりベジエ曲線の長さは大雑把に見ても|*P*3−*P*0|以上で|*P*1−*P*0| + |*P*2−*P*1| + |*P*3−*P*2|以下であることが見て取れるだろう

![https://img.esa.io/uploads/production/attachments/7911/2021/01/09/35899/a0e2c763-b83c-47c0-a3e2-26e4607b14db.png](https://img.esa.io/uploads/production/attachments/7911/2021/01/09/35899/a0e2c763-b83c-47c0-a3e2-26e4607b14db.png)

(出典：[1.ベジエ曲線とは](http://nakayasu.com/lecture/%E3%83%99%E3%82%B8%E3%82%A7%E6%9B%B2%E7%B7%9A%E7%89%B9%E8%A8%93/7881))

今*MinLength*と*MaxLength*を次のように定義する

```math
\begin{aligned}
MinLnegth &= |P_3-P_0|\\
&= \sqrt{(P_{3x}-P_{0x})^2 + (P_{3y}-P_{0y})^2}\\
MaxLength &= |P_1-P_0| + |P_2-P_1| + |P_3-P_2|\\
&= \sqrt{(P_{1x}-P_{0x})^2 + (P_{1y}-P_{0y})^2} + 
\sqrt{(P_{2x}-P_{1x})^2 + (P_{2y}-P_{1y})^2} +
\sqrt{(P_{3x}-P_{2x})^2 + (P_{3y}-P_{2y})^2}
\end{aligned}
```

(*Pn*は前項まで*Bn*と記述していたけど画像を作るのが面倒くさくて持ってきたのに合わせただけなので誤解しないでね)

この平均を大体の長さとして定義する

```math
EstimateLength = \frac{MinLength + MaxLength}{2}
```

すると誤差は大きくても差の半分である

```math
MaxError = \frac{MaxLength - MinLength}{2}
```

### 許容誤差の情報を使って解像度を最適化する

上記の方法で「大体の」長さが求まる。*MaxError*の値が大きければ曲線の前述の方法で分解してそれぞれについて大体の長さを求める再帰的な処理になるだろう。ここで注意するのは*MaxError*はあくまで*MinLength*と*MaxLength*から見た誤差の最大で精度がほしいからと言って*MaxError*が0.001を下回るまで分割し続けるなんて必要はない。検証はしてないが0.1、小さくても0.05を下回っていれば十分な精度を得られると思う。

### 区間を指定して長さを求める

上で求めた長さは*t*が0から1までの長さと捉えることができる。任意の*t*の区間における長さについて拡張するには区間の分割を活用する

*t*0から*t*1の範囲の長さを求めるとき *t*0 = 0のとき -> *t*1で分割した前半の長さを出す *t*1 = 1のとき -> *t*0で分割して後半の長さを出す それ以外のとき -> 分割を二回行って区間を出してから長さを出す

## 数値的に速度を1にする

媒介変数*t*を用いて*t*を動かしたときに曲線の上を移動する点の速度は一定ではない。Catmull-Rom曲線やCubic-Spline曲線では速度を指定しないため速度について考えにくい。 速度を線形化するような関数を定義して媒介変数として曲線の関数に渡すことになるがこの関数は解析的に求めるのはできない(と思う)ので数値的に実装する方法をとる

!!! info
    Todo
## 曲率

詳細は省略するが忘れがちなので書いておく

曲率*κ*と曲率半径*R*の関係

```math
\kappa = \frac{1}{R}
```

速度ベクトル*v*と加速度ベクトル*a*が与えられたとき

```math
R = \frac{|v|^3}{|v\times a|}
```

## (Todo)任意の座標から一番近い曲線上の点を出す

!!! info
    Todo

## 円弧近似

円周上の二点が与えられたとき、その二点を結ぶ円弧をHermite曲線で近似するためのパラメータを考える。

前提条件として

- 二点は一つの円周上にある

Hermite曲線のパラメータ$P_0$, $P_1$, $v_0$, $v_1$のうち$P_0$, $P_1$は与えられた二点、$v_0$, $v_1$の方向は円に正接で大きさは以下で近似される

```math
\kappa = \frac{4}{3\sqrt{r}}tan\frac{\theta}{4}
```

ここで$\theta$は円弧の角度、$r$は円の半径

またこの近似は$\theta < \pi$のときに有効でありそれ以上では著しく円弧から離れてしまうため注意が必要

## 特殊な条件での円弧近似(式変形)

既知のパラメータ

- $`r`$
- $`P_0`$, $`P_1`$
- $`v_0`$, $`v_1`$の方向

```math
cos\theta = \frac{v_0 \cdot v_1}{|v_0| |v_1|}
```

半角公式

```math
cos\theta = \sqrt{\frac{1+cos\theta}{2}}
```

半角公式

```math
\tan\frac{\theta}{4} = \sqrt{ \frac{1-\cos{ \frac{\theta}{2}}}{1+\cos{\frac{\theta}{2}}}  }
```

```math
\kappa = \frac{4}{3\sqrt{r}}tan\frac{\theta}{4}
```

## 参考文献

- [ベジェ曲線](https://ja.wikipedia.org/wiki/%E3%83%99%E3%82%B8%E3%82%A7%E6%9B%B2%E7%B7%9A)
- [ゲームプログラマのためのパラメトリック曲線入門(Hermite Curve)](https://qiita.com/Pctg-x8/items/47127a770b23b8934fff)
- [t-pot『3次曲線』](https://t-pot.com/program/2_3rdcurve/index.html)
- [コンピュータグラフィクス論](http://research.nii.ac.jp/~takayama/teaching/utokyo-iscg-2019/slides/iscg-2019-modeling1.pdf)
- [簡略化した3次スプライン曲線の生成方法](http://www5d.biglobe.ne.jp/stssk/maze/spline.html)
- [３次スプライン補間の概要とC++, Pythonサンプルコード](https://myenigma.hatenablog.com/entry/2016/10/12/073335)
- [De Casteljau’s algorithm](https://en.wikipedia.org/wiki/De_Casteljau%27s_algorithm)

- [ベジェ曲線で描く円弧と本物の円弧の差（中心角について一般化）](https://cat-in-136.github.io/2014/03/bezier-4-diff.html)