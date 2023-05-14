# 離散化

コンピュータでシステムモデルを扱う際にはふるまいをシミュレーションするために連続時間領域やs領域で与えられているシステムを離散化する必要がある。以下に離散化の手法について述べる。

## 離散化手法と方法
- ZOH法(0次ホールド)
- 後退差分法
- オイラー法
- 双一次変換

## 伝達関数の双一次変換による離散化

伝達関数

$$
G(s) = \frac{num(s)}{den(s)}
$$

に対して

$$
s = \frac{2}{T} \frac{z-1}{z+1}
$$

としてz領域の伝達関数に変換した後

$$
\frac{y}{u} = \frac{num(z)}{den(z)}
$$

の形を変形することで

$$
y = f(u, u^{-1}, u^{-2} \cdots, y^{-1}, y^{-2} \cdots)
$$

を得る。


## 状態空間表現の双一次変換による離散化
!!! waring
    Todo


## 参考文献
- [連続時間システムの離散化手法の比較 [Python Scipy]](https://blog.chachay.org/2021/05/discretization.html)
- [離散化 (Wikipedia)](https://ja.wikipedia.org/wiki/%E9%9B%A2%E6%95%A3%E5%8C%96)
- [双一次変換 (Wikipedia)](https://ja.wikipedia.org/wiki/%E5%8F%8C%E4%B8%80%E6%AC%A1%E5%A4%89%E6%8F%9B)
- [連続系の代表的な伝達関数の双一次変換による離散化](https://negligible.hatenablog.com/entry/2020/06/28/020336)