#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"
B2ObjectBox::B2ObjectBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, const sf::Texture& texture) : texture(texture)
{
	b2Vec2 p = Utils_b2d::xy_to_b2v(position.x, position.y);

	bodydef.type = type;
	bodydef.position.Set(p.x, p.y);

	body = world.CreateBody(&bodydef);

	b2PolygonShape box;
	box.SetAsBox(size.x / SCALE_B2D / 2.f, size.y / SCALE_B2D / 2.f);
	this->size = size;

	b2FixtureDef fd;
	fd.shape = &box;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;

	body->CreateFixture(&fd);
}

void B2ObjectBox::Update(b2World& world)
{

}

void B2ObjectBox::Render()
{
	sf::RectangleShape shape(size);
	shape.setTexture(&texture);
	shape.setOrigin(size / 2.f);
	shape.setScale(1, -1);
	shape.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	shape.setRotation(body->GetAngle() * RAD_TO_DEG);
	System::window->draw(shape);
}

B2ObjectBox::~B2ObjectBox()
{
}
