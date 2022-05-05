#include "Cat.hpp"

//___________________
Cat::Cat(Board &board)
        : m_board(&board), MoveObject(StartPos) {

    m_catSprite.setTexture(Resources::instance().getTexture());
    m_catSprite.setTextureRect(IntRect(375, 7, 100, 73));
    m_catSprite.setScale(float(1.2), float(1.2));
    m_catSprite.setPosition(m_board->getCircle(StartPos.x, StartPos.y).getPosition());
}

//___________________________________________________
void Cat::setCatPosition(const sf::Vector2i &nextMove) {
    m_catSprite.setPosition(m_board->getCircle(nextMove.x, nextMove.y).getPosition());
    setMovingObjectPLace(nextMove);
}

//_____________
void Cat::move() {
    Vector2i newMove = getNextMove(m_board->getBoard());
    if (newMove == getMovingObjectPLace())
        return;
    setCatPosition(newMove);
}

//_________________________
bool Cat::checkCatWon() const {
    if (getMovingObjectPLace().x == BoardSize - 1 || getMovingObjectPLace().x == 0 ||
            getMovingObjectPLace().y == BoardSize - 1 || getMovingObjectPLace().y == 0) {
        std::cout << getMovingObjectPLace().x << " m_place " << getMovingObjectPLace().y << "\n";
        return true;
    }
    return false;
}

//__________________________
bool Cat::handleCatTrapped() const {
    return checkObjectFullyTrapped(m_board->getBoard());
}