#pragma once

#include "pch.h"
#include "FoundryUtil.h"

constexpr int FRAMES_PER_SECOND = 60;

namespace Foundry {
    class FOUNDRY_API FoundryApp {
        public:
            FoundryApp();
            virtual void onUpdate();
            void run();
        
        private:
            // Change seconds to 1000 if causing issues
            std::chrono::milliseconds mFrameDuration{ 1000 / FRAMES_PER_SECOND };
            std::chrono::steady_clock::time_point mNextFrameTime;
    };
}
