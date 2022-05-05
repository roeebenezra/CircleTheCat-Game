#pragma once

#include "Screen.hpp"
#include "Board.hpp"
#include "Cat.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>


class Controller {
public:
    Controller();

    void runGame();

private:
    void drawBoard(RenderWindow &);

    void handleEvents();

    void handleClickOnUndo();

    void mouseEventPressed(const Event &);

    void mouseEventMoved(const Event &);

    void exitGame(const Event &);

    void handleEnd();

    RenderWindow m_gameWindow = {VideoMode(1200, 950), "Circle the Cat"};
    Screen m_screen;
    Board m_board;
    Cat m_cat;
    bool m_gameOver;
    bool m_userWon;
    vector<pair<Vector2i, Vector2i >> m_moves; //cat moves + player clicks
};