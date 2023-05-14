# 直線探索

連続最適化問題における逐次最適化において探索方向を決めた後にどれだけその方向に進むかのステップサイズを決定する手法

目的関数$f$に対して$g$を以下のように定義し、$\alpha$について最小化することを目的とする

$$
g(\alpha) = f(\bf{x}^{(k)} + \alpha \bf{d}^{(k)})
$$

## 囲い込み法
ステップ幅を1から開始し反復ごとに0より大きく1より小さい定数をかけてステップ幅を小さくしていく。関数の値が小さくなる限りこの反復を続ける

## アルミホ条件
ある定数$0 < \tau < 1$に対して以下を満たすようなステップ幅を採用する

$$
g(\alpha) \leq g(0) + \tau g'(0) \alpha
$$

ここで$f$は微分可能であるとし

$$
g'(\alpha) = \Delta f(\bf{x}^{(k)} + \alpha \bf{d}^{(k)})^T \bf{d}^{(k)}
$$

## ウルフ条件
ある定数$0 < \tau_1 < \tau_2 < 1$に対して以下を満たすようなステップ幅を採用する

$$
\begin{array}
g(\alpha) \leq g(0) + \tau_1 g'(0) \alpha  \\
g'(\alpha) \geq \tau_2 g'(\alpha)
\end{array}
$$

## 参考文献
- [しっかり学ぶ数理最適化](https://sites.google.com/view/introduction-to-optimization/main)
- [直線探索におけるArmijo条件とWolfe条件を図から理解する](https://tm23forest.com/contents/linesearch-armijo-wolfe-condition-explained-visually)