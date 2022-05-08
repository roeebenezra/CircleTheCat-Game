#include "Controller.hpp"

//_______________________
void Controller::runGame() {
    while (m_gameWindow.isOpen() && m_screen.getNumOfLevel() < 4) {
        if (m_cat.checkCatWon())
            handleEnd(false);
        if (!m_cat.getCanMove())
            handleEnd(true);
        handleEvents();
        m_gameWindow.clear(Color::White);
        drawBoard(m_gameWindow);
        m_gameWindow.display();
    }
}

//____________________________
void Controller::handleEvents() {
    auto event = sf::Event();
    while (m_gameWindow.pollEvent(event)) {
        switch (event.type) {
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
void Controller::exitGame(const Event &event) {
    if (event.key.code == sf::Keyboard::Escape ||
        event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//_________________________________________________
void Controller::mouseEventMoved(const Event &event) {
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
    m_board.findMovement(location, m_cat.getObjectLoc());
    m_screen.findMovement(location);
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    if (m_board.ClickOnBoard(location, m_cat.getObjectLoc())) {
        m_moves.emplace_back(pair<Vector2i, Vector2i>(m_cat.getObjectLoc(), m_board.getCurrClick()));
        m_screen.setSteps();
        m_cat.move();
    }
    if (m_screen.clickOnUndo(location))
        handleClickOnUndo();
}

//______________________________________________
void Controller::drawBoard(RenderWindow &window) {
    m_board.drawBoard(window);
    m_cat.showObject(window);
    m_screen.drawScreen(window);
}

//________________________________________
void Controller::handleEnd(const bool won) {
    m_gameWindow.clear(Color::White);
    drawBoard(m_gameWindow);
    if (won){
        m_screen.drawEnd(m_gameWindow, "You Win!", Color::Blue);
        m_screen.setLevels();
        m_board.restartBoard();
    }
    else {
        m_screen.drawEnd(m_gameWindow, "Game Over!", Color::Red);
        m_board.resetBoard();
    }
    m_gameWindow.display();
    m_screen.resetSteps();
    m_cat.setCatPosition(StartPos);
    m_cat.setCanMove(true);
    m_cat.setCatMove(true);
    m_moves.clear();
}

//_________________________________
void Controller::handleClickOnUndo() {
    if (m_moves.empty())
        return;
    m_cat.setCatPosition(m_moves.back().first);
    m_board.setBoardCircle(m_moves.back().second);
    m_screen.stepsCounterDown();
    m_moves.pop_back();
}