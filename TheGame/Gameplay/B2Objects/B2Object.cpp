#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"

B2Object::B2Object(B2OBJECT_ARGS)
{
	const b2Vec2& p = Utils_b2d::xy_to_b2v(position.x, position.y);
	bodydef.type = type;
	bodydef.position.Set(p.x, p.y);
	this->size = size;
}

void B2Object::Update(const b2World& world) {}
void B2Object::Render(const sf::Texture* texture){}
B2Object::~B2Object() {}

