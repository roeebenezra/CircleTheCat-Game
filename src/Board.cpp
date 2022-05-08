#include "Board.hpp"

//____________
Board::Board() : m_numOfRandomBlackCircles(15) {
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
    for (size_t i = 0; i < BoardSize; i++)
        for (size_t j = 0; j < BoardSize; j++)
            if (m_board[i][j].getGlobalBounds().contains(loc)) {
                m_board[i][j].getFillColor() == Color::Black ||
                (i == size_t(catLoc.x) && j == size_t(catLoc.y)) ?
                m_board[i][j].setOutlineColor(Color{255, 0, 0, 127}) :
                m_board[i][j].setOutlineColor(Color{0, 0, 255, 127});
                m_board[i][j].setOutlineThickness(4);
                return;
            } else {
                m_board[i][j].setOutlineColor(Color::Black);
                m_board[i][j].setOutlineThickness(3);
            }
}

//_________________________________
bool Board::ClickOnBoard(Vector2f &loc,
                         const Vector2i &catLoc) {
    for (size_t i = 0; i < BoardSize; i++)
        for (size_t j = 0; j < BoardSize; j++)
            if (m_board[i][j].getGlobalBounds().contains(loc)) {
                if (m_board[i][j].getFillColor() == Color::Black
                    || (i == size_t(catLoc.x) && j == size_t(catLoc.y)))
                    return false;
                else {
                    m_currClick = {int(i), int(j)};
                    m_board[i][j].setFillColor(Color::Black);
                }
                return true;
            }
    return false;
}

//________________________________
void Board::setRandomBlackCircles() {
    int size = m_numOfRandomBlackCircles,
            x, y;
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < size; ++i) {
        do {
            x = rand() % BoardSize;
            y = rand() % BoardSize;
        } while (m_board[x][y].getFillColor() == Color::Black ||
                 (x == StartPos.x && y == StartPos.y));
        m_board[x][y].setFillColor(Color::Black);
        m_randomBlack.push_back({x, y});
    }
}

//_______________________
void Board::restartBoard() {
    for (auto &i: m_board)
        for (auto &j: i)
            j.setFillColor(Color{0, 255, 0, 127});

    m_randomBlack.clear();
    m_numOfRandomBlackCircles -= 3;
    setRandomBlackCircles();
}

//______________________
void Board::resetBoard() {
    for (auto &i: m_board)
        for (auto &j: i)
            j.setFillColor(Color{0, 255, 0, 127});

    setBackRandomBlackCircles();
}

//_____________________________________
void Board::setBackRandomBlackCircles() {
    for (int i = 0; i < m_randomBlack.size(); ++i)
        m_board[m_randomBlack[i].x][m_randomBlack[i].y].setFillColor(Color::Black);
}

//_______________________________________
void Board::setBoardCircle(Vector2i &pos) {
    m_board[size_t(pos.x)][size_t(pos.y)].setFillColor(Color{0, 255, 0, 127});
}