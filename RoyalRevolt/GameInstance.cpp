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
	for (Map* _map : GetAllValues())
	{
		if (TowerDefense* _td = dynamic_cast<TowerDefense*>(_map))
		{
			_td->Launch();
		}
	}
}

void GameInstance::LaunchVillage()
{
	for (Map* _map : GetAllValues())
	{
		if (Village* _village = dynamic_cast<Village*>(_map))
		{
			_village->Launch();
		}
	}
} 

void GameInstance::LaunchGestion()
{
	/*for (Map* _map : GetAllValues())
	{
		if (MapCreator* _gestion = dynamic_cast<MapCreator*>(_map))
		{
			_gestion->Launch();
		}
	}*/
}
