#pragma once

#include "pch.h"
#include "FoundryUtil.h"
#include "ShaderImplementation.h"

namespace Foundry {
    class FOUNDRY_API Shader {
        public:
            Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
            Shader(std::string&& vertexShaderFile, std::string&& fragmentShaderFile);
            
            void activate();
            void provideFloatValues(const std::string& valueName, const std::vector<float>& values);
            void provideFloatValues(std::string&& valueName, std::vector<float>&& values);

        private:
            ShaderImplementation* mImplementation{nullptr};
    };
}