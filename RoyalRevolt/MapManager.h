#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Map.h"

class MapManager : public IManager<string,Map>// , public Singleton<MapManager>
{

};

