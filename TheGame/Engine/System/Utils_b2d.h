#pragma once
#include "System.h"
#define b2sb b2BodyType::b2_staticBody
#define b2db b2BodyType::b2_dynamicBody
#define b2kb b2BodyType::b2_kinematicBody

CLASSDECL(Utils_b2d,
public:
    static const sf::Vector2f b2v_to_v2f(const b2Vec2& b2v2);                 // ������� b2Vec2 Box2d � SFML ������� ��������
    static const sf::Vector2f xy_to_v2f(const float32& x, const float32& y);  // ������� float xy Box2d � SFML ������� ��������
    static const b2Vec2 v2f_to_b2v(const sf::Vector2f& v2f);                  // ������� Vector2f SFML � b2Vec2 ������� ��������
    static const b2Vec2 xy_to_b2v(const float32& x, const float32& y);        // ������� float xy SFML � b2Vec2 ������� ��������
    static void CoordsConvert(sf::Vector2f& sf_point);                        // ������ ����������� ��������� SFML � Box2d
    static void CoordsConvert(b2Vec2& b2_point);                              // ������ ����������� ��������� Box2d � SFML
    static const b2Vec2 DicectionToCursor(b2Body* body);                      // ��������������� ������ ����������� �� ���� �� ����������� ������� ����
)

const b2Vec2 operator / (const b2Vec2& lhs, const float& rhs);
const b2Vec2& operator /= (b2Vec2& lhs, const float& rhs);