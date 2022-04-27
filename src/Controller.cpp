#include "Controller.hpp"

//_____________________
Controller::Controller() :
	m_cat(&m_board)
{
	runGame();
}
//_______________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		handleEvents();
		m_gameWindow.clear(Color::White);
		drawBoard(m_gameWindow);
		m_gameWindow.display();
	}
}
//____________________________
void Controller::handleEvents()
{
	auto event = sf::Event();
	while (m_gameWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			mouseEventPressed(event);
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
//__________________________________________
void Controller::exitGame(const Event& event)
{
	if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		m_gameWindow.close();
}
//____________________________________________________
void Controller::mouseEventPressed(const Event& event)
{
	auto location = m_gameWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
	if (m_board.findClick(location))
	{
		m_screen.setSteps();
		m_cat.setCatPosition();
	}
}
//_________________________________________________
void Controller::mouseEventMoved(const Event& event)
{
	auto location = Vector2f(event.mouseMove.x, event.mouseMove.y);
	m_board.findMovement(location);
}
//______________________________________________
void Controller::drawBoard(RenderWindow& window)
{
	m_board.drawBoard(window);
	m_cat.showCat(window);
	m_screen.drawScreen(window);
}