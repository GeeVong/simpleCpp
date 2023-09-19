project(logmain)

cmake_minimum_required(VERSION 3.25)  # cmake版本最低要求

set(CMAKE_CXX_STANDARD 11)  # 指定 C++ 版本
set(CMAKE_BUILD_TYPE Release)  # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快

message("${PROJECT_SOURCE_DIR}=" ${PROJECT_SOURCE_DIR})
# 这里设置好路径后，进入子模块的cmake时不用再次设置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  # 设置可执行文件的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)	   # 设置库文件的输出目录

##====================================================##

# 文件包含
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(main ${SRC_LIST})

TARGET_LINK_LIBRARIES(main
        ${PROJECT_SOURCE_DIR}/libgame.a
        ${PROJECT_SOURCE_DIR}/libutility.a
        ${PROJECT_SOURCE_DIR}/liblog.dylib)
