# 実装したい機能・勉強したいこと
- 数学
    - 確率統計
- 制御・コントローラ
    - PID2
        2つのPIDパラメータとフィードバックの連結構造指定したらPID2のパラメータを返す関数
    - PID
        - アンチワインドアップ
        - pidtune
    - 零位相誤差追従制御
    - スミス補償器
    - LMI制御
    - モデル化誤差抑制補償器(MEC)
    - システム同定
        - 伝達関数同定
    - ループ整形
- 安定性とロバスト性
    - ゲイン余裕
    - 位相余裕
- ロボットアームの運動学・順運動学
    - アームのモデルを表現するオブジェクト
    - 何個かIK実装しておく
        - デルタロボット
- ロボットアームの動力学
    - ニュートンオイラー法による順運動学の導出
- パスプランニング
    - DWA
    - Frenet path
- アルゴリズム
    - K-means++法
- 整数最適化問題

# 理論的なものではない&あったら便利そうなもの
- 多段フィルタ構成用クラス
    指定したフィルタを直並列につなげて一つのフィルタを構成するクラス

# 要検討
- シミュレーション環境
    - アニメーション, ビジュアライズ

# 実装途中・バグありで動作が保証できないやつ
- algorithm/ICP
- optimize/ActiveSetMethod
- optimize/SQP

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
- [legged_control](https://github.com/qiayuanliao/legged_control) ROS1対応の4足歩行ロボットのコントローラ・シミュレータ