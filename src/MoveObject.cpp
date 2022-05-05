#include "MoveObject.hpp"
#include <iostream>

//___________________________________________________________
sf::Vector2i MoveObject::getNextMove(const BoardVector &board) {
    bool visited[BoardSize][BoardSize] = {{false}};
    sf::Vector2i prev[BoardSize][BoardSize];
    sf::Vector2i e;
    if (bfs(board, e, visited, prev)) {
        return reversePrev(prev, e);
    }
    m_moves.emplace_back(prev.front());
    std::cout << "no path, cat trapped\n";
    return m_place;
}

//___________________________________________
// Function to perform the BFS traversal
bool MoveObject::bfs(const BoardVector &board,
                     sf::Vector2i &e,
                     bool visited[][BoardSize],
                     sf::Vector2i prev[BoardSize][BoardSize]) {
    // Stores indices of the matrix cells
    std::queue<std::pair<int, int>> q;

    // Mark the starting cell as visited
    // and push it into the queue
    q.push({m_place.x, m_place.y});
    visited[m_place.x][m_place.y] = true;

    // Iterate while the queue is not empty
    while (!q.empty()) {
        std::pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        q.pop();

        int adjx, adjy;
        // Go to the adjacent cells
        for (int i = 0; i < amountOfDir; i++) {
            adjx = x + dRow[i];
            m_place.x % 2 == 0 ? adjy = y + dColEven[i] :
                    adjy = y + dColOdd[i];
            e = sf::Vector2i(adjx, adjy);
//            std::cout << "parent1: (" << x << ", " << y << ")" << std::endl;
//            std::cout << "neighbor1: (" << adjx << ", " << adjy << ")" << std::endl;
            if (isValid(board, visited, sf::Vector2i(adjx, adjy))) {
                q.push({adjx, adjy});
                visited[adjx][adjy] = true;
                prev[adjx][adjy] = sf::Vector2i(x, y);
//                std::cout << "parent2: (" << x << ", " << y << ")" << std::endl;
//                std::cout << "neighbor2: (" << adjx << ", " << adjy << ")" << std::endl;
                if (adjx == 10 || adjx == 0 || adjy == 0 || adjy == 10)
                    return true;
            }
        }
    }
    std::cout << "\nend1!!!!" << std::endl;
    return false;
}

//________________________________________________
bool MoveObject::isValid(const BoardVector &board,
                         bool visited[][BoardSize],
                         const sf::Vector2i &i) {
    // If cell lies out of bounds
    if (i.x < 0 || i.y < 0 || i.x >= BoardSize || i.y >= BoardSize)
        return false;

    // If cell is already visited
    if (visited[i.x][i.y] || board[i.x][i.y].getFillColor() == Color::Black)
        return false;

    // Otherwise
    return true;
}

//___________________________________________________________________
sf::Vector2i MoveObject::reversePrev(sf::Vector2i prev[BoardSize][BoardSize],
                                     const sf::Vector2i &e) {
    std::vector<sf::Vector2i> path;
    for (auto at = e; at != m_place; at = prev[at.x][at.y]) {
        std::cout << "path: (" << at.x << ", " << at.y << ")" << std::endl;
        path.push_back(at);
    }
    std::cout << "\nend2!!!!" << std::endl;
    return path[path.size() - 1];
}

//__________________________________________________________________
[[noreturn]] sf::Vector2i MoveObject::returnRandomMove(const BoardVector &board) {
    int y;
    for (int i = 0; i < amountOfDir; i++) {
        int x = m_place.x + dRow[i];
        m_place.x % 2 == 0 ? y = m_place.y + dColEven[i] :
                y = m_place.y + dColOdd[i];

        // If cell lies out of bounds
        if (y < 0 || m_place.y < 0 || m_place.x >= BoardSize || m_place.y >= BoardSize)
            continue;
        if (board[x][y].getFillColor() != Color::Black)
            return {x, y};
    }
}

//__________________________________________
bool MoveObject::checkObjectFullyTrapped(const BoardVector &board) const {
    int y;
    for (int i = 0; i < amountOfDir; i++) {
        int x = m_place.x + dRow[i];
        m_place.y % 2 == 0 ? y = m_place.y + dColEven[i] :
                y = m_place.y + dColOdd[i];

        // If cell lies out of bounds
        if (m_place.x < 0 || m_place.y < 0 ||
            m_place.x > BoardSize - 1 || m_place.y > BoardSize - 1)
            continue;
        if (board[x][y].getFillColor() != Color::Black)
            return false;
    }
    return true;
}
