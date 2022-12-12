#include "pch.h"
#include "Event.h"

namespace Foundry {
    KeyPressedEvent::KeyPressedEvent(int codeOfKey) : mKeyCode(codeOfKey) {}

    int KeyPressedEvent::getKeyCode() const {
        return mKeyCode;
    }

    KeyReleasedEvent::KeyReleasedEvent(int codeOfKey) : mKeyCode(codeOfKey) {}

    int KeyReleasedEvent::getKeyCode() const{
        return mKeyCode;
    }
}