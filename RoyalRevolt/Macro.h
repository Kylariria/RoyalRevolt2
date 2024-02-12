#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

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

static void SetOriginAtMiddle(Shape* _shape)
{
	_shape->setOrigin(_shape->getGlobalBounds().getSize()/2.0f);
}
