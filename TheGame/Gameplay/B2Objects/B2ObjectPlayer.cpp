#include "B2Object.h"
#include "Engine/System/Utils_b2d.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"
// Без реализации
B2ObjectPlayer::B2ObjectPlayer(B2OBJECT_ARGS, b2World& world, sf::Texture* texture) : B2OBJECT_INHERITANCE, texture(texture) {}
void B2ObjectPlayer::Update(const b2World& world) {}
void B2ObjectPlayer::Render(const sf::Texture* texture) {}
void B2ObjectPlayer::Action() {}
B2ObjectPlayer::~B2ObjectPlayer() {}