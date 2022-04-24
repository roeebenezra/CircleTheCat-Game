#include "Board.hpp"

Board::Board()
{
	setBoard();
}

//____________________
void Board::setBoard()
{
	setFonts();
	Vector2f pos = { 20, 110 };
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
		if (i % 2 == 0) pos.x = CircleLeftOddDistance;
		else pos.x = CircleLeftEvenDistance;
	}
}

//____________________________________________
CircleShape Board::createCircle(Vector2f& pos)
{
	CircleShape circle(CircleSize);
	circle.setPosition(pos);
	circle.setFillColor(Color::Green);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(3);

	return circle;
}
//___________________
void Board::setFonts()
{
	Vector2f pos = { 350, 0 };
	
	for (size_t i = 0; i < Texts.size() ; i++)
	{
		if (i == 1) pos.x += X_TextAdd;
		if (i > 0)  pos.y += Y_TextAdd;
		Text text = createText(pos);
		text.setString(Texts[i]);
		m_boardTexts.push_back(text);
	}
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
void Board::drawBoard(RenderWindow &window)const 
{
	for (auto i : m_boardTexts)
		window.draw(i);

	for (auto i : m_board)
	{
		for (auto j : i)
			window.draw(j);
	}
}
