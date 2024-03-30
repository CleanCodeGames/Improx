#pragma once
#include "Engine/System/System.h"

#define B2OBJECT_INHERITANCE B2Object(position, size, type)
#define B2OBJECT_ARGS const sf::Vector2f& position, const sf::Vector2f& size, const b2BodyType type
#define B2OBJECT_DECL(CLASS) CLASS(B2OBJECT_ARGS); virtual void Update(const b2World& world); virtual void Render(const sf::Texture* texture = nullptr); virtual ~CLASS();
#define B2OBJECT_DECL_ADDITION(CLASS, ...) CLASS(B2OBJECT_ARGS, __VA_ARGS__); virtual void Update(const b2World& world); virtual void Render(const sf::Texture* texture = nullptr); virtual ~CLASS();

/* 
* * * * * * B2Object * * * * * * *	
* 
* B2ObjectBox			: B2Object	// Твёрдый ящик
* B2ObjectCircle		: B2Object	// Твёрдый круг
* B2ObjectChain			: B2Object
* B2ObjectElasticRope	: B2Object
* B2ObjectFanBlower		: B2Object
* ∙
* * * * * B2ObjectPlayer * * * * *
* ∙
* B2ObjectPlayer		: B2Object			// Игрок без реализации
* B2ObjectPlayerMrKoc	: B2ObjectPlayer	// MrKoc
* B2ObjectPlayerMrEsc	: B2ObjectPlayer	// MrEscow
*/

CLASSDECL(B2Object,
public: B2OBJECT_DECL(B2Object)
sf::Vector2f size; b2Body *body; b2BodyDef bodydef;
)

CLASSDECL_INHERITANCE(B2ObjectPlayer, B2Object,
public:
	B2OBJECT_DECL_ADDITION(B2ObjectPlayer, b2World& world, sf::Texture* texture = nullptr)
		sf::RectangleShape shape;
	sf::Texture* texture;
	void Action();
	)

CLASSDECL_INHERITANCE(B2ObjectPlayerMrKoc, B2ObjectPlayer,
public: 
	B2OBJECT_DECL_ADDITION(B2ObjectPlayerMrKoc, b2World& world, sf::Texture* texture = nullptr)
	sf::RectangleShape shape;
	sf::Texture* texture;
	void Action();
)

CLASSDECL_INHERITANCE(B2ObjectPlayerMrEsc, B2ObjectPlayer,
public:
	B2OBJECT_DECL_ADDITION(B2ObjectPlayerMrEsc, b2World& world, sf::Texture* texture = nullptr)
		sf::RectangleShape shape;
	sf::Texture* texture;
	void Action();
	)

CLASSDECL_INHERITANCE(B2ObjectBox, B2Object,
public: 
	B2OBJECT_DECL_ADDITION(B2ObjectBox, b2World& world)
)

CLASSDECL_INHERITANCE(B2ObjectCircle, B2Object,
	public:
		B2OBJECT_DECL_ADDITION(B2ObjectCircle, b2World& world)
)

CLASSDECL_INHERITANCE(B2ObjectChain, B2Object,
public: 
	B2OBJECT_DECL_ADDITION(B2ObjectChain, b2World& world)
)

CLASSDECL_INHERITANCE(B2ObjectElasticRope, B2Object,
public: 
	B2OBJECT_DECL_ADDITION(B2ObjectElasticRope, b2Body* bodyA, b2Body* bodyB, const size_t segments_count, b2World& world)
	b2RopeJoint* rope_joint;
	b2RopeJointDef rope_joint_def;

	b2Body* bodyA;
	b2Body* bodyB;

	std::vector<B2ObjectCircle> vec_rope_segments;
	size_t segments_count;
)

CLASSDECL_INHERITANCE(B2ObjectFanBlower, B2Object,
public:
	std::vector<B2ObjectBox> vec_boxes;
	const float angular_velocity;
	B2OBJECT_DECL_ADDITION(B2ObjectFanBlower, b2World& world, float32 angular_velocity)
)