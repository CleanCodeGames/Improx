#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Gameplay/Objects/B2Object.h"

CLASSDECL_INHERITANCE(Player, B2Object,
public:
	sf::RectangleShape shape;
	Player(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type, const sf::Texture& texture);
	void Update(b2World& world) override;
	void Render() override;
	virtual void Action();
	~Player() override;
)