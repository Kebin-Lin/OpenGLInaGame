#pragma once

#include "FoundryUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Foundry {
    class FOUNDRY_API FoundryApp {
        public:
            virtual void onUpdate();
            void run();
        
        private:
            std::chrono::milliseconds mFrameDuration{ std::chrono::seconds{1} / FRAMES_PER_SECOND };
            std::chrono::steady_clock::time_point mNextFrameTime;
    };
}
