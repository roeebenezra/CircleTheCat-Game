#include "MoveObject.hpp"
#include <iostream>

MoveObject::MoveObject(const Board &board, const Vector2i &start) :
        m_board(&board), m_canMove(true), m_place(start) {
    m_sprite.setTexture(Resources::instance().getTexture());
    m_sprite.setScale(1.2f, 1.2f);
}

//________________________________
Vector2i MoveObject::getNextMove() {
    bool visited[BoardSize][BoardSize] = {{false}};
    sf::Vector2i prev[BoardSize][BoardSize];
    sf::Vector2i e;
    if (bfs(e, visited, prev)) {
        return reversePrev(prev, e);
    }
    return getObjectLoc();
}

// Function to perform the BFS traversal
//_______________________________
bool MoveObject::bfs(Vector2i &e,
                     bool visited[][BoardSize],
                     Vector2i prev[BoardSize][BoardSize]) {
    // Stores indices of the matrix cells
    std::queue<std::pair<int, int>> q;

    // Mark the starting cell as visited
    // and push it into the queue
    q.push({getObjectLoc().x, getObjectLoc().y});
    visited[getObjectLoc().x][getObjectLoc().y] = true;

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
            x % 2 == 0 ? adjy = y + dColEven[i] :
                    adjy = y + dColOdd[i];
            e = {adjx, adjy};
            if (isValid(visited, {adjx, adjy})) {
                q.push({adjx, adjy});
                visited[adjx][adjy] = true;
                prev[adjx][adjy] = {x, y};
                if (adjx == 10 || adjx == 0 || adjy == 0 || adjy == 10)
                    return true;
            }
        }
    }
    return false;
}

//________________________________________________
bool MoveObject::isValid(bool visited[][BoardSize],
                         const Vector2i &i) {
    // If cell lies out of bounds
    if (checkAdjInBounds(i))
        return false;

    // If cell is already visited
    if (visited[i.x][i.y] || isShapeBlack(i.x, i.y))
        return false;

    // Otherwise
    return true;
}

//________________________________________________________
bool MoveObject::checkAdjInBounds(const Vector2i &i) const {
    return i.x < 0 || i.y < 0 || i.x > BoardSize - 1 || i.y > BoardSize - 1;
}

//_______________________________________________________________________
sf::Vector2i MoveObject::reversePrev(Vector2i prev[BoardSize][BoardSize],
                                     const sf::Vector2i &e) {
    std::vector<Vector2i> path;
    for (auto at = e; at != getObjectLoc(); at = prev[at.x][at.y]) {
        path.push_back(at);
    }
    return path[path.size() - 1];
}

//_____________________________________
Vector2i MoveObject::returnRandomMove() {
    int y;
    for (int i = 0; i < amountOfDir; i++) {
        int x = getObjectLoc().x + dRow[i];
        getObjectLoc().x % 2 == 0 ? y = getObjectLoc().y + dColEven[i] :
                y = getObjectLoc().y + dColOdd[i];

        // If cell lies out of bounds
        if (checkAdjInBounds({x, y}))
            continue;
        if (!isShapeBlack(x, y))
            return {x, y};
    }
    return getObjectLoc();
}

//______________________________________________
bool MoveObject::checkObjectFullyTrapped() const {
    int y;
    for (int i = 0; i < amountOfDir; i++) {
        int x = getObjectLoc().x + dRow[i];
        getObjectLoc().x % 2 == 0 ? y = getObjectLoc().y + dColEven[i] :
                y = getObjectLoc().y + dColOdd[i];
        // If cell lies out of bounds
        if (checkAdjInBounds({x, y}))
            continue;
        if (!isShapeBlack(x, y))
            return false;
    }
    return true;
}
