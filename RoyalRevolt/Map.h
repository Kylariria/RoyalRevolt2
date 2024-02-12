#pragma once
#include <SFML/Graphics.hpp>
#include "IManagable.h"
#include "Macro.h"

using namespace sf;

class Map : IManagable<string>
{
	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	Map(const RenderWindow& _window,const string& _name);

};

