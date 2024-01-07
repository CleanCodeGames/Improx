#pragma once

#include "Engine/System/System.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Engine/System/Input/Input.h"

class Suspect : public URA
{
	DECLARATION_URA(Suspect, public)

	typedef sf::Vector2f AnchorPoint, GravityPoint, HighestPoint, LowestPoint, Size, Origin;
	typedef int HitPoint;
	typedef std::tuple<sf::RectangleShape, HitPoint, AnchorPoint, GravityPoint, HighestPoint, LowestPoint>
		BodyPart;

	typedef std::string KeyMap;
	typedef std::map<KeyMap, BodyPart> 
		Body;

	Body m_body;
	void BuildBody();
	void AddBodyPart(const KeyMap& body_part_name);
	BodyPart* GetBodyPart(const KeyMap& body_part_name);
	void SwapBodyPart(const KeyMap& k1, const KeyMap& k2);
};