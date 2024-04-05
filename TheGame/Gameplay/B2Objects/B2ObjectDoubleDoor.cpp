#include "B2Object.h"
#include"Engine/System/Utils_b2d.h"

B2ObjectDoubleDoor::B2ObjectDoubleDoor(B2OBJECT_ARGS, b2World& world, bool is_open) :
	B2OBJECT_INHERITANCE,
	is_open(is_open),
	box_doors
	{
		{ position, size, type, world }, 
		{ position, size, type, world }
	}
{

}

void B2ObjectDoubleDoor::Update(const b2World& world)
{

}

void B2ObjectDoubleDoor::Close()
{
	is_open = false;
}

void B2ObjectDoubleDoor::Open()
{
	is_open = true;
}

void B2ObjectDoubleDoor::Render(const sf::Texture* texture)
{
	box_doors[0].Render(texture);
	box_doors[1].Render(texture);
}

B2ObjectDoubleDoor::~B2ObjectDoubleDoor() {}