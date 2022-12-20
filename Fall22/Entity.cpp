#include "Entity.h"

Entity::Entity(const std::vector<std::string>& frames): mAnim(frames) {}
Entity::Entity(Anim anim): mAnim(anim) {}

void Entity::draw(int frameNum) {
    Foundry::Renderer::draw(mAnim.getFrame(frameNum), mX, mY, mZ);
}

int Entity::getX() const {
    return mX;
}

int Entity::getY() const {
    return mY;
}

int Entity::getZ() const {
    return mZ;
}

int Entity::changeX(int val) {
    mX += val;
    return mX;
}

int Entity::changeY(int val) {
    mY += val;
    return mY;
}

int Entity::changeZ(int val) {
    mZ += val;
    return mZ;
}

void Entity::setCoords(int x, int y, int z) {
    mX = x;
    mY = y;
    mZ = z;
}

int Entity::getXVel() const {
    return mXVel;
}

int Entity::getYVel() const {
    return mYVel;
}

int Entity::setXVel(int val) {
    mXVel = val;
    return mXVel;
}

int Entity::setYVel(int val) {
    mYVel = val;
    return mYVel;
}

void Entity::move() {
    changeX(mXVel);
    changeY(mYVel);
}


int Entity::setState(int state) {
    mState = state;
    return mState;
}

int Entity::getState() const {
    return mState;
}

bool Entity::overlapsWith(const Entity& other) const {
    int oneLeft{ getX() };
    int oneRight{ getX() + mAnim.getFrame(0).getWidth() };
    int otherLeft{ other.getX() };
    int otherRight{ other.getX() + other.mAnim.getFrame(0).getWidth() };

    int oneBottom{ getY() };
    int oneTop{ getY() + mAnim.getFrame(0).getHeight() };
    int otherBottom{ other.getY() };
    int otherTop{ other.getY() + other.mAnim.getFrame(0).getHeight() };

    bool collideX{ false };
    if ((oneLeft <= otherLeft && otherLeft <= oneRight) ||
        (otherLeft <= oneLeft && oneLeft <= otherRight)) {
            collideX = true;
    }

    bool collideY{ false };
    if ((oneBottom <= otherBottom && otherBottom <= oneTop) ||
        (otherBottom <= oneBottom && oneBottom <= otherTop)) {
            collideY = true;
    }

    return collideX && collideY;
}