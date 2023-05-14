[![build](https://github.com/Kotakku/cpp_robotics/actions/workflows/build.yaml/badge.svg)](https://github.com/Kotakku/cpp_robotics/actions/workflows/build.yaml)
[![documentation](https://github.com/Kotakku/cpp_robotics/actions/workflows/documentation.yaml/badge.svg)](https://github.com/Kotakku/cpp_robotics/actions/workflows/documentation.yaml)

# cpp_robotics

**cpp_robotics**はロボティクスのためのC++ライブラリです

# 機能追加・実装の方針
- 勉強したものの確認用に実装する
- あったら便利そうな機能を実装する
- その他実装してみたい機能を実装する

# 環境
- C++17
- Eigen
- Python3 (matplotlib用)
- gtest

# サードパーティライブラリ
- [matplotlib-cpp](https://github.com/lava/matplotlib-cpp)

# 依存関係の環境構築
```
sudo apt install libeigen3-dev libgtest-dev
pip install numpy matplotlib
```

# ビルド・インストール
```
mkdir build && cd build
cmake ..
cmake --build .
sudo cmake --install .
```

exampleをビルドするときは以下
```
mkdir build && cd build
cmake -DCR_BUILD_EXAMPLE=ON ..
cmake --build .
```

# cpp_roboticsを使用する(ROS2)
vendorパッケージをワークスペースにcloneしてcolcon buildすることで使用できます  
https://github.com/Kotakku/cpp_robotics_vendor

# cpp_roboticsを使用する(Pure C++ project)
ライブラリはEigen3の様にヘッダファイルのみであるためCMakeLists.txtには一行追加するだけで使用できます
```
find_package(cpp_robotics REQUIRED)
```

# ドキュメント
- [https://kotakku.github.io/cpp_robotics/](https://kotakku.github.io/cpp_robotics/)

# ドキュメント生成
doxybook2とmkdocsをインストール後に

```sh
sh gen_doc.sh
mkdocs build
```