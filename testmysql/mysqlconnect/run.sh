# 自动化编译和运行的脚本
rm -rf build
mkdir build
cd build/
cmake ..
make  # 使用并行编译会失败，