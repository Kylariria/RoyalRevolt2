#include "Map.h"
#include "GameInstance.h"
#include "TextureManager.h"

#define GRASS_PATH "UI/Grass.png"

Vector2f Map::cellSize;

Map::Map(const string& _name, const Vector2f& _mapSize) : IManagable(S_ID(_name))
{
	cellCount = _mapSize;

	cells = vector<vector<Cell*>>(static_cast<int>(_mapSize.x));

	cellSize = Vector2f(50.0f, 50.0f);

	background = new RectangleShape(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	
	TextureManager::GetInstance().Load(background, GRASS_PATH,true);

	background->setTextureRect(IntRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));




	Register();

	Init();

}

void Map::Init()
{
	float mapSizeX = cellSize.x * cellCount.y;
	float mapSizeY = cellSize.y * cellCount.x;
	const float _posX = (SCREEN_WIDTH - mapSizeX)/2.0f;
	const float _posY = (SCREEN_HEIGHT - mapSizeY)/2.0f;

	for (int _i = 0; _i < cellCount.x; _i++)
	{
		for (int _j = 0; _j < cellCount.y; _j++)
		{
			cells[_i].push_back(new Cell(cellSize));
			Shape* _shape = cells[_i][_j]->cellShape;

			const float _posShapeX =_posX+ cellSize.x*_j;
			const float _posShapeY =_posY + cellSize.y*_i;

			_shape->setPosition(_posShapeX, _posShapeY);
			_shape->setOutlineThickness(-1.0f);
			_shape->setOutlineColor(Color::Black);
			_shape->setOrigin(_shape->getGlobalBounds().getSize() / 2.0f);
		}
	}
}

void Map::Register()
{
	//GameInstance::GetInstance().GetMapManager().Add(id, this);
}
