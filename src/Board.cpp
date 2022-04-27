#include "Board.hpp"

//____________
Board::Board()
{
	setBoard();
}
//___________________
void Board::setBoard()
{
	Vector2f pos = { 35, 150 };
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
//______________________________________________
void Board::drawBoard(RenderWindow& window)const
{
	for (auto const &i : m_board)
		for (auto const &j : i)
			window.draw(j);
}
//____________________________________
void Board::findMovement(Vector2f& loc)
{
	for (auto &row : m_board)
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
bool Board::findClick(Vector2f& loc)
{
	for (auto& row : m_board)
		for (auto& circle : row)
			if (circle.getGlobalBounds().contains(loc))
			{
				if (circle.getFillColor() == Color::Black)
					return false;
				else
				{
					circle.setFillColor(Color::Black);
					return true;
				}
			}
	return false;
}
