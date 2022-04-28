#include "Controller.hpp"

//_____________________
Controller::Controller() :
	m_cat(m_board), m_catWon(false)
{
    m_board.setRandomBlackCircles();
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
        if(m_catWon){
            std::cout << "Cat Won!\n";
            m_gameWindow.close();
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
	if (m_board.findClick(location, m_cat.getCatCoordinates()))
	{
		m_screen.setSteps();
        m_cat.move();
        if(m_cat.checkCatWon())
            m_catWon = true;
	}
}
//_________________________________________________
void Controller::mouseEventMoved(const Event& event)
{
	auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
	m_board.findMovement(location, m_cat.getCatCoordinates());
}
//______________________________________________
void Controller::drawBoard(RenderWindow& window)
{
	m_board.drawBoard(window);
	m_cat.showCat(window);
	m_screen.drawScreen(window);
}