#pragma once

#include "pch.h"
#include "FoundryUtil.h"
#include "WindowImplementation.h"

namespace Foundry {
    class FOUNDRY_API FoundryWindow {
        private:
            inline static FoundryWindow* mInstance{ nullptr };
            WindowImplementation* mImplementation{ nullptr };
        public:
            static void init();
            static FoundryWindow* getWindow();
            void create(int width, int height, const std::string& windowName);
            void swapBuffers();
    };
}
