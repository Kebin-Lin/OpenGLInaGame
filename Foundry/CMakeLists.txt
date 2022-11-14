# CMake variable
set(SOURCE_FILES
    FoundryApp.cpp
    FoundryWindow.cpp
    GLFWCode/GLFWImplementation.cpp
)
set(HEADER_FILES
    Foundry.h
    FoundryApp.h
    FoundryUtil.h
    FoundryWindow.h
    WindowImplementation.h
    GLFWCode/GLFWImplementation.h
)

add_library(Foundry SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DFOUNDRY_LIB)

target_precompile_headers(Foundry PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(.)

target_link_libraries(Foundry glfw)
target_link_libraries(Foundry glad)
target_link_libraries(Foundry stbi)