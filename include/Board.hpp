#pragma once

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <memory>

#include "macros.hpp"
#include "Resources.hpp"

class Board {
public:
    Board();

    void drawBoard(RenderWindow &) const;
    void setRandomBlackCircles();
    void findMovement(Vector2f &, const Vector2i&);
    bool findClick(Vector2f &, const Vector2i&);
    const BoardVector getBoard() const { return m_board; }
    const CircleShape &getCircle(size_t row, size_t col) { return m_board[row][col]; }

private:
    void setBoard();
    static CircleShape createCircle(Vector2f &);

    BoardVector m_board;
};
