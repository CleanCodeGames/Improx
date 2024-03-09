#pragma once
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include <complex>
#include <valarray>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <Box2D/Box2D.h>

#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

static constexpr auto PI = 3.141592f;
static constexpr auto PI2 = PI * 2.0f;
static constexpr auto DEG_TO_RAD = 0.017453f;
static constexpr auto RAD_TO_DEG = 57.29577f;
static constexpr auto SCALE_B2D = 30.f;

class URA
{
public:

	URA(void) {}
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Action() = 0;
	virtual ~URA(void) {};
};

#define DECLARATION_URA(CLASS, VISIBLE) VISIBLE: CLASS(void); void Update() override; void Render() override; void Action() override; ~CLASS() override;
#define DECLURA(CLASS, VISIBLE) DECLARATION_URA(CLASS, VISIBLE)
#define CLASSURA(NAME) class NAME : public URA { DECLURA(NAME, public) };
#define CLASSURA_ADDITION(NAME, ADDITION_CONTENT) class NAME : public URA { DECLURA(NAME, public) ADDITION_CONTENT };
#define CLASSDECL(NAME, CONTENT) class NAME { CONTENT };
#define CLASSDECL_INHERITANCE(NAME, INHERITANCE, CONTENT) class NAME : public INHERITANCE { CONTENT };

