#include<iostream>
#include <list>
#include "macros.hpp"
#include <queue>

class MoveObject {
public:
    MoveObject() {}
    sf::Vector2i getNextMove(const BoardVector &,
                             const sf::Vector2i &);
private:
    bool solve(const BoardVector &,
               const sf::Vector2i &,
               bool[][BoardSize],
               std::vector<sf::Vector2i> &);
    void setArray(bool[][BoardSize]);
    bool isValid(const BoardVector &,
                 bool[][BoardSize],
                 const sf::Vector2i &);
};