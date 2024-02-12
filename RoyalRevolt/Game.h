#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "EntityManager.h"

using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1080
#define SREEN_HEIGHT 1920

class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	Game();



public:
	void Launch();

private:
	void Start();
	void Update();
	void UpdateEvent();
	void UpdateWindow();
	void Stop();

};

