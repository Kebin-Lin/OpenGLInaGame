#pragma once

#include "FoundryUtil.h"
#include "RendererImplementation.h"
#include "Shader.h"

namespace Foundry {
    class FOUNDRY_API Renderer {
        public:
            static void init();
            static void draw(Picture& picture, int x, int y, int z, Shader& shader);
            static void draw(Picture& picture, int x, int y, int z);
            static Renderer* getRenderer();

        private:
            inline static Renderer* mInstance{nullptr};
            Shader mDefaultShader{"assets/shaders/defaultFoundryVertex.glsl", "assets/shaders/defaultFoundryFragment.glsl"};
            RendererImplementation* mImplementation{nullptr};

            Renderer();
    };
}