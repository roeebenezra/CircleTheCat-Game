#include "GameObject.hpp"

GameObject::GameObject(const Vector2i &start) : m_place(start) {
    m_sprite.setTexture(Resources::instance().getTexture());
}
