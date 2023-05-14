# 数値微分法

## 1階差分法
与えられた関数の与えられた変数周りでの1階微分を求める方法

何もなければ中央差分方を使うのが良い

$$
\left(\frac{\partial f}{\partial x}\right)_i = \frac{f_{i+1} - f_{i-1}}{2\Delta x} 
$$


この他簡単な方法としては後退差分法がある

$$
\left(\frac{\partial f}{\partial x}\right)_i = \frac{f_i - f_{i-1}}{\Delta x} 
$$

## 2階差分法
与えられた関数の与えられた変数周りでの2階微分を求める方法

これも何もなければ中央差分法を使うのが良い

$$
\left(\frac{\partial^2 f}{\partial^2 x}\right)_i = \frac{f_{i+1} - 2f_{i} + f_{i-1}}{\Delta x^2} 
$$