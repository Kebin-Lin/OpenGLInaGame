#pragma once

#include "../pch.h"
#include "../ShaderImplementation.h"

namespace Foundry {
    class OpenGLShader: public ShaderImplementation {
        public:
            OpenGLShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
            OpenGLShader(std::string&& vertexShaderFile, std::string&& fragmentShaderFile);

            virtual void activate() override;
            virtual void provideFloatValues(const std::string& valueName, const std::vector<float>& values) override;
            virtual void provideFloatValues(std::string&& valueName, std::vector<float>&& values) override;

            ~OpenGLShader();

        private:
            unsigned int mShaderProg{0};
    };
}