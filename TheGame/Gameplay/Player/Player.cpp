#include "Player.h"
#include "Engine/System/Utils_b2d.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"

Player::Player(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, const sf::Texture& texture) 
	: B2Object(world, position, size, type, texture)
{
	const b2Vec2& p = Utils_b2d::xy_to_b2v(position.x, position.y);

	b2PolygonShape box;

	box.SetAsBox(size.x / SCALE_B2D / 2.f, size.y / SCALE_B2D / 2.f);
	this->size = size;

	b2FixtureDef fd;
	fd.shape = &box;
	fd.density = 1.0f;
	fd.friction = 1.0f;
	fd.restitution = 1.0f;

	body->CreateFixture(&fd);
	body->SetFixedRotation(true);
	body->SetGravityScale(0);

	shape.setSize(this->size);
	shape.setTexture(&texture); 
	shape.setOrigin(size / 2.f);
	shape.setScale(1, -1); 
}

void Player::Update(b2World& world)
{
	// Влияние ветра на тело игрока
	const b2Vec2 force = Utils_b2d::DicectionToCursor(body);
	const float32 distance = b2Distance(body->GetWorldCenter(), Utils_b2d::v2f_to_b2v(System::cursor_world)) * SCALE_B2D;

	body->ApplyForce(b2Vec2(force.x * distance, force.y * distance), body->GetWorldCenter(), true);

	// Влияние силы импульса на тело игрока
	//body->ApplyLinearImpulse(Utils_b2d::DicectionToCursor(body), body->GetWorldCenter(), false);
	
	shape.setPosition(Utils_b2d::b2v_to_v2f(body->GetPosition()));
	shape.setRotation(body->GetAngle() * RAD_TO_DEG);
}


void Player::Render()
{
	System::window->draw(shape);
}

void Player::Action()
{
	const b2Vec2& p = body->GetPosition();

	if (Input::Keyboard::Pressed(sf::Keyboard::A))
		body->ApplyLinearImpulse(b2Vec2(-10, 0), b2Vec2(p.x + 30, p.y), true);
	if (Input::Keyboard::Pressed(sf::Keyboard::D))
		body->ApplyLinearImpulse(b2Vec2( 10, 0), b2Vec2(p.x - 30, p.y), true);
	if (Input::Keyboard::Pressed(sf::Keyboard::W))
		body->ApplyLinearImpulse(b2Vec2( 0, 10), b2Vec2(p.x, p.y + 30), true);
	if (Input::Keyboard::Pressed(sf::Keyboard::S))
		body->ApplyLinearImpulse(b2Vec2(0, -10), b2Vec2(p.x, p.y + -30), true);
}

Player::~Player()
{

}