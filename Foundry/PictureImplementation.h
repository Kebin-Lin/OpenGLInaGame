#pragma once

#include "pch.h"

namespace Foundry {
    class PictureImplementation {
        public:
            virtual int getHeight() const = 0;
            virtual int getWidth() const = 0;

            virtual void activate() = 0;

            virtual ~PictureImplementation() {};
    };
}