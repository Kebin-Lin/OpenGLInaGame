#pragma once

#include "../pch.h"
#include "../WindowImplementation.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Event.h"

namespace Foundry {
    class GLFWImplementation: public WindowImplementation {
        public:
            GLFWImplementation();
            virtual void create(int width, int height, const std::string& windowName) override;
            virtual void swapBuffers() override;

            ~GLFWImplementation();

            virtual void setKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback) override;
            virtual void setKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback) override;
        
        private:
            GLFWwindow *mWindow{ nullptr };

            struct Callbacks {
                std::function<void(const KeyPressedEvent&)> keyPressedCallback{ [](const KeyPressedEvent&) {} };
                std::function<void(const KeyReleasedEvent&)> keyReleasedCallback{ [](const KeyReleasedEvent&) {} };
            } mCallbacks;
    };
}