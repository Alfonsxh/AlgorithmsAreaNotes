cmake_minimum_required(VERSION 3.0)
project(AlgorithmsTest)

# 设置c++11 选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# 打印功能
message("-- system arch:  ${CMAKE_SYSTEM_PROCESSOR}")

# 设置值
set(INCLUDE_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/ElementNotRepeat")
message("-- INCLUDE_DIR:  ${INCLUDE_DIR}")

# 添加文件
include_directories(${INCLUDE_DIR})

add_executable(Test
        ${INCLUDE_DIR}/DeleteRepeatElem.cpp
        main.cpp)