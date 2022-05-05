#pragma once

#include <queue>
#include "macros.hpp"

class MoveObject {
public:
    MoveObject() = default;

    sf::Vector2i getNextMove(const BoardVector &,
                             const sf::Vector2i &);

private:
    bool bfs(const BoardVector &, const sf::Vector2i &,
             bool[][BoardSize], vector<sf::Vector2i> &);

    void undo();

    bool isValid(const BoardVector &,
                 bool[][BoardSize],
                 const sf::Vector2i &);

    vector<Vector2i> m_moves;
};