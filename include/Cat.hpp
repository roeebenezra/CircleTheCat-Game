#pragma once

#include "Board.hpp"
#include "MoveObject.hpp"
#include "macros.hpp"
#include <SFML/Graphics.hpp>

class Cat  : public MoveObject {
public:
    explicit Cat(Board &);
    void showCat(RenderWindow &window) const { window.draw(m_catSprite); }
    void move();
    bool handleCatTrapped()const;
    sf::Vector2i getCatCoordinates()const { return getMovingObjectPLace(); }
    bool checkCatWon() const;
    void setCatPosition(const sf::Vector2i &);

private:
    Sprite m_catSprite;
    Board *m_board;
};
