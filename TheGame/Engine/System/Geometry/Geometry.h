#pragma once
#include "../Overhead.h"

class Geometry
{
private:

    Geometry() = delete;
    ~Geometry() = default;

public:

    static const float Distance (const sf::Vector2f& start_position, const sf::Vector2f& end_position);
    static const float Angle    (const sf::Vector2f& start_position, const sf::Vector2f& end_position);
    static const sf::Vector2f Normalized(const sf::Vector2f& position, const float& distance, const float& angle);

    static const sf::Vector2f BezierGetPoint(
        const sf::Vector2f& position_1, 
        const sf::Vector2f& position_2, 
        const sf::Vector2f& position_3, 
        const sf::Vector2f& position_4, 
        float step
    );
};