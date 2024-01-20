# cpp_robotics

制御工学、最適化、逆運動学などロボティクスに多用される技術をパッケージ化したライブラリ

## 機能
### 伝達関数・状態空間表現の表現とシミュレーション
伝達関数や状態空間表現クラスを使用してシステムを表現し、応答をシミュレーションする

### 様々な制御器による制御系の実現
PID制御器、LQR、極配置等による状態フィードバック、MPC等の制御系を構成する

### 最適化
連続関数の最適化で最適制御の実現を補助

### フィルタ
ローパスフィルタやハイパスフィルタをはじめ、速度制限フィルタや加速度制限フィルタ、カルマンフィルタ等

### 逆運動学
移動機構やロボットのアームの逆運動学を解くためのクラス

### 単位クラス
SI単位系を実装してあり物理的な意味を対応させながらのコーディングが可能  
組立単位にも対応

### 頻繁に使用するベクトル演算クラス
Vector2 Vector3 Vector4 Quaternion Transformを用意
ベクトル同士の演算やノルム、回転の処理を簡単に記述

### モータークラス
DCモーターのモデルを使ってシミュレーション

### パスプランニング
A*、wave propagation、スプライン曲線、Dubins曲線

### その他アルゴリズム
Kd木, k-means法, ICPマッチング等