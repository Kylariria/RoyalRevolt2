#pragma once
#include <iostream>
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"
#include "Player.h"
#include "MapManager.h"

#define PLAYER GameInstance::GetInstance().GetPlayer()

using namespace std;

class GameInstance : public Singleton<GameInstance>
{
	MapManager mapManager;

	Player* player;

public:
	MapManager GetMapManager()
	{
		return mapManager;
	}

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
	void LaunchMapManger();
};

