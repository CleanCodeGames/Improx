#include "B2Object.h"

B2ObjectFanBlower::B2ObjectFanBlower(B2OBJECT_ARGS, b2World& world, float32 angular_velocity) : B2OBJECT_INHERITANCE, angular_velocity(angular_velocity) 
{
	vec_boxes.push_back({ position, size, type, world });
	vec_boxes.push_back({ position, size, type, world });
	b2Body* b[2] = { vec_boxes[0].body, vec_boxes[1].body };
	b[0]->SetTransform(b[0]->GetPosition(), 90.f * DEG_TO_RAD);
	b[0]->SetAngularVelocity(angular_velocity);
	b[1]->SetAngularVelocity(angular_velocity);
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