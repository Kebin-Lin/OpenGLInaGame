#include "Text.h"

Text::Text(const std::string& input): mText(input) {}

void Text::setText(const std::string& input) {
    mText = input;
}

std::string Text::getText() {
    return mText;
}

int Text::draw(int x, int y, int z) {
    int currentOffset = 0;
    for (int i = 0; i < mText.length(); i++) {
        if (mText[i] == ' ') {
            currentOffset += TEXT_SPACING * 5;
            continue;
        }
        auto got = CHAR_PICTURES.find(mText[i]);
        if (got != CHAR_PICTURES.end()) {
            Foundry::Renderer::draw(got->second, x + currentOffset, y, z);
            currentOffset += got->second.getWidth() + TEXT_SPACING;
        }
    }
    return x + currentOffset;
}