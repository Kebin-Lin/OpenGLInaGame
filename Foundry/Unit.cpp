#include "Unit.h"

namespace Foundry {
    bool Unit::overlapsWith(const Unit& other) const {
        int oneLeft{ getX() };
        int oneRight{ getX() + mPicture.getWidth() };
        int otherLeft{ other.getX() };
        int otherRight{ other.getX() + other.mPicture.getWidth() };

        int oneBottom{ getY() };
        int oneTop{ getY() + mPicture.getHeight() };
        int otherBottom{ other.getY() };
        int otherTop{ other.getY() + other.mPicture.getHeight() };

        bool collideX{ false };
        if ((oneLeft <= otherLeft && otherLeft <= oneRight) ||
            (otherLeft <= oneLeft && oneLeft << otherRight)) {
                collideX = true;
        }

        bool collideY{ false };
        if ((oneBottom <= otherBottom && otherBottom <= oneTop) ||
            (otherBottom <= oneBottom && oneBottom << otherTop)) {
                collideX = true;
        }

        return collideX && collideY;
    }
}