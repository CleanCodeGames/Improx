#include "Engine/System/Utils_b2d.h"
#include "B2Object.h"

B2ObjectPlayerMrVol::B2ObjectPlayerMrVol(B2OBJECT_ARGS, b2World& world, sf::Texture* texture) : B2ObjectPlayer(position, size, type, world, texture)
{
	// why?
}

void B2ObjectPlayerMrVol::Action()
{

}

void B2ObjectPlayerMrVol::Render(const sf::Texture* texture)
{
	sf::RectangleShape shape(size);
	if (texture)
		shape.setTexture(texture);
	System::window->draw(shape);
}

void B2ObjectPlayerMrVol::Update(const b2World& world)
{

}

B2ObjectPlayerMrVol::~B2ObjectPlayerMrVol() {}