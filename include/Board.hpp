#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"
#include "Resources.hpp"

class Board
{
public:
	Board();
	void drawBoard(RenderWindow&)const;
	void findMovement(Vector2f&);
	void findClick(Vector2f&);

private:
	void setBoard();
	void setFonts();

	CircleShape createCircle(Vector2f &);
	Text createText(Vector2f& pos);

	std::vector<Text> m_boardTexts;
	std::vector<std::vector<Vector2f>> m_levels;
	std::vector<std::vector<CircleShape>> m_board;
};
