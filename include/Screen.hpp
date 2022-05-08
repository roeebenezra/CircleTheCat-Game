#pragma once

#include <vector>
#include <string>
#include "macros.hpp"
#include "Resources.hpp"

class Screen {
public:

    Screen();

    void setSteps();

    void findMovement(const Vector2f &);

    bool clickOnUndo(const Vector2f &)const ;

    void drawScreen(RenderWindow &) const;

    void drawEnd(RenderWindow &, const std::string &, const Color &) const;

    void resetSteps();

    void setLevels();

    void stepsCounterDown();

    unsigned int getNumOfLevel() const { return m_level; }

private:
    void setTextString(const TEXTS&, int);

    void setFonts();

    Text createText(Vector2f, unsigned int, const string &, Color) const;

    void stepsCounter() { m_steps++; }

    unsigned int m_steps = 0;
    unsigned int m_level = 0;

    vector<Text> m_boardTexts;
    vector<vector<Vector2f>> m_levels;
    vector<string> Texts = {"Circle The Cat", "Level: ", "Steps: ", "Undo"};
};