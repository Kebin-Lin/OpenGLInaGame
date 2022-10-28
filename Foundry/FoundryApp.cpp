#include "pch.h"
#include "FoundryWindow.h"
#include "FoundryApp.h"
#include "glad/glad.h"

namespace Foundry
{
    void FoundryApp::onUpdate() {}
    void FoundryApp::run()
    {
        FOUNDRY_LOG("RUNNING");

        // float vertices[] = {
        //     -0.5f, -0.5f,
        //     0.5f, -0.5f,
        //     -0.5f, 0.5f
        // };

        // unsigned int VBO, VAO;
        // glGenVertexArrays(1, &VAO);
        // glGenBuffers(1, &VBO);
        // glBindVertexArray(VAO);

        // glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        FoundryWindow::init();
        FoundryWindow::getWindow()->create(600, 400, "TestWindow");

        while (true)
        {
            FoundryWindow::getWindow()->swapBuffers();

            onUpdate();
        }
    }
}
