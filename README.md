# cpp_robotics

# コンセプト
自分の勉強用とするなら
- 勉強したものの確認用に実装する
- あったら便利そうな機能を実装する
- その他実装してみたい機能を実装する

# 環境
- C++17
- Eigen
- Python3 (matplotlib用)

# サードパーティライブラリ
- matplotlibcpp

# ドキュメント
- [https://kotakku.github.io/cpp_robotics/](https://kotakku.github.io/cpp_robotics/)

## ドキュメント生成
doxybook2とmkdocsをインストール後に

```sh
sh gen_doc.sh
mkdocs build
```

# ビルド・インストール
```
mkdir build && cd build
cmake ..
cmake --build .
sudo make install
```

# 実装した機能
- C++補助関数
- 数学関数
    - 定数
    - deg <-> rad
    - 角度用関数
    - lerp
    - マハラノビス距離
- ベクトル生成関数
    - linspace
    - logspace
- 多項式
    - 根を指定して多項式に展開する
- Vector
    - Vector2
    - Vector3
    - Vector4
    - Quaternion
    - Transform
- 図形
    - 図形クラス
    - 図形同士の当たり判定関数
- フィルタ
    - 微分器
    - 積分器
    - (ローパスフィルタ)
    - (ハイパスフィルタ)
    - (ノッチフィルタ)
    - 遅延フィルタ
    - 速度制限フィルタ
    - 加速度制限フィルタ
- 制御・コントローラ
    - PID
    - PID2
    - NCTF
    - 周波数特性(ボード線図)
    - ナイキスト線図
    - カルマンフィルタ
    - LQR
    - 極配置
    - 安定性とロバスト性
        - 可制御性
        - 可観測性
    - システムの記述
        - 伝達関数
        - 状態空間表現
        - z伝達関数
    - システムの離散化
        - tustinのみ, 他の手法もやる?(zoh, euler)
    - システムの応答
        - ステップ応答
        - 強制振動と零入力応答の実装はまだ
- パスプランニング
    - スプライン曲線
    - グリッドパスプラニング
    - Dubins path
- パストラッキング
    - pure pursuit
- 連続な関数の最適化
    - スカラー最適化  
        - 黄金探索
        - 囲い込み法
    - 制約なし最適化
        - 最急降下法  
        - ニュートン法  
        - 準ニュートン法  
            - BFGS法
    - 制約あり最適化
        - ペナルティ法
        - バリア法
- アルゴリズム
    - KDtree
        - KD木をICP, NDT, 教師なし分類器などに使用できる
    
# 実装したい機能・勉強したいこと
- 数学
    - 確率統計
    - 乱数生成器
- 回帰曲線
- 制御・コントローラ
    - PID2
        2つのPIDパラメータとフィードバックの連結構造指定したらPID2のパラメータを返す関数
    - PID
        - アンチワインドアップ
        - pidtune
    - PFC
    - PSMC
    - 零位相誤差追従制御
    - スミス補償器
    - LMI制御
    - モデル化誤差抑制補償器
- 安定性とロバスト性
    - ゲイン余裕
    - 位相余裕
- フィルタ
    - z伝達関数クラスを継承したフィルタクラス
    - 多段フィルタ構成用クラス
        テンプレート引数に取ったフィルタを全て直列につなげて一つのフィルタを構成するクラス
            直並列侍従にやりたくね？
- 拡張カルマンフィルタ
- システム
    - 連続システムの表現クラスと離散システムの実用クラスは分けたい(c2d)
- シミュレーション環境
    - アニメーション, ビジュアライズ
- パスプランニング
    - DWA
    - Frenet path
- 速度プロファイラ
    - 躍度最小化モデル
- 連続な関数の最適化
    - 直線探索法
        - アルミホ条件を厳密に適応した探索
        - [直線探索におけるArmijo条件とWolfe条件を図から理解する](https://tm23forest.com/contents/linesearch-armijo-wolfe-condition-explained-visually)
    - スカラー最適化
        - ブレント法
    - 制約なし最適化
        - 準ニュートン法
            - L-BFGS法(BFGS法との違いを調べるところから)
        - ベンチマーク
    - 制約あり最適化
        - 有効制約法
            - [実装例](https://darden.hatenablog.com/entry/2016/09/05/212147)
        - 逐次2次計画法(SQP)
            - 部分問題のソルバ実装がいくつかある
- 整数最適化問題
- 最適制御
    - MPC(できたら非線形も)
    - DDP, iLQRとの区別もできるようにする
- Dead Reckoning
- ホイール移動機構
    - メカナム
    - オムニ
    - ステア
- ロボットアーム
    - アームのモデルを表現するオブジェクト
    - 順運動学, 逆運動学の計算
    - 何個かIK実装しておく
        - デルタロボット
- SLAM
- ドローン
    - 力学モデルによるシミュレーション
- 多脚
    - SpotMicro
- アルゴリズム
    - K-means法

- ICP, NDT(2D, 3D)
    - [NDT勉強会](https://docs.google.com/presentation/d/1rWhCQtZv4YSWdedoJWPAF3Q4umwaA8yuDADyWIhrM20/edit?usp=sharing)
    - [Scan Matching 自己位置推定手法](chrome-extension://oemmndcbldboiebfnladdacbdfmadadm/https://web.wakayama-u.ac.jp/~nakajima/SelfDrivingSystem/assets/pdf/method_pmv_03.pdf)
- FSM(Finit State Machine)

# 参考プロジェクト
- [python control](https://github.com/python-control/python-control)
- [PythonRobotics](https://github.com/AtsushiSakai/PythonRobotics)
- [awesome-robotic-tooling](https://github.com/protontypes/awesome-robotic-tooling)
- [AutonomousDrivingCookbook](https://github.com/microsoft/AutonomousDrivingCookbook) 自動運転, 機械学習
- [simbody](https://github.com/simbody/simbody) 剛体のシミュレーション
- [Klampt Python](http://motion.cs.illinois.edu/software/klampt/latest/pyklampt_docs/index.html) ロボットアームの運動学, 逆運動学
- [notspot_sim_cpp](https://github.com/lnotspotl/notspot_sim_cpp) ROS1のGazeboで動かす4足歩行ロボットのシミュレータ
- [champ](https://github.com/chvmp/champ) ROS1の4足歩行ロボットのコントローラ
- [Cheetah-Software](https://github.com/mit-biomimetics/Cheetah-Software) MIT mini cheetahのソフトウェア
- [OpenRCF](https://booth.pm/ja/items/2754488) C#で開発するロボットコントロールプラットフォーム
- [gym-pybullet-drones](https://github.com/utiasDSL/gym-pybullet-drones) pybulletでベースのドローンコントローラ
- [webot](https://github.com/cyberbotics/webots_ros2) シミュレータ