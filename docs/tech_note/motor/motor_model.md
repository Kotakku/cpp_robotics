# モーターの状態空間表現

```math
\begin{array}{l}
\frac{\rm{d}}{\rm{dt}}
\begin{bmatrix}
i(t)\\
\omega(t)
\end{bmatrix}
=
\begin{bmatrix}
-\frac{R}{L} & -\frac{K_e}{L} \\
\frac{K_t}{J} & 0
\end{bmatrix}
\begin{bmatrix}
i(t)\\
\omega(t)
\end{bmatrix}

+ 

\begin{bmatrix}
\frac{1}{L}\\
0
\end{bmatrix}
V(t) \\

y(t)
=
\begin{bmatrix}
0 & 1
\end{bmatrix}
\begin{bmatrix}
i(t)\\
\omega(t)
\end{bmatrix}
\end{array}
```


## 参考文献
- [現代制御 2次システム(RL回路+モーター)の状態方程式](http://arduinopid.web.fc2.com/O2.html)