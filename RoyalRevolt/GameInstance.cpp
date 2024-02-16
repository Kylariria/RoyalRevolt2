#include "GameInstance.h"
#include "TowerDefense.h"
#include "MapCreator.h"
#include "Village.h"
#include "FileManager.h"
#include "Menu.h"

#define PATH_LEVEL1 "LevelEditor/Level1.txt"
#define PATH_LEVEL2 "LevelEditor/Level2.txt"


GameInstance::GameInstance()
{
	player = new Player();
}

GameInstance::~GameInstance()
{
	delete player;
}

void GameInstance::LaunchMenu()
{
	Menu _menu;
	_menu.Launch();
}

void GameInstance::LaunchTD()
{
	bool _hasLaunch = false;
	for (Map* _map : mapManager.GetAllValues())
	{
		if (TowerDefense* _td = dynamic_cast<TowerDefense*>(_map))
		{
			_hasLaunch = true;
			_td->Launch();
		}
	}
	if (!_hasLaunch)
	{
		FileManager _fileManager;
		Vector2f _mapSize = _fileManager.GetSizeFill(PATH_LEVEL1);
		TowerDefense* _td = new TowerDefense("TowerDefence", _mapSize, 1);
		_td->Launch();
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
void GameInstance::LaunchMapCreator()
{
	bool _hasLaunch = false;
	for (Map* _map : mapManager.GetAllValues())
	{
		if (MapCreator* _mapCreator = dynamic_cast<MapCreator*>(_map))
		{
			_hasLaunch = true;
			_mapCreator->Launch();
		}
	}
	if (!_hasLaunch)
	{
		MapCreator* _mapCreator = new MapCreator("MapCreator", Vector2f(10.0f,10.0f));
		_mapCreator->Launch();
	}
}
