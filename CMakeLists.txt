cmake_minimum_required(VERSION 3.28.3)
project(ppfetch)

include_directories(include)
file(GLOB SRCS src/*.cpp)
add_executable(${PROJECT_NAME} ${SRCS})