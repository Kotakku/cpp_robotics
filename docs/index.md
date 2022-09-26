# cpp_robotics

制御工学、最適化、逆運動学などロボティクスに多用される技術をパッケージ化したライブラリ

## 機能
### 伝達関数・状態空間表現の表現とシミュレーション
伝達関数や状態空間表現クラスを使用してシステムを表現し、応答をシミュレーションする

### 様々な制御器による制御系の実現
PID制御器、LQR、極配置等による状態フィードバック等により制御系を構成する

### 最適化関数
連続関数の最適化関数が用意されており最適制御の実現を補助する

### フィルタ
ローパスフィルタやハイパスフィルタをはじめ、速度制限フィルタや加速度制限フィルタ、カルマンフィルタが用意されている

### 逆運動学
移動機構やロボットのアームの逆運動学を解くためのクラスを用意

### 単位クラス
SI単位系を実装してあり物理的な意味を対応させながらのコーディングが可能  
組立単位にも対応

### 頻繁に使用するベクトル演算クラス
Vector2 Vector3 Vector4 Quaternion Transformを用意
ベクトル同士の演算やノルム、回転の処理を簡単に記述

## プログラム例
プログラムのサンプルが用意されているため動かしながら理解することができる

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/cpp_robotics.hpp>

int main()
{
    namespace cr = cpp_robotics;

    constexpr cr::Vector2d vec(3.0, 4.0);
    printf("constexpr 2D vector: %f, %f\n", vec.x, vec.y);

    Eigen::MatrixXd A(2,2), B(2,1), Q(2,2), R(1,1), P(2,2);
    A << 0, 1, -10, -1;
    B << 0, 1;
    Q << 300, 0, 0, 60;
    R << 1;

    Eigen::MatrixXd K = cr::lqr(A, B, Q, R);
    std::cout << "LQR feedback vector" << std::endl;
    std::cout << K << std::endl;

    std::cout << "polynomial" << std::endl;
    cr::Polynomial p0({1, 0, 3});
    std::cout << p0 << std::endl;
    cr::Polynomial p1 = cr::Polynomial({1, -2}) * cr::Polynomial({1, 2});
    std::cout << p1 << std::endl;

    cr::TransferFunction tf({1.0}, {1, 1.0}, 0.01);

    namespace plt = matplotlibcpp;
    std::cout << "transfer function step responce" << std::endl;
    {
        auto [t, y] = cr::step(tf, 30);
        plt::plot(t, y);
        plt::show();
    }

    std::cout << "transfer function sin cruve input responce" << std::endl;
    {
        auto input = cr::sinspace(1, 0.1, 1000);
        auto [t, y] = cr::lsim(tf, input);
        plt::plot(t, y);
        plt::show();
    }
    
    std::cout << "transfer function bode fig plot" << std::endl;
    cr::bode_plot(tf);

    std::cout << "transfer function nyquist fig plot" << std::endl;
    cr::nyquist_plot(tf);
}
```
(プログラム例の[HelloWorld](example/hello_world.md)より)

## 技術資料
実装してあるパッケージについての技術資料も用意してあるためプログラムと理論を対応させながら使うことができる

## API
使用できる関数・クラスについては[こちら](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)