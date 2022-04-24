#include "Controller.hpp"

//______________________
Controller::Controller()
{
	runGame();
}
//________________________
void Controller::runGame()
{
	while (m_gameWindow.isOpen())
	{
		m_gameWindow.clear(Color::White);
		drawBoard(m_gameWindow);
		handleEvents();
		m_gameWindow.display();
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
void Controller::exitGame(const Event& event)
{
	if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
		m_gameWindow.close();
}
//_________________________________________________________
void Controller::mouseEventReleased(const Event& event)
{
	// getting the location of where the mouse was pressed
	auto location = m_gameWindow.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });

}
//______________________________________________________
void Controller::mouseEventMoved(const Event& event)
{
}

//__________________________________________________
void Controller::drawBoard(RenderWindow& window)
{
	m_board.drawBoard(window);
}
