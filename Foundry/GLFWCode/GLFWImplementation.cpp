#include "../pch.h"
#include "GLFWImplementation.h"
#include "FoundryUtil.h"
#include "Event.h"

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

        glfwSetWindowUserPointer(mWindow, &mCallbacks);

        glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (action == GLFW_PRESS || action == GLFW_REPEAT) {
                Callbacks* userPointer{ (Callbacks*) glfwGetWindowUserPointer(window) };

                KeyPressedEvent event{ key };
                userPointer->keyPressedCallback(event);
            } else if (action == GLFW_RELEASE) {
                Callbacks* userPointer{ (Callbacks*) glfwGetWindowUserPointer(window) };

                KeyReleasedEvent event{ key };
                userPointer->keyReleasedCallback(event);
            }
        });
    }

    void GLFWImplementation::swapBuffers() {
        glfwSwapBuffers(this->mWindow);
        glfwPollEvents();
    }

    GLFWImplementation::~GLFWImplementation() {
        glfwTerminate();
    }

    void GLFWImplementation::setKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback) {
        mCallbacks.keyPressedCallback = keyPressedCallback;
    }
    void GLFWImplementation::setKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback) {
        mCallbacks.keyReleasedCallback = keyReleasedCallback;
    }
}