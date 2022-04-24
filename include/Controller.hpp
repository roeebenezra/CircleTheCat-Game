#pragma once
#include "Board.hpp"
#include "Cat.hpp"

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
	void mouseEventPressed(const Event&);
	void mouseEventMoved(const Event&);
	void exitGame(const Event&);
	
	RenderWindow m_gameWindow = { VideoMode(950, 800), "Circle the Cat" };
	Board m_board;
	Cat m_cat;
};