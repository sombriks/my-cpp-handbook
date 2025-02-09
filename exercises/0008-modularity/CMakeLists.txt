cmake_minimum_required(VERSION 3.20)
project(modularity)
file(GLOB distinct_files_src "01-distinct-files/*.cc")
add_executable(distinct-files ${distinct_files_src})
