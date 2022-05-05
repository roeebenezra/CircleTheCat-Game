#pragma once

#include "Board.hpp"
#include "MoveObject.hpp"
#include "macros.hpp"
#include <SFML/Graphics.hpp>

class Cat : public MoveObject {
public:
    explicit Cat(Board &);

    void showCat(RenderWindow &window) const { window.draw(m_catSprite); }

    void move();

    //void animation() const;
    Vector2i getCatPos() const { return m_place; }

    bool checkCatWon() const;

    void setCatPosition(const sf::Vector2i &);

private:
    Sprite m_catSprite;
    Board *m_board;
    Vector2i m_place;
};
