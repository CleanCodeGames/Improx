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

    b2Vec2 gravity(0, -20.f);
    float32 gravity_factor = 0.f;
    b2World world(gravity);
    
    //walls.push_back({ {0, 300},  {600, 50}, b2sb, world });
    walls.push_back({ {0, -300}, {512, 512}, b2sb, world });
    //walls.push_back({ {300, 0},  {50, 600}, b2sb, world });
    //walls.push_back({ {-300, 0}, {50, 600}, b2sb, world });

    B2ObjectPlayerMrKoc playerMrKoc({ 0.f, 0.f }, { 125.f, 125.f }, b2db, world, TEXTURE("qqq"));
    B2ObjectBox rope_end({ -50, 0 }, { 48,48 }, b2db, world);
    B2ObjectElasticRope rope({ 0,0 }, { 10.f, 10.f }, b2db, playerMrKoc.body, rope_end.body, 36, world);
    B2ObjectSingleDoor door({ 500, 0 }, { 50, 350 }, b2sb, world, false);
    std::vector<B2ObjectFanBlower> vec_fan;
    vec_fan.push_back(B2ObjectFanBlower({ 300,0 }, { 150, 25 }, b2kb, world, 180.f));
    vec_fan.push_back(B2ObjectFanBlower({ -300,0 }, { 150, 25 }, b2kb, world, -180.f));
    TEXTURE("box")->setRepeated(true);

    while (System::window->isOpen()) 
    {
        System::Update();
        gravity_factor += System::time_elapsed;
        //world.SetGravity({ gravity.x * std::cosf(gravity_factor), gravity.y * std::sinf(gravity_factor) });
        System::window->setView(*System::camera);
        world.Step(System::time_elapsed, 1, 1);
        while (System::window->pollEvent(*System::event))
        {
            if (System::event->type == sf::Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                const int random = rand() % 40;
                boxes.push_back({ System::cursor_world, {65.f + random ,65.f + random}, b2db, world });
            }
            if (Input::Mouse::Pressed(sf::Mouse::Right))
                vec_fan.push_back(B2ObjectFanBlower(System::cursor_world, { 150, 25 }, b2kb, world, 180.f));

            playerMrKoc.Action();
        }

        System::window->clear();

        for (auto& box : boxes)
        {
            box.Update(world);
            box.Render(TEXTURE("greenbox"));
        }

        for (auto& fan : vec_fan)
            fan.Update(world);

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
        for (auto& fan : vec_fan)
            fan.Render(TEXTURE("fan"));
        playerMrKoc.Render();
        rope.Update(world);

        for (auto& wall : walls)
            wall.Render(TEXTURE("greenbox"));
        rope_end.Render(TEXTURE("box"));
        rope.Render(TEXTURE("ball"));

        door.Update(world);
        door.Render(TEXTURE("fan"));

        System::window->display();
    }
    return 0;
}