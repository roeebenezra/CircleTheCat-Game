#pragma once

#include "macros.hpp"
#include "Resources.hpp"

class GameObject {

public:
    GameObject(const Vector2i &);

    void showObject(RenderWindow &window) const { window.draw(m_sprite); }

    Vector2i getObjectLoc() const { return m_place; }

    void setMovingObjectPLace(const Vector2i &place) { m_place = place; }

    void setSpritePosition(const Vector2f &loc) { m_sprite.setPosition(loc); }

    void setIntRectSprite(const sf::IntRect &loc) { m_sprite.setTextureRect(loc); }

    void setSpriteScale(const float x, const float y) { m_sprite.setScale(x, y); }

private:
    Vector2i m_place;
    Sprite m_sprite;
};