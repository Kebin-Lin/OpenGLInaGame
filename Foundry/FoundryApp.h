#pragma once

#include "FoundryUtil.h"

namespace Foundry {
    class FOUNDRY_API FoundryApp {
        public:
            virtual void onUpdate();
            void run();
    };
}
