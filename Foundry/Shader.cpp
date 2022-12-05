#include "pch.h"
#include "Shader.h"

namespace Foundry {
    // Shader::Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
    // Shader::Shader(std::string&& vertexShaderFile, std::string&& fragmentShaderFile);

    void Shader::provideFloatValues(const std::string& valueName, const std::vector<float>& values) {
        mImplementation->provideFloatValues(valueName, values);
    }

    void Shader::provideFloatValues(std::string&& valueName, std::vector<float>&& values) {
        mImplementation->provideFloatValues(valueName, values);
    }
}