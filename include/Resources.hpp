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

private:
	Resources();
	void loadResources();

	sf::Font m_textFont;
};