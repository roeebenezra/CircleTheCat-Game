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
	void drawBoard(sf::RenderWindow&);
	void handleEvents();
	void mouseEventReleased(const sf::Event&);
	void mouseEventMoved(const sf::Event&);
	void exitGame(const sf::Event&);
	
	sf::RenderWindow m_gameWindow = { sf::VideoMode(1100, 920), "Circle the Cat" };
	Board m_board;
};