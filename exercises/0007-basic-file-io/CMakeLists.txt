cmake_minimum_required(VERSION 3.20)

project(sample-file-io VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

add_executable(01-file-read 01-file-read.cc)
add_executable(02-file-read 02-file-read.cc)
add_executable(03-file-write 03-file-write.cc)
add_executable(04-file-write 04-file-write.cc)
add_executable(05-custom-read-write 05-custom-read-write.cc)
