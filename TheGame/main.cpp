#include "Gameplay/Game.h"

//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

using namespace sf;
using namespace std;

const sf::Vector2f b2Vec2ToVector2f(const b2Vec2& b2v2)
{
    sf::Vector2f v2f;
    v2f.x = b2v2.x * SCALE_B2D;
    v2f.y = -b2v2.y * SCALE_B2D;
    return v2f;
}

const b2Vec2 Vec2fTob2Vec2(const sf::Vector2f& vec)
{
    b2Vec2 b2v2;
    b2v2.x = vec.x / SCALE_B2D;
    b2v2.y = -vec.y / SCALE_B2D;
    return b2v2;
}

// ƒл€ координат ( дл€ размеров не нужен отрицательный Y)
const b2Vec2 xy2fTob2Vec2(const float& x, const float& y)
{
    b2Vec2 b2v2;
    b2v2.x = x / SCALE_B2D;
    b2v2.y = -y / SCALE_B2D;
    return b2v2;
}

b2Body* CreateStaticBox(b2World& world)
{
    b2BodyDef bodydef;
    b2Vec2 pos = xy2fTob2Vec2(400, 350);
    bodydef.position.Set(pos.x, pos.y);
    b2Body* body = world.CreateBody(&bodydef);
    b2PolygonShape groundbox;

    b2Vec2 size = xy2fTob2Vec2(300, 10);
    groundbox.SetAsBox(size.x, -size.y);
    body->CreateFixture(&groundbox, 1.0f);
    body->SetUserData(const_cast<char*>("static_box"));
    return body;
}

b2Body* CreateDynamicBox(b2World& world, float x, float y)
{
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(x, y);

    b2Body* body = world.CreateBody(&bodydef);

    b2PolygonShape box;
    box.SetAsBox(10.f / SCALE_B2D, 10.f / SCALE_B2D);

    b2FixtureDef fixdef;
    fixdef.shape = &box;
    fixdef.density = 0.8f;
    fixdef.friction = 0.1f;
    fixdef.restitution = 0.8f;

    body->CreateFixture(&fixdef);
    int color = rand() % 4;
    switch (color)
    {
    case 0: body->SetUserData(const_cast<char*>("yellow")); break;
    case 1: body->SetUserData(const_cast<char*>("red")); break;
    case 2: body->SetUserData(const_cast<char*>("magenta")); break;
    case 3: body->SetUserData(const_cast<char*>("cyan")); break;
    }
    std::cout << static_cast<char const*>(body->GetUserData()) << std::endl;
    return body;
}

int main() 
{
    System::Initialization();
    System::window->close();

    vector<b2Body*> boxes;
    b2World world(b2Vec2(0.0, -9.8));

    RenderWindow window(VideoMode(800, 600), "Blocks");
    CreateStaticBox(world);
    Clock clock;
    

    RectangleShape stayblock(Vector2f(600, 20));
    stayblock.setFillColor(Color::Blue);
    stayblock.setOrigin(stayblock.getSize() / 2.f);
    stayblock.setPosition(sf::Vector2f(400, 350));

    RectangleShape block(Vector2f(20, 20));
    block.setFillColor(Color::White);

    while (window.isOpen()) 
    {
        System::time_elapsed = clock.getElapsedTime().asSeconds();
        clock.restart();
        world.Step(System::time_elapsed, 8, 3);
          
        while (window.pollEvent(*System::event)) 
        {
            if (System::event->type == Event::Closed)
                window.close();

            if ((System::event->type == System::event->MouseButtonPressed) && Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i a = Mouse::getPosition(window);
                b2Vec2 c = xy2fTob2Vec2(a.x, a.y);
                boxes.push_back(CreateDynamicBox(world, c.x, c.y));
            }
            if (Input::Keyboard::Pressed(Keyboard::A)) boxes.back()->ApplyLinearImpulse(b2Vec2(-1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::S)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, 1), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::D)) boxes.back()->ApplyLinearImpulse(b2Vec2(1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::W)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, -1), boxes.back()->GetWorldCenter(), false);
        }

        window.clear();

        for (size_t i = 0; i < boxes.size(); i++) 
        {
            block.setOrigin(block.getSize() / 2.f);
            block.setPosition(b2Vec2ToVector2f(boxes[i]->GetPosition()));
            block.setRotation(-boxes[i]->GetAngle() * RAD_TO_DEG);

            if (static_cast<char const*>(boxes[i]->GetUserData()) == "yellow") block.setFillColor(sf::Color::Yellow);
            else if (static_cast<char const*>(boxes[i]->GetUserData()) == "red") block.setFillColor(sf::Color::Red);
            else if (static_cast<char const*>(boxes[i]->GetUserData()) == "magenta") block.setFillColor(sf::Color::Magenta);
            else if (static_cast<char const*>(boxes[i]->GetUserData()) == "cyan") block.setFillColor(sf::Color::Cyan);
            window.draw(block);
        }

        window.draw(stayblock);
        window.display();
    }
    return 0;
}
