#pragma once

#include "Screen.hpp"
#include "Board.hpp"
#include "Cat.hpp"

#include <iostream>
#include <string>
#include <vector>

class Controller {
public:
    Controller() : m_cat(m_board) {}    //constructor

    void runGame();     //main game loop function

private:
    void drawBoard(RenderWindow &);

    void handleEvents();

    void handleClickOnUndo();

    void mouseEventPressed(const Event &);

    void mouseEventMoved(const Event &);

    void exitGame(const Event &);

    void handleEnd(const bool);

    RenderWindow m_gameWindow = {VideoMode(1200, 950), "Circle the Cat"};
    Screen m_screen;
    Board m_board;
    Cat m_cat;
    vector<pair<Vector2i, Vector2i >> m_moves; //cat moves + player clicks
};