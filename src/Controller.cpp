#include "Controller.hpp"

//_____________________
Controller::Controller()
        : m_cat(m_board), m_gameOver(false),
          m_userWon(false) {}

//_______________________
void Controller::runGame() {
    while (m_gameWindow.isOpen()) {
        handleEvents();
        m_gameWindow.clear(Color::White);
        drawBoard(m_gameWindow);
        if (m_gameOver || m_userWon)
            handleEnd();
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
    if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
        m_gameWindow.close();
}

//___________________________________________________
void Controller::mouseEventPressed(const Event &event) {
    auto location = m_gameWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
    if (m_board.ClickOnBoard(location, m_cat.getCatCoordinates())) {
        m_moves.emplace_back(pair<Vector2i, Vector2i>(m_cat.getCatCoordinates(), m_board.getCurrClick()));
        m_screen.setSteps();
        m_cat.move();
        if (m_cat.checkCatWon())
            m_gameOver = true;
        if (m_cat.handleCatTrapped())
            m_userWon = true;
    }
    if (m_screen.clickOnUndo(location))
        handleClickOnUndo();
}

//_________________________________________________
void Controller::mouseEventMoved(const Event &event) {
    auto location = Vector2f(float(event.mouseMove.x), float(event.mouseMove.y));
    m_board.findMovement(location, m_cat.getCatCoordinates());
    m_screen.findMovement(location);
}

//_____________________________________________
void Controller::drawBoard(RenderWindow &window) {
    m_board.drawBoard(window);
    m_cat.showCat(window);
    m_screen.drawScreen(window);
}

//____________________________
void Controller::handleEnd() {
    if (m_userWon)
        m_screen.drawUserWon(m_gameWindow);
    if (m_gameOver)
        m_screen.drawGameOver(m_gameWindow);
    m_screen.resetSteps();
    m_board.restartBoard();
    m_cat.setCatPosition(StartPos);
    m_moves.clear();
    m_gameOver = false;
    m_userWon = false;
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