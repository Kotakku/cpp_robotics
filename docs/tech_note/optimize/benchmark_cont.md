# 連続関数最適化のベンチマーク関数

最適化手法の比較などに使用されるベンチマーク用の関数は以下を考慮して作られたものが多い。

- 変数によって取る範囲が違う(悪スケール性)
- 変数が独立でなく変数ごとの関数の和として表現できない(変数間依存性)
- 局所解が沢山存在するもの(多峰性)

例として以下の関数が挙げられる。

- Sphere関数
- Ellipsoid関数
- k-tablet関数
- Rosenbrock関数(star型/chain型)
- Bohachevsky関数
- Ackley関数
- Scaffer関数
- Rastrign関数

## 参考文献
- [最適化手法評価のためのベンチマーク関数【Pythonプログラム付】](https://yuyumoyuyu.com/2021/03/21/benchmarkfunction/)
- [最適化アルゴリズムを評価するベンチマーク関数まとめ](https://qiita.com/tomitomi3/items/d4318bf7afbc1c835dda)