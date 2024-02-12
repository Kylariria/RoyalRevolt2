#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Singleton.h"

using namespace std;
using namespace sf;

class GameWindow : Singleton<GameWindow>
{
	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	GameWindow();
};

