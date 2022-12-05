#include "pch.h"
#include "Picture.h"
#include "OpenGLCode/OpenGLPicture.h"

namespace Foundry {
    Picture::Picture(const std::string& sourceFile) {
        #ifdef FOUNDRY_OPENGL
            mImplementation = new OpenGLPicture(sourceFile);
        #else
            #onlyopenglatm
        #endif
    }

    Picture::Picture(const std::string&& sourceFile) {
        #ifdef FOUNDRY_OPENGL
            mImplementation = new OpenGLPicture(sourceFile);
        #else
            #onlyopenglatm
        #endif
    }

    int Picture::getHeight() const {
        return mImplementation->getHeight();
    }

    int Picture::getWidth() const {
        return mImplementation->getWidth();
    }

    void Picture::activate() {
        mImplementation->activate();
    }
}