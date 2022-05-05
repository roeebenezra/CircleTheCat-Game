#pragma once

#include <queue>
#include "macros.hpp"
#include "Board.hpp"
#include "GameObject.hpp"

class MoveObject : public GameObject {

public:
    MoveObject(Board &board, const Vector2i &start) :
             GameObject(start), m_board(&board), m_canMove(true) {};

    Vector2i getNextMove();

    Vector2i returnRandomMove();

    bool checkObjectFullyTrapped() const;

    Vector2f getObjectPos(const int x, const int y) const { return m_board->getPos(x, y); }

    bool isShapeBlack(const int x, const int y) const { return m_board->isShapeBlack(x, y); }

    bool getCanMove() const { return m_canMove; }

    void setCanMove(const bool move) { m_canMove = move; }

private:
    bool bfs(Vector2i &,
             bool[][BoardSize],
             Vector2i [BoardSize][BoardSize]);

    bool isValid(bool[][BoardSize],
                 const Vector2i &);

    Vector2i reversePrev(Vector2i [BoardSize][BoardSize],
                         const Vector2i &);

    bool checkAdjInBounds(const Vector2i &i) const;

    Board *m_board;
    bool m_canMove;
};