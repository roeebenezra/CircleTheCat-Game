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

    bool isShapeBlack(const int x, const int y) const { return m_board[x][y].getFillColor() == Color::Black; }

    Vector2f getPos(const int x, const int y) const { return m_board[x][y].getPosition(); }

    Vector2i getCurrClick() const { return m_currClick; }

private:
    void setBoard();

    static CircleShape createCircle(Vector2f &);

    BoardVector m_board;
    Vector2i m_currClick;
};
