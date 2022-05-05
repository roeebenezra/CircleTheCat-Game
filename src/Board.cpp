#include "Board.hpp"

//____________
Board::Board() {
    setBoard();
}

//___________________
void Board::setBoard() {
    Vector2f pos = {35, 150};
    for (size_t i = 0; i < BoardSize; i++) {
        std::vector<CircleShape> circleRow;
        for (size_t j = 0; j < BoardSize; j++) {
            CircleShape circle = createCircle(pos);
            circleRow.push_back(circle);
            pos.x += X_CircleDistance;
        }
        m_board.push_back(circleRow);
        pos.y += Y_CircleDistance;
        if (i % 2 == 0)
            pos.x = CircleLeftOddDistance;
        else
            pos.x = CircleLeftEvenDistance;
    }
    setRandomBlackCircles();
}

//___________________________________________
CircleShape Board::createCircle(Vector2f &pos) {
    CircleShape circle(CircleSize);
    circle.setPosition(pos);
    circle.setFillColor(Color{0, 255, 0, 127});
    circle.setOutlineColor(Color::Black);
    circle.setOutlineThickness(3);
    return circle;
}

//______________________________________________
void Board::drawBoard(RenderWindow &window) const {
    for (auto const &i: m_board)
        for (auto const &j: i)
            window.draw(j);
}

//____________________________________
void Board::findMovement(Vector2f &loc,
                         const Vector2i &catLoc) {
    for (int i = 0; i < BoardSize; i++) {
        for (int j = 0; j < BoardSize; j++) {
            if (m_board[i][j].getGlobalBounds().contains(loc)) {
                m_board[i][j].getFillColor() == Color::Black ||
                (i == catLoc.x && j == catLoc.y) ?
                m_board[i][j].setOutlineColor(Color{255, 0, 0, 127}) :
                m_board[i][j].setOutlineColor(Color{0, 0, 255, 127});
                m_board[i][j].setOutlineThickness(4);
                return;
            } else {
                m_board[i][j].setOutlineColor(Color::Black);
                m_board[i][j].setOutlineThickness(3);
            }
        }
    }
}

//_________________________________
bool Board::findClick(Vector2f &loc,
                      const Vector2i &catLoc) {
    for (int i = 0; i < BoardSize; i++)
        for (int j = 0; j < BoardSize; j++)
            if (m_board[i][j].getGlobalBounds().contains(loc)) {
                if (m_board[i][j].getFillColor() == Color::Black
                    || (i == catLoc.x && j == catLoc.y))
                    return false;
                else
                    m_board[i][j].setFillColor(Color::Black);
                return true;
            }
    return false;
}

//________________________________
void Board::setRandomBlackCircles() {
    int size = 14, x, y;
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < size; ++i) {
        do {
            x = rand() % BoardSize;
            y = rand() % BoardSize;
        } while (m_board[x][y].getFillColor() == Color::Black ||
                 (x == StartPos.x && y == StartPos.y));
        m_board[x][y].setFillColor(Color::Black);
    }
}

//_______________________
void Board::restartLevel() {
    setBoard();
    setRandomBlackCircles();
}

//_______________________
void Board::restartBoard() {
    for (auto &i: m_board)
        for (auto &j: i)
            j.setFillColor(Color{0, 255, 0, 127});

    setRandomBlackCircles();
}