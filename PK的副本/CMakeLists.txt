cmake_minimum_required(VERSION 3.19)
project(PK)

set(CMAKE_CXX_STANDARD 14)

add_executable(PK main.cpp )
add_executable(01  演讲比赛管理.cpp speechManager.cpp speechManager.h speaker.h)