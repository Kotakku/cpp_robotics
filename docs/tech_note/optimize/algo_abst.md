# アルゴリズム概要

ここでは変数・制約に取る値が整数に制限されない最適化問題について概要をまとめる

## 単体法(シンプレックス法)
線形計画問題で使用されるDantzigによって提案された手法。実行可能領域の境界に沿って解を更新する。後にカーマーカーが提案した多項式時間アルゴリズムである楕円体法によって普及した内点法と並んで広く使われている。

> 単体法という名前は、Dantzigが提案した特殊な図解法においては、アルゴリズムの進行に従って単体が下に落ちていくように見えることに由来する。


```math
\text{max} \space z = Cx \\
\text{s.t.} \space Ax < b

```

## 有効制約法
有効制約法は凸二次計画問題に対して用いられる。

```math
\text{min} \space f(x) = \frac{1}{2}x^TQx + cx \\
\text{s.t.} \space a_i^T x \geq b_i
```

## 内点法
バリア法のような実行可能領域の内部を進むように解を更新する手法の総称  
初期解が実行可能領域にない場合、実行可能領域に解を移動させる手段が必要になる

> 点列を生成する方法によって、アフィン変換法、ポテンシャル減少法、パス追跡法などに分類される

> 与えられた問題を直接扱う方法(主内点法)、その双対問題を扱う方法(双対内点法)、主問題と双対問題を同時に解く方法(主双対内点法)に分けられる

### 主内点法
!!! Note
    Todo
### 主双対内点法
!!! Note
    Todo
### 主双対内点法
!!! Note
    Todo
## 外点法
ペナルティ法に代表される実行可能領域外での反復を許す手法の総称  
内点法と異なり初期解が実行可能領域外であっても反復計算が可能であるがペナルティ関数のスケール調整によっては実行可能領域外に収束する場合がある

## 逐次二次計画法(SQP法)
NLP問題に対して現在の解付近で問題を二次近似し、その二次計画問題の解を探索方向として反復計算を行う手法の総称

- 準ニュートン法による解く手法
- 信頼領域法により解く手法
- 逐次線形二次計画法(SLP-SQP)
- 逐次最小二乗計画法(SLSQP)

などがある  
基本的に違いは問題を二次近似する方法と、近似した二次問題から探索方向を決定する方法への違い

### 準ニュートン法
ヘッシアンの代わりにBFGS法で近似したB行列を使用したQP問題を作成し、連立方程式を解く
### 信頼領域法
!!! Note
    Todo

### 逐次線形二次計画法(SLP-SQP, SLQP)
制約充足のためのフェーズと目的関数値最小化のフェーズという二つのフェーズから構成される他のSQP法とは毛色が違う最適化手法

### 逐次最小二乗計画法(SLSQP)
「逐次最小二乗計画法」という日本語訳はあってないか日本語訳が当てられていない可能性がある  
MATLABやScipyで導入されているSLSQPは1988年Kraftらの発表したソフトウェアパッケージに同梱され言語はFortran  
論文タイトルは以下

> Kraft, D. A software package for sequential quadratic
   programming. 1988. Tech. Rep. DFVLR-FB 88-28, DLR German Aerospace
   Center -- Institute for Flight Mechanics, Koln, Germany.



## 参考文献
- [最適化問題](https://ja.wikipedia.org/wiki/%E6%9C%80%E9%81%A9%E5%8C%96%E5%95%8F%E9%A1%8C)
- [シンプレックス法](https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%B3%E3%83%97%E3%83%AC%E3%83%83%E3%82%AF%E3%82%B9%E6%B3%95)
- [B.2 単体法・有効制約法](https://www.msi.co.jp/nuopt/docs/v18/manual/html/0B-02-00.html)
- [内点法](https://ja.wikipedia.org/wiki/%E5%86%85%E7%82%B9%E6%B3%95)
    - [カーマーカーのアルゴリズム](https://ja.wikipedia.org/wiki/%E3%82%AB%E3%83%BC%E3%83%9E%E3%83%BC%E3%82%AB%E3%83%BC%E3%81%AE%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0)
    - [B.1 内点法](https://www.msi.co.jp/nuopt/docs/v18/manual/html/0B-01-00.html)
- [B.7 外点法](https://www.msi.co.jp/nuopt/docs/v18/manual/html/0B-07-00.html)
- [B.3 逐次二次計画（SQP）法](https://www.msi.co.jp/nuopt/docs/v18/manual/html/0B-03-00.html)
    - [SQPとSLSQPの違いについて](https://stats.stackexchange.com/questions/268290/in-mathematical-optimization-are-sequential-quadratic-programming-and-sequentia)