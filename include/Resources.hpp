#pragma once
#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>
#include "macros.hpp"

class Resources {
public:
    static Resources &instance();

    Resources(const Resources &) = delete;

    void operator=(const Resources &) = delete;

    Font &getFont() { return m_textFont; }

    Texture &getTexture() { return m_catTexture; }

private:
    Resources();
    void loadResources();

    Font m_textFont;
    Sprite m_catSprite;
    Texture m_catTexture;
};