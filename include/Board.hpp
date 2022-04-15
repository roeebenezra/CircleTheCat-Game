#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"

class Data;

class Board
{
public:
	Board();
	void drawBoard(sf::RenderWindow&)const;

private:
	void setBoard();
	void setTitle();

	sf::Texture m_title;
	sf::Sprite m_spriteTitle;

	std::vector<std::vector<sf::Vector2f>> m_levels;
	std::vector<std::vector<sf::CircleShape>> m_board;
};
