cmake_minimum_required(VERSION 3.22)

# Project name and version
project(Tutorial VERSION 1.0) # Or project(anyname)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Fall22)
add_subdirectory(Foundry)
add_subdirectory(glfw)
# CMake 3.24
set(VS_STARTUP_PROJECT Fall2022)

if(WIN32)
    add_definitions(-DFOUNDRY_WINDOWS -DOTHER_DEF ...)
elseif(APPLE)
    add_definitions(-DFOUNDRY_MAC)
else()
    add_definitions(-DFOUNDRY_LINUX)
endif()

add_definitions(-DFOUNDRY_DEBUG)