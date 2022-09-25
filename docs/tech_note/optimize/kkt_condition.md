# KKT条件

## 等式制約付き最適化問題における1次の最適性

```math
\text{min} \space  f(x)\\
\text{s.t.} \space  g_i(x) = 0, \space i = 0, \dots , m\\
x \in \R^n
```
上記の最適問題において1次の最適性は以下  
点$`x^*`$は局所最適解かつ正則。この時以下を満たす$`u^*`$が存在する
```math
\nabla f(x^*) + \Sigma_{i=1}^{m} u_i^* \nabla g_i(x^*) = 0
```

!!! note
    点$`x`$において$`\nabla g_1(x), \dots ,\nabla g_m(x)`$が互いに1次独立ならば点$`x`$は**正則**であるという

## 不等式制約付き最適化問題における1次の最適性
```math
\text{min} \space  f(x)\\
\text{s.t.} \space  g_i(x) \leq 0, \space i = 0, \dots , m\\
x \in \R^n
```
上記の最適問題において1次の最適性は以下  
点$`x^*`$は局所最適解かつ正則。この時以下を満たす$`u^*`$が存在する
```math
\nabla f(x^*) + \Sigma_{i=1}^{m} u_i^* \nabla g_i(x^*) = 0\\
u_i^* g_i(x^*) = 0, \space i = 0, \dots , m\\
u_i^* \geq 0, \space i = 0, \dots , m
```

2式目は**相補性条件**と呼ばれる。$`g_i(x^*)`$が有効な時は$`g_i(x^*)=0`$となり, 有効でない場合は$`u_i^*=0`$となる。



## 参考文献
- [しっかり学ぶ数理最適化](https://sites.google.com/view/introduction-to-optimization/main)