#include <vector>
#include <SFML/Graphics.hpp>
#include "macros.hpp"
#include "Resources.hpp"


class Window
{
public :
	Widow();
	void stepsCounter() { m_steps++; }
private:
	int m_steps = 0;
	Text createText(Vector2f& pos);
	std::vector<Text> m_boardTexts;
	std::vector<std::vector<Vector2f>> m_levels;
	std::vector<std::string> Texts = { "Circle The Cat", "Level: ", "Steps: " };
};