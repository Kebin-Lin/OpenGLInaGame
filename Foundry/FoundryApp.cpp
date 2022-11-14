#include "pch.h"
#include "FoundryWindow.h"
#include "FoundryApp.h"
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

        float vertices[] = {
            // Position      // Texture
            -0.5f, -0.5f,    0.0f, 0.0f, // Bottom-left
             0.5f, -0.5f,    1.0f, 0.0f, // Bottom-right
            -0.5f,  0.5f,    0.0f, 1.0f, // Top-left
             0.5f,  0.5f,    1.0f, 1.0f  // Top-right
        };

        unsigned int indices[] = {
            0, 1, 2,
            1, 2, 3
        };

        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*) (2 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // Texture setup
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;
        // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load("../assets/textures/amogus.png", &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

        // Vertex Shader Setup
        const char *vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec2 aPos;\n"
            "layout (location = 1) in vec2 texData;\n"
            "out vec2 TexCoord;\n"
            "void main()\n"
            "{\n"
            "    gl_Position = vec4(aPos.x, aPos.y, 1.0, 1.0);\n"
            "    TexCoord = texData;\n"
            "}\n\0";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        // check for linking errors
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Fragment Shader Setup
        const char *fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "in vec2 TexCoord;\n"
            "uniform sampler2D texture1;\n"
            "void main()\n"
            "{\n"
            "   FragColor = texture(texture1, TexCoord);\n"
            "}\n\0";
        
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }

        // Set up shader program and link vertex + fragment shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            FoundryWindow::getWindow()->swapBuffers();

            onUpdate();
        }
    }
}
