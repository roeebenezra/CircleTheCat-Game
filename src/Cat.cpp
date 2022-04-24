#include "Cat.hpp"

Cat::Cat(const sf::Vector2f& loc)
{
	m_catSprite.setTexture(Resources::instance().getTexture());
	m_catSprite.setTextureRect(sf::IntRect(float(95), 0, float(50), float(50)));
	m_catSprite.setPosition(loc);
	m_catSprite.setScale(1.2, 1.3);
}