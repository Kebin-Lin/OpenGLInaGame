#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Foundry.h"

constexpr int TEXT_SPACING = 5;


class Text {
    private:
        std::string mText{""};
        std::unordered_map<char, Foundry::Picture> CHAR_PICTURES{
            {'0', {"assets/textures/minecraftText/0.png"}},
            {'1', {"assets/textures/minecraftText/1.png"}},
            {'2', {"assets/textures/minecraftText/2.png"}},
            {'3', {"assets/textures/minecraftText/3.png"}},
            {'4', {"assets/textures/minecraftText/4.png"}},
            {'5', {"assets/textures/minecraftText/5.png"}},
            {'6', {"assets/textures/minecraftText/6.png"}},
            {'7', {"assets/textures/minecraftText/7.png"}},
            {'8', {"assets/textures/minecraftText/8.png"}},
            {'9', {"assets/textures/minecraftText/9.png"}},
            {'W', {"assets/textures/minecraftText/W.png"}},
            {'a', {"assets/textures/minecraftText/a.png"}},
            {'v', {"assets/textures/minecraftText/v.png"}},
            {'e', {"assets/textures/minecraftText/e.png"}},
        };
    public:
        Text(const std::string& input);
        int draw(int x, int y, int z);
        std::string getText();
        void setText(const std::string& input);
};