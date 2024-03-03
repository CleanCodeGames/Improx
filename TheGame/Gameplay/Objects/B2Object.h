#pragma once
#include "Engine/System/System.h"

CLASSDECL(B2ObjectBox,

public:

	B2ObjectBox(
		b2World& world, 
		const sf::Vector2f& position, 
		const sf::Vector2f& size, 
		const b2BodyType type,
		const sf::Texture& texture
	);

	void Update(b2World& world);
	void Render();

	const sf::Texture& texture;
	sf::Vector2f size;
	b2Body *body;
	b2BodyDef bodydef;
	~B2ObjectBox();
)