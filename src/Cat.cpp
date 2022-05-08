#include "Cat.hpp"

//___________________
Cat::Cat(const Board &board) : MoveObject(board, StartPos), m_catMove(true) {
    setIntRectSprite(catRectSprite);
    (float(1.2), float(1.2));
    setSpritePosition(getObjectPos(StartPos.x, StartPos.y));
}

//___________________________________________________
void Cat::setCatPosition(const Vector2i &nextMove) {
    setSpritePosition(getObjectPos(nextMove.x, nextMove.y));
    setObjectPLace(nextMove);
}

//_____________
void Cat::move() {
    if (m_catMove) {
        Vector2i newMove = getNextMove();
        if (newMove == getObjectLoc()) {
            setCatMove(false);
            setCatPosition(returnRandomMove());
            return;
        }
        setCatPosition(newMove);
    } else {
        setCatPosition(returnRandomMove());
        if (checkObjectFullyTrapped())
            setCanMove(false);
    }
}

//____________________________
bool Cat::checkCatWon() const {
    if (getObjectLoc().x == BoardSize - 1 || getObjectLoc().x == 0 ||
        getObjectLoc().y == BoardSize - 1 || getObjectLoc().y == 0)
        return true;

    return false;
}