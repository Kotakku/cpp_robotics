---
title: cpp_robotics

---

# cpp_robotics



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics::constants](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1constants/)** <br>数学・物理定数  |
| **[cpp_robotics::grid_path_planning_utils](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/)** <br>グリッドパスプランニング用関数・クラス郡  |
| **[cpp_robotics::spline](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/)** <br>スプライン曲線用関数郡  |
| **[cpp_robotics::unit](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/)** <br>単位系  |
| **[cpp_robotics::unit::prefix](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/)**  |
| **[cpp_robotics::unit::tag](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1tag/)**  |
| **[cpp_robotics::unit::unit_dimention](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::AccelerationLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/)** <br>加速度制限フィルタ(速度制限込み)  |
| class | **[cpp_robotics::ActiveSetMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ActiveSetMethod/)** <br>線形不等式制約を持つ2次計画法を解く有効制約法  |
| class | **[cpp_robotics::AngleRange](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/)** <br>角度[rad]に対して範囲を指定する 複数の角度の範囲の合成をしたり逆を取ったりできる  |
| class | **[cpp_robotics::AutoDiffAdaptor](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/)** <br>自動微分でヤコビアンを求めるクラス  |
| class | **[cpp_robotics::BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/)** <br>バンドパスフィルタ  |
| class | **[cpp_robotics::CatumullRom2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CatumullRom2D/)** <br>Catumull曲線  |
| struct | **[cpp_robotics::Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/)** <br>円クラス  |
| struct | **[cpp_robotics::Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/)** <br>数理最適問題に使用する制約クラス  |
| class | **[cpp_robotics::ConstraintArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/)** <br>数理最適化問題の制約の集合  |
| class | **[cpp_robotics::CubicSpline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CubicSpline/)** <br>3次スプライン曲線  |
| struct | **[cpp_robotics::DCGearedMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/)** <br>ギアヘッド付きDCモーターモデル  |
| struct | **[cpp_robotics::DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/)** <br>DCモーターモデル  |
| class | **[cpp_robotics::DelayFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DelayFilter/)** <br>遅延フィルタ  |
| class | **[cpp_robotics::DeltaRobotIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/)** <br>デルタロボットの逆運動学  |
| class | **[cpp_robotics::Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/)** <br>疑似微分器  |
| class | **[cpp_robotics::Discret](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Discret/)** <br>状態空間モデルを双一次変換で離散化する  |
| class | **[cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)** <br>z空間の伝達関数  |
| class | **[cpp_robotics::DubinsPath](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/)** <br>Dubinsパス  |
| class | **[cpp_robotics::ExtendedKalmanFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/)**  |
| class | **[cpp_robotics::FilterConnector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterConnector/)**  |
| class | **[cpp_robotics::FilterStateHolder](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/)** <br>フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス  |
| struct | **[cpp_robotics::GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/)** <br>ギアヘッドモデル  |
| class | **[cpp_robotics::HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/)** <br>ハイパスフィルタ  |
| class | **[cpp_robotics::Integrator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Integrator/)** <br>積分器  |
| class | **[cpp_robotics::KalmanFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/)** <br>カルマンフィルタ  |
| class | **[cpp_robotics::KDTree](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/)** <br>k-d木  |
| class | **[cpp_robotics::KMeansMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansMethod/)** <br>K-means法  |
| struct | **[cpp_robotics::Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/)** <br>直線クラス  |
| class | **[cpp_robotics::LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/)** <br>ローパスフィルター  |
| class | **[cpp_robotics::MecanumIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/)** <br>メカナムの逆運動学モデル  |
| class | **[cpp_robotics::NctfController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/)** <br>NCTF制御器  |
| class | **[cpp_robotics::NDT2d](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NDT2d/)** <br>2次元のNDTマッチングクラス  |
| class | **[cpp_robotics::NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/)** <br>ノッチフィルタ  |
| class | **[cpp_robotics::Omni3Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/)** <br>3輪オムニの逆運動学モデル  |
| class | **[cpp_robotics::Omni4Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/)** <br>4輪オムニの逆運動学モデル  |
| class | **[cpp_robotics::PID2Controller](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/)** <br>2自由度PID制御器  |
| class | **[cpp_robotics::PIDController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/)** <br>PID制御器  |
| struct | **[cpp_robotics::Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/)** <br>多項式  |
| struct | **[cpp_robotics::unit::Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/)** <br>単位系接頭辞クラス  |
| class | **[cpp_robotics::PurePursuit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PurePursuit/)** <br>Pure pursuit制御器  |
| struct | **[cpp_robotics::Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/)** <br>四角形クラス  |
| class | **[cpp_robotics::QuadProg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1QuadProg/)** <br>線形等式制約と線形不等式制約を持つ2次計画法  |
| class | **[cpp_robotics::Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/)** <br>クォータニオンクラス  |
| class | **[cpp_robotics::RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)** <br>stdの乱数生成をラップしてこのクラス一つだけ実体化すればいいようにした乱数生成器  |
| struct | **[cpp_robotics::Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/)** <br>長方形クラス(回転は考えない)  |
| class | **[cpp_robotics::Singleton](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/)** <br>シングルトンなオブジェクトを生成する  |
| class | **[cpp_robotics::SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/)** <br>コントローラとシステムからなるSISOのフィードバックシステム  |
| class | **[cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)** <br>2次元のスプライン曲線のインターフェイスクラス  |
| class | **[cpp_robotics::SQP](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/)** <br>[SQP]()(逐次二次計画法)  |
| class | **[cpp_robotics::StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/)** <br>状態空間モデル  |
| class | **[cpp_robotics::SwerveIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/)** <br>メカナムの逆運動学モデル  |
| class | **[cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)** <br>伝達関数モデル  |
| struct | **[cpp_robotics::Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)** <br>2次元のロボットの座標を扱うクラス  |
| struct | **[cpp_robotics::Triangle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/)** <br>三角形クラス  |
| class | **[cpp_robotics::unit::Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)** <br>単位クラス  |
| struct | **[cpp_robotics::unit::UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)** <br>SI単位系次元定義クラス  |
| struct | **[cpp_robotics::Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)** <br>2次元のベクトル  |
| struct | **[cpp_robotics::Vector3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector3/)** <br>3次元のベクトル  |
| struct | **[cpp_robotics::Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)** <br>4次元のベクトル  |
| class | **[cpp_robotics::VelocityLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/)** <br>速度制限フィルタ  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[CanonicalizeMode](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enum-canonicalizemode)** { COMPANION, OBSERBAVLE, CONTROLLABLE} |
| enum| **[UnitIndex](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enum-unitindex)** { MetereIdx, KiloGramIdx, SecondIdx, AmpereIdx, KelvinIdx, MoleIdx, CandelaIdx} |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::uniform_int_distribution<> > | **[UniformIntRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-uniformintrandomengine)** <br>整数型一様分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::uniform_real_distribution<> > | **[UniformRealRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-uniformrealrandomengine)** <br>実数型一様分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::bernoulli_distribution > | **[BernoulliRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-bernoullirandomengine)** <br>ベルヌーイ分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::binomial_distribution<> > | **[BinomialRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-binomialrandomengine)** <br>二項分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::geometric_distribution<> > | **[GeometricRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-geometricrandomengine)** <br>幾何学分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::negative_binomial_distribution<> > | **[NegativeBinomialRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-negativebinomialrandomengine)** <br>負の二項分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::poisson_distribution<> > | **[PoissonRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-poissonrandomengine)** <br>ポワソン分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::exponential_distribution<> > | **[ExponentialRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-exponentialrandomengine)** <br>指数分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::gamma_distribution<> > | **[GammaRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-gammarandomengine)** <br>ガンマ分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::weibull_distribution<> > | **[WeibullRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-weibullrandomengine)** <br>ワイブル分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::extreme_value_distribution<> > | **[ExtremeValueRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-extremevaluerandomengine)** <br>極値分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::normal_distribution<> > | **[NormalRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-normalrandomengine)** <br>正規分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::lognormal_distribution<> > | **[LognormalRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-lognormalrandomengine)** <br>対数正規分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::chi_squared_distribution<> > | **[ChiSquaredRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-chisquaredrandomengine)** <br>カイ二乗分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::cauchy_distribution<> > | **[CauchyRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-cauchyrandomengine)** <br>コーシー分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::fisher_f_distribution<> > | **[FisherFRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-fisherfrandomengine)** <br>フィッシャーのF分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::student_t_distribution<> > | **[StudentTRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-studenttrandomengine)** <br>ステューデントのt分布乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::discrete_distribution<> > | **[DiscreteRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-discreterandomengine)** <br>整数のインデックスごとに離散した確率分布の乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::piecewise_constant_distribution<> > | **[PiecewiseConstantRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-piecewiseconstantrandomengine)** <br>区間ごとの重み付けを定数値とした分布の乱数生成エンジン  |
| using [RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)< std::piecewise_linear_distribution<> > | **[PiecewiseLinearRandomEngine](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-piecewiselinearrandomengine)** <br>区間ごとの重み付けを線形に接続した分布の乱数生成エンジン  |
| using unit_assem::unit_div< [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque), [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) >::unit | **[TorqueConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torqueconstant)**  |
| using unit_assem::unit_div< [Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt), [AngularVelocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularvelocity) >::unit | **[BackEmfConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-backemfconstant)**  |
| using unit_assem::unit_mul< [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque), [Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) >::unit | **[FrictionConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-frictionconstant)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::second, prefix::none > | **[Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::second, prefix::milli > | **[MilliSecond](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-millisecond)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::second, prefix::micro > | **[MicroSecond](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-microsecond)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::metere, prefix::none > | **[Meter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-meter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::metere, prefix::milli > | **[MilliMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-millimeter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::metere, prefix::micro > | **[MicroMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-micrometer)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::metere, prefix::centi > | **[CentiMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-centimeter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::kilogram, prefix::none > | **[KiloGram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-kilogram)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::kilogram, prefix::milli > | **[Gram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-gram)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::watt, prefix::none > | **[Watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-watt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::watt, prefix::kilo > | **[KiloWatt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-kilowatt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::newton, prefix::none > | **[Newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-newton)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::newton, prefix::kilo > | **[KiloNewton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-kilonewton)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::pascal, prefix::none > | **[Pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-pascal)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::pascal, prefix::kilo > | **[KiloPascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-kilopascal)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::hertz, prefix::none > | **[Hertz](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-hertz)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::area, prefix::none > | **[Area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-area)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::volume, prefix::none > | **[Volume](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volume)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::velocity, prefix::none > | **[Velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-velocity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::acceleration, prefix::none > | **[Acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-acceleration)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::dencity, prefix::none > | **[Dencity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-dencity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::torque, prefix::none > | **[Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::inertia, prefix::none > | **[Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::ampere, prefix::none > | **[Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::ampere, prefix::milli > | **[MilliAmpere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-milliampere)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::volt, prefix::none > | **[Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::volt, prefix::milli > | **[MilliVolt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-millivolt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::ohm, prefix::none > | **[Ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ohm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::ohm, prefix::milli > | **[MilliOhm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-milliohm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::henry, prefix::none > | **[Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-henry)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::henry, prefix::milli > | **[MilliHenry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-millihenry)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::farad, prefix::none > | **[Farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-farad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::farad, prefix::milli > | **[MilliFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-millifarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::farad, prefix::micro > | **[MicroFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-microfarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::farad, prefix::nano > | **[NanoFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-nanofarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angle, prefix::none, tag::angle::radian > | **[Radian](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-radian)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angle, prefix::none, tag::angle::degree > | **[Degree](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-degree)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rad_per_sec > | **[AngularVelocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularvelocity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rps > | **[Rps](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rps)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rpm > | **[Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, unit_dimention::angular_acceleration, prefix::none > | **[AngularAcceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularacceleration)**  |
| template <class DerType \> <br>using Eigen::AutoDiffScalar< DerType > | **[AutoDiffScalar](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-autodiffscalar)**  |
| template <class DerType ,int NX =Eigen::Dynamic\> <br>using Eigen::Matrix< [AutoDiffScalar](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-autodiffscalar)< DerType >, NX, 1 > | **[AutoDiffVector](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-autodiffvector)**  |
| using [Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/)< float > | **[Quaternionf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-quaternionf)**  |
| using [Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/)< double > | **[Quaterniond](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-quaterniond)**  |
| using [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)< float > | **[Transformf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformf)**  |
| using [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)< double > | **[Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd)**  |
| using [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)< float > | **[Vector2f](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2f)**  |
| using [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)< double > | **[Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d)**  |
| using [Vector3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector3/)< float > | **[Vector3f](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector3f)**  |
| using [Vector3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector3/)< double > | **[Vector3d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector3d)**  |
| using [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)< float > | **[Vector4f](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4f)**  |
| using [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)< double > | **[Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <size_t DIM\> <br>std::pair< Eigen::Matrix< double, DIM, DIM >, Eigen::Matrix< double, DIM, 1 > > | **[calcu_transformatoin](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-calcu-transformatoin)**(std::vector< Eigen::Matrix< double, DIM, 1 >> dest, std::vector< Eigen::Matrix< double, DIM, 1 >> fixed) |
| template <size_t DIM\> <br>std::tuple< std::vector< Eigen::Matrix< double, DIM, 1 > >, size_t > | **[icp](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-icp)**(std::vector< Eigen::Matrix< double, DIM, 1 >> dest, std::vector< Eigen::Matrix< double, DIM, 1 >> fixed, size_t max_iter =100) |
| double | **[mahalanobis](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-mahalanobis)**(const Eigen::VectorXd & a, const Eigen::VectorXd & b, const Eigen::MatrixXd cov_inv)<br>マハラノビス距離の計算  |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[poly_regression](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-poly-regression)**(const std::vector< double > & x, const std::vector< double > & y, const size_t degree)<br>回帰曲線  |
| template <typename Real  =double\> <br>Real | **[gererate_random](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-gererate-random)**()<br>0.0〜1.0までの一様分布の乱数を生成する  |
| std::optional< Eigen::MatrixXd > | **[solve_riccati_arimoto_potter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-solve-riccati-arimoto-potter)**(const Eigen::MatrixXd & A, const Eigen::MatrixXd & B, const Eigen::MatrixXd & Q, const Eigen::MatrixXd & R)<br>有本-ポッターの方法によるリカッチ方程式の解法  |
| Eigen::MatrixXd | **[lqr](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-lqr)**(const Eigen::MatrixXd & A, const Eigen::MatrixXd & B, const Eigen::MatrixXd & Q, const Eigen::MatrixXd & R) |
| Eigen::MatrixXd | **[controllability_matrix](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-controllability-matrix)**(const Eigen::MatrixXd & A, const Eigen::VectorXd & B)<br>可制御性行列の計算  |
| bool | **[is_controllable](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-is-controllable)**(const Eigen::MatrixXd & A, const Eigen::VectorXd & B)<br>可制御性の判別  |
| bool | **[is_controllable](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-is-controllable)**(const [StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/) & sys) |
| Eigen::MatrixXd | **[observability_matrix](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-observability-matrix)**(const Eigen::MatrixXd & A, const Eigen::RowVectorXd & C)<br>可観測性行列を計算する  |
| bool | **[is_observable](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-is-observable)**(const Eigen::MatrixXd & A, const Eigen::RowVectorXd & C)<br>可観測性の判別  |
| bool | **[is_observable](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-is-observable)**(const [StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/) & sys) |
| std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > | **[canonicalize_system](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-canonicalize-system)**(const Eigen::MatrixXd & A, const Eigen::MatrixXd & B, const Eigen::MatrixXd & C, const Eigen::MatrixXd & D, [CanonicalizeMode](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enum-canonicalizemode) mode =[CanonicalizeMode::COMPANION](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enumvalue-companion))<br>同値変換による可制御正準形への変換  |
| std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > | **[canonicalize_system](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-canonicalize-system)**(const Eigen::MatrixXd & A, const Eigen::MatrixXd & B, const Eigen::MatrixXd & C, [CanonicalizeMode](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enum-canonicalizemode) mode =[CanonicalizeMode::COMPANION](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enumvalue-companion))<br>同値変換による可制御正準形への変換  |
| std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > | **[canonicalize_system](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-canonicalize-system)**(const [StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/) & sys, [CanonicalizeMode](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enum-canonicalizemode) mode =[CanonicalizeMode::COMPANION](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#enumvalue-companion))<br>同値変換による可制御正準形への変換  |
| Eigen::VectorXd | **[place](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-place)**(const [StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/) & sys, std::vector< double > poles)<br>アッカーマン法によるSISOモデルの極配置  |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| bool | **[intersect](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect)**(const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & a, const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b) |
| std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > | **[intersect_at](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-intersect-at)**(const [Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/) & a, const [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/) & b) |
| bool | **[contain](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-contain)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & range, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & target) |
| bool | **[contain](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-contain)**(const [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) & range, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & target) |
| std::ostream & | **[operator<<](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator<<)**(std::ostream & os, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & v) |
| std::ostream & | **[operator<<](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator<<)**(std::ostream & os, const [Vector3d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector3d) & v) |
| std::ostream & | **[operator<<](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator<<)**(std::ostream & os, const [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & v) |
| std::ostream & | **[operator<<](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator<<)**(std::ostream & os, const [Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) & v) |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[generate_mabuchi_motor_param](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-generate-mabuchi-motor-param)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) nominal_voltage, [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) free_speed, [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) free_current, [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque) stall_torque, [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) stall_current, [Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-henry) inductance, [Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia) rotor_inertia) |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[generate_maxon_brush_motor_param](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-generate-maxon-brush-motor-param)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) nominal_voltage, [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) free_speed, [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) free_current, [Ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ohm) resistance, [Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-henry) inductance, [TorqueConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torqueconstant) Kt, [Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia) rotor_inertia) |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_motor_vel_tf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-motor-vel-tf)**(const [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) & motor, const double dt)<br>DCモーターのモデルから角速度の伝達関数を生成する  |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_motor_pos_tf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-motor-pos-tf)**(const [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) & motor, const double dt)<br>DCモーターのモデルから角度の伝達関数を生成する  |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_geared_motor_vel_tf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-geared-motor-vel-tf)**(const [DCGearedMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/) & geared_motor, const double dt)<br>ギアヘッド付きDCモーターのモデルから角速度の伝達関数を生成する  |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_geared_motor_pos_tf](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-geared-motor-pos-tf)**(const [DCGearedMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/) & geared_motor, const double dt)<br>ギアヘッド付きDCモーターのモデルから角度の伝達関数を生成する  |
| std::tuple< bool, Eigen::VectorXd, size_t > | **[barrier_method](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-barrier-method)**(std::function< double(const Eigen::VectorXd &)> f, [ConstraintArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/) constraint, Eigen::VectorXd x_init, const double r_init =10.0, const double tol =1e-3, const size_t max_iter =1000)<br>バリア法  |
| void | **[bfgs_step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-bfgs-step)**(Eigen::MatrixXd & hess, Eigen::VectorXd s, Eigen::VectorXd y)<br>BFGS法  |
| void | **[powells_modified_bfgs_step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-powells-modified-bfgs-step)**(Eigen::MatrixXd & hess, Eigen::VectorXd s, Eigen::VectorXd y, double gamma =0.2)<br>パウエルの修正BFGS法  |
| double | **[bracketing_serach](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-bracketing-serach)**(std::function< double(Eigen::VectorXd)> func, std::function< Eigen::VectorXd(Eigen::VectorXd)> grad, const Eigen::VectorXd & x, const Eigen::VectorXd & d, double gamma =0.3, double tau =0.9, const size_t max_iter =1000)<br>アルミホ条件を満たすステップ幅を求める囲い込み法  |
| double | **[bracketing_serach](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-bracketing-serach)**(std::function< double(double)> func, const double init =1.0, const double beta =0.9, const size_t max_iter =1000)<br>囲い込み法  |
| double | **[derivative](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-derivative)**(std::function< double(double)> f, double x, double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5))<br>R -> Rの数値微分  |
| Eigen::VectorXd | **[derivative](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-derivative)**(std::function< double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5))<br>R^n -> Rの数値微分  |
| Eigen::MatrixXd | **[derivative](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-derivative)**(std::function< Eigen::VectorXd(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5))<br>R^n -> R^mの数値微分  |
| double | **[second_derivative](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-second-derivative)**(std::function< double(double)> f, double x, double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5))<br>R -> Rの2回数値微分  |
| Eigen::MatrixXd | **[approx_hessian](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-approx-hessian)**(std::function< double(Eigen::VectorXd)> f, Eigen::VectorXd x, double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)) |
| double | **[golden_search](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-golden-search)**(std::function< double(double)> f, double low, double high, const double tol =1e-6, const size_t max_iter =100)<br>黄金探索  |
| std::tuple< bool, Eigen::VectorXd, size_t > | **[newton_method](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-newton-method)**(std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad, std::function< Eigen::MatrixXd(const Eigen::VectorXd &)> hesse, Eigen::VectorXd x_init, const double tol =1e-6, const size_t max_iter =1000)<br>ニュートン法  |
| std::tuple< bool, Eigen::VectorXd, size_t > | **[penalty_method](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-penalty-method)**(std::function< double(const Eigen::VectorXd &)> f, [ConstraintArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/) constraint, Eigen::VectorXd x_init, const double r_init =1.0, const double tol =1e-3, const size_t max_iter =1000)<br>ペナルティ法  |
| std::tuple< bool, Eigen::VectorXd, size_t > | **[quasi_newton_method](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-quasi-newton-method)**(std::function< double(const Eigen::VectorXd &)> f, std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad, Eigen::VectorXd x_init, const double tol =1e-6, const size_t max_iter =1000)<br>準ニュートン法  |
| std::tuple< bool, Eigen::VectorXd, size_t > | **[steepest_descent_method](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-steepest-descent-method)**(std::function< double(const Eigen::VectorXd &)> f, std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad, Eigen::VectorXd x_init, const double tol =1e-6, const size_t max_iter =1000)<br>最急降下法  |
| std::vector< Eigen::Vector2i > | **[a_star](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-a-star)**(const Eigen::Vector2i & start, const Eigen::Vector2i & end, const Eigen::MatrixXi & map)<br>A*法  |
| std::vector< Eigen::Vector2i > | **[wave_propagation](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-wave-propagation)**(const Eigen::Vector2i & start, const Eigen::Vector2i & end, const Eigen::MatrixXi & map)<br>Wave propagation法  |
| std::tuple< std::vector< double >, std::vector< double > > | **[bode](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-bode)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & tf, const std::vector< double > & omegas =[logspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-logspace)(-2, 2, 500), bool gain_db_mode =true, bool phase_deg_mode =true)<br>ボード線図の応答を計算する  |
| void | **[bode_plot](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-bode-plot)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & tf, const std::vector< double > & omegas =[logspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-logspace)(-2, 2, 500))<br>ボード線図を表示する(matplotlibが必要)  |
| std::tuple< std::vector< double >, std::vector< double > > | **[nyquist](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-nyquist)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & tf, const std::vector< double > & omegas =[logspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-logspace)(-2, 2, 500))<br>ナイキスト線図の応答を計算する  |
| void | **[nyquist_plot](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-nyquist-plot)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & tf, const std::vector< double > & omegas =[logspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-logspace)(-2, 2, 500))<br>ナイキスト線図を表示する(matplotlibが必要)  |
| std::ostream & | **[operator<<](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator<<)**(std::ostream & os, const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & v) |
| template <class CONTROLLER_T ,class SYSTEM_T \> <br>[SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/) | **[make_feedback_system](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-feedback-system)**(CONTROLLER_T & controller, SYSTEM_T & system) |
| void | **[set_controller](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-set-controller)**([SisoFeedbackSystem::func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/) & fn, [PIDController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/) & controller) |
| void | **[set_controller](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-set-controller)**([SisoFeedbackSystem::func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/) & fn, [NctfController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/) & controller) |
| void | **[set_system](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-set-system)**([SisoFeedbackSystem::func_list_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/) & fn, [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & system) |
| std::tuple< std::vector< double >, std::vector< double > > | **[impluse](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-impluse)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & sys, double time)<br>インパルス応答を求める  |
| std::tuple< std::vector< double >, std::vector< double > > | **[step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-step)**(const std::function< double(double)> & sys, double dt, double time, const double gain =1.0)<br>ステップ応答を求める  |
| std::tuple< std::vector< double >, std::vector< double > > | **[step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-step)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & sys, double time, const double gain =1.0)<br>ステップ応答を求める  |
| std::tuple< std::vector< double >, std::vector< double > > | **[step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-step)**([DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/) & sys, double time, const double gain =1.0)<br>ステップ応答を求める  |
| std::tuple< std::vector< double >, std::vector< double > > | **[lsim](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-lsim)**([TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) & sys, std::vector< double > input)<br>任意の入力による応答を求める  |
| template <class UnitDimType ,int FromTag,int ToTag,bool IsNormalTag =tag::is_normal_tag<FromTag>::value && tag::is_normal_tag<ToTag>::value\> <br>constexpr double | **[conv_factor](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-conv-factor)**() |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator*)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & l_value, const T2 & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator*)**(const T1 & l_value, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator/)**(const T1 & l_value, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator/)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & l_value, const T2 & r_value) |
| template <typename T1 ,class UnitDim1 ,class Prefix1 ,int Tag1,typename T2 ,class UnitDim2 ,class Prefix2 ,int Tag2\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator*)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim1, Prefix1, Tag1 > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim2, Prefix2, Tag2 > & rhl) |
| template <typename T1 ,class UnitDim1 ,class Prefix1 ,int Tag1,typename T2 ,class UnitDim2 ,class Prefix2 ,int Tag2\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator/)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim1, Prefix1, Tag1 > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim2, Prefix2, Tag2 > & rhl) |
| template <typename T ,class UnitDim ,class Prefix1 ,class Prefix2 ,int Tag\> <br>constexpr auto | **[operator+](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator+)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix1, Tag > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix2, Tag > & rhl) |
| template <typename T ,class UnitDim ,class Prefix1 ,class Prefix2 ,int Tag\> <br>constexpr auto | **[operator-](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-operator-)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix1, Tag > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix2, Tag > & rhl) |
| template <class DerType \> <br>auto | **[make_auto_diff_vector](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-make-auto-diff-vector)**(const size_t & dim, const std::optional< DerType > & x =std::nullopt) |
| template <class ForwardIterator \> <br>constexpr ForwardIterator | **[shift_left](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-shift-left)**(ForwardIterator first, ForwardIterator last, typename std::iterator_traits< ForwardIterator >::difference_type n)<br>C++17のstd::shift_leftの自前実装 C++14で動作する  |
| template <class ForwardIterator \> <br>constexpr ForwardIterator | **[shift_right](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-shift-right)**(ForwardIterator first, ForwardIterator last, typename std::iterator_traits< ForwardIterator >::difference_type n)<br>C++17のstd::shift_rightの自前実装 C++14で動作する  |
| template <typename... Args\> <br>std::string | **[c_format](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-c-format)**(const std::string & format, Args const &... args)<br>printfと同様の操作でstd::stringを得る  |
| template <typename T \> <br>constexpr bool | **[in_range_open](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-in-range-open)**(T x, T min, T max) |
| template <typename T \> <br>constexpr bool | **[in_range](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-in-range)**(T x, T min, T max) |
| template <typename T \> <br>constexpr int | **[sgn](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-sgn)**(T x) |
| template <typename T \> <br>constexpr float | **[radians](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-radians)**(T deg) |
| template <typename T \> <br>constexpr float | **[degrees](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-degrees)**(T rad) |
| float | **[normalize_angle_positive](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-normalize-angle-positive)**(float angle) |
| float | **[normalize_angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-normalize-angle)**(float angle) |
| float | **[shortest_angular_distance](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-shortest-angular-distance)**(float from, float to) |
| float | **[nearest_angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-nearest-angle)**(float from, float to) |
| constexpr float | **[square](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-square)**(const float x) |
| constexpr float | **[cubic](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-cubic)**(const float x) |
| constexpr float | **[lerp](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-lerp)**(const float a, const float b, const float t) |
| constexpr float | **[approx_eq](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-approx-eq)**(const float a, const float b) |
| constexpr float | **[approx_zero](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-approx-zero)**(const float a) |
| std::vector< double > | **[arrange](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-arrange)**(double start, double end, double step =1.0) |
| std::vector< double > | **[linspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-linspace)**(double start, double end, size_t n =100) |
| std::vector< double > | **[logspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-logspace)**(double start, double end, size_t n =100) |
| std::vector< double > | **[funcspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-funcspace)**(std::function< double(size_t, size_t)> f, size_t n =100) |
| std::vector< double > | **[sinspace](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#function-sinspace)**(double a, double b, size_t n =100) |

## Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RZ_735VA_9517](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rz-735va-9517)**  |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RS_775_8513](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rs-775-8513)**  |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RS_555VC_5524](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rs-555vc-5524)**  |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RS_380PH_4045](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rs-380ph-4045)**  |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RS_385PH_2465](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rs-385ph-2465)**  |
| constexpr [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[RE_65_250_18](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-re-65-250-18)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG42C_4](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig42c-4)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG42C_14](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig42c-14)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG42C_17](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig42c-17)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG32_27](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig32-27)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG32_71](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig32-71)**  |
| constexpr [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[IG32_100](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-ig32-100)**  |
| constexpr float | **[PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-pi)** <br>円周率  |
| constexpr float | **[HALF_PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-half-pi)** <br>円周率 / 2  |
| constexpr float | **[TWO_PI](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-two-pi)** <br>円周率 * 2  |
| constexpr float | **[DEG_TO_RAD](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-deg-to-rad)** <br>degree -> radians  |
| constexpr float | **[RAD_TO_DEG](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-rad-to-deg)** <br>radian -> degree  |
| constexpr float | **[EULER](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-euler)** <br>ネイピア数  |
| constexpr float | **[GRAVITY](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-gravity)** <br>重力  |
| constexpr float | **[Nm2gfm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-nm2gfm)**  |
| constexpr float | **[gfm2Nm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-gfm2nm)**  |
| constexpr float | **[mNm2gfcm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-mnm2gfcm)**  |
| constexpr float | **[gfcm2mNm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#variable-gfcm2mnm)**  |

## Types Documentation

### enum CanonicalizeMode

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| COMPANION | |   |
| OBSERBAVLE | |   |
| CONTROLLABLE | |   |




### enum UnitIndex

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| MetereIdx | |   |
| KiloGramIdx | |   |
| SecondIdx | |   |
| AmpereIdx | |   |
| KelvinIdx | |   |
| MoleIdx | |   |
| CandelaIdx | |   |




### using UniformIntRandomEngine

```cpp
using cpp_robotics::UniformIntRandomEngine = typedef RandomGenerator<std::uniform_int_distribution<> >;
```

整数型一様分布乱数生成エンジン 

### using UniformRealRandomEngine

```cpp
using cpp_robotics::UniformRealRandomEngine = typedef RandomGenerator<std::uniform_real_distribution<> >;
```

実数型一様分布乱数生成エンジン 

### using BernoulliRandomEngine

```cpp
using cpp_robotics::BernoulliRandomEngine = typedef RandomGenerator<std::bernoulli_distribution>;
```

ベルヌーイ分布乱数生成エンジン 

### using BinomialRandomEngine

```cpp
using cpp_robotics::BinomialRandomEngine = typedef RandomGenerator<std::binomial_distribution<> >;
```

二項分布乱数生成エンジン 

### using GeometricRandomEngine

```cpp
using cpp_robotics::GeometricRandomEngine = typedef RandomGenerator<std::geometric_distribution<> >;
```

幾何学分布乱数生成エンジン 

### using NegativeBinomialRandomEngine

```cpp
using cpp_robotics::NegativeBinomialRandomEngine = typedef RandomGenerator<std::negative_binomial_distribution<> >;
```

負の二項分布乱数生成エンジン 

### using PoissonRandomEngine

```cpp
using cpp_robotics::PoissonRandomEngine = typedef RandomGenerator<std::poisson_distribution<> >;
```

ポワソン分布乱数生成エンジン 

### using ExponentialRandomEngine

```cpp
using cpp_robotics::ExponentialRandomEngine = typedef RandomGenerator<std::exponential_distribution<> >;
```

指数分布乱数生成エンジン 

### using GammaRandomEngine

```cpp
using cpp_robotics::GammaRandomEngine = typedef RandomGenerator<std::gamma_distribution<> >;
```

ガンマ分布乱数生成エンジン 

### using WeibullRandomEngine

```cpp
using cpp_robotics::WeibullRandomEngine = typedef RandomGenerator<std::weibull_distribution<> >;
```

ワイブル分布乱数生成エンジン 

### using ExtremeValueRandomEngine

```cpp
using cpp_robotics::ExtremeValueRandomEngine = typedef RandomGenerator<std::extreme_value_distribution<> >;
```

極値分布乱数生成エンジン 

### using NormalRandomEngine

```cpp
using cpp_robotics::NormalRandomEngine = typedef RandomGenerator<std::normal_distribution<> >;
```

正規分布乱数生成エンジン 

### using LognormalRandomEngine

```cpp
using cpp_robotics::LognormalRandomEngine = typedef RandomGenerator<std::lognormal_distribution<> >;
```

対数正規分布乱数生成エンジン 

### using ChiSquaredRandomEngine

```cpp
using cpp_robotics::ChiSquaredRandomEngine = typedef RandomGenerator<std::chi_squared_distribution<> >;
```

カイ二乗分布乱数生成エンジン 

### using CauchyRandomEngine

```cpp
using cpp_robotics::CauchyRandomEngine = typedef RandomGenerator<std::cauchy_distribution<> >;
```

コーシー分布乱数生成エンジン 

### using FisherFRandomEngine

```cpp
using cpp_robotics::FisherFRandomEngine = typedef RandomGenerator<std::fisher_f_distribution<> >;
```

フィッシャーのF分布乱数生成エンジン 

### using StudentTRandomEngine

```cpp
using cpp_robotics::StudentTRandomEngine = typedef RandomGenerator<std::student_t_distribution<> >;
```

ステューデントのt分布乱数生成エンジン 

### using DiscreteRandomEngine

```cpp
using cpp_robotics::DiscreteRandomEngine = typedef RandomGenerator<std::discrete_distribution<> >;
```

整数のインデックスごとに離散した確率分布の乱数生成エンジン 

### using PiecewiseConstantRandomEngine

```cpp
using cpp_robotics::PiecewiseConstantRandomEngine = typedef RandomGenerator<std::piecewise_constant_distribution<> >;
```

区間ごとの重み付けを定数値とした分布の乱数生成エンジン 

### using PiecewiseLinearRandomEngine

```cpp
using cpp_robotics::PiecewiseLinearRandomEngine = typedef RandomGenerator<std::piecewise_linear_distribution<> >;
```

区間ごとの重み付けを線形に接続した分布の乱数生成エンジン 

### using TorqueConstant

```cpp
using cpp_robotics::unit::TorqueConstant = typedef unit_assem::unit_div<Torque, Ampere>::unit;
```


### using BackEmfConstant

```cpp
using cpp_robotics::unit::BackEmfConstant = typedef unit_assem::unit_div<Volt, AngularVelocity>::unit;
```


### using FrictionConstant

```cpp
using cpp_robotics::unit::FrictionConstant = typedef unit_assem::unit_mul<Torque, Second>::unit;
```


### using Second

```cpp
using cpp_robotics::unit::Second = typedef Unit<double, unit_dimention::second, prefix::none>;
```


### using MilliSecond

```cpp
using cpp_robotics::unit::MilliSecond = typedef Unit<double, unit_dimention::second, prefix::milli>;
```


### using MicroSecond

```cpp
using cpp_robotics::unit::MicroSecond = typedef Unit<double, unit_dimention::second, prefix::micro>;
```


### using Meter

```cpp
using cpp_robotics::unit::Meter = typedef Unit<double, unit_dimention::metere, prefix::none>;
```


### using MilliMeter

```cpp
using cpp_robotics::unit::MilliMeter = typedef Unit<double, unit_dimention::metere, prefix::milli>;
```


### using MicroMeter

```cpp
using cpp_robotics::unit::MicroMeter = typedef Unit<double, unit_dimention::metere, prefix::micro>;
```


### using CentiMeter

```cpp
using cpp_robotics::unit::CentiMeter = typedef Unit<double, unit_dimention::metere, prefix::centi>;
```


### using KiloGram

```cpp
using cpp_robotics::unit::KiloGram = typedef Unit<double, unit_dimention::kilogram, prefix::none>;
```


### using Gram

```cpp
using cpp_robotics::unit::Gram = typedef Unit<double, unit_dimention::kilogram, prefix::milli>;
```


### using Watt

```cpp
using cpp_robotics::unit::Watt = typedef Unit<double, unit_dimention::watt, prefix::none>;
```


### using KiloWatt

```cpp
using cpp_robotics::unit::KiloWatt = typedef Unit<double, unit_dimention::watt, prefix::kilo>;
```


### using Newton

```cpp
using cpp_robotics::unit::Newton = typedef Unit<double, unit_dimention::newton, prefix::none>;
```


### using KiloNewton

```cpp
using cpp_robotics::unit::KiloNewton = typedef Unit<double, unit_dimention::newton, prefix::kilo>;
```


### using Pascal

```cpp
using cpp_robotics::unit::Pascal = typedef Unit<double, unit_dimention::pascal, prefix::none>;
```


### using KiloPascal

```cpp
using cpp_robotics::unit::KiloPascal = typedef Unit<double, unit_dimention::pascal, prefix::kilo>;
```


### using Hertz

```cpp
using cpp_robotics::unit::Hertz = typedef Unit<double, unit_dimention::hertz, prefix::none>;
```


### using Area

```cpp
using cpp_robotics::unit::Area = typedef Unit<double, unit_dimention::area, prefix::none>;
```


### using Volume

```cpp
using cpp_robotics::unit::Volume = typedef Unit<double, unit_dimention::volume, prefix::none>;
```


### using Velocity

```cpp
using cpp_robotics::unit::Velocity = typedef Unit<double, unit_dimention::velocity, prefix::none>;
```


### using Acceleration

```cpp
using cpp_robotics::unit::Acceleration = typedef Unit<double, unit_dimention::acceleration, prefix::none>;
```


### using Dencity

```cpp
using cpp_robotics::unit::Dencity = typedef Unit<double, unit_dimention::dencity, prefix::none>;
```


### using Torque

```cpp
using cpp_robotics::unit::Torque = typedef Unit<double, unit_dimention::torque, prefix::none>;
```


### using Inertia

```cpp
using cpp_robotics::unit::Inertia = typedef Unit<double, unit_dimention::inertia, prefix::none>;
```


### using Ampere

```cpp
using cpp_robotics::unit::Ampere = typedef Unit<double, unit_dimention::ampere, prefix::none>;
```


### using MilliAmpere

```cpp
using cpp_robotics::unit::MilliAmpere = typedef Unit<double, unit_dimention::ampere, prefix::milli>;
```


### using Volt

```cpp
using cpp_robotics::unit::Volt = typedef Unit<double, unit_dimention::volt, prefix::none>;
```


### using MilliVolt

```cpp
using cpp_robotics::unit::MilliVolt = typedef Unit<double, unit_dimention::volt, prefix::milli>;
```


### using Ohm

```cpp
using cpp_robotics::unit::Ohm = typedef Unit<double, unit_dimention::ohm, prefix::none>;
```


### using MilliOhm

```cpp
using cpp_robotics::unit::MilliOhm = typedef Unit<double, unit_dimention::ohm, prefix::milli>;
```


### using Henry

```cpp
using cpp_robotics::unit::Henry = typedef Unit<double, unit_dimention::henry, prefix::none>;
```


### using MilliHenry

```cpp
using cpp_robotics::unit::MilliHenry = typedef Unit<double, unit_dimention::henry, prefix::milli>;
```


### using Farad

```cpp
using cpp_robotics::unit::Farad = typedef Unit<double, unit_dimention::farad, prefix::none>;
```


### using MilliFarad

```cpp
using cpp_robotics::unit::MilliFarad = typedef Unit<double, unit_dimention::farad, prefix::milli>;
```


### using MicroFarad

```cpp
using cpp_robotics::unit::MicroFarad = typedef Unit<double, unit_dimention::farad, prefix::micro>;
```


### using NanoFarad

```cpp
using cpp_robotics::unit::NanoFarad = typedef Unit<double, unit_dimention::farad, prefix::nano>;
```


### using Radian

```cpp
using cpp_robotics::unit::Radian = typedef Unit<double, unit_dimention::angle, prefix::none, tag::angle::radian>;
```


### using Degree

```cpp
using cpp_robotics::unit::Degree = typedef Unit<double, unit_dimention::angle, prefix::none, tag::angle::degree>;
```


### using AngularVelocity

```cpp
using cpp_robotics::unit::AngularVelocity = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rad_per_sec>;
```


### using Rps

```cpp
using cpp_robotics::unit::Rps = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rps>;
```


### using Rpm

```cpp
using cpp_robotics::unit::Rpm = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rpm>;
```


### using AngularAcceleration

```cpp
using cpp_robotics::unit::AngularAcceleration = typedef Unit<double, unit_dimention::angular_acceleration, prefix::none>;
```


### using AutoDiffScalar

```cpp
template <class DerType >
using cpp_robotics::AutoDiffScalar = typedef Eigen::AutoDiffScalar<DerType>;
```


### using AutoDiffVector

```cpp
template <class DerType ,
int NX =Eigen::Dynamic>
using cpp_robotics::AutoDiffVector = typedef Eigen::Matrix<AutoDiffScalar<DerType>, NX, 1>;
```


### using Quaternionf

```cpp
using cpp_robotics::Quaternionf = typedef Quaternion<float>;
```


### using Quaterniond

```cpp
using cpp_robotics::Quaterniond = typedef Quaternion<double>;
```


### using Transformf

```cpp
using cpp_robotics::Transformf = typedef Transform<float>;
```


### using Transformd

```cpp
using cpp_robotics::Transformd = typedef Transform<double>;
```


### using Vector2f

```cpp
using cpp_robotics::Vector2f = typedef Vector2<float>;
```


### using Vector2d

```cpp
using cpp_robotics::Vector2d = typedef Vector2<double>;
```


### using Vector3f

```cpp
using cpp_robotics::Vector3f = typedef Vector3<float>;
```


### using Vector3d

```cpp
using cpp_robotics::Vector3d = typedef Vector3<double>;
```


### using Vector4f

```cpp
using cpp_robotics::Vector4f = typedef Vector4<float>;
```


### using Vector4d

```cpp
using cpp_robotics::Vector4d = typedef Vector4<double>;
```



## Functions Documentation

### function calcu_transformatoin

```cpp
template <size_t DIM>
static std::pair< Eigen::Matrix< double, DIM, DIM >, Eigen::Matrix< double, DIM, 1 > > calcu_transformatoin(
    std::vector< Eigen::Matrix< double, DIM, 1 >> dest,
    std::vector< Eigen::Matrix< double, DIM, 1 >> fixed
)
```


### function icp

```cpp
template <size_t DIM>
static std::tuple< std::vector< Eigen::Matrix< double, DIM, 1 > >, size_t > icp(
    std::vector< Eigen::Matrix< double, DIM, 1 >> dest,
    std::vector< Eigen::Matrix< double, DIM, 1 >> fixed,
    size_t max_iter =100
)
```


### function mahalanobis

```cpp
double mahalanobis(
    const Eigen::VectorXd & a,
    const Eigen::VectorXd & b,
    const Eigen::MatrixXd cov_inv
)
```

マハラノビス距離の計算 

**Parameters**: 

  * **a** 
  * **b** 
  * **cov_inv** 分散の逆行列 


**Return**: double マハラノビス距離 

### function poly_regression

```cpp
Polynomial poly_regression(
    const std::vector< double > & x,
    const std::vector< double > & y,
    const size_t degree
)
```

回帰曲線 

**Parameters**: 

  * **x** 
  * **y** 
  * **degree** 回帰曲線の次元 


**Return**: [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/)

### function gererate_random

```cpp
template <typename Real  =double>
static Real gererate_random()
```

0.0〜1.0までの一様分布の乱数を生成する 

**Template Parameters**: 

  * **Real** 浮動小数点型 


**Return**: Real 乱数 

### function solve_riccati_arimoto_potter

```cpp
static std::optional< Eigen::MatrixXd > solve_riccati_arimoto_potter(
    const Eigen::MatrixXd & A,
    const Eigen::MatrixXd & B,
    const Eigen::MatrixXd & Q,
    const Eigen::MatrixXd & R
)
```

有本-ポッターの方法によるリカッチ方程式の解法 

**Parameters**: 

  * **A** 
  * **B** 
  * **Q** 
  * **R** 


**Return**: std::optional<Eigen::MatrixXd> 

### function lqr

```cpp
static Eigen::MatrixXd lqr(
    const Eigen::MatrixXd & A,
    const Eigen::MatrixXd & B,
    const Eigen::MatrixXd & Q,
    const Eigen::MatrixXd & R
)
```


### function controllability_matrix

```cpp
static Eigen::MatrixXd controllability_matrix(
    const Eigen::MatrixXd & A,
    const Eigen::VectorXd & B
)
```

可制御性行列の計算 

**Parameters**: 

  * **A** 
  * **B** 


**Return**: Eigen::MatrixXd 

### function is_controllable

```cpp
static bool is_controllable(
    const Eigen::MatrixXd & A,
    const Eigen::VectorXd & B
)
```

可制御性の判別 

**Parameters**: 

  * **A** 
  * **B** 


**Return**: 

  * true システムが可制御である 
  * false システムが可制御でない 


### function is_controllable

```cpp
static bool is_controllable(
    const StateSpaceSystem & sys
)
```


### function observability_matrix

```cpp
static Eigen::MatrixXd observability_matrix(
    const Eigen::MatrixXd & A,
    const Eigen::RowVectorXd & C
)
```

可観測性行列を計算する 

**Parameters**: 

  * **A** 
  * **C** 


**Return**: Eigen::MatrixXd 

### function is_observable

```cpp
static bool is_observable(
    const Eigen::MatrixXd & A,
    const Eigen::RowVectorXd & C
)
```

可観測性の判別 

**Parameters**: 

  * **A** 
  * **C** 


**Return**: 

  * true システムが可観測である 
  * false システムが可観測でない 


### function is_observable

```cpp
static bool is_observable(
    const StateSpaceSystem & sys
)
```


**Parameters**: 

  * **sys** 可観測性の判別 


**Return**: 

  * true システムが可観測である 
  * false システムが可観測でない 


### function canonicalize_system

```cpp
static std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > canonicalize_system(
    const Eigen::MatrixXd & A,
    const Eigen::MatrixXd & B,
    const Eigen::MatrixXd & C,
    const Eigen::MatrixXd & D,
    CanonicalizeMode mode =CanonicalizeMode::COMPANION
)
```

同値変換による可制御正準形への変換 

**Parameters**: 

  * **A** 
  * **B** 
  * **C** 
  * **D** 
  * **mode** 


**Return**: std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> 

### function canonicalize_system

```cpp
static std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > canonicalize_system(
    const Eigen::MatrixXd & A,
    const Eigen::MatrixXd & B,
    const Eigen::MatrixXd & C,
    CanonicalizeMode mode =CanonicalizeMode::COMPANION
)
```

同値変換による可制御正準形への変換 

**Parameters**: 

  * **A** 
  * **B** 
  * **C** 
  * **mode** 


**Return**: std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> 

### function canonicalize_system

```cpp
static std::tuple< Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd > canonicalize_system(
    const StateSpaceSystem & sys,
    CanonicalizeMode mode =CanonicalizeMode::COMPANION
)
```

同値変換による可制御正準形への変換 

**Parameters**: 

  * **sys** 
  * **mode** 


**Return**: std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd> 

### function place

```cpp
static Eigen::VectorXd place(
    const StateSpaceSystem & sys,
    std::vector< double > poles
)
```

アッカーマン法によるSISOモデルの極配置 

**Parameters**: 

  * **sys** 
  * **poles** 


**Return**: Eigen::VectorXd 

### function intersect

```cpp
bool intersect(
    const Vector2d & a,
    const Vector2d & b
)
```


### function intersect

```cpp
bool intersect(
    const Vector2d & a,
    const Line & b
)
```


### function intersect

```cpp
bool intersect(
    const Vector2d & a,
    const Rect & b
)
```


### function intersect

```cpp
bool intersect(
    const Vector2d & a,
    const Circle & b
)
```


### function intersect

```cpp
bool intersect(
    const Line & a,
    const Vector2d & b
)
```


### function intersect

```cpp
bool intersect(
    const Line & a,
    const Line & b
)
```


### function intersect

```cpp
bool intersect(
    const Line & a,
    const Circle & b
)
```


### function intersect

```cpp
bool intersect(
    const Rect & a,
    const Vector2d & b
)
```


### function intersect

```cpp
bool intersect(
    const Circle & a,
    const Vector2d & b
)
```


### function intersect

```cpp
bool intersect(
    const Circle & a,
    const Line & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Vector2d & a,
    const Vector2d & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Vector2d & a,
    const Line & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Vector2d & a,
    const Rect & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Vector2d & a,
    const Circle & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Line & a,
    const Vector2d & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Line & a,
    const Line & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Line & a,
    const Circle & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Rect & a,
    const Vector2d & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Circle & a,
    const Vector2d & b
)
```


### function intersect_at

```cpp
std::vector< Vector2d > intersect_at(
    const Circle & a,
    const Line & b
)
```


### function contain

```cpp
bool contain(
    const Vector2d & range,
    const Vector2d & target
)
```


### function contain

```cpp
bool contain(
    const Rect & range,
    const Vector2d & target
)
```


### function operator<<

```cpp
std::ostream & operator<<(
    std::ostream & os,
    const Vector2d & v
)
```


### function operator<<

```cpp
std::ostream & operator<<(
    std::ostream & os,
    const Vector3d & v
)
```


### function operator<<

```cpp
std::ostream & operator<<(
    std::ostream & os,
    const Vector4d & v
)
```


### function operator<<

```cpp
std::ostream & operator<<(
    std::ostream & os,
    const Transformd & v
)
```


### function generate_mabuchi_motor_param

```cpp
inline constexpr DCMotorParam generate_mabuchi_motor_param(
    Volt nominal_voltage,
    Rpm free_speed,
    Ampere free_current,
    Torque stall_torque,
    Ampere stall_current,
    Henry inductance,
    Inertia rotor_inertia
)
```


### function generate_maxon_brush_motor_param

```cpp
inline constexpr DCMotorParam generate_maxon_brush_motor_param(
    Volt nominal_voltage,
    Rpm free_speed,
    Ampere free_current,
    Ohm resistance,
    Henry inductance,
    TorqueConstant Kt,
    Inertia rotor_inertia
)
```


### function make_motor_vel_tf

```cpp
static TransferFunction make_motor_vel_tf(
    const DCMotorParam & motor,
    const double dt
)
```

DCモーターのモデルから角速度の伝達関数を生成する 

**Parameters**: 

  * **motor** 
  * **dt** 


**Return**: [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

### function make_motor_pos_tf

```cpp
static TransferFunction make_motor_pos_tf(
    const DCMotorParam & motor,
    const double dt
)
```

DCモーターのモデルから角度の伝達関数を生成する 

**Parameters**: 

  * **motor** 
  * **dt** 


**Return**: [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

### function make_geared_motor_vel_tf

```cpp
static TransferFunction make_geared_motor_vel_tf(
    const DCGearedMotorParam & geared_motor,
    const double dt
)
```

ギアヘッド付きDCモーターのモデルから角速度の伝達関数を生成する 

**Parameters**: 

  * **geared_motor** 
  * **dt** 


**Return**: [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

### function make_geared_motor_pos_tf

```cpp
static TransferFunction make_geared_motor_pos_tf(
    const DCGearedMotorParam & geared_motor,
    const double dt
)
```

ギアヘッド付きDCモーターのモデルから角度の伝達関数を生成する 

**Parameters**: 

  * **geared_motor** 
  * **dt** 


**Return**: [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

### function barrier_method

```cpp
static std::tuple< bool, Eigen::VectorXd, size_t > barrier_method(
    std::function< double(const Eigen::VectorXd &)> f,
    ConstraintArray constraint,
    Eigen::VectorXd x_init,
    const double r_init =10.0,
    const double tol =1e-3,
    const size_t max_iter =1000
)
```

バリア法 

### function bfgs_step

```cpp
static void bfgs_step(
    Eigen::MatrixXd & hess,
    Eigen::VectorXd s,
    Eigen::VectorXd y
)
```

BFGS法 

**Parameters**: 

  * **hess** 前ステップまでの近似ヘッシアン 
  * **s** x_k+1 - x_k 
  * **y** \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k) 


### function powells_modified_bfgs_step

```cpp
static void powells_modified_bfgs_step(
    Eigen::MatrixXd & hess,
    Eigen::VectorXd s,
    Eigen::VectorXd y,
    double gamma =0.2
)
```

パウエルの修正BFGS法 

**Parameters**: 

  * **hess** 前ステップまでの近似ヘッシアン 
  * **s** x_k+1 - x_k 
  * **y** \grad_x L(x_k+1, u_k+1) - \grad_x L(x_k, u_k) 
  * **gamma** 


### function bracketing_serach

```cpp
static double bracketing_serach(
    std::function< double(Eigen::VectorXd)> func,
    std::function< Eigen::VectorXd(Eigen::VectorXd)> grad,
    const Eigen::VectorXd & x,
    const Eigen::VectorXd & d,
    double gamma =0.3,
    double tau =0.9,
    const size_t max_iter =1000
)
```

アルミホ条件を満たすステップ幅を求める囲い込み法 

**Parameters**: 

  * **func** 
  * **grad** 
  * **x** 
  * **d** 
  * **gamma** 
  * **tau** 
  * **max_iter** 


**Return**: double 

### function bracketing_serach

```cpp
static double bracketing_serach(
    std::function< double(double)> func,
    const double init =1.0,
    const double beta =0.9,
    const size_t max_iter =1000
)
```

囲い込み法 

**Parameters**: 

  * **func** 
  * **init** 
  * **beta** 
  * **max_iter** 


**Return**: double 

### function derivative

```cpp
static double derivative(
    std::function< double(double)> f,
    double x,
    double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)
)
```

R -> Rの数値微分 

**Parameters**: 

  * **f** 
  * **x** 
  * **eps** 


**Return**: double 

### function derivative

```cpp
static Eigen::VectorXd derivative(
    std::function< double(Eigen::VectorXd)> f,
    Eigen::VectorXd x,
    double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)
)
```

R^n -> Rの数値微分 

**Parameters**: 

  * **f** 
  * **x** 
  * **eps** 


**Return**: Eigen::VectorXd 

### function derivative

```cpp
static Eigen::MatrixXd derivative(
    std::function< Eigen::VectorXd(Eigen::VectorXd)> f,
    Eigen::VectorXd x,
    double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)
)
```

R^n -> R^mの数値微分 

**Parameters**: 

  * **f** 
  * **x** 
  * **eps** 


**Return**: Eigen::MatrixXd 

### function second_derivative

```cpp
static double second_derivative(
    std::function< double(double)> f,
    double x,
    double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)
)
```

R -> Rの2回数値微分 

**Parameters**: 

  * **f** 
  * **x** 
  * **eps** 


**Return**: double 

### function approx_hessian

```cpp
static Eigen::MatrixXd approx_hessian(
    std::function< double(Eigen::VectorXd)> f,
    Eigen::VectorXd x,
    double eps =std::pow(std::numeric_limits< double >::epsilon(), 0.5)
)
```


**Parameters**: 

  * **f** 
  * **x** 
  * **eps** 


**Return**: Eigen::MatrixXd 

### function golden_search

```cpp
static double golden_search(
    std::function< double(double)> f,
    double low,
    double high,
    const double tol =1e-6,
    const size_t max_iter =100
)
```

黄金探索 

**Parameters**: 

  * **f** 
  * **low** 
  * **high** 
  * **tol** 
  * **max_iter** 


**Return**: double 

### function newton_method

```cpp
static std::tuple< bool, Eigen::VectorXd, size_t > newton_method(
    std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad,
    std::function< Eigen::MatrixXd(const Eigen::VectorXd &)> hesse,
    Eigen::VectorXd x_init,
    const double tol =1e-6,
    const size_t max_iter =1000
)
```

ニュートン法 

**Parameters**: 

  * **grad** 
  * **hesse** 
  * **x_init** 
  * **tol** 
  * **max_iter** 


**Return**: std::tuple<bool, Eigen::VectorXd, size_t> 

### function penalty_method

```cpp
static std::tuple< bool, Eigen::VectorXd, size_t > penalty_method(
    std::function< double(const Eigen::VectorXd &)> f,
    ConstraintArray constraint,
    Eigen::VectorXd x_init,
    const double r_init =1.0,
    const double tol =1e-3,
    const size_t max_iter =1000
)
```

ペナルティ法 

**Parameters**: 

  * **f** 
  * **constraint** 
  * **x_init** 
  * **r_init** 
  * **tol** 
  * **max_iter** 


**Return**: std::tuple<bool, Eigen::VectorXd, size_t> 

### function quasi_newton_method

```cpp
static std::tuple< bool, Eigen::VectorXd, size_t > quasi_newton_method(
    std::function< double(const Eigen::VectorXd &)> f,
    std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad,
    Eigen::VectorXd x_init,
    const double tol =1e-6,
    const size_t max_iter =1000
)
```

準ニュートン法 

**Parameters**: 

  * **f** 
  * **grad** 
  * **x_init** 
  * **tol** 
  * **max_iter** 


**Return**: std::tuple<bool, Eigen::VectorXd, size_t> 

### function steepest_descent_method

```cpp
static std::tuple< bool, Eigen::VectorXd, size_t > steepest_descent_method(
    std::function< double(const Eigen::VectorXd &)> f,
    std::function< Eigen::VectorXd(const Eigen::VectorXd &)> grad,
    Eigen::VectorXd x_init,
    const double tol =1e-6,
    const size_t max_iter =1000
)
```

最急降下法 

**Parameters**: 

  * **f** 
  * **grad** 
  * **x_init** 
  * **tol** 
  * **max_iter** 


**Return**: std::tuple<bool, Eigen::VectorXd, size_t> 

### function a_star

```cpp
static std::vector< Eigen::Vector2i > a_star(
    const Eigen::Vector2i & start,
    const Eigen::Vector2i & end,
    const Eigen::MatrixXi & map
)
```

A*法 

**Parameters**: 

  * **start** 
  * **end** 
  * **map** 


**Return**: std::vector<Eigen::Vector2i> 

### function wave_propagation

```cpp
std::vector< Eigen::Vector2i > wave_propagation(
    const Eigen::Vector2i & start,
    const Eigen::Vector2i & end,
    const Eigen::MatrixXi & map
)
```

Wave propagation法 

**Parameters**: 

  * **start** 
  * **end** 
  * **map** 


**Return**: std::vector<Eigen::Vector2i> 

### function bode

```cpp
static std::tuple< std::vector< double >, std::vector< double > > bode(
    TransferFunction & tf,
    const std::vector< double > & omegas =logspace(-2, 2, 500),
    bool gain_db_mode =true,
    bool phase_deg_mode =true
)
```

ボード線図の応答を計算する 

**Parameters**: 

  * **tf** 
  * **omegas** 
  * **gain_db_mode** 
  * **phase_deg_mode** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function bode_plot

```cpp
static void bode_plot(
    TransferFunction & tf,
    const std::vector< double > & omegas =logspace(-2, 2, 500)
)
```

ボード線図を表示する(matplotlibが必要) 

**Parameters**: 

  * **tf** 
  * **omegas** 


### function nyquist

```cpp
static std::tuple< std::vector< double >, std::vector< double > > nyquist(
    TransferFunction & tf,
    const std::vector< double > & omegas =logspace(-2, 2, 500)
)
```

ナイキスト線図の応答を計算する 

**Parameters**: 

  * **tf** 
  * **omegas** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function nyquist_plot

```cpp
static void nyquist_plot(
    TransferFunction & tf,
    const std::vector< double > & omegas =logspace(-2, 2, 500)
)
```

ナイキスト線図を表示する(matplotlibが必要) 

**Parameters**: 

  * **tf** 
  * **omegas** 


### function operator<<

```cpp
std::ostream & operator<<(
    std::ostream & os,
    const Polynomial & v
)
```


### function make_feedback_system

```cpp
template <class CONTROLLER_T ,
class SYSTEM_T >
static SisoFeedbackSystem make_feedback_system(
    CONTROLLER_T & controller,
    SYSTEM_T & system
)
```


### function set_controller

```cpp
static void set_controller(
    SisoFeedbackSystem::func_list_t & fn,
    PIDController & controller
)
```


### function set_controller

```cpp
static void set_controller(
    SisoFeedbackSystem::func_list_t & fn,
    NctfController & controller
)
```


### function set_system

```cpp
static void set_system(
    SisoFeedbackSystem::func_list_t & fn,
    TransferFunction & system
)
```


### function impluse

```cpp
static std::tuple< std::vector< double >, std::vector< double > > impluse(
    TransferFunction & sys,
    double time
)
```

インパルス応答を求める 

**Parameters**: 

  * **sys** 
  * **time** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function step

```cpp
static std::tuple< std::vector< double >, std::vector< double > > step(
    const std::function< double(double)> & sys,
    double dt,
    double time,
    const double gain =1.0
)
```

ステップ応答を求める 

**Parameters**: 

  * **sys** 
  * **dt** 
  * **time** 
  * **gain** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function step

```cpp
static std::tuple< std::vector< double >, std::vector< double > > step(
    TransferFunction & sys,
    double time,
    const double gain =1.0
)
```

ステップ応答を求める 

**Parameters**: 

  * **sys** 
  * **time** 
  * **gain** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function step

```cpp
static std::tuple< std::vector< double >, std::vector< double > > step(
    DiscreteTransferFunction & sys,
    double time,
    const double gain =1.0
)
```

ステップ応答を求める 

**Parameters**: 

  * **sys** 
  * **time** 
  * **gain** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function lsim

```cpp
static std::tuple< std::vector< double >, std::vector< double > > lsim(
    TransferFunction & sys,
    std::vector< double > input
)
```

任意の入力による応答を求める 

**Parameters**: 

  * **sys** 
  * **input** 


**Return**: std::tuple<std::vector<double>, std::vector<double>> 

### function conv_factor

```cpp
template <class UnitDimType ,
int FromTag,
int ToTag,
bool IsNormalTag =tag::is_normal_tag<FromTag>::value && tag::is_normal_tag<ToTag>::value>
constexpr double conv_factor()
```


### function operator*

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator*(
    const Unit< T1, UnitDim, Prefix, Tag > & l_value,
    const T2 & r_value
)
```


### function operator*

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator*(
    const T1 & l_value,
    const Unit< T2, UnitDim, Prefix, Tag > & r_value
)
```


### function operator/

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator/(
    const T1 & l_value,
    const Unit< T2, UnitDim, Prefix, Tag > & r_value
)
```


### function operator/

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator/(
    const Unit< T1, UnitDim, Prefix, Tag > & l_value,
    const T2 & r_value
)
```


### function operator*

```cpp
template <typename T1 ,
class UnitDim1 ,
class Prefix1 ,
int Tag1,
typename T2 ,
class UnitDim2 ,
class Prefix2 ,
int Tag2>
constexpr auto operator*(
    const Unit< T1, UnitDim1, Prefix1, Tag1 > & lhl,
    const Unit< T2, UnitDim2, Prefix2, Tag2 > & rhl
)
```


### function operator/

```cpp
template <typename T1 ,
class UnitDim1 ,
class Prefix1 ,
int Tag1,
typename T2 ,
class UnitDim2 ,
class Prefix2 ,
int Tag2>
constexpr auto operator/(
    const Unit< T1, UnitDim1, Prefix1, Tag1 > & lhl,
    const Unit< T2, UnitDim2, Prefix2, Tag2 > & rhl
)
```


### function operator+

```cpp
template <typename T ,
class UnitDim ,
class Prefix1 ,
class Prefix2 ,
int Tag>
constexpr auto operator+(
    const Unit< T, UnitDim, Prefix1, Tag > & lhl,
    const Unit< T, UnitDim, Prefix2, Tag > & rhl
)
```


### function operator-

```cpp
template <typename T ,
class UnitDim ,
class Prefix1 ,
class Prefix2 ,
int Tag>
constexpr auto operator-(
    const Unit< T, UnitDim, Prefix1, Tag > & lhl,
    const Unit< T, UnitDim, Prefix2, Tag > & rhl
)
```


### function make_auto_diff_vector

```cpp
template <class DerType >
static auto make_auto_diff_vector(
    const size_t & dim,
    const std::optional< DerType > & x =std::nullopt
)
```


### function shift_left

```cpp
template <class ForwardIterator >
constexpr ForwardIterator shift_left(
    ForwardIterator first,
    ForwardIterator last,
    typename std::iterator_traits< ForwardIterator >::difference_type n
)
```

C++17のstd::shift_leftの自前実装 C++14で動作する 

**Parameters**: 

  * **first** 
  * **last** 
  * **n** 


**Template Parameters**: 

  * **ForwardIterator** 


**Return**: constexpr ForwardIterator 

### function shift_right

```cpp
template <class ForwardIterator >
constexpr ForwardIterator shift_right(
    ForwardIterator first,
    ForwardIterator last,
    typename std::iterator_traits< ForwardIterator >::difference_type n
)
```

C++17のstd::shift_rightの自前実装 C++14で動作する 

**Parameters**: 

  * **first** 
  * **last** 
  * **n** 


**Template Parameters**: 

  * **ForwardIterator** 


**Return**: constexpr ForwardIterator 

### function c_format

```cpp
template <typename... Args>
std::string c_format(
    const std::string & format,
    Args const &... args
)
```

printfと同様の操作でstd::stringを得る 

**Parameters**: 

  * **format** 
  * **args** 


**Template Parameters**: 

  * **Args** 


**Return**: std::string 

### function in_range_open

```cpp
template <typename T >
static constexpr bool in_range_open(
    T x,
    T min,
    T max
)
```


**Parameters**: 

  * **x** 
  * **min** 
  * **max** 


**Template Parameters**: 

  * **T** 


**Return**: 

  * true 
  * false 


### function in_range

```cpp
template <typename T >
static constexpr bool in_range(
    T x,
    T min,
    T max
)
```


**Parameters**: 

  * **x** 
  * **min** 
  * **max** 


**Template Parameters**: 

  * **T** 


**Return**: 

  * true 
  * false 


### function sgn

```cpp
template <typename T >
static constexpr int sgn(
    T x
)
```


**Parameters**: 

  * **x** 


**Template Parameters**: 

  * **T** 


**Return**: constexpr int 

### function radians

```cpp
template <typename T >
static constexpr float radians(
    T deg
)
```


**Parameters**: 

  * **deg** 


**Template Parameters**: 

  * **T** 


**Return**: constexpr float 

### function degrees

```cpp
template <typename T >
static constexpr float degrees(
    T rad
)
```


**Parameters**: 

  * **rad** 


**Template Parameters**: 

  * **T** 


**Return**: constexpr float 

### function normalize_angle_positive

```cpp
static inline float normalize_angle_positive(
    float angle
)
```


**Parameters**: 

  * **angle** 


**Return**: float 

### function normalize_angle

```cpp
static inline float normalize_angle(
    float angle
)
```


**Parameters**: 

  * **angle** 


**Return**: float 

### function shortest_angular_distance

```cpp
static inline float shortest_angular_distance(
    float from,
    float to
)
```


**Parameters**: 

  * **from** 
  * **to** 


**Return**: float 

### function nearest_angle

```cpp
static inline float nearest_angle(
    float from,
    float to
)
```


### function square

```cpp
inline constexpr float square(
    const float x
)
```


### function cubic

```cpp
inline constexpr float cubic(
    const float x
)
```


### function lerp

```cpp
inline constexpr float lerp(
    const float a,
    const float b,
    const float t
)
```


### function approx_eq

```cpp
inline constexpr float approx_eq(
    const float a,
    const float b
)
```


### function approx_zero

```cpp
inline constexpr float approx_zero(
    const float a
)
```


### function arrange

```cpp
static std::vector< double > arrange(
    double start,
    double end,
    double step =1.0
)
```


### function linspace

```cpp
static std::vector< double > linspace(
    double start,
    double end,
    size_t n =100
)
```


### function logspace

```cpp
static std::vector< double > logspace(
    double start,
    double end,
    size_t n =100
)
```


### function funcspace

```cpp
static std::vector< double > funcspace(
    std::function< double(size_t, size_t)> f,
    size_t n =100
)
```


### function sinspace

```cpp
static std::vector< double > sinspace(
    double a,
    double b,
    size_t n =100
)
```



## Attributes Documentation

### variable RZ_735VA_9517

```cpp
constexpr DCMotorParam RZ_735VA_9517 = generate_mabuchi_motor_param(
    18_V,
    20400_rpm,
    2.8_A,
    1265_mmNm,
    156_A,
    7.088e-5_H,
    2.46e-5 
);
```


### variable RS_775_8513

```cpp
constexpr DCMotorParam RS_775_8513 = generate_mabuchi_motor_param(
    18_V,
    18400_rpm,
    2.7_A,
    1216_mmNm, 
    130_A,
    5.872e-5_H,
    2.46e-5 
);
```


### variable RS_555VC_5524

```cpp
constexpr DCMotorParam RS_555VC_5524 = generate_mabuchi_motor_param(
    12_V,
    9100_rpm,
    0.8_A,
    450_mmNm, 
    36_A,
    1.820e-4_H,
    2.46e-5 
);
```


### variable RS_380PH_4045

```cpp
constexpr DCMotorParam RS_380PH_4045 = generate_mabuchi_motor_param(
    6_V,
    12500_rpm,
    0.56_A,
    77.5_mmNm, 
    18_A,
    1.521e-4_H,
    2.46e-5 
);
```


### variable RS_385PH_2465

```cpp
constexpr DCMotorParam RS_385PH_2465 = generate_mabuchi_motor_param(
    18_V,
    17500_rpm,
    0.23_A,
    76.9_mmNm, 
    7.91_A,
    1.521e-4_H,
    2.46e-5 
);
```


### variable RE_65_250_18

```cpp
constexpr DCMotorParam RE_65_250_18 = generate_maxon_brush_motor_param(
    18_V,
    3520_rpm,
    755_mA,
    0.0609_ohm,
    0.0226_mH,
    46e-3_Nm_per_A,
    1.38
);
```


### variable IG42C_4

```cpp
constexpr GearHeadParam IG42C_4 = { 1/4.0f, 0.8f };
```


### variable IG42C_14

```cpp
constexpr GearHeadParam IG42C_14 = { 1/14.0f, 0.7f };
```


### variable IG42C_17

```cpp
constexpr GearHeadParam IG42C_17 = { 1/17.0f, 0.7f };
```


### variable IG32_27

```cpp
constexpr GearHeadParam IG32_27 = { 1/27.0f, 0.7f };
```


### variable IG32_71

```cpp
constexpr GearHeadParam IG32_71 = { 1/71.0f, 0.6f };
```


### variable IG32_100

```cpp
constexpr GearHeadParam IG32_100 = { 1/100.0f, 0.6f };
```


### variable PI

```cpp
constexpr float PI = 3.1415926535897932384626433832795;
```

円周率 

### variable HALF_PI

```cpp
constexpr float HALF_PI = PI / 2.0;
```

円周率 / 2 

### variable TWO_PI

```cpp
constexpr float TWO_PI = PI * 2.0;
```

円周率 * 2 

### variable DEG_TO_RAD

```cpp
constexpr float DEG_TO_RAD = PI / 180.0;
```

degree -> radians 

### variable RAD_TO_DEG

```cpp
constexpr float RAD_TO_DEG = 180.0 / PI;
```

radian -> degree 

### variable EULER

```cpp
constexpr float EULER = 2.718281828459045235360287471352;
```

ネイピア数 

### variable GRAVITY

```cpp
constexpr float GRAVITY = 9.807;
```

重力 

### variable Nm2gfm

```cpp
constexpr float Nm2gfm = (1/GRAVITY);
```


### variable gfm2Nm

```cpp
constexpr float gfm2Nm = GRAVITY;
```


### variable mNm2gfcm

```cpp
constexpr float mNm2gfcm = (Nm2gfm * 100);
```


### variable gfcm2mNm

```cpp
constexpr float gfcm2mNm = (gfm2Nm / 100);
```





-------------------------------

Updated on 2022-10-05 at 01:02:06 +0900