cmake_minimum_required(VERSION 3.22)

# Project name and version
project(final_game)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
    add_definitions(-DFOUNDRY_WINDOWS)
elseif(APPLE)
    add_definitions(-DFOUNDRY_MAC)
else()
    add_definitions(-DFOUNDRY_LINUX)
endif()

add_definitions(-DFOUNDRY_DEBUG)

add_subdirectory(Fall22)
add_subdirectory(Foundry)
add_subdirectory(glfw)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FinalGame)