#include "MoveObject.hpp"

//_____________________________________________________
sf::Vector2i MoveObject::getNextMove(const BoardVector &board,
                              const sf::Vector2i &src) {

    bool vis[BoardSize][BoardSize];
    std::vector<sf::Vector2i> prev;
    setArray(vis);

    if(!solve(board, src, vis, prev))
        return src;
    return prev.front();
}
//______________________________________________
void MoveObject::setArray(bool vis[][BoardSize]) {
    for (int i = 0; i < BoardSize; ++i)
        for (int j = 0; j < BoardSize; ++j)
            vis[i][j] = false;
}
//___________________________________________
// Function to perform the BFS traversal
bool MoveObject::solve(const BoardVector &board,
                const sf::Vector2i &src,
                bool vis[][BoardSize],
                std::vector<sf::Vector2i>& prev) {

    // Stores indices of the matrix cells
    std::queue<std::pair<int, int> > q;

    // Mark the starting cell as visited
    // and push it into the queue
    q.push({src.x, src.y});
    vis[src.x][src.y] = true;
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

            if (isValid(board, vis, sf::Vector2i(adjx, adjy))) {
                q.push({adjx, adjy});
                vis[adjx][adjy] = true;
                prev.push_back(sf::Vector2i(adjx, adjy));
                if (adjx == 10 || adjx == 0 || adjy == 0 || adjy == 10)
                    return true;
            }
        }
    }
    return false;
}
//_______________________________________________________________
bool MoveObject::isValid(const BoardVector &board, bool vis[][BoardSize],
                  const sf::Vector2i &i) {
    // If cell lies out of bounds
    if (i.x < 0 || i.y < 0
        || i.x >= BoardSize - 1 || i.y >= BoardSize - 1)
        return false;

    // If cell is already visited
    if (vis[i.x][i.y])
        return false;

    if (board[i.x][i.y].getFillColor() == Color::Black)
        return false;

    // Otherwise
    return true;
}