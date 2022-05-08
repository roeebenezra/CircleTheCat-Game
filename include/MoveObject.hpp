#pragma once

#include <queue>
#include "macros.hpp"
#include "Board.hpp"

class MoveObject {
public:
    MoveObject(const Board &, const Vector2i &) ;   //constructor

    //bfs functions
    Vector2i getNextMove();

    Vector2i returnRandomMove();

    bool checkObjectFullyTrapped() const;

    //get & set functions
    Vector2f getObjectPos(const int x, const int y) const { return m_board->getPos(x, y); }

    bool isShapeBlack(const int x, const int y) const { return m_board->isShapeBlack(x, y); }

    bool getCanMove() const { return m_canMove; }

    void setCanMove(const bool move) { m_canMove = move; }

    void showObject(RenderWindow &window) const { window.draw(m_sprite); }

    Vector2i getObjectLoc() const { return m_place; }

    void setObjectPLace(const Vector2i &place) { m_place = place; }

    void setSpritePosition(const Vector2f &loc) { m_sprite.setPosition(loc); }

    void setIntRectSprite(const sf::IntRect &loc) { m_sprite.setTextureRect(loc); }

private:
    //bfs private functions
    bool bfs(Vector2i &,
             bool[][BoardSize],
             Vector2i [BoardSize][BoardSize]);

    bool isValid(bool[][BoardSize],
                 const Vector2i &);

    Vector2i reversePrev(Vector2i [BoardSize][BoardSize],
                         const Vector2i &);

    bool checkAdjInBounds(const Vector2i &i) const;

    const Board *m_board;
    bool m_canMove;
    Vector2i m_place;
    Sprite m_sprite;
};