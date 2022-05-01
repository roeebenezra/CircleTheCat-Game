#include "Screen.hpp"

//______________
Screen::Screen()
{
	setFonts();
}
//_____________________
void Screen::setFonts()
{
	Vector2f pos = { 400, 0 };

	for (size_t i = 0; i < Texts.size() ; i++)
	{
		if (i == 1) pos.x += X_TextAdd;
		if (i > 0)  pos.y += Y_TextAdd;
		Text text = createText(pos);
		text.setString(Texts[i]);
		m_boardTexts.push_back(text);
	}
	Texts[2] += std::to_string(m_steps);
	m_boardTexts[2].setString(Texts[2]);
}
//____________________________________
Text Screen::createText(Vector2f& pos)const
{
	Text text;
	text.setFont(Resources::instance().getFont());
	text.setCharacterSize(FontSize);
	text.setFillColor(Color::Black);
	text.setPosition(pos);

	return text;
}
//________________________________________________
void Screen::drawScreen(RenderWindow& window)const
{
	for (auto const &i : m_boardTexts)
		window.draw(i);
}
//____________________
void Screen::setSteps()
{
	stepsCounter();
	Texts[2].replace(7, std::to_string(m_steps).size(), std::to_string(m_steps));
	m_boardTexts[2].setString(Texts[2]);
}

void Screen::drawGameOver(RenderWindow& window)const
{
	Vector2f pos{ 250, 300 };
	Text text = createText(pos);
	text.setCharacterSize(250);
	text.setString("Game Over");
	text.setColor(Color{ 255, 0, 0, 100 });

	Clock clock;
	while (clock.getElapsedTime().asSeconds() < 1)
	{
		window.draw(text);
		window.display();
	}
}