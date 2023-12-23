#pragma once

#include "Engine/System/System.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"

class Suspect
{
public:

	typedef std::tuple<sf::RectangleShape, int> 
		BodyPart;

	typedef std::map<std::string, BodyPart> 
		Body;

	Body m_body;
	void BuildBody();
	void AddBodyPart(const std::string& body_part_name);
	BodyPart* GetBodyPart(const std::string& body_part_name);
	void SwapBodyPart(const std::string& k1, const std::string& k2);
	void Draw();
	Suspect();
	~Suspect();
};