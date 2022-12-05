#include "pch.h"
#include "Shader.h"
#include "OpenGLCode/OpenGLShader.h"

namespace Foundry {
    Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
        #ifdef FOUNDRY_OPENGL
            mImplementation = new OpenGLShader(vertexShaderFile, fragmentShaderFile);
        #else
            #onlyopenglatm
        #endif
    }

    Shader::Shader(std::string&& vertexShaderFile, std::string&& fragmentShaderFile) {
        #ifdef FOUNDRY_OPENGL
            mImplementation = new OpenGLShader(vertexShaderFile, fragmentShaderFile);
        #else
            #onlyopenglatm
        #endif
    }

    void Shader::activate() {
        mImplementation->activate();
    }

    void Shader::provideFloatValues(const std::string& valueName, const std::vector<float>& values) {
        mImplementation->provideFloatValues(valueName, values);
    }

    void Shader::provideFloatValues(std::string&& valueName, std::vector<float>&& values) {
        mImplementation->provideFloatValues(valueName, values);
    }
}