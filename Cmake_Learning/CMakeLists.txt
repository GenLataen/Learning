cmake_minimum_required(VERSION 3.10)
project(HelloCMake)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 自动收集源文件（更可靠）
file(GLOB SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# 打印调试信息
message(STATUS "Source files: ${SOURCES}")

# 创建可执行文件
add_executable(myapp ${SOURCES})

# 设置输出目录到 build 根目录（简化）
set_target_properties(myapp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

# 打印完成信息
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")