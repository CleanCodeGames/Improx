#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"

B2ObjectCircle::B2ObjectCircle(B2OBJECT_ARGS, b2World& world) : B2OBJECT_INHERITANCE
{
	body = world.CreateBody(&bodydef);

	b2CircleShape circle;
	circle.m_radius = Utils_b2d::v2f_to_b2v(size).x;
	circle.m_p = Utils_b2d::v2f_to_b2v(position);
	circle.m_type = b2Shape::Type::e_circle;

	b2FixtureDef fd;
	fd.shape = &circle;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;

	body->CreateFixture(&fd);
}

void B2ObjectCircle::Update(const b2World& world)
{

}

void B2ObjectCircle::Render(const sf::Texture* texture)
{
	sf::CircleShape circle(size.x);
	if (texture)
		circle.setTexture(texture);

	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setScale(1, -1);
	circle.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	circle.setRotation(body->GetAngle() * RAD_TO_DEG);
	System::window->draw(circle);
}

B2ObjectCircle::~B2ObjectCircle()
{

}