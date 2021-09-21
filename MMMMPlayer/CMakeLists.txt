# CMakeList.txt: MMMMPlayer 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)



# 将源代码添加到此项目的可执行文件。
add_executable (MMMMPlayer "MMMMPlayer.cpp" "MMMMPlayer.h")

#添加头文件依赖库（不需要编译，h文件）
include_directories(../)

#添加链接依赖库（编译cpp文件）
target_link_libraries(MMMMPlayer MMMMThread)
# TODO: 如有需要，请添加测试并安装目标。
