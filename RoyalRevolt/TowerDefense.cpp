#include "TowerDefense.h"
#include "Macro.h"
#include "FileManager.h"
#include "InputManager.h"
#include "EntityManager.h"

#define PATH_LEVEL1 "LevelEditor/Level1.txt"

TowerDefense::TowerDefense(const string& _name,const Vector2f& _mapSize, const int _level) : Map(_name, _mapSize)
{
	mapSize = _mapSize;
	level = _level;
	allLevel.push_back(PATH_LEVEL1);

	allLevel.push_back(PATH_LEVEL1);	
}

void TowerDefense::Launch()
{
	FileManager _fileManager;
	vector<vector<Entity*>> _mapFile = _fileManager.CreateEntityFromChar(allLevel[level - 1]);


	for (int _index = 0; _index < mapSize.x; _index++)
	{
		for (int _i = 0; _i < mapSize.y; _i++)
		{
			cells[_index][_i]->entityOnCell = _mapFile[_index][_i];
			_mapFile[_index][_i]->GetShape()->setPosition(cells[_index][_i]->cellShape->getPosition());
			cells[_index][_i]->cellShape = _mapFile[_index][_i]->GetShape();
		}
	}


	Update();
}

void TowerDefense::Update()
{
	while (WINDOW.isOpen())
	{
		Event _event;
		while (WINDOW.pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW.close();
			InputManager::GetInstance().Update(WINDOW, _event);
		}
		EntityManager::GetInstance().Update();
		Display();
	}
}

void TowerDefense::Display()
{
	WINDOW.clear(Color::Black);

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}

	WINDOW.display();
}
