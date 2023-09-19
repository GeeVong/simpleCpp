cmake_minimum_required(VERSION 3.25)
project(simpleCpp)

set(CMAKE_CXX_STANDARD 17)

# 这里设置好路径后，进入子模块的cmake时不用再次设置
SET(EXECUTABLE_OUTPUT_PATH ../../bin)  # 设置可执行文件的输出目录
SET(LIBRARY_OUTPUT_PATH ../../lib)	   # 设置库文件的输出目录

add_executable(simpleCpp
        main.cpp system.h system.cpp)

aux_source_directory(../.. SRC_LIST)
add_library(libsimpleCpp SHARED ${SRC_LIST})