#include "pch.h"
#include "Renderer.h"
#include "OpenGLCode/OpenGLRenderer.h"

namespace Foundry {
    void Renderer::init() {
        if (mInstance == nullptr) {
            mInstance = new Renderer();
        }
    }

    Renderer* Renderer::getRenderer() {
        return mInstance;
    }

    Renderer::Renderer() {
        #ifdef FOUNDRY_OPENGL
            mImplementation = new OpenGLRenderer();
        #else
            #onlyopenglatm
        #endif
    }

    void Renderer::draw(Picture& picture, int x, int y, int z, Shader& shader) {
        getRenderer()->mImplementation->draw(picture, x, y, z, shader);
    }

    void Renderer::draw(Picture& picture, int x, int y, int z) {
        getRenderer()->mImplementation->draw(picture, x, y, z, getRenderer()->mDefaultShader);
    }

    void Renderer::clear() {
        getRenderer()->mImplementation->clear();
    }
}