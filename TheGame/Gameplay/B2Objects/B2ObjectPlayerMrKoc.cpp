#include "Engine/System/Utils_b2d.h"
#include "B2Object.h"

B2ObjectPlayerMrKoc::B2ObjectPlayerMrKoc(B2OBJECT_ARGS, b2World& world, sf::Texture* texture) : B2ObjectPlayer(position, size, type, world, texture), texture(texture)
{
	const b2Vec2& p = Utils_b2d::xy_to_b2v(position.x, position.y);

	b2PolygonShape box;

	const b2Vec2& s = Utils_b2d::v2f_to_b2v(size) / 2.f;
	box.SetAsBox(s.x, s.y);
	this->size = size;

	b2FixtureDef fixturedef;
	fixturedef.shape = &box;
	fixturedef.density = 1.0f;
	fixturedef.friction = 1.0f;
	fixturedef.restitution = 1.0f;

	body = world.CreateBody(&bodydef);

	body->CreateFixture(&fixturedef);
	body->SetFixedRotation(true);
	body->SetGravityScale(0);

	shape.setSize(this->size);
	shape.setTexture(texture);
	shape.setOrigin(size / 2.f);
	shape.setScale(1, -1);
}

void B2ObjectPlayerMrKoc::Render(const sf::Texture* texture)
{
	System::window->draw(shape);
}

void B2ObjectPlayerMrKoc::Action()
{

}

void B2ObjectPlayerMrKoc::Update(const b2World& world)
{
	// Влияние ветра на тело игрока
	const b2Vec2 force = Utils_b2d::DicectionToCursor(body);
	const float32 distance = b2Distance(body->GetWorldCenter(), Utils_b2d::v2f_to_b2v(System::cursor_world)) * SCALE_B2D;

	if (distance > 60) body->ApplyForce(b2Vec2(force.x * distance, force.y * distance), body->GetWorldCenter(), true);
	else body->ApplyLinearImpulse(Utils_b2d::DicectionToCursor(body), body->GetWorldCenter(), false);

	shape.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	shape.setRotation(body->GetAngle() * RAD_TO_DEG);
}

B2ObjectPlayerMrKoc::~B2ObjectPlayerMrKoc() {}