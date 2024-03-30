#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"

B2ObjectBox::B2ObjectBox(B2OBJECT_ARGS, b2World& world) : B2OBJECT_INHERITANCE
{
	body = world.CreateBody(&bodydef);

	b2PolygonShape box;
	const b2Vec2& s = Utils_b2d::v2f_to_b2v(size) / 2.f;
	box.SetAsBox(s.x, s.y);


	b2FixtureDef fd;
	fd.shape = &box;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;

	body->CreateFixture(&fd);
}

void B2ObjectBox::Update(const b2World& world)
{

}

void B2ObjectBox::Render(const sf::Texture* texture)
{
	sf::Image image;
	image.create(size.x, size.y);
	sf::RectangleShape shape(size);
	if(texture)
		shape.setTexture(texture);
	shape.setOrigin(size / 2.f);
	shape.setScale(1, -1);
	shape.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	shape.setRotation(body->GetAngle() * RAD_TO_DEG);
	System::window->draw(shape);
}

B2ObjectBox::~B2ObjectBox()
{
}