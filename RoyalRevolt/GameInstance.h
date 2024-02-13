#pragma once
#include <iostream>
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"
#include "Player.h"

#define PLAYER GameInstance::GetInstance().GetPlayer()

using namespace std;

class GameInstance : public Singleton<GameInstance>, public IManager<string,Map>
{
	Player* player;

public:
	Player* GetPlayer()
	{
		return player;
	}

public:
	GameInstance();
	~GameInstance();

public:
	void LaunchTD();
	void LaunchVillage();
	void LaunchGestion();
};

