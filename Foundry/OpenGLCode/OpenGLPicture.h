#pragma once

#include "../pch.h"
#include "../PictureImplementation.h"

namespace Foundry {
    class OpenGLPicture: public PictureImplementation {
        public:
            OpenGLPicture(const std::string& sourceFile);
            OpenGLPicture(const std::string&& sourceFile);

            virtual int getHeight() const override;
            virtual int getWidth() const override;

            virtual void activate() override;

            ~OpenGLPicture();

        private:
            unsigned int mImage{0};
            int mWidth{0};
            int mHeight{0};
    };
}