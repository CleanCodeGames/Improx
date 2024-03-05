#pragma once
#include "Engine/System/System.h"

CLASSDECL(B2Object,
public:
	B2Object(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, const sf::Texture& texture);
	virtual void Update(b2World& world);
	virtual void Render();
	const sf::Texture& texture;
	sf::Vector2f size;
	b2Body *body;
	b2BodyDef bodydef;
	virtual ~B2Object();
)