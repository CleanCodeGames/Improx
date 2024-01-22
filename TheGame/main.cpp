#include "Gameplay/Game.h"

//  int main()
//  {
//  	Game game;
//  	game.Play();
//  	return 0;
//  }

using namespace sf;
using namespace std;

const sf::Vector2f toVector2f(const b2Vec2& b2v2);
const sf::Vector2f toVector2f(const float32& x, const float32& y);
const b2Vec2 toB2Vec2(const sf::Vector2f& v2f);
const b2Vec2 toB2Vec2(const float32& x, const float32& y);

// ƒл€ координат ( дл€ размеров не нужен отрицательный Y)
const sf::Vector2f b2Vec2ToVector2f(const b2Vec2& b2v2)
{
    sf::Vector2f v2f;
    v2f.x = b2v2.x * SCALE_B2D;
    v2f.y = b2v2.y * SCALE_B2D;
    return v2f;
}

// ƒл€ координат ( дл€ размеров не нужен отрицательный Y)
const b2Vec2 Vec2fTob2Vec2(const sf::Vector2f& vec)
{
    b2Vec2 b2v2;
    b2v2.x = vec.x / SCALE_B2D;
    b2v2.y = vec.y / SCALE_B2D;
    return b2v2;
}

// ƒл€ координат ( дл€ размеров не нужен отрицательный Y)
const b2Vec2 xy2fTob2Vec2(const float& x, const float& y)
{
    b2Vec2 b2v2;
    b2v2.x = x / SCALE_B2D;
    b2v2.y = y / SCALE_B2D;
    return b2v2;
}

b2Body* CreateStaticBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size)
{
    b2BodyDef bodydef;
    b2Vec2 pos = xy2fTob2Vec2(position.x, position.y);
    bodydef.position.Set(pos.x, pos.y);
    b2Body* body = world.CreateBody(&bodydef);
    b2PolygonShape groundbox;
    groundbox.SetAsBox(size.x / SCALE_B2D / 2, size.y / SCALE_B2D / 2);
    body->CreateFixture(&groundbox, 1.0f);
    body->SetUserData(const_cast<char*>("static_box"));
    return body;
}

b2Body* CreateDynamicBox(b2World& world, const sf::Vector2f& position, const sf::Vector2f& size)
{
    b2BodyDef bodydef;
    b2Vec2 pos = xy2fTob2Vec2(position.x, position.y);
    bodydef.type = b2_dynamicBody;
    bodydef.position.Set(pos.x, pos.y);

    b2Body* body = world.CreateBody(&bodydef);
    
    b2PolygonShape box;
    box.SetAsBox(size.x / SCALE_B2D / 2, size.y / SCALE_B2D / 2);
    b2FixtureDef fixdef;
    fixdef.shape = &box;
    fixdef.density = 0.8f;
    fixdef.friction = 0.1f;
    fixdef.restitution = 0.8f;

    body->CreateFixture(&fixdef);
    return body;
}

void UpdateDynamicBoxes(const std::vector<b2Body*>& boxes)
{
    RectangleShape block(Vector2f(30, 30));
    block.setOrigin(block.getSize() / 2.f);
    block.setScale(1, -1);
    block.setTexture(TEXTURE("test"));
    for (size_t i = 0; i < boxes.size(); i++)
    {
        block.setPosition(b2Vec2ToVector2f(boxes[i]->GetPosition()));
        block.setRotation(boxes[i]->GetAngle() * RAD_TO_DEG);
        System::window->draw(block);
    }
}

void ClearDynamicBoxes(b2World& world, std::vector<b2Body*>& vec_bodies)
{
    for (const auto& body : vec_bodies)
        world.DestroyBody(body);
    vec_bodies.clear();
}

int main() 
{
    System::Initialization();
    vector<b2Body*> boxes;
    b2World world(b2Vec2(0.0f, -9.8f));
    CreateStaticBox(world, sf::Vector2f(0, 200), sf::Vector2f(600, 25));
    

    RectangleShape stayblock(Vector2f(600, 25));
    stayblock.setFillColor(Color::Blue);
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
            if (System::event->type == Event::Closed)
                System::window->close();

            if (Input::Mouse::Pressed(sf::Mouse::Left))
            {
                boxes.push_back(CreateDynamicBox(world, sf::Vector2f(System::cursor_world.x, System::cursor_world.y), sf::Vector2f(30, 30)));
            }

            if (Input::Mouse::Pressed(sf::Mouse::Right))
            {
                ClearDynamicBoxes(world, boxes);
            }

            if (Input::Keyboard::Pressed(Keyboard::A)) boxes.back()->ApplyLinearImpulse(b2Vec2(-1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::S)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, 1), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::D)) boxes.back()->ApplyLinearImpulse(b2Vec2(1, 0), boxes.back()->GetWorldCenter(), false);
            if (Input::Keyboard::Pressed(Keyboard::W)) boxes.back()->ApplyLinearImpulse(b2Vec2(0, -1), boxes.back()->GetWorldCenter(), false);
        }

        System::window->clear();

        UpdateDynamicBoxes(boxes);
        System::window->draw(stayblock);
        System::window->display();
    }
    return 0;
}