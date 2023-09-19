
cmake_minimum_required(VERSION 3.10)
project(MySQLConnectorDemo)

set(CMAKE_CXX_STANDARD 11)

# 添加头文件路径
include_directories("/usr/local/mysql/include")
include_directories("/usr/local/mysql/lib")
include_directories("/usr/local/mysql-8.0.23-macos10.15-x86_64/lib")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  # 设置可执行文件的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)	   # 设置库文件的输出目录
# 添加可执行文件
add_executable(MySQLConnectorDemo main.cpp)

# 链接 MySQL Connector/C++ 库
target_link_libraries(MySQLConnectorDemo /usr/local/mysql/lib/libmysqlclient.21.dylib)





