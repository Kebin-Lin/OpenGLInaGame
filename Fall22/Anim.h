#pragma once

#include <vector>
#include <string>
#include "Foundry.h"

class Anim {
    private:
        std::vector<Foundry::Picture> mFrames;
    
    public:
        Anim(const std::vector<std::string>& frames);
        Foundry::Picture getFrame(int frameNum) const;
};