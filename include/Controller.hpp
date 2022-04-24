#pragma once
#include "Board.hpp"

#include <stdio.h>
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
	void mouseEventReleased(const Event&);
	void mouseEventMoved(const Event&);
	void exitGame(const Event&);
	
	RenderWindow m_gameWindow = { VideoMode(1150, 1000), "Circle the Cat" };
	Board m_board;
};