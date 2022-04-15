#include "Board.hpp"

Board::Board()
{
	setBoard();
}

void Board::setBoard()
{
	setTitle();
	sf::Vector2f pos = { 35, 50 };
	for (size_t i = 0; i < BOARD_SIZE; i++) {
		std::vector<sf::CircleShape> circleRow;
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			sf::CircleShape circle(35);
			circle.setPosition(pos);
			circle.setFillColor(sf::Color::Green);
			circleRow.push_back(circle);
			pos.x += 75;
		}
		m_board.push_back(circleRow);
		pos.y += 75;
		if (i % 2 == 0) pos.x = 60;
		else pos.x = 35;
	}
}

void Board::setTitle()
{
	m_title.loadFromFile("Title.png");
	m_spriteTitle.setTexture(m_title);
	m_spriteTitle.setPosition(400,0);
}

void Board::drawBoard(sf::RenderWindow &window)const 
{
	window.draw(m_spriteTitle);
	for (auto i : m_board)
	{
		for (auto j : i)
			window.draw(j);
	}
}
