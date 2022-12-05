#pragma once

namespace Foundry {
    class ShaderImplementation {
        public:
            virtual void activate() = 0;
            virtual void provideFloatValues(const std::string& valueName, const std::vector<float>& values) = 0;
            virtual void provideFloatValues(std::string&& valueName, std::vector<float>&& values) = 0;
    };
}