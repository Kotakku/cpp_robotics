# cpp_robotics

# コンセプト
- 勉強したものの確認用に実装する
- あったら便利そうな機能を実装する
- その他実装してみたい機能を実装する

# 環境
- C++17
- Eigen
- Python3 (matplotlib用)
- [gtest](https://github.com/google/googletest)

# サードパーティライブラリ
- [matplotlib-cpp](https://github.com/lava/matplotlib-cpp)

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
sudo cmake --install .
```

# 実装したい機能
[実装したい機能リスト](idea_note.md)