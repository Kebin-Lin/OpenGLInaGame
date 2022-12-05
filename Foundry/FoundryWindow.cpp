#include "pch.h"
#include "FoundryWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace Foundry {
    void FoundryWindow::create(int width, int height, const std::string& windowName) {
        mImplementation->create(width, height, windowName);
        mWidth = width;
        mHeight = height;
    }

    void FoundryWindow::swapBuffers() {
        mImplementation->swapBuffers();
    }

    FoundryWindow* FoundryWindow::getWindow() {
        return mInstance;
    }

    void FoundryWindow::init() {
        if (mInstance == nullptr) {
            mInstance = new FoundryWindow;

            #ifdef FOUNDRY_WINDOWS
                mInstance->mImplementation = new GLFWImplementation;
            #elif defined FOUNDRY_MAC
                mInstance->mImplementation = new GLFWImplementation;
            #else
                mInstance->mImplementation = new GLFWImplementation;
            #endif
        }
    }

    int FoundryWindow::getHeight() const {
        return mHeight;
    }
    
    int FoundryWindow::getWidth() const {
        return mWidth;
    }
}