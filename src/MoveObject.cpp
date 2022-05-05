#include "MoveObject.hpp"

//_________________________________
void MoveObject::undo() {

}

//___________________________________________________________
sf::Vector2i MoveObject::getNextMove(const BoardVector &board,
                                     const sf::Vector2i &src) {
    bool visited[BoardSize][BoardSize] = {{false}};
    std::vector<sf::Vector2i> prev;

    if (!bfs(board, src, visited, prev))
        return src; //return source pos
    m_moves.emplace_back(prev.front());
    return prev.front();
}

//___________________________________________
// Function to perform the BFS traversal
bool MoveObject::bfs(const BoardVector &board,
                     const sf::Vector2i &src,
                     bool visited[][BoardSize],
                     std::vector<sf::Vector2i> &prev) {
    // Stores indices of the matrix cells
    std::queue<std::pair<int, int>> q;

    // Mark the starting cell as visited
    // and push it into the queue
    q.push({src.x, src.y});
    visited[src.x][src.y] = true;
    // Iterate while the queue is not empty
    while (!q.empty()) {
        std::pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;

        q.pop();

        // Go to the adjacent cells
        for (int i = 0; i < amountOfDir; i++) {
            int adjx = x + dRow[i];
            int adjy = y + dCol[i];

            if (isValid(board, visited, sf::Vector2i(adjx, adjy))) {
                q.push({adjx, adjy});
                visited[adjx][adjy] = true;
                prev.emplace_back(sf::Vector2i(adjx, adjy));
                if (adjx == 10 || adjx == 0 || adjy == 0 || adjy == 10)
                    return true;
            }
        }
    }
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