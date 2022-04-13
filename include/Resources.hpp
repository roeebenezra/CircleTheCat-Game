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

	sf::Sprite& getSprite(const int name) { return m_sprite; }
	sf::Texture& getTexture(const int name) { return m_texture; }
	sf::Font& getFont() { return m_font; }

private:
	Resources();
	void loadResources();

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Font m_font;
};