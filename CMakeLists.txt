cmake_minimum_required(VERSION 3.7)
project(Grafos2017_1)

set(CMAKE_C_STANDARD 11)

add_custom_target(Grafos2017_1 ALL COMMAND make WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})