# Yêu cầu phiên bản CMake tối thiểu
cmake_minimum_required(VERSION 3.10)

# Tên dự án và ngôn ngữ sử dụng
project(detectdeadlock C)

# Đặt tiêu chuẩn ngôn ngữ C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Thêm tệp nguồn
add_executable(detectdeadlock src/detectdeadlock.c)
