#include "../pch.h"
#include "GLFWImplementation.h"
#include "FoundryUtil.h"

namespace Foundry {
    GLFWImplementation::GLFWImplementation() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void GLFWImplementation::create(int width, int height, const std::string& windowName) {
        this->mWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
        
        glfwMakeContextCurrent(this->mWindow);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            FOUNDRY_LOG("Failed to initialize GLAD");
        }
    }

    void GLFWImplementation::swapBuffers() {
        glfwSwapBuffers(this->mWindow);
        glfwPollEvents();
    }
}