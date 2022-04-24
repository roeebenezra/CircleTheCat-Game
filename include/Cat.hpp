#pragma once
#include "Board.hpp"

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>


class Cat
{
public:
	Cat(const sf::Vector2f&);
	void showCat(sf::RenderWindow& window) const { window.draw(m_catSprite); }

private:
	Sprite m_catSprite;
};