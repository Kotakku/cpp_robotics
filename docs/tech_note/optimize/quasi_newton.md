# 準ニュートン法

準ニュートン法はニュートン法で使用したヘッシアンを使用せず近似したものを使用して関数を最小化する手法である。このとき近似ヘッシアンは正則である必要があるのでBFGS公式を使用して近似ヘッシアンを更新する。

最適化の反復法における解の更新則は
```math
\bm{x}^{(k+1)} = \bm{x}^{(k)} + \alpha \bm{d}^{(k)}
```

準ニュートン法では探索方向を以下のように取る。現在の解周りでの目的関数の2次近似を近似ヘッシアン$`B`$を使って行っている
```math
\bm{d}^{(k)} = - (\bm{B}^{(k)})^{-1} \Delta f(\bm{x}^{(k)})
```
近似ヘッシアン$`B`$は初期化のときには単位行列などを選ぶ


探索方向決定後は直線探索でステップ幅を計算して解を更新する。また、近似ヘッシアン$`B`$をBFGS公式により更新する

## 参考文献
- [しっかり学ぶ数理最適化](https://sites.google.com/view/introduction-to-optimization/main)