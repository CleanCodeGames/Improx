#pragma once
#include "Engine/System/System.h"
#include "Engine/System/Input/Input.h"
#include "Engine/System/Geometry/Geometry.h"
#include "Gameplay/World/Settings/WorldSettings.h"
#include "Gameplay/B2Objects/B2Object.h"

CLASSURA_ADDITION(oLevel,
protected:
	std::wstring name = L"Тестовый уровень";
	uint32 number = 0;
	bool m_is_level_complete;
	WorldSettings m_world_settings;

	public:
		void SetName(const std::wstring& name);
		void SetNumber(const uint32 number);
		void SetComplete(const bool is_winer);
		void Restart();
		void SetWorldSettings(const WorldSettings& ws);
)
