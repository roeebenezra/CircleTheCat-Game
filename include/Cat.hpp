#pragma once

#include "MoveObject.hpp"
#include "macros.hpp"

class Cat : public MoveObject {
public:
    Cat(Board &);

    void move();

    bool checkCatWon() const;

private:
    void setCatPosition(const Vector2i &);

    void handleCatTrapped();
};
