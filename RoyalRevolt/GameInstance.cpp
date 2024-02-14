#include "GameInstance.h"
#include "TowerDefense.h"
#include "MapCreator.h"
#include "Village.h"

GameInstance::GameInstance()
{
	player = new Player();
}

GameInstance::~GameInstance()
{
	delete player;
}

void GameInstance::LaunchTD()
{
	for (Map* _map : mapManager.GetAllValues())
	{
		if (TowerDefense* _td = dynamic_cast<TowerDefense*>(_map))
		{
			_td->Launch();
		}
	}
}

void GameInstance::LaunchVillage()
{
	bool _hasLaunch = false;
	for (Map* _map : mapManager.GetAllValues())
	{
		if (Village* _village = dynamic_cast<Village*>(_map))
		{
			_hasLaunch = true;
			_village->Launch();
		}
	}
	if (!_hasLaunch)
	{
		Village* _village = new Village("Village");
		_village->Launch();
	}
}
void GameInstance::LaunchMapManger()
{
	/*for (Map* _map : mapManager.GetAllValues())
	{
		if (MapCreator* _mapCreator = dynamic_cast<MapCreator*>(_map))
		{
			_mapCreator->Launch();
		}
	}*/
}
