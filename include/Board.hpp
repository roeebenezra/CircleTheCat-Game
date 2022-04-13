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

private:
	void setBoard();
	std::vector<std::vector<sf::Vector2f>> m_levels;
};
