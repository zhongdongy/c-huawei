cmake_minimum_required(VERSION 3.25)
project(huawei)

set(CMAKE_MAKE_PROGRAM "/usr/bin/make")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target)
set(BUILD_SHARED_LIBS ON)

set(SRC_LIST main.c)

add_library(sorting "libs/sorting.c")
add_library(utils "libs/utils.c")
add_library("string" "libs/string.c")

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries("string" PUBLIC sorting utils)
target_link_libraries(${PROJECT_NAME} PUBLIC sorting utils "string")
