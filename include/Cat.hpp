#pragma once

#include "MoveObject.hpp"
#include "macros.hpp"

class Cat : public MoveObject {
public:
    Cat(const Board &);

    void move();

    bool checkCatWon() const;

    void setCatPosition(const Vector2i &);

    void setCatMove(const bool move) { m_catMove = move; }

private:
    bool m_catMove;
};
