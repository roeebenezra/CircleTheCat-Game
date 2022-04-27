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
	bool findClick(Vector2f&);
    const CircleShape& getCircle(size_t row, size_t col) {return m_board[row][col];}
private:
	void setBoard();
	
	static CircleShape createCircle(Vector2f &);
	std::vector<std::vector<CircleShape>> m_board;
};
