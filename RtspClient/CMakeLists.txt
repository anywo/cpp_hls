cmake_minimum_required(VERSION 3.12)
# project(httpflv)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES *.cpp)

# 添加库源文件
add_library(rtsp_client STATIC ${SOURCES})

# target_include_directories(httpflv .)