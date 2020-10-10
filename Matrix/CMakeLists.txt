cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Matrix)
project(${PROJECT_NAME})
set(TARGET_SRC "source.cpp" "Matrix.h")
add_executable(${PROJECT_NAME} ${TARGET_SRC})