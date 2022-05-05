#include "Cat.hpp"

//___________________
Cat::Cat(Board &board) : MoveObject(board, StartPos) {

    setIntRectSprite(IntRect(375, 7, 100, 73));
    setSpriteScale(float(1.2), float(1.2));
    setSpritePosition(getObjectPos(StartPos.x, StartPos.y));
}

//___________________________________________________
void Cat::setCatPosition(const sf::Vector2i &nextMove) {
    setSpritePosition(getObjectPos(nextMove.x, nextMove.y));
    setMovingObjectPLace(nextMove);
}

//_____________
void Cat::move() {
    if (getCanMove()) {
        Vector2i newMove = getNextMove();
        if (newMove == getObjectLoc())
            return;
        setCatPosition(newMove);
    }
    else
        setCatPosition(returnRandomMove());
    handleCatTrapped();
}

//____________________________
bool Cat::checkCatWon() const {
    if (getObjectLoc().x == BoardSize - 1 || getObjectLoc().x == 0 ||
        getObjectLoc().y == BoardSize - 1 || getObjectLoc().y == 0)
        return true;

    return false;
}

//__________________________
void Cat::handleCatTrapped() {
    if (checkObjectFullyTrapped())
        setCanMove(false);

}