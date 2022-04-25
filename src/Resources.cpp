#include "Resources.hpp"

//___________________
Resources::Resources()
{
	loadResources();
}
//_____________________________
Resources& Resources::instance()
{
	static auto resource = Resources();
	return resource;
}
//____________________________
void Resources::loadResources()
{
	m_textFont.loadFromFile("FontFile.ttf");
	if (!m_catTexture.loadFromFile("cat.png"))
		std::cout << "fail to load cat\n";
	m_catTexture.setSmooth(true);
	m_catSprite.setTexture(m_catTexture);

}
