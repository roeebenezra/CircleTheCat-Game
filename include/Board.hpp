#pragma once

#include "macros.hpp"
#include "Resources.hpp"

class Board {
public:
    Board();

    void drawBoard(RenderWindow &) const;

    void setRandomBlackCircles();

    void findMovement(Vector2f &, const Vector2i &);

    bool ClickOnBoard(Vector2f &, const Vector2i &);

    void restartBoard();

    void setBoardCircle(Vector2i &pos);

    BoardVector getBoard() const { return m_board; }

    const CircleShape &getCircle(size_t row, size_t col) { return m_board[row][col]; }

    Vector2i getCurrClick() { return m_currClick; }

private:
    void setBoard();

    static CircleShape createCircle(Vector2f &);

    BoardVector m_board;
    Vector2i m_currClick;
};
