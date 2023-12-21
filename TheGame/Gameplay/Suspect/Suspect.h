#pragma once

#include "Engine/System/System.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"

class Suspect
{
public:

	typedef std::tuple<sf::RectangleShape, int, sf::Vector2f, sf::Vector2f> BodyPart;
	typedef std::unordered_map<std::string, BodyPart> Body;

	Body m_body;

	void AddPart(const std::string& part_name);
	BodyPart* Get(const std::string& name);
	Suspect();
	~Suspect();
};