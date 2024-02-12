#pragma once
#include <iostream>
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"

using namespace std;

class GameInstance : public Singleton<GameInstance>, public IManager<string,Map>
{
public:
	void LaunchTD();
	void LaunchVillage();
	void LaunchGestion();
};

