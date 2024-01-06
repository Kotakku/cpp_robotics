# 無制約最適化

簡単な2値関数の最適化を行います。  
最急降下法と準ニュートン法で同じ問題を解いて準ニュートン法では反復回数が少ないことが確認できます。

{{ include_example("example/optimize/optimize_without_constraint.cpp") }}

出力
```
steepest_descent_method
(2 3), itr: 14
quasi_newton_method
(2 3), itr: 2
```