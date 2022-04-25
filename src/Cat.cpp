#include "Cat.hpp"

Cat::Cat(const sf::Vector2f& loc)
{
	m_catSprite.setTexture(Resources::instance().getTexture());
	m_catSprite.setTextureRect(sf::IntRect(float(370), 0, float(100), float(70)));
	m_catSprite.setPosition(loc);
	m_catSprite.setScale(1.2, 1.3);
}