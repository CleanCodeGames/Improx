#pragma once
#include "System.h"

class Utils_b2d
{
public:

    // Перевод b2Vec2 Box2d в SFML возврат значения
    static const sf::Vector2f b2v_to_v2f(const b2Vec2& b2v2);
    // Перевод float xy Box2d в SFML возврат значения
    static const sf::Vector2f xy_to_v2f(const float32& x, const float32& y);
    // Перевод Vector2f SFML в b2Vec2 возврат значения
    static const b2Vec2 v2f_to_b2v(const sf::Vector2f& v2f);
    // Перевод float xy SFML в b2Vec2 возврат значения
    static const b2Vec2 xy_to_b2v(const float32& x, const float32& y);
    // Прямая конвертация координат SFML в Box2d
    static void CoordsConvert(sf::Vector2f& sf_point);
    // Прямая конвертация координат Box2d в SFML
    static void CoordsConvert(b2Vec2& b2_point);
    // Нормализованный вектор направления от тела до глобального курсора мыши
    static const b2Vec2 DicectionToCursor(b2Body* body);
    // Создание статичного бокса (depricated)
    static b2Body* CreateStaticBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size);

};

