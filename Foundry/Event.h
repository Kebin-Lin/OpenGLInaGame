#pragma once

#include "FoundryUtil.h"

namespace Foundry {
    class FOUNDRY_API KeyPressedEvent {
        public:
            KeyPressedEvent(int codeOfKey);
            KeyPressedEvent() = delete;

            int getKeyCode() const;
        private:
            int mKeyCode;
    };

    class FOUNDRY_API KeyReleasedEvent {
        public:
            KeyReleasedEvent(int codeOfKey);
            KeyReleasedEvent() = delete;

            int getKeyCode() const;
        private:
            int mKeyCode;
    };
}