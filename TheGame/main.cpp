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

    std::vector<B2ObjectBox> boxes;
    std::vector<B2ObjectBox> walls;

    b2Vec2 gravity(0, -9.8f);
    float32 gravity_factor = 0.f;
    b2World world(gravity);
    
    //walls.push_back({ {0, 300},  {600, 25}, b2sb, world });
    walls.push_back({ {0, -300}, {1000, 25}, b2sb, world });
    //walls.push_back({ {300, 0},  {25, 600}, b2sb, world });
    //walls.push_back({ {-300, 0}, {25, 600}, b2sb, world });

    B2ObjectPlayer player({ 0.f, 0.f }, { 125.f, 125.f }, b2db, world, TEXTURE("qqq"));
    B2ObjectBox body_A({ -50, 0 }, { 48,48 }, b2db, world);
    B2ObjectElasticRope rope({ 0,0 }, { 15,15 }, b2db, player.body, body_A.body, 15, world);

    while (System::window->isOpen()) 
    {
        System::Update();
        gravity_factor += System::time_elapsed;
       // world.SetGravity({ gravity.x * std::cosf(gravity_factor), gravity.y * std::sinf(gravity_factor) });
        System::window->setView(*System::camera);
        world.Step(System::time_elapsed, 8, 3);

        while (System::window->pollEvent(*System::event))
        {
            if (System::event->type == sf::Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                sf::Vector2f size({ 15.f + rand() % 40 }, { 15.f + rand() % 40 });
                boxes.push_back({ System::cursor_world, size, b2db, world });
            }
            player.Action();
        }

        System::window->clear();

        for (auto& box : boxes)
        {
            box.Update(world);
            box.Render(TEXTURE("test"));
        }

        static sf::Color color(255,255,255);
        for (b2Contact* contact = world.GetContactList(); contact; contact = contact->GetNext())
        {
            if (contact->IsTouching() && contact->GetFixtureA()->GetBody() == player.body)
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
        rope.Update(world);
        for (auto& wall : walls)
            wall.Render();
        body_A.Render();
        rope.Render();

        System::window->display();
    }
    return 0;
}