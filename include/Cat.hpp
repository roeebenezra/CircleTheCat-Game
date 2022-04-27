#pragma once
#include "Board.hpp"
#include "Bfs.hpp"

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>


class Cat
{
public:
	Cat(Board*);
	void showCat(sf::RenderWindow& window) const { window.draw(m_catSprite); }
	void setCatPosition();

private:
	Sprite m_catSprite;
	Board *m_board;
};