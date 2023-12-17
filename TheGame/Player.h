#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Engine/System/Geometry/Geometry.h"

typedef std::unordered_map<std::string, sf::RectangleShape> BodyParts;

class PlayerBody : public BodyParts
{
private:

public:

	PlayerBody()
	{
		
	}

	sf::RectangleShape* Get(const std::string& name)
	{
		if (const auto& it = find(name); it != end()) 
		{
			return &it->second;
		}
		return nullptr;
	}

	void AddBodyPart(const std::string& body_name, const sf::RectangleShape& part)
	{
		this->insert({ body_name, part });
		// this->rehash(this->size()); после полного создани€ тела вызвать этот метод
	}
};

class Player
{
private:

protected:

	PlayerBody body;

public:

	Player()
	{
		body.AddBodyPart("legs", sf::RectangleShape());
	}

	void ChangeWeapon(const std::string name);
	void Update();
	void Action();
	void Render();
	~Player();
};

