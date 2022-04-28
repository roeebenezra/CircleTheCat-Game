#pragma once
#include "Screen.hpp"
#include "Board.hpp"
#include "Cat.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <memory>


class Controller
{
public:
	Controller();
	void runGame();

private:
	void drawBoard(RenderWindow&);
	void handleEvents();
	void mouseEventPressed(const Event&);
	void mouseEventMoved(const Event&);
	void exitGame(const Event&);
	
	RenderWindow m_gameWindow = { VideoMode(1300, 1000), "Circle the Cat" };
	Screen m_screen;
	Board m_board;
	Cat m_cat;
    sf::Vector2i m_nextMove = {5,6};
    bool m_catWon;
};