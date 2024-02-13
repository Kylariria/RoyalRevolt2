#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Interface.h"

using namespace std;
using namespace sf;

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

