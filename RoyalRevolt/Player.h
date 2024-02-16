#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "InputManager.h"
#include "Hero.h"
#include "Spawner.h"

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

	RessourcesData()
	{
		bread = 200;
		diamond = 50;
		money = 0;
	}
};

struct UpgradeCounts
{
	int bread;
	int diamond;
	int money;

	UpgradeCounts()
	{
		bread = 1;
		diamond = 1;
		money = 1;
	}
};

class Player
{
	static Vector2f savedMousePosition;
	UpgradeCounts upgradesCounts;
	RessourcesData data;
	Hero* hero;
	Spawner* spawner;
protected :
	static int level; 

public:
	int GetBread() const
	{
		return data.bread;
	}
	int GetDiamond() const
	{
		return data.diamond;
	}
	int GetMoney() const
	{
		return data.money;
	}
	int GetTrophee() const
	{
		return data.trophee;
	}
	int GetHammer() const
	{
		return data.hammer;
	}
	int GetExperience() const
	{
		return data.experience;
	}
	Hero* GetHero() const
	{
		return hero;
	}
	static int GetLevel()
	{
		return level;
	}
	static Vector2f GetSavedMousePosition()
	{
		return savedMousePosition;
	}

public:
	Player();

private:
	void Init();
	void Actions();
};
