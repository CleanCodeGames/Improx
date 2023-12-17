#include "Geometry.h"

const float Geometry::Distance(const sf::Vector2f& start_position, const sf::Vector2f& end_position)
{
    const sf::Vector2f diff = end_position - start_position;
    return hypotf(diff.x, diff.y);
}

const float Geometry::Angle(const sf::Vector2f& start_position, const sf::Vector2f& end_position)
{
    return atan2f(end_position.y - start_position.y, end_position.x - start_position.x) * DEG_TO_RAD;
}

const sf::Vector2f Geometry::Normalized(const sf::Vector2f& position, const float& dist, const float& angle)
{
    const float& A = { angle * RAD_TO_DEG };
    return position + sf::Vector2f(std::cosf(A), std::sinf(A)) * dist;
}

const sf::Vector2f Geometry::BezierGetPoint( const sf::Vector2f& position_1, const sf::Vector2f& position_2, const sf::Vector2f& position_3, const sf::Vector2f& position_4, float step)
{
    step = std::clamp(step, 0.f, 1.f);
    const float &dist = 1.f - step;
    const sf::Vector2f &result =
    {
        dist * dist * dist * position_1 +
        3.f * dist * dist * step * position_2 +
        3.f * dist * step * step * position_3 +
        step * step * step * position_4
    };
    return result;
}