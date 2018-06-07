cmake_minimum_required(VERSION 3.10)
project(Image2Character)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
add_executable(Image2Character main.cpp)
target_link_libraries(Image2Character ${OpenCV_LIBS})