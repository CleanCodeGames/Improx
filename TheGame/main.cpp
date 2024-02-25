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
    b2Vec2 gravity(9.8f, 9.8f);
    float32 gravity_factor = 0.f;
    b2World world(gravity);
    Utils_b2d::CreateStaticBox(world, sf::Vector2f(0, 300), sf::Vector2f(600, 25));
    Utils_b2d::CreateStaticBox(world, sf::Vector2f(0, -300), sf::Vector2f(600, 25));
    Utils_b2d::CreateStaticBox(world, sf::Vector2f(300, 0), sf::Vector2f(25, 600));
    Utils_b2d::CreateStaticBox(world, sf::Vector2f(-300, 0), sf::Vector2f(25, 600));

    sf::RectangleShape stayblock[4] = { 
        sf::RectangleShape(sf::Vector2f(600, 25)), 
        sf::RectangleShape(sf::Vector2f(600, 25)), 
        sf::RectangleShape(sf::Vector2f(25, 600)), 
        sf::RectangleShape(sf::Vector2f(25, 600)) 
    };

    stayblock[0].setPosition(sf::Vector2f(0, 300));
    stayblock[1].setPosition(sf::Vector2f(0, -300));
    stayblock[2].setPosition(sf::Vector2f(300, 0));
    stayblock[3].setPosition(sf::Vector2f(-300, 0));

    for (auto& shape : stayblock)
    {
        shape.setFillColor(sf::Color::Blue);
        shape.setOrigin(shape.getSize() / 2.f);
    }
    
    while (System::window->isOpen()) 
    {
        System::Update();
        gravity_factor += System::time_elapsed;
        world.SetGravity(b2Vec2(gravity.x * std::cosf(gravity_factor), gravity.y * std::sinf(gravity_factor)));
        //System::camera->rotate(5.f * System::time_elapsed);
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
        for (auto& shape : stayblock)
            System::window->draw(shape);
        System::window->display();
    }
    return 0;
}