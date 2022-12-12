#pragma once

#include "FoundryUtil.h"
#include "Picture.h"

namespace Foundry {
    class Unit {
        public:
            Unit(const std::string& picFile, int hp);
            Unit(std::string&& picFile, int hp);

            int setCoord(int x, int y, int z);
            int changeX(int xDiff);
            int changeY(int yDiff);
            int changeZ(int zDiff);

            int getX() const;
            int getY() const;
            int getZ() const;

            int changeHP(int hpDiff);
            int getHP() const;

            bool overlapsWith(const Unit& other) const;

        private:
            Picture mPicture;
            int mXCoord{ 0 };
            int mYCoord{ 0 };
            int mZCoord{ 0 };
            int mHP{ 0 };

            friend class Renderer; // Renderer can access private variables of Unit
    };
}