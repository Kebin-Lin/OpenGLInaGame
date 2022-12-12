#pragma once

#include "Shader.h"
#include "Picture.h"

namespace Foundry {
    class RendererImplementation {
        public:
            virtual void draw(Picture& picture, int x, int y, int z, Shader& shader) = 0;
            virtual void clear() = 0;
    };
}