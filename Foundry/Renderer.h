#pragma once

#include "FoundryUtil.h"
#include "RendererImplementation.h"
#include "Shader.h"
#include "Unit.h"

namespace Foundry {
    class FOUNDRY_API Renderer {
        public:
            static void init();
            static void draw(Picture& picture, int x, int y, int z, Shader& shader);
            static void draw(Picture& picture, int x, int y, int z);
            static void draw(Picture&& picture, int x, int y, int z, Shader& shader);
            static void draw(Picture&& picture, int x, int y, int z);
            static void draw(Unit& unit, Shader& shader);
            static void draw(Unit& unit);
            static Renderer* getRenderer();
            static void clear();

        private:
            inline static Renderer* mInstance{nullptr};
            Shader mDefaultShader{"assets/shaders/defaultFoundryVertex.glsl", "assets/shaders/defaultFoundryFragment.glsl"};
            RendererImplementation* mImplementation{nullptr};

            Renderer();
    };
}