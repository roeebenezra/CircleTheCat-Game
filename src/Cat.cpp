#include "Cat.hpp"

//___________________
Cat::Cat(const Board &board) : MoveObject(board, StartPos), m_catMove(true) {
    setIntRectSprite(IntRect(375, 7, 100, 73));
    setSpriteScale(float(1.2), float(1.2));
    setSpritePosition(getObjectPos(StartPos.x, StartPos.y));
}

//___________________________________________________
void Cat::setCatPosition(const sf::Vector2i &nextMove) {
    setSpritePosition(getObjectPos(nextMove.x, nextMove.y));
    setObjectPLace(nextMove);
}

//_____________
void Cat::move() {
    if (m_catMove) {
        Vector2i newMove = getNextMove();
        if (newMove == getObjectLoc())
            setCatMove(false);
        setCatPosition(newMove);
    } else
        setCatPosition(returnRandomMove());
    if (handleCatTrapped())
        setCanMove(false);
}

//____________________________
bool Cat::checkCatWon() const {
    if (getObjectLoc().x == BoardSize - 1 || getObjectLoc().x == 0 ||
        getObjectLoc().y == BoardSize - 1 || getObjectLoc().y == 0)
        return true;

    return false;
}

//__________________________
bool Cat::handleCatTrapped() {
    if (checkObjectFullyTrapped())
        return true;
}