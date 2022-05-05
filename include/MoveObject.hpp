#pragma once

#include <queue>
#include "macros.hpp"

class MoveObject {
public:
    MoveObject(const sf::Vector2i& start){ m_place = start; };

    sf::Vector2i getNextMove(const BoardVector &);

    sf::Vector2i getMovingObjectPLace() const { return m_place; }
    void setMovingObjectPLace(const sf::Vector2i & place){ m_place = place; }
    bool checkObjectFullyTrapped(const BoardVector &) const;

private:
    bool bfs(const BoardVector &,
             sf::Vector2i &,
             bool[][BoardSize],
             sf::Vector2i [BoardSize][BoardSize]);

    bool isValid(const BoardVector &,
                 bool[][BoardSize],
                 const sf::Vector2i &);

    sf::Vector2i reversePrev(sf::Vector2i [BoardSize][BoardSize],
                             const sf::Vector2i &);

    [[noreturn]] sf::Vector2i returnRandomMove(const BoardVector &);
    sf::Vector2i m_place;
};