#pragma once

#include "RendererImplementation.h"
#include "Picture.h"

namespace Foundry {
    class OpenGLRenderer: public RendererImplementation  {
        public:
            OpenGLRenderer();
            virtual void draw(Picture& picture, int x, int y, int z, Shader& shader) override;
    };
}