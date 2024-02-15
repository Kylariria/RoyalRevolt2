#include "Spawner.h"
#include "Macro.h"
#include "Map.h"
#include "EntityManager.h"
#include "Troop.h"

#define BARBARIAN "Barbarian.png"
#define ARCHER "Archer.png"

Spawner::Spawner()
{
}

void Spawner::Spawn()
{
	for (const Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		if (_entity->GetEntityData()->name == "Casern")
		{
			Vector2f _position = _entity->GetShapePosition();
			_position.x += Map::GetCellSize().x;
			const int _randomSpawn = Random(2, 0);
			if (_randomSpawn == 0) new Troop(S_ID("Barbarian"), ENTITY_MOB, TROOP_BARBARIAN, _position, Map::GetCellSize(), BARBARIAN, 1, 100, 15);
			else (new Troop(S_ID("Archer"), ENTITY_MOB, TROOP_ARCHER, _position, Map::GetCellSize(), ARCHER, 2, 50, 30));
		}
	}
}