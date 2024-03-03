#pragma once
#include "System.h"

class Utils_b2d
{
public:

    // ������� SFML � Box2d �� ������
    static void CoordsConvert(sf::Vector2f& sf_point);
    // ������� Box2d � SFML �� ������
    static void CoordsConvert(b2Vec2& b2_point);

    // ������� b2Vec2 Box2d � SFML ������� ��������
    static const sf::Vector2f b2v_to_v2f(const b2Vec2& b2v2);
    // ������� float xy Box2d � SFML ������� ��������
    static const sf::Vector2f xy_to_v2f(const float32& x, const float32& y);

    // ������� Vector2f SFML � b2Vec2 ������� ��������
    static const b2Vec2 v2f_to_b2v(const sf::Vector2f& v2f);
    // ������� float xy SFML � b2Vec2 ������� ��������
    static const b2Vec2 xy_to_b2v(const float32& x, const float32& y);
    
    static b2Body* CreateStaticBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size);
    static b2Body* CreateDynamicBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size);

    static void UpdateDynamicBoxes(const std::vector<b2Body*>& boxes);
    static void ClearDynamicBoxes(b2World& world, std::vector<b2Body*>& vec_bodies);
};

