#include <iostream>
#include <Eigen/Dense>
#include <chrono>

void test1(Eigen::VectorXd &mat) {
    // ここで何らかの計算を行います。例:
    mat = Eigen::VectorXd::Random(mat.size());
}

Eigen::VectorXd test2(int size) {
    Eigen::VectorXd mat(size);
    // ここで何らかの計算を行います。例:
    mat = Eigen::VectorXd::Random(size);
    return mat;
}

int main() {
    const int size = 1000; // ベクトルのサイズ
    const int iterations = 1000; // 繰り返し回数

    // test1の時間計測
    Eigen::VectorXd mat1(size);
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        test1(mat1);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed1 = end1 - start1;
    std::cout << "test1 Average time: " << elapsed1.count() / iterations << " ms" << std::endl;

    // test2の時間計測
    auto start2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        Eigen::VectorXd mat2 = test2(size);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed2 = end2 - start2;
    std::cout << "test2 Average time: " << elapsed2.count() / iterations << " ms" << std::endl;

    return 0;
}
