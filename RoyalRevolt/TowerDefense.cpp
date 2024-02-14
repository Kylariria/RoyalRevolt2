#include "TowerDefense.h"
#include "Macro.h"
#include "FileManager.h"
#include "InputManager.h"
#include "EntityManager.h"

#define PATH_LEVEL1 "LevelEditor/Level1.txt"
#define PATH_LEVEL2 "LevelEditor/Level2.txt"

#define BATTLE_BUTTON_PATH "UI/Battle_Button.png"
#define UPGRADE_BUTTON_PATH "UI/Upgrade_Button.png"

TowerDefense::TowerDefense(const string& _name,const Vector2f& _mapSize, const int _level) : Map(_name, _mapSize)
{
	mapSize = _mapSize;
	level = _level;
	allLevel.push_back(PATH_LEVEL1);
	allLevel.push_back(PATH_LEVEL2);	

	
}

void TowerDefense::Launch()
{
	FileManager _fileManager;
	vector<vector<Entity*>> _mapFile = _fileManager.CreateEntityFromChar(allLevel[level - 1]);

	for (int _i = 0; _i < mapSize.x; _i++)
	{
		for (int _index = 0; _index < mapSize.y; _index++)
		{
			cells[_i][_index]->entityOnCell = _mapFile[_i][_index];
			_mapFile[_i][_index]->GetShape()->setPosition(cells[_i][_index]->cellShape->getPosition());
			cells[_i][_index]->cellShape = _mapFile[_i][_index]->GetShape();
		}
	}


	InitUI();
	Update();
}

void TowerDefense::InitUI()
{
	function<void()> _battleCallback = [&]() {cout << "Battle !"; };
	function<void()> _upgradeCallback = [&]() {cout << "Upgrade !"; };

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), BATTLE_BUTTON_PATH, Vector2f(150.0f,650.0f),
		"", _battleCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), UPGRADE_BUTTON_PATH, Vector2f(1050.0f, 650.0f),
		"", _upgradeCallback));


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

	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		WINDOW.draw(*_entity->GetShape());
	}

	WINDOW.display();
}
