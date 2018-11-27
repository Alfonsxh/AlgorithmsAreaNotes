cmake_minimum_required(VERSION 3.0)

project(AlgorithmsTest)

# 设置编译选项选项
# 值得注意的是add_compile_options命令添加的编译选项是针对所有编译器的(包括c和c++编译器)，
# 而set命令设置CMAKE_C_FLAGS或CMAKE_CXX_FLAGS变量则是分别只针对c和c++编译器的

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_compile_options(-std=c++11)

# 设置编译选项
set(VERSION_MAJOR 1)        # 设置选项需放定义文件的前面
set(VERSION_MINOR 0)

configure_file(     # 配置文件
        "${PROJECT_SOURCE_DIR}/include/config.h.in"
        "${PROJECT_SOURCE_DIR}/include/config.h"
        )

option(USE_NO_REPEAT_LIB "use norepeat library." ON)        # 设置编译选项，通过判断是否设置该选项，添加对应的预编译内容。改变编译选项后，要清理后编译
if (USE_NO_REPEAT_LIB)
    add_definitions(-DUSE_NO_REPEAT_LIB)
endif ()

# 添加头文件目录
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(ElementNotRepeat ${INCLUDE_DIR})

# 添加子文件夹，会包含子文件夹目录下的CMakeLists.txt文件
add_subdirectory(ElementNotRepeat)
add_subdirectory(RBTree)

# 添加可执行程序
add_executable(AlgorithmsTest main.cpp)

# 添加动态库依赖
target_link_libraries(AlgorithmsTest NotRepeat)