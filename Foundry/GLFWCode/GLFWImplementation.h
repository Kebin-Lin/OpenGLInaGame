#pragma once

#include "../pch.h"
#include "../WindowImplementation.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Foundry {
    class GLFWImplementation: public WindowImplementation {
        public:
            GLFWImplementation();
            virtual void create(int width, int height, const std::string& windowName) override;
            virtual void swapBuffers() override;
        
        private:
            GLFWwindow *mWindow{ nullptr };
    };
}