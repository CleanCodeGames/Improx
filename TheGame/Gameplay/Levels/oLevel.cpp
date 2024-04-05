#include "olevel.h"

oLevel::oLevel() : m_world_settings({ 0,0 })
{
	m_is_level_complete = false;
}

void oLevel::SetName(const std::wstring& name)
{
	this->name = name;
}
void oLevel::SetNumber(const uint32 number)
{
	this->number = number;
}
void oLevel::SetComplete(const bool is_winer)
{
	if(is_winer)
	{
	
	}
	else 
	{

	}

	m_is_level_complete = true;
}
void oLevel::Restart()
{

}
void oLevel::SetWorldSettings(const WorldSettings& ws)
{
	m_world_settings = ws;
}

void oLevel::Update()
{

}

void oLevel::Render()
{

}

void oLevel::Action()
{

}

oLevel::~oLevel()
{

}