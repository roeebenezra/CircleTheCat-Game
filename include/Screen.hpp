#pragma once
#include <vector>
#include "macros.hpp"
#include "Resources.hpp"

class Screen {
public:

    Screen();

    void setSteps();

    void findMovement(const Vector2f &);

    bool clickOnUndo(const Vector2f &);

    void drawScreen(RenderWindow &) const;

    void drawGameOver(RenderWindow &) const;
  
    void drawUserWon(RenderWindow&)const;

    void resetSteps();

    void stepsCounterDown();

private:
    void setStepsString();

    void setFonts();

    Text createText(Vector2f, unsigned int, const string &, Color) const;

    void stepsCounter() { m_steps++; }

    unsigned int m_steps = 0;

    std::vector<Text> m_boardTexts;
    std::vector<std::vector<Vector2f>> m_levels;
    std::vector<std::string> Texts = {"Circle The Cat", "Level: ", "Steps: ", "Undo"};
};