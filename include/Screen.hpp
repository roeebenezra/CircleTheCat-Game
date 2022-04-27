#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.hpp"
#include "Resources.hpp"

class Screen
{
public:
	Screen();
	void drawScreen(RenderWindow& window)const;
	void setSteps();

private:
	void setFonts();
	void stepsCounter() { m_steps++; }

	unsigned int m_steps = 0;
	Text createText(Vector2f& pos);
	std::vector<Text> m_boardTexts;
	std::vector<std::vector<Vector2f>> m_levels;
	std::vector<std::string> Texts = { "Circle The Cat", "Level: ", "Steps: " };
};