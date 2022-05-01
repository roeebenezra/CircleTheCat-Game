#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.hpp"
#include "Resources.hpp"

class Screen
{
public:
	Screen();
	void setSteps();
	void drawScreen(RenderWindow&)const;
	void drawGameOver(RenderWindow&)const;

private:
	void setFonts();
	const Text createText(Vector2f, unsigned int, string, Color)const;
	void stepsCounter() { m_steps++; }
	unsigned int m_steps = 0;

	std::vector<Text> m_boardTexts;
	std::vector<std::vector<Vector2f>> m_levels;
	std::vector<std::string> Texts = { "Circle The Cat", "Level: ", "Steps: " };
};