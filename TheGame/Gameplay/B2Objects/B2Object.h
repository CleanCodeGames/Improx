#pragma once
#include "Engine/System/System.h"

/*
* B2Object
* B2ObjectBox : B2Object
* B2ObjectPlayer : B2Object
*/

#define B2OBJECT_IMPL B2Object(position, size, type)
#define B2OBJECT_ARGS const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type
CLASSDECL(B2Object,
public:
	B2Object(B2OBJECT_ARGS);
	virtual void Update(const b2World& world);
	virtual void Render(const sf::Texture* texture = nullptr);
	virtual ~B2Object();

protected:
	sf::Vector2f size;
	b2Body *body;
	b2BodyDef bodydef;
)

CLASSDECL_INHERITANCE(B2ObjectBox, B2Object,
public:
	B2ObjectBox(b2World& world, B2OBJECT_ARGS);
	virtual void Update(const b2World& world) override;
	virtual void Render(const sf::Texture* texture = nullptr) override;
	virtual ~B2ObjectBox() override;
)

CLASSDECL_INHERITANCE(B2ObjectPlayer, B2Object,
public:
	sf::RectangleShape shape;
	sf::Texture* texture;
	B2ObjectPlayer(b2World& world, B2OBJECT_ARGS, sf::Texture* texture);
	virtual void Update(const b2World& world) override;
	virtual void Render(const sf::Texture* texture = nullptr) override;
	virtual void Action();
	virtual ~B2ObjectPlayer() override;
)

CLASSDECL_INHERITANCE(B2ObjectChain, B2Object,
public:
	B2ObjectChain(b2World& world, B2OBJECT_ARGS);
	virtual void Update(const b2World& world) override;
	virtual void Render(const sf::Texture* texture = nullptr) override;
	virtual ~B2ObjectChain() override;
)