#include "Controller.hpp"

//______________________
Controller::Controller()
{}
//________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		handleEvents();
	}
}
//_____________________________
void Controller::handleEvents()
{
	auto event = sf::Event();
	while (m_gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonReleased:
			mouseEventReleased(event);
			break;
		case sf::Event::KeyPressed:
			keyboardEvent(event);
			break;
		case sf::Event::MouseMoved:
			mouseEventMoved(event);
			break;
		default:
			exitGame(event);
			break;
		}
	}
}
//_______________________________________________
void Controller::exitGame(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		m_gameWindow.close();
}
//_________________________________________________________
void Controller::mouseEventReleased(const sf::Event& event)
{
	// getting the location of where the mouse was pressed
	auto location = m_gameWindow.mapPixelToCoords(
		{ event.mouseButton.x, event.mouseButton.y });
}
//______________________________________________________
void Controller::mouseEventMoved(const sf::Event& event)
{
}
//____________________________________________________
void Controller::keyboardEvent(const sf::Event& event)
{
}