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
}
