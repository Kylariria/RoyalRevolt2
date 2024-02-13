#include "Map.h"
#include "GameInstance.h"

Vector2f Map::cellSize;

Map::Map(const string& _name, const Vector2f& _mapSize) : IManagable(S_ID(_name))
{
	cellCount = _mapSize;

	cells = vector<vector<Cell*>>(static_cast<int>(_mapSize.x));

	cellSize = Vector2f(50.0f, 50.0f);

	Register();
	Init();

}

void Map::Init()
{
	for (int _i = 0; _i < cellCount.x; _i++)
	{
		for (int _j = 0; _j < cellCount.y; _j++)
		{
			cells[_i].push_back(new Cell(cellSize));
			Shape* _shape = cells[_i][_j]->cellShape;

			const float _posX = cellSize.x * _j; 
			const float _posY = cellSize.y * _i;
			_shape->setPosition(_posX, _posY);
			_shape->setOutlineThickness(-1.0f);
			_shape->setOutlineColor(Color::Black);
			_shape->setOrigin(_shape->getGlobalBounds().getSize() / 2.0f);
		}
	}
}

void Map::Register()
{
	GameInstance::GetInstance().Add(id, this);
}
