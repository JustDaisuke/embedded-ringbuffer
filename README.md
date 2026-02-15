# embedded-ringbuffer
C++17 で実装する組み込み向け RingBuffer トレーニング用プロジェクトです。

Linux (WSL) + CMake + GoogleTest + GitHub Actions を用いた開発環境構築の学習を目的としています。

# Features
- C++17
- CMake ビルド
- GoogleTest 単体テスト
- clang-tidy 静的解析
- Address / Undefined Sanitizer 有効
- GitHub Actions による CI

# Build
mkdir build

cd build

cmake -DCMAKE_BUILD_TYPE=Debug ..

cmake --build .

# Test
cd build

ctest --output-on-failure

# Acknowledgements
本プロジェクトは ChatGPT の学習支援を受けて作成しています。

コードおよび設定内容はすべて理解・確認のうえ、作者が修正・管理しています。