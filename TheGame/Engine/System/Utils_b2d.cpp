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

const b2Vec2 operator / (const b2Vec2& lhs, const float& rhs)
{
    b2Vec2 result;
    result.x = lhs.x / rhs;
    result.y = lhs.y / rhs;
    return result;
}

const b2Vec2& operator /= (b2Vec2& lhs, const float& rhs)
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}