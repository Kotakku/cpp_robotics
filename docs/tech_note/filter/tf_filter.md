# 伝達関数で表現されるフィルタ

| 説明 | 伝達関数 | 離散伝達関数(双一次変換) | 
| :----: | :--------: | :------------: | 
| 積分要素 |  $`\dfrac{1}{s}`$   | $`\dfrac{T}{2} \dfrac{z+1}{z-1}`$ | 
| ローパスフィルタ | $`\dfrac{\omega}{s + \omega}`$ | $`\dfrac{T\omega z + T\omega}{(T\omega + 2)z + (T\omega - 2)}`$ |
| ハイパスフィルタ | $`\dfrac{s}{s + \omega}`$ | $`\dfrac{2z - 2}{(T\omega + 2)z + (T\omega - 2)}`$ |
| バンドパスフィルタ | $`\dfrac{2\zeta\omega s}{s^2 + 2\zeta\omega s + \omega^2}`$ | $`\dfrac{(4T\zeta\omega)z^2 + (-4T\zeta\omega) }{(4+ 4T\zeta \omega +T^2\omega^2)z^2 + (-8+2T^2\omega^2)z + (4-4T\zeta \omega + T^2\omega^2)}`$ |
| ノッチフィルタ | $`\dfrac{s^2 + \omega^2}{s^2 + 2\zeta\omega s + \omega^2}`$ | $`\dfrac{(4+T^2\omega^2)z^2 + (-8+2T^2\omega^2)z + (4+T^2\omega^2)}{(4+ 4T\zeta \omega +T^2\omega^2)z^2 + (-8+2T^2\omega^2)z + (4-4T\zeta \omega + T^2\omega^2)}`$ |

| 説明 | 伝達関数 |
| :----: | :--------: |
| バターワースフィルタ(2次) | $`\dfrac{1}{\tau^2s^2 + \sqrt{2} \tau s + 1 }`$ |
| バターワースフィルタ(3次) | $`\dfrac{1}{(\tau s + 1)(\tau^2s^2 + \tau s + 1) }`$ |
| バターワースフィルタ(4次) | $`\dfrac{1}{(\tau^2s^2 + 0.7654 \tau s + 1)(\tau^2s^2 + 1.8478\tau s + 1) }`$ |
| バターワースフィルタ(5次) | $`\dfrac{1}{(\tau s + 1)(\tau^2s^2 + 0.6180\tau s + 1)(\tau^2s^2 + 1.6180\tau s + 1) }`$|
| バターワースフィルタ(n次: nが偶数) | $`\dfrac{1}{ \prod_{k=1}{\frac{n}{2}} \left[ \tau^2 s^2 -2 \tau s \cos \left( \dfrac{2k+n-1}{2n}\pi \right) + 1 \right] }`$ |
| バターワースフィルタ(n次: nが奇数) | $`\dfrac{1}{ (\tau s + 1) \prod_{k=1}{\frac{n-1}{2}} \left[ \tau^2s^2 - 2 \tau s \cos \left( \dfrac{2k+n-1}{2n}\pi \right) + 1 \right] }`$ |

## 参考文献
- [双一次変換 (Wikipedia)](https://ja.wikipedia.org/wiki/%E5%8F%8C%E4%B8%80%E6%AC%A1%E5%A4%89%E6%8F%9B)
- [バターワースフィルタ](https://ja.wikipedia.org/wiki/%E3%83%90%E3%82%BF%E3%83%BC%E3%83%AF%E3%83%BC%E3%82%B9%E3%83%95%E3%82%A3%E3%83%AB%E3%82%BF)
- [バターワース型ローパス・フィルタ](https://cc.cqpub.co.jp/system/contents/2067/)