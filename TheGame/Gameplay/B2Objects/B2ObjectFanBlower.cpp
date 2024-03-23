#include "B2Object.h"

B2ObjectFanBlower::B2ObjectFanBlower(B2OBJECT_ARGS, b2World& world) : B2OBJECT_INHERITANCE
{
	vec_boxes.push_back({ position, size, type, world });
	vec_boxes.push_back({ position, {size.y, size.x}, type, world});
	b2Body* b[2] = { vec_boxes[0].body, vec_boxes[1].body };

	b[0]->SetAngularVelocity(180.f);
	b[1]->SetAngularVelocity(180.f);
}

void B2ObjectFanBlower::Update(const b2World& world)
{
	vec_boxes[0].Update(world);
	vec_boxes[1].Update(world);
}

void B2ObjectFanBlower::Render(const sf::Texture* texture)
{
	vec_boxes[0].Render(texture);
	vec_boxes[1].Render(texture);
}

B2ObjectFanBlower::~B2ObjectFanBlower()
{

}