#include "Player.h"

Player::Player(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, const sf::Texture& texture) 
	: B2Object(world, position, size, type, texture)
{

}

void Player::Update(b2World& world)
{
}


void Player::Render()
{

}

void Player::Action()
{

}

Player::~Player()
{

}