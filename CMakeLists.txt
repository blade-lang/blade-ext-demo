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

if(WIN32)
	target_link_libraries(demo wsock32 ws2_32)

	# we are linking sqlite here because sqlite library is still part 
	# of Blade core. Once separated into it's own project, this won't be 
	# necessary anymore. Also, note that sqlite.lib is not in path. If 
	# you built Blade from source, you can get it from the build directory's 
	# thirdpaties/sqlite/sqlite.lib and copy it into Blade's root directory.
	target_link_libraries(demo sqlite)
endif()

