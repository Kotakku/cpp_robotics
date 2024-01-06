# 状態空間表現

以下のシステムを表すオブジェクトを作成します。またシステムが可制御・可観測であるかを判定します

$$
\begin{align}
\frac{d}{dt}
\left [\begin{array}{c}
x_1 \\
x_2
\end{array}
\right ]
&=
\left [\begin{array}{c}
0 & 1 \\
1 & 0.5
\end{array}
\right ]
\left [\begin{array}{c}
x_1 \\
x_2
\end{array}
\right ]
+
\left [\begin{array}{c}
0 \\
0.5
\end{array}
\right ]
u\\
y &=
\left [\begin{array}{c}
1 & 0
\end{array}
\right ]
\left [\begin{array}{c}
x_1 \\
x_2
\end{array}
\right ]
\end{align}
$$

{{ include_example("example/system/state_space_system.cpp") }}

出力
 
```
Controllable
Observable
```