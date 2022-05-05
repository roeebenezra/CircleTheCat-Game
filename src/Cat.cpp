#include "Cat.hpp"

//___________________
Cat::Cat(Board &board)
        : m_board(&board) {
    m_catSprite.setTexture(Resources::instance().getTexture());
    m_catSprite.setTextureRect(IntRect(375, 7, 100, 73));

    m_place = sf::Vector2i(5, 5);

    m_catSprite.setPosition(m_board->getCircle(5, 5).getPosition());
    m_catSprite.setScale(float(1.2), float(1.2));
}

//___________________________________________________
void Cat::setCatPosition(const sf::Vector2i &nextMove) {
    m_catSprite.setPosition(m_board->getCircle(size_t(nextMove.x), size_t(nextMove.y)).getPosition());
    m_place = nextMove;
}

//_____________
void Cat::move() {
    Vector2i newMove = getNextMove(m_board->getBoard(), m_place);
    if (m_board->getCircle(size_t(newMove.x), size_t(newMove.y)).getFillColor() == Color::Black)
        return;
    m_place = newMove;
    setCatPosition(m_place);
}

//_________________________
bool Cat::checkCatWon() const {
    if (m_place.x == BoardSize - 1 || m_place.x == 0 || m_place.y == BoardSize - 1 || m_place.y == 0)
        return true;

    return false;
}
////_________________________
//bool Cat::animation() const
//{
//
//}
