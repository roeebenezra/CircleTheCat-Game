#pragma once

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
	void handleEvents();
	void mouseEventReleased(const sf::Event&);
	void keyboardEvent(const sf::Event&);
	void mouseEventMoved(const sf::Event&);
	void exitGame(const sf::Event& event);
	
	sf::RenderWindow m_gameWindow = { {1280, 720}, "Circle the Cat" };
};