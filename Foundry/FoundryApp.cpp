#include "pch.h"
#include "FoundryWindow.h"
#include "FoundryApp.h"
#include "Picture.h"
#include "Renderer.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace Foundry
{
    FoundryApp::FoundryApp() {
        FoundryWindow::init();
        FoundryWindow::getWindow()->create(600, 400, "TestWindow");

        Renderer::init();
    }

    void FoundryApp::onUpdate() {}
    void FoundryApp::run()
    {
        FOUNDRY_LOG("RUNNING");
        mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

        while (true)
        {
            Renderer::clear();
            onUpdate();

            std::this_thread::sleep_until(mNextFrameTime);

            FoundryWindow::getWindow()->swapBuffers();

            mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
        }
    }
}
