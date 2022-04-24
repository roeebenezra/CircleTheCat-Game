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
}
