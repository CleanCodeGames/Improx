#include "Gameplay/Game.h"

//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

int main() 
{
    System::Initialization();
    std::vector<b2Body*> boxes;
    b2World world(b2Vec2(0.0f, -9.8f));
    Utils_b2d::CreateStaticBox(world, sf::Vector2f(0, 200), sf::Vector2f(600, 25));
    

    sf::RectangleShape stayblock(sf::Vector2f(600, 25));
    stayblock.setFillColor(sf::Color::Blue);
    stayblock.setOrigin(stayblock.getSize() / 2.f);
    stayblock.setPosition(sf::Vector2f(0, 200));
    
    while (System::window->isOpen()) 
    {
        System::Update();
        System::camera->rotate(5.f * System::time_elapsed);
        System::window->setView(*System::camera);
        world.Step(System::time_elapsed, 8, 3);
        
        while (System::window->pollEvent(*System::event))
        {
            if (System::event->type == sf::Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                boxes.push_back(Utils_b2d::CreateDynamicBox(world, sf::Vector2f(System::cursor_world.x, System::cursor_world.y), sf::Vector2f(30, 30)));
            }

            if (Input::Mouse::Pressed(sf::Mouse::Right))
            {
                Utils_b2d::ClearDynamicBoxes(world, boxes);
            }

            if (Input::Keyboard::Pressed(sf::Keyboard::A)) boxes.back()->ApplyLinearImpulse(b2Vec2(-1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(sf::Keyboard::S)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, 1), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(sf::Keyboard::D)) boxes.back()->ApplyLinearImpulse(b2Vec2(1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(sf::Keyboard::W)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, -1), boxes.back()->GetWorldCenter(), false);
        }

        System::window->clear();

        Utils_b2d::UpdateDynamicBoxes(boxes);
        System::window->draw(stayblock);
        System::window->display();
    }
    return 0;
}