#include "Gameplay/Game.h"
#include "Gameplay/Objects/B2Object.h"
#include "Gameplay/Player/Player.h"
//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

int main() 
{
    System::Initialization();
    //std::vector<b2Body*> boxes;
    std::vector<B2Object> boxes;
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

    Player player(world, sf::Vector2f(0, 0), sf::Vector2f(125, 125), b2BodyType::b2_dynamicBody, *TEXTURE("qqq"));
    
    while (System::window->isOpen()) 
    {
        System::Update();
        gravity_factor += System::time_elapsed;
        world.SetGravity(b2Vec2(gravity.x * std::cosf(gravity_factor), gravity.y * std::sinf(gravity_factor)));
        System::window->setView(*System::camera);
        world.Step(System::time_elapsed, 8, 3);

        while (System::window->pollEvent(*System::event))
        {
            if (System::event->type == sf::Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                sf::Vector2f size(float32(15.f + rand() % 40), float32(15.f + rand() % 40));
                boxes.push_back(B2Object(world, System::cursor_world, size, b2BodyType::b2_dynamicBody, *TEXTURE("test")));
            }
            player.Action();
        }

        System::window->clear();

        for (auto& box : boxes)
        {
            box.Update(world);
            box.Render();
        }

        static sf::Color color(255,255,255);
        for (b2Contact* contact = world.GetContactList(); contact; contact = contact->GetNext())
        {
            if (contact->IsTouching())
            {
                static int count = 0;
                count++;
                color.g = 0;
                color.b = 0;
                std::cout << "Contact #" << count << std::endl;
            }
        }

        if (color.g < 255) color.g++;
        if (color.b < 255) color.b++;
        player.shape.setFillColor(color);
        player.Update(world);
        player.Render();

        for (auto& shape : stayblock)
            System::window->draw(shape);

        System::window->display();
    }
    return 0;
}