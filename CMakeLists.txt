# Cmakeのバージョン設定
cmake_minimum_required(VERSION 3.20)
# プロジェクトファイル名の定義　実行ファイル名やIDE表示名、ログ表示に使用
project(embedded_ringbuffer)

# C++17を使用
set(CMAKE_CXX_STANDARD 17)
# 必ずC++17を使用する　これがないと古い規格に勝手に落ちるらしい
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# compile_commands.json を出力する
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# ビルド時に静的解析を自動実行
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

include(FetchContent)

# ===== GoogleTest取得 =====
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ===== 本体 =====
# main.cpp から実行ファイル main を作る
add_executable(main main.cpp ring_buffer.cpp)

# この実行ファイル専用のコンパイルオプション Wall(一般警告), Wextra(追加警告), Werror(警告をエラー扱い), Pedantic(規格厳守)
target_compile_options(main PRIVATE
    -Wall
    -Wextra
    -Werror
    -pedantic
)

# Debugビルド時にメモリ破壊検出、未定義動作検出
target_compile_options(main PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)
# リンク時も同様
target_link_options(main PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

# ===== テスト =====
add_executable(test_ringbuffer test.cpp)

target_compile_options(test_ringbuffer PRIVATE
    -Wall
    -Wextra
    -Werror
    -pedantic
)

target_compile_options(test_ringbuffer PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

target_link_options(test_ringbuffer PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

target_link_libraries(test_ringbuffer
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_ringbuffer)
