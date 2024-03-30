#include "Gameplay/Game.h"
#include "Gameplay/B2Objects/B2Object.h"
//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

int main() 
{
    System::Initialization();
    std::thread worldstep_thr;
    std::vector<B2ObjectBox> boxes;
    std::vector<B2ObjectBox> walls;

    b2Vec2 gravity(0, -9.8f);
    float32 gravity_factor = 0.f;
    b2World world(gravity);
    
    //walls.push_back({ {0, 300},  {600, 25}, b2sb, world });
    walls.push_back({ {0, -300}, {1000, 25}, b2sb, world });
    //walls.push_back({ {300, 0},  {25, 600}, b2sb, world });
    //walls.push_back({ {-300, 0}, {25, 600}, b2sb, world });

    B2ObjectPlayerMrKoc playerMrKoc({ 0.f, 0.f }, { 125.f, 125.f }, b2db, world, TEXTURE("qqq"));
    B2ObjectBox body_A({ -50, 0 }, { 48,48 }, b2db, world);
    B2ObjectElasticRope rope({ 0,0 }, { 10.f, 10.f }, b2db, playerMrKoc.body, body_A.body, 36, world);
    B2ObjectFanBlower fan1({ 300,0 }, { 150, 25 }, b2kb, world, 180.f);
    B2ObjectFanBlower fan2({ -300,0 }, { 150, 25 }, b2kb, world, -180.f);

    while (System::window->isOpen()) 
    {
        System::Update();
        gravity_factor += System::time_elapsed;
       // world.SetGravity({ gravity.x * std::cosf(gravity_factor), gravity.y * std::sinf(gravity_factor) });
        System::window->setView(*System::camera);
        world.Step(System::time_elapsed, 1, 1);
        while (System::window->pollEvent(*System::event))
        {
            if (System::event->type == sf::Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                sf::Vector2f size({ 15.f + rand() % 40 }, { 15.f + rand() % 40 });
                boxes.push_back({ System::cursor_world, size, b2db, world });
            }
            playerMrKoc.Action();
        }

        System::window->clear();

        for (auto& box : boxes)
        {
            box.Update(world);
            box.Render(TEXTURE("test"));
        }

        fan1.Update(world);
        fan2.Update(world);

        static sf::Color color(255,255,255);
        for (b2Contact* contact = world.GetContactList(); contact; contact = contact->GetNext())
        {
            if (contact->IsTouching() && contact->GetFixtureA()->GetBody() == playerMrKoc.body)
            {
                static int count = 0;
                count++;
                color.g = 0;
                color.b = 0;
            }
        }

        if (color.g < 255) color.g++;
        if (color.b < 255) color.b++;
        playerMrKoc.shape.setFillColor(color);
        playerMrKoc.Update(world);
        fan1.Render(TEXTURE("fan"));
        fan2.Render(TEXTURE("fan"));
        playerMrKoc.Render();
        rope.Update(world);
        for (auto& wall : walls)
            wall.Render();
        body_A.Render();
        rope.Render(TEXTURE("ball"));

        System::window->display();
    }
    return 0;
}