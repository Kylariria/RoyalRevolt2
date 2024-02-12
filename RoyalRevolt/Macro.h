#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

#define S_ID(name) name + to_string(GetUniqueID())

static int GetUniqueID()
{
	static int _id = 0;
	return _id++;
}

static int Random(const int _max, const int _min = 0)
{
	return rand() % _max + _min;
}
