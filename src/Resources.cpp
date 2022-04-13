#include "Resources.hpp"

//____________________
Resources::Resources()
{
	loadResources();
}
//____________________________
Resources& Resources::instance()
{
	static auto resource = Resources();
	return resource;
}
//_____________________________
void Resources::loadResources()
{
	if (!m_texture.loadFromFile("board.png"))
		std::cout << "fail to load board\n";
	m_sprite.setTexture(m_texture);
}
