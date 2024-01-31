cmake_minimum_required(VERSION 3.27)
project(get_next_line C)

set(CMAKE_C_STANDARD 11)

add_executable(tmp
        get_next_line.c
        get_next_line_utils.c)

file(GLOB MY_FILES "testing.txt")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
