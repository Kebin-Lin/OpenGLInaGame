cmake_minimum_required(VERSION 3.22) # Maybe change to 3.24

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
add_definitions(-DFOUNDRY_OPENGL)

add_subdirectory(Fall22)
add_subdirectory(Foundry)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT FinalGame)

file(COPY Fall22/assets DESTINATION ${PROJECT_BINARY_DIR}/Fall22)
file(COPY Fall22/assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Fall22/assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
file(COPY Fall22/assets DESTINATION ${PROJECT_BINARY_DIR})