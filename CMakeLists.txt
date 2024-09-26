cmake_minimum_required(VERSION 3.10)

project(fuzzing_test)

# Установка версии стандарта C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем необходимые флаги для компиляции с AFL (если требуется)
if (AFL_COMPILE)
    set(CMAKE_C_COMPILER afl-gcc)
    set(CMAKE_CXX_COMPILER afl-g++)
endif()

find_package(Qt5Core REQUIRED)

add_executable(fuzzing_test main.cpp)

target_link_libraries(fuzzing_test Qt5::Core)
