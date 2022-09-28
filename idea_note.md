# 実装したい機能・勉強したいこと
- 数学
    - 確率統計
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
    - 多段フィルタ構成用クラス
        テンプレート引数に取ったフィルタを全て直列につなげて一つのフィルタを構成するクラス
            直並列侍従にやりたくね？
- ロボットアームの運動学・順運動学
    - アームのモデルを表現するオブジェクト
    - 順運動学, 逆運動学の計算
    - 何個かIK実装しておく
        - デルタロボット
- パスプランニング
    - DWA
    - Frenet path
- 速度プロファイラ
    - 躍度最小化モデル
- アルゴリズム
    - K-means++法
- 連続な関数の最適化
    - 制約なし最適化
        - ベンチマーク
- 整数最適化問題
- ICP, NDT(2D, 3D)
    - [NDT勉強会](https://docs.google.com/presentation/d/1rWhCQtZv4YSWdedoJWPAF3Q4umwaA8yuDADyWIhrM20/edit?usp=sharing)
    - [Scan Matching 自己位置推定手法](chrome-extension://oemmndcbldboiebfnladdacbdfmadadm/https://web.wakayama-u.ac.jp/~nakajima/SelfDrivingSystem/assets/pdf/method_pmv_03.pdf)
- 最適制御
    - MPC(できたら非線形も)
    - DDP, iLQRとの区別もできるようにする
- SLAM
- ドローン
    - 力学モデルによるシミュレーション
- 多脚
    - SpotMicro

# ほしいけど要検討
- シミュレーション環境
    - アニメーション, ビジュアライズ

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