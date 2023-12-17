#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Engine/System/Geometry/Geometry.h"

struct LevelConstants
{

};

class ILevel
{
private:

protected:

	bool is_level_complete;

	std::string name_level;

public:

	ILevel();

	virtual void Update();
	virtual void Action();
	virtual void Render();

	virtual ~ILevel();
};

