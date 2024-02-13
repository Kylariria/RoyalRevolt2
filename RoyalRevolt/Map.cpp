#include "Map.h"
#include "GameInstance.h"

Map::Map(const string& _name) : IManagable(S_ID(_name))
{
	GameInstance::GetInstance().Add(id, this);
}
