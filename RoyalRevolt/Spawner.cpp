#include "Spawner.h"
#include "Archer.h"
#include "Barbarian.h"
#include "Macro.h"
#include "Map.h"

#define BARBARIAN "Barbarian.png"
#define ARCHER "Archer.png"

Spawner::Spawner()
{
	numberOfEntity = 1;
}

void Spawner::Spawn()
{
	const Vector2f& _position = GetRandomPosition();
	const Vector2f& _position2 = GetRandomPosition();

	for (int _i = 0; _i < numberOfEntity; _i++)
	{
		new Barbarian(S_ID("Barbarian"),_position , Map::GetCellSize(), BARBARIAN);
		new Archer(S_ID("Archer"), _position2, Map::GetCellSize(), ARCHER);
	}
}

void Spawner::Update()
{
	Spawn();
}
