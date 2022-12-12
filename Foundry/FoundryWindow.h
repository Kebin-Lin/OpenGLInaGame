#pragma once

#include "pch.h"
#include "FoundryUtil.h"
#include "WindowImplementation.h"
#include "Event.h"

namespace Foundry {
    class FOUNDRY_API FoundryWindow {
        private:
            inline static FoundryWindow* mInstance{ nullptr };
            WindowImplementation* mImplementation{ nullptr };
            int mWidth{ 0 };
            int mHeight{ 0 };
        public:
            static void init();
            static FoundryWindow* getWindow();
            void create(int width, int height, const std::string& windowName);
            void swapBuffers();
            int getWidth() const;
            int getHeight() const;

            void setKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
            void setKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);
    };
}
