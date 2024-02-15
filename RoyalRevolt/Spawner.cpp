#include "Spawner.h"
#include "Macro.h"
#include "Map.h"
#include "EntityManager.h"

#define BARBARIAN "Barbarian.png"
#define ARCHER "Archer.png"

Spawner::Spawner()
{
	numberOfEntity = 1;
}

void Spawner::Spawn()
{
	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		/*if (Casern* _casern = dynamic_cast<Casern*>(_entity))
		{
			Vector2f _position = _casern->GetShapePosition();
			_position.x += Map::GetCellSize().x;
			new Barbarian(S_ID("Barbarian"), _position, Map::GetCellSize(), BARBARIAN);
		}*/
	}
}

void Spawner::Update()
{
	Spawn();
}
