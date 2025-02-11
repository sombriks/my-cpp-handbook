cmake_minimum_required(VERSION 3.20)
project(modularity)

# set(CMAKE_CXX_COMPILER clang++)
file(GLOB distinct_files_src "01-distinct-files/*.cc")
add_executable(distinct-files ${distinct_files_src})

file(GLOB namespaces_src "02-namespaces/*.cc")
add_executable(namespaces ${namespaces_src})

file(GLOB modules_src "03-modules/*.cc")
add_executable(modules ${modules_src})
target_compile_options(modules PRIVATE -std=c++20 -fmodules-ts)
