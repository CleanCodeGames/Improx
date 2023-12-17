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

#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

static constexpr auto PI = 3.141592f;
static constexpr auto PI2 = PI * 2.0f;
static constexpr auto DEG_TO_RAD = 0.017453f;
static constexpr auto RAD_TO_DEG = 57.29577f;
