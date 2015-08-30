cmake_minimum_required(VERSION 2.8)
project(mikan CXX)

add_subdirectory(src)
include_directories(include)

add_library(
  mikan
  STATIC
  ${mikanSource}
)

ADD_DEFINITIONS(-std=c++11)

