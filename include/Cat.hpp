#pragma once

#include "MoveObject.hpp"
#include "macros.hpp"

class Cat : public MoveObject {
public:
    Cat(const Board &);

    void move();

    bool checkCatWon() const;

    void setCatPosition(const Vector2i &);
private:

    void handleCatTrapped();
};
