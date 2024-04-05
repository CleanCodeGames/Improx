#include "B2Object.h"
#include"Engine/System/Utils_b2d.h"

B2ObjectSingleDoor::B2ObjectSingleDoor(B2OBJECT_ARGS, b2World& world, bool is_open) : 
	B2OBJECT_INHERITANCE, 
	is_open(is_open), 
	box_door(position, size, type, world)
{
	b2PolygonShape box;
	const b2Vec2& s = Utils_b2d::v2f_to_b2v(size) / 2.f;
	body = world.CreateBody(&bodydef);
	b2FixtureDef fd;
	fd.shape = &box;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;
	body->CreateFixture(&fd);
}

void B2ObjectSingleDoor::Update(const b2World& world)
{
	if (is_open)
	{

	}
	else 
	{

	}
}

void B2ObjectSingleDoor::Close()
{
	is_open = false;
}

void B2ObjectSingleDoor::Open()
{
	is_open = true;
}

void B2ObjectSingleDoor::Render(const sf::Texture* texture)
{
	box_door.Render(texture);
}

B2ObjectSingleDoor::~B2ObjectSingleDoor() {}