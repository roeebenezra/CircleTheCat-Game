#include "Screen.hpp"

//_____________
Screen::Screen() {
    setFonts();
    setLevels();
}

//____________________
void Screen::setFonts() {
    Vector2f pos = {400, 0};
    for (size_t i = 0; i < Texts.size(); i++) {
        if (i == 1) pos.x += X_TextAdd;
        if (i > 0) pos.y += Y_TextAdd;
        Text text = createText(pos, FontSize, Texts[i], Color::Black);
        m_boardTexts.push_back(text);
    }
    Texts[STEPS] += std::to_string(m_steps);
    m_boardTexts[STEPS].setString(Texts[STEPS]);
}

//_____________________________________________________
Text Screen::createText(Vector2f pos, unsigned int size,
                        const string &name, Color color) const {
    Text text(name, Resources::instance().getFont(), size);
    text.setFillColor(color);
    text.setPosition(pos);

    return text;
}

//_______________________________________________
void Screen::drawScreen(RenderWindow &window) const {
    for (auto const &i: m_boardTexts)
        window.draw(i);
}

//__________________________________________________________
void Screen::setTextString(const TEXTS& text, int num)
{
    Texts[text].replace(7, std::to_string(num).size() + 1, std::to_string(num));
    m_boardTexts[text].setString(Texts[text]);
}

//____________________
void Screen::setSteps() {
    stepsCounter();
    setTextString(STEPS, m_steps);
}
//____________________
void Screen::setLevels() {
    m_level++;
    setTextString(LEVEL, m_level);
}

//______________________
void Screen::resetSteps() {
    m_steps = 0;
    setTextString(STEPS, m_steps);
}

//_____________________________________________________________________
void Screen::drawEnd(RenderWindow & window, const std::string & message,
                     const Color& color) const
{
    Text text = createText({250, 300}, 250, message, color);
    Clock clock;
    while (clock.getElapsedTime().asSeconds() < 2) {
        window.draw(text);
        window.display();
    }
}

//___________________________________________
void Screen::findMovement(const Vector2f &loc) {
    if (m_boardTexts[UNDO].getGlobalBounds().contains(loc))
        m_boardTexts[UNDO].setFillColor(Color{255, 0, 0, 127});
    else
        m_boardTexts[UNDO].setFillColor(Color::Black);
}

//__________________________________________
bool Screen::clickOnUndo(const Vector2f &loc)const {
    if (m_boardTexts[UNDO].getGlobalBounds().contains(loc))
        return true;

    return false;
}

//____________________________
void Screen::stepsCounterDown() {
    m_steps--;
    setTextString(STEPS, m_steps);
}
