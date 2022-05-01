#pragma once
#include <queue>
#include "macros.hpp"

class MoveObject {
public:
    MoveObject() { initNeighborsList(); }
    sf::Vector2i getNextMove(const BoardVector&,
                              const sf::Vector2i &);
private:
    void initNeighborsList();
    bool solve(const BoardVector& ,
                const sf::Vector2i& ,
                bool[][BoardSize],
                std::vector<sf::Vector2i> &);
 
    bool isValid(const BoardVector&,
                  bool[][BoardSize],
                  const sf::Vector2i &);
};