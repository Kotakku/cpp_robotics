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
- matplotlib

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