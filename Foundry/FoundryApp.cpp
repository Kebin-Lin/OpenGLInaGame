#include "pch.h"
#include "FoundryWindow.h"
#include "FoundryApp.h"
#include "Picture.h"
#include "Renderer.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace Foundry
{
    void FoundryApp::onUpdate() {}
    void FoundryApp::run()
    {
        FOUNDRY_LOG("RUNNING");

        FoundryWindow::init();
        FoundryWindow::getWindow()->create(600, 400, "TestWindow");

        Picture pic{"assets/textures/amogus.png"};

        Renderer::init();

        // Texture setup
        unsigned int texture;

        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            Renderer::draw(pic, 100, 100, 1);

            FoundryWindow::getWindow()->swapBuffers();

            onUpdate();
        }
    }
}
