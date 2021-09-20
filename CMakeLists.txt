cmake_minimum_required(VERSION 3.18)

project(demo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

message(STATUS "BLADE_ROOT = ${BLADE_ROOT}")

if("" STREQUAL "${BLADE_ROOT}")
    message(FATAL_ERROR "BLADE_ROOT not set.")
endif()

include_directories("${BLADE_ROOT}/includes")
link_directories("${BLADE_ROOT}")

add_library(demo SHARED demo.c)
target_link_libraries(demo blade)
