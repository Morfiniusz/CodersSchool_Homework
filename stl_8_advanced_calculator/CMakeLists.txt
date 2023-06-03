cmake_minimum_required(VERSION 3.10)
project(AdvancedCalculator)

set(FLAGS -Wall -Wpedantic -Wextra)

add_executable(${PROJECT_NAME} advancedCalculator.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)