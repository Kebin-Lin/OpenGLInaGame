#pragma once

#include <vector>
#include "Foundry.h"
#include "Anim.h"

class Entity {
    private:
        Anim mAnim;
        int mX{ 0 };
        int mY{ 0 };
        int mZ{ 0 };
        int mXVel{ 0 };
        int mYVel{ 0 };
        int mState{ 0 };
    
    public:
        Entity(const std::vector<std::string>& frames);
        void draw(int frameNum);

        int getX() const;
        int getY() const;
        int getZ() const;

        int changeX(int val);
        int changeY(int val);
        int changeZ(int val);

        void setCoords(int x, int y, int z);

        int getXVel() const;
        int getYVel() const;

        int setXVel(int val);
        int setYVel(int val);

        void move();
        int setState(int state);
        int getState() const;

        bool overlapsWith(const Entity& other) const;

};