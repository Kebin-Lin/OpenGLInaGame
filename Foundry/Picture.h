#pragma once

#include "pch.h"
#include "FoundryUtil.h"
#include "PictureImplementation.h"

namespace Foundry {
    class FOUNDRY_API Picture {
        public:
            Picture(const std::string& sourceFile);
            Picture(const std::string&& sourceFile);

            int getHeight() const;
            int getWidth() const;

            void activate();

        private:
            PictureImplementation* mImplementation{nullptr};
    };
}