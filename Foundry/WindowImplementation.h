#pragma once

#include "pch.h"

namespace Foundry {
    class WindowImplementation {
        public:
            virtual void create(int width, int height, const std::string& windowName) = 0;
            virtual void swapBuffers() = 0;
    };
}