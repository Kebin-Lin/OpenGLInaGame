#include "Anim.h"

Anim::Anim(const std::vector<std::string>& frames) {
    for (int i = 0; i < frames.size(); i++) {
        mFrames.push_back(Foundry::Picture(frames[i]));
    }
}

Foundry::Picture Anim::getFrame(int frameNum) const {
    return mFrames[frameNum % mFrames.size()];
}