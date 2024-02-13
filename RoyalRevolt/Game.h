#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Interface.h"
#include "Spawner.h"
#include "Player.h"
#include "EntityManager.h"

using namespace std;
using namespace sf;

class Game
{
	RenderWindow window;
	Vector2f windowSize;
	string name;
	Player* player;

	Spawner* spawner;
public:
	Game();

public:
	void Launch();

private:
	void Start();
	void Update();
	void UpdateEvent();
	void UpdateWindow();
	void UpdateInputs(const Event& _event);
	void Stop();


};

