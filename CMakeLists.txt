cmake_minimum_required (VERSION 3.0)

project (Final_Project)

set(HEADER_FILES graph_node.h subwaygraph.h)
add_executable (main main.cpp ${HEADER_FILES})

target_compile_options(main PRIVATE -std=c++11 -g -Wall)