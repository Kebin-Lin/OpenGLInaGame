#include "../pch.h"
#include "../FoundryUtil.h"
#include "OpenGLPicture.h"
#include "glad/glad.h"
#include "stb_image.h"

namespace Foundry {
    OpenGLPicture::OpenGLPicture(const std::string& sourceFile) {
        glGenTextures(1, &(this->mImage));
        glBindTexture(GL_TEXTURE_2D, this->mImage);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(sourceFile.c_str(), &(this->mWidth), &(this->mHeight), &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->mWidth, this->mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            FOUNDRY_LOG("Failed to load texture");
        }
        stbi_image_free(data);
    }

    OpenGLPicture::OpenGLPicture(const std::string&& sourceFile) {
        glGenTextures(1, &(this->mImage));
        glBindTexture(GL_TEXTURE_2D, this->mImage);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(sourceFile.c_str(), &(this->mWidth), &(this->mHeight), &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->mWidth, this->mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            FOUNDRY_LOG("Failed to load texture");
        }
        stbi_image_free(data);
    }

    int OpenGLPicture::getHeight() const {
        return this->mHeight;
    }
    int OpenGLPicture::getWidth() const {
        return this->mWidth;
    }

    void OpenGLPicture::activate() {
        glBindTexture(GL_TEXTURE_2D, this->mImage);
    }
}