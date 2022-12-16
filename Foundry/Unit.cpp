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

    Unit::Unit(const std::string& picFile, int hp): mPicture(picFile), mHP(hp) {}
    Unit::Unit(std::string&& picFile, int hp): mPicture(picFile), mHP(hp) {}

    void Unit::setCoord(int x, int y, int z) {
        mXCoord = x;
        mYCoord = y;
        mZCoord = z;
    }

    int Unit::changeX(int xDiff) {
        mXCoord += xDiff;
        return mXCoord;
    }

    int Unit::changeY(int yDiff) {
        mYCoord += yDiff;
        return mYCoord;
    }

    int Unit::changeZ(int zDiff) {
        mZCoord += zDiff;
        return mZCoord;
    }

    int Unit::getX() const {
        return mXCoord;
    }

    int Unit::getY() const {
        return mYCoord;
    }

    int Unit::getZ() const {
        return mZCoord;
    }

    int Unit::changeHP(int hpDiff) {
        mHP += hpDiff;
        return mHP;
    }

    int Unit::getHP() const {
        return mHP;
    }
}