#include "Cat.hpp"

Cat::Cat(Board& board): m_board(board)
{
	m_catSprite.setTexture(Resources::instance().getTexture());
	m_catSprite.setTextureRect(IntRect(375, 7, 100, 73));
	m_catSprite.setPosition(m_board.getCircle(5,5).getPosition());
	m_catSprite.setScale(float(1.2), float(1.2));

}

void Cat::setCatPosition(NextMove& nextMove)
{
    m_catSprite.setPosition(m_board.getCircle(nextMove._row, nextMove._col).getPosition());
}
