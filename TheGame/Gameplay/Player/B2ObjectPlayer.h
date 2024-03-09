#pragma once
#include "Gameplay/Objects/B2Object.h"

CLASSDECL_INHERITANCE(B2ObjectPlayer, B2Object,
public:
	sf::RectangleShape shape;
	sf::Texture* texture;
	B2ObjectPlayer(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, sf::Texture* texture);
	virtual void Update(const b2World& world) override;
	virtual void Render(const sf::Texture* texture = nullptr) override;
	virtual void Action();
	virtual ~B2ObjectPlayer() override;
)