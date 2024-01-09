#include "Gameplay/Game.h"

//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

using namespace sf;
using namespace std;

int fps = 0;
float32 ewidth = 80;
float32 ehei = 5;
float32 x = 60;
float32 y = 75;

b2Body* CreateStaticBox(b2World& world)
{
    b2BodyDef earthdef;
    earthdef.position.Set(0.0f, -1.35f);
    b2Body* body = world.CreateBody(&earthdef);
    b2PolygonShape groundbox;
    groundbox.SetAsBox(1.5f, 0.05f);
    body->CreateFixture(&groundbox, 1.0f);
    const char* a[] = { "static_box" };
    body->SetUserData(a);
    return body;
}

b2Body* CreateDynamicBox(b2World& world, float x, float y)
{
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(x, y);

    b2Body* body = world.CreateBody(&bodydef);

    b2PolygonShape box;
   //b2CircleShape circle;
    box.SetAsBox(0.05f, 0.05f);
   //circle.m_radius = 0.05f;

    b2FixtureDef fixdef;
    fixdef.shape = &box;
    fixdef.density = 0.8f;
    fixdef.friction = 0.8f;
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

const Vector2f b2Vec2ToVector2f(const b2Vec2& b2v2) {
    Vector2f v2f;
    v2f.x = b2v2.x * 200 + 400;
    v2f.y = -b2v2.y * 200 + 300;
    return v2f;
}

const b2Vec2 xyTob2Vec2(const int x, const int y) {
    b2Vec2 b2v2;
    b2v2.x = (float32)(x / 200.0);
    b2v2.y = (float32)(y / 200.0);
    return b2v2;
}

int main() 
{
    vector<b2Body*> boxes;
    b2World world(b2Vec2(0.0, -9.8));

    RenderWindow window(VideoMode(800, 600), "Blocks");

    // world.GetBodyList();
    CreateStaticBox(world);
    Clock clock;


    RectangleShape stayblock(Vector2f(600, 22));
    stayblock.setFillColor(Color::Blue);
    stayblock.setOrigin(301, 11);
    stayblock.setPosition(b2Vec2ToVector2f(b2Vec2(0.0f, -1.35f)));

    RectangleShape block(Vector2f(22, 22));
    block.setFillColor(Color::White);

    while (window.isOpen()) 
    {
        System::time_elapsed = clock.getElapsedTime().asSeconds();
        clock.restart();
        world.Step(System::time_elapsed, 8, 3);
            
        Event event;

        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                window.close();

            if ((event.type == event.MouseButtonPressed) && Mouse::isButtonPressed(Mouse::Left)) 
            {
                Vector2i a = Mouse::getPosition(window);
                b2Vec2 c = xyTob2Vec2(a.x, a.y);
                boxes.push_back(CreateDynamicBox(world, c.x, c.y));
            }
        }
        window.clear();
        for (size_t i = 0; i < boxes.size(); i++) 
        {
            block.setOrigin(11, 11);
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
