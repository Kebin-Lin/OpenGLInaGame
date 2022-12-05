# CMake variable
set(SOURCE_FILES
    FoundryApp.cpp
    FoundryWindow.cpp
    GLFWCode/GLFWImplementation.cpp
    Picture.cpp
    OpenGLCode/OpenGLPicture.cpp
    Shader.cpp
    OpenGLCode/OpenGLShader.cpp
    Renderer.cpp
    OpenGLCode/OpenGLRenderer.cpp
)
set(HEADER_FILES
    Foundry.h
    FoundryApp.h
    FoundryUtil.h
    FoundryWindow.h
    WindowImplementation.h
    GLFWCode/GLFWImplementation.h
    Picture.h
    PictureImplementation.h
    OpenGLCode/OpenGLPicture.h
    Shader.h
    ShaderImplementation.h
    OpenGLCode/OpenGLShader.h
    Renderer.h
    RendererImplementation.h
    OpenGLCode/OpenGLRenderer.h
)

add_library(Foundry SHARED ${SOURCE_FILES} ${HEADER_FILES})

add_definitions(-DFOUNDRY_LIB)

add_definitions(-DFOUNDRY_OPENGL)

target_precompile_headers(Foundry PRIVATE pch.h)

include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(.)

target_link_libraries(Foundry glfw)
target_link_libraries(Foundry glad)
target_link_libraries(Foundry stbi)