# PID

古典制御の代表的なフィードバック制御器。システムへの入力を、状態量と目標値の差分、その積分値、微分値によって決定する。3つの値に対してゲインをかけシステムへの応答を調整する。

$$
u(t) = K_p e + K_i \int_0^t e dt + K_d \dot{e}
$$

PID制御器は上記のように表され、$K_p$, $K_i$, $K_d$をそれぞれ比例ゲイン、積分ゲイン、微分ゲインと呼ぶ。

積分項、微分項の係数を以下のように表記することもできる。

$$
u(t) = K_p \left( e + \frac{1}{T_i} \int_0^t e dt + T_d \dot{e} \right) \text{ ただし}K_i=K_p/T_i, Kd = K_pT_d
$$

ここで$T_i$は積分時間と呼ばれ$T_d$は微分時間と呼ばれる。

## パラメータ調整法
### 限界感度法
### ステップ応答法
### CHR法

## アンチワインドアップ
積分項が有効なPID制御器の場合、偏差が長い時間に渡って存在すると積分値が大きくなり入力量が飽和することがある。これを防ぐための手法について解説する。

### 積分の停止
一番簡単な手法として積分を停止させることが考えられる。これはPID制御の出力が飽和したときには積分項への入力をそれ以上積分項が大きくならないようにする手法である。簡単であるが人によって実装方法にゆらぎが出やすい

### 自動整合
自動整合や逆解析と呼ばれるこの手法は、純粋なPIDの出力と飽和して制限がかかった出力の差分をPD制御器の逆システムを通して積分項へフィードバックする形を取る。

### 速度型PID
アンチワインドアップというわけではないがワインドアップしない形のPID制御器の形として速度型PIDがある。最初に紹介したPID制御器は位置型PIDと呼ばれ対比される。速度型PIDは偏差を一階微分してPIDに入力することでPIDの中から積分要素を排除していることにある。


## 参考文献
- [PID制御](https://ja.wikipedia.org/wiki/PID%E5%88%B6%E5%BE%A1)
- [PID制御とは？仕組みと動作イメージを分かりやすく解説！](https://controlabo.com/pid-control-introduction/)
- [PID制御器のAnti-windup](https://hamachannel.hatenablog.com/entry/2019/01/06/135004)