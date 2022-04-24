#pragma once
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "macros.hpp"

class Resources
{
public:
	static Resources& instance();
	Resources(const Resources&) = delete;
	void operator=(const Resources&) = delete;

	Font& getFont() { return m_textFont; }
	sf::Sprite& getSprite() { return m_catSprite; }
	sf::Texture& getTexture() { return m_catTexture; }

private:
	Resources();
	void loadResources();

	sf::Font m_textFont;
	sf::Sprite m_catSprite;
	sf::Texture m_catTexture;
};