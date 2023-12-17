#include "Input.h"

bool Input::Keyboard::Pressed(const sf::Keyboard::Key key)
{
    if (System::event->type == sf::Event::KeyPressed)
        if (System::event->key.code == key) 
            return true;

    return false;
}

bool Input::Keyboard::Released(const sf::Keyboard::Key key)
{
    if (System::event->type == sf::Event::KeyReleased)
        if (System::event->key.code == key) 
            return true;

    return false;
}

bool Input::Mouse::Pressed(const sf::Mouse::Button code)
{
    if (System::event->type == sf::Event::MouseButtonPressed)
        if (System::event->key.code == code) 
            return true;

    return false;
}

bool Input::Mouse::Released(const sf::Mouse::Button code)
{
    if (System::event->type == sf::Event::MouseButtonReleased)
        if (System::event->key.code == code) 
            return true;

    return false;
}