cmake_minimum_required(VERSION 3.20)
project(embedded_ringbuffer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
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
add_executable(main main.cpp)

target_compile_options(main PRIVATE
    -Wall
    -Wextra
    -Werror
    -pedantic
)

target_compile_options(main PRIVATE
    $<$<CONFIG:Debug>:-fsanitize=address,undefined>
)

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
