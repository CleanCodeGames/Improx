#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"

B2ObjectPlayer::B2ObjectPlayer(B2OBJECT_ARGS, b2World& world, sf::Texture* texture) : B2OBJECT_INHERITANCE, texture(texture)
{
	const b2Vec2& p = Utils_b2d::xy_to_b2v(position.x, position.y);

	b2PolygonShape box;

	const b2Vec2& s = Utils_b2d::v2f_to_b2v(size) / 2.f;
	box.SetAsBox(s.x, s.y);
	this->size = size;

	b2FixtureDef fd;
	fd.shape = &box;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;

	body = world.CreateBody(&bodydef);

	body->CreateFixture(&fd);
	body->SetFixedRotation(true);
	body->SetGravityScale(0);

	shape.setSize(this->size);
	shape.setTexture(texture); 
	shape.setOrigin(size / 2.f);
	shape.setScale(1, -1); 
}

void B2ObjectPlayer::Update(const b2World& world)
{
	// Влияние ветра на тело игрока
	const b2Vec2 force = Utils_b2d::DicectionToCursor(body);
	const float32 distance = b2Distance(body->GetWorldCenter(), Utils_b2d::v2f_to_b2v(System::cursor_world)) * SCALE_B2D;
	
	if(distance > 60) body->ApplyForce(b2Vec2(force.x * distance, force.y * distance), body->GetWorldCenter(), true);
	else body->ApplyLinearImpulse(Utils_b2d::DicectionToCursor(body), body->GetWorldCenter(), false);
	
	shape.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	shape.setRotation(body->GetAngle() * RAD_TO_DEG);
}


void B2ObjectPlayer::Render(const sf::Texture* texture)
{
	System::window->draw(shape);
}

void B2ObjectPlayer::Action()
{

}

B2ObjectPlayer::~B2ObjectPlayer()
{

}