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
		Text text = createText(pos,FontSize,Texts[i],Color::Black);
		m_boardTexts.push_back(text);
	}
	Texts[2] += std::to_string(m_steps);
	m_boardTexts[2].setString(Texts[2]);
}
//_______________________________________
const Text Screen::createText(Vector2f pos, unsigned int size,
						string name, Color color)const
{
	Text text(name, Resources::instance().getFont(),size);
	text.setFillColor(color);
	text.setPosition(pos);

	return text;
}
//_______________________________________________
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

//_________________________________________________
void Screen::drawGameOver(RenderWindow& window)const
{
	Text text = createText({ 250, 300 }, 250, "Game Over", Color::Red);
	Clock clock;
	while (clock.getElapsedTime().asSeconds() < 1)
	{
		window.draw(text);
		window.display();
	}
}
//_________________________________________________
void Screen::drawUserWon(RenderWindow& window)const
{
	Text text = createText({ 250, 300 }, 250, "You Win!", Color::Red);
	Clock clock;
	while (clock.getElapsedTime().asSeconds() < 1)
	{
		window.draw(text);
		window.display();
	}
}