#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"
#include "Hero.h"

using namespace sf;
using namespace std;

struct RessourcesData
{
	int bread;
	int diamond;
	int money;
	int trophee;
	int hammer;
	int experience;
};

class Player
{
	RessourcesData data;
	Hero* hero;
public:
	Player();

private:
	void Init();
	void Actions();
};
