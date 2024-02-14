#include "TowerDefense.h"
#include "Macro.h"
#include "FileManager.h"
#include "InputManager.h"

#define PATH_LEVEL1 "LevelEditor/Level1.txt"

TowerDefense::TowerDefense(const string& _name,const Vector2f& _mapSize) : Map(_name, _mapSize)
{
	allLevel.push_back(PATH_LEVEL1);

	
}

void TowerDefense::Launch()
{
	FileManager _fileManager;
	map = _fileManager.CreateEntityFromChar(PATH_LEVEL1);

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

	for (vector<Entity*> _vectroEntity: map)
	{
		for (Entity* _partOfMap : _vectroEntity)
		{
			WINDOW.draw(*_partOfMap->GetShape());
		}
	}

	WINDOW.display();
}
