#include "Board.hpp"

//____________
Board::Board()
{
	setFonts();
	setBoard();
}
//___________________
void Board::setBoard()
{
	Vector2f pos = { 30, 110 };
	for (size_t i = 0; i < BoardSize; i++) {
		std::vector<CircleShape> circleRow;
		for (size_t j = 0; j < BoardSize; j++)
		{
			CircleShape circle = createCircle(pos);
			circleRow.push_back(circle);
			pos.x += X_CircleDistance;
		}
		m_board.push_back(circleRow);
		pos.y += Y_CircleDistance;
		if (i % 2 == 0)
			pos.x = CircleLeftOddDistance;
		else
			pos.x = CircleLeftEvenDistance;
	}
}
//___________________________________________
CircleShape Board::createCircle(Vector2f& pos)
{
	CircleShape circle(CircleSize);
	circle.setPosition(pos);
	circle.setFillColor(Color{ 0, 255, 0, 127 });
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(3);
	
	return circle;
}
//___________________
void Board::setFonts()
{
	Vector2f pos = { 300, 0 };

	for (size_t i = 0; i < Texts.size(); i++)
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
//__________________________________
Text Board::createText(Vector2f& pos)
{
	Text text;
	text.setFont(Resources::instance().getFont());
	text.setCharacterSize(FontSize);
	text.setFillColor(Color::Black);
	text.setPosition(pos);

	return text;
}
//______________________________________________
void Board::drawBoard(RenderWindow& window)const
{
	for (auto i : m_boardTexts)
		window.draw(i);

	for (auto i : m_board)
		for (auto j : i)
			window.draw(j);
}
//____________________________________
void Board::findMovement(Vector2f& loc)
{
	for (auto& row : m_board)
	{
		for (auto& circle : row)
		{
			if (circle.getGlobalBounds().contains(loc))
			{
				circle.getFillColor() == Color::Black ?
					circle.setOutlineColor(Color{ 255, 0, 0, 127 }) :
					circle.setOutlineColor(Color{ 0, 0, 255, 127 });
				circle.setOutlineThickness(4);
				return;
			}
			else
			{
				circle.setOutlineColor(Color::Black);
				circle.setOutlineThickness(3);
			}
		}
	}
}
//_________________________________
void Board::findClick(Vector2f& loc)
{
	for (auto& row : m_board)
		for (auto& circle : row)
			if (circle.getGlobalBounds().contains(loc))
			{
				if (circle.getFillColor() == Color::Black)
					return;
				else
					stepsCounter();
				circle.setFillColor(Color::Black);
				setSteps();
				return;
			}
}
//____________________
void Board::setSteps()
{
	Texts[2].replace(7, std::to_string(m_steps).size(), std::to_string(m_steps));
	m_boardTexts[2].setString(Texts[2]);
}