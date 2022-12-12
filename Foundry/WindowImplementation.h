#pragma once

#include "pch.h"

namespace Foundry {
    class WindowImplementation {
        public:
            virtual void create(int width, int height, const std::string& windowName) = 0;
            virtual void swapBuffers() = 0;

            virtual void setKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback) = 0;
            virtual void setKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback) = 0;
    };
}