cmake_minimum_required(VERSION 3.9)
project(miniftpd27dd C)
file(GLOB SRC *.h *.c)

set(CMAKE_C_STANDARD 99)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
link_libraries(crypt)
add_executable(miniftpd ${SRC})