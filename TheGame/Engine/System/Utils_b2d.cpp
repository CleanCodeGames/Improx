#include "Utils_b2d.h"

void Utils_b2d::CoordsConvert(sf::Vector2f& sf_point)
{
    sf_point /= SCALE_B2D;
}
void Utils_b2d::CoordsConvert(b2Vec2& b2_point)
{
    b2_point *= SCALE_B2D;
}
const sf::Vector2f Utils_b2d::b2v_to_v2f(const b2Vec2& b2v2)
{
    sf::Vector2f v2f(b2v2.x * SCALE_B2D, b2v2.y * SCALE_B2D);
    return v2f;
}
const sf::Vector2f Utils_b2d::xy_to_v2f(const float32& x, const float32& y)
{
    sf::Vector2f v2f(x * SCALE_B2D, y * SCALE_B2D);
    return v2f;
}
const b2Vec2 Utils_b2d::v2f_to_b2v(const sf::Vector2f& v2f)
{
    b2Vec2 b2v2(v2f.x / SCALE_B2D, v2f.y / SCALE_B2D);
    return b2v2;
}
const b2Vec2 Utils_b2d::xy_to_b2v(const float32& x, const float32& y)
{
    b2Vec2 b2v2(x / SCALE_B2D, y / SCALE_B2D);
    return b2v2;
}

const b2Vec2 Utils_b2d::DicectionToCursor(b2Body* body)
{
    b2Vec2 direction = body->GetPosition() - v2f_to_b2v(System::cursor_world);
    direction.Normalize();
    return -direction;
}

b2Body* Utils_b2d::CreateStaticBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size)
{
    b2BodyDef bodydef;
    b2Vec2 pos = xy_to_b2v(position.x, position.y);
    bodydef.position.Set(pos.x, pos.y);
    b2Body* body = world.CreateBody(&bodydef);
    b2PolygonShape groundbox;
    groundbox.SetAsBox(size.x / SCALE_B2D / 2, size.y / SCALE_B2D / 2);
    body->CreateFixture(&groundbox, 1.0f);
    body->SetUserData(const_cast<char*>("static_box"));
    return body;
}