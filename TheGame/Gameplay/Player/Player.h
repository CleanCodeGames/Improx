#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Engine/System/Geometry/Geometry.h"

class Player
{

public:

	Player();
	void ChangeWeapon(const std::string name);
	void Update();
	void Action();
	void Render();

	~Player();
};