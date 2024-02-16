#include "TowerDefense.h"
#include "Macro.h"
#include "FileManager.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "Interface.h"
#include "Spawner.h"
#include "Hero.h"

#define PATH_LEVEL1 "LevelEditor/Level1.txt"
#define PATH_LEVEL2 "LevelEditor/Level2.txt"

#define ATTACK_BUTTON_PATH "UI/Button_Attack.png"
#define SPELL_BUTTON_PATH "UI/Button_spell1.png"
#define PAUSE_BUTTON_PATH "UI/Button_pause.png"

#define CHARACTER_PATH "UI/Character.png"

#define BAR_FULL "UI/BarFull.png"
#define BAR_EMPTY "UI/EmptyBar.png"

#define LIFEBAR_FULL "UI/LifeBarFull.png"
#define LIFEBAR_EMPTY "UI/LifeBarEmpty.png"

TowerDefense::TowerDefense(const string& _name,const Vector2f& _mapSize, const int _level) : Map(_name, _mapSize)
{
	mapSize = _mapSize;
	level = _level;
	allLevel.push_back(PATH_LEVEL1);
	allLevel.push_back(PATH_LEVEL2);	
	spawnBar = nullptr;
	lifeBar = nullptr;

	activeElements = vector<BasicElement*>();
	character = new RectangleShape(Vector2f(110.0f, 110.0f));
}

void TowerDefense::Launch()
{
	FileManager _fileManager;
	vector<vector<Entity*>> _mapFile = _fileManager.CreateEntityFromChar(allLevel[level - 1]);

	for (int _i = 0; _i < mapSize.x; _i++)
	{
		for (int _index = 0; _index < mapSize.y; _index++)
		{
			_mapFile[_i][_index]->GetShape()->setPosition(cells[_i][_index]->cellShape->getPosition());
			cells[_i][_index]->entityOnCell = _mapFile[_i][_index];
			cells[_i][_index]->cellShape->setFillColor(Color::Transparent);
			cells[_i][_index]->cellShape->setOutlineThickness(0.0f);
			//cells[_i][_index]->cellShape = _mapFile[_i][_index]->GetShape();
		}
	}

	InitUI();
	Update();
}

void TowerDefense::InitUI()
{
	function<void()> _attackCallback = [&]() { Spawn(); };
	function<void()> _spellCallback = [&]() {cout << "KABOUM !"; Spell();  };
	function<void()> _pauseCallback = [&]() {cout << "Freeze !"; Pause();  };

	Vector2f _characterPos = Vector2f(30.0f, 10.0f);
	character->setPosition(_characterPos);
	TextureManager::GetInstance().Load(character, CHARACTER_PATH);

	activeElements.push_back(new Button(new RectangleShape(Vector2f(110.0f, 110.0f)), PAUSE_BUTTON_PATH, Vector2f(240.0f, 60.0f),
		"", _pauseCallback));

		activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), ATTACK_BUTTON_PATH, Vector2f(150.0f, 650.0f),
			"", _attackCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), SPELL_BUTTON_PATH, Vector2f(1050.0f, 650.0f),
		"", _spellCallback));

	#pragma region SpawnAllies

	RectangleShape* _spawnBar = new RectangleShape(Vector2f(450.0f, 50.0f));
	Vector2f _spawnPos = Vector2f(25.0f, 730.0f);
	vector<string> _pathsSpawn = { BAR_FULL, BAR_EMPTY };
	spawnBar = new MovingBar(_spawnBar, _pathsSpawn, _spawnPos, 100, 100);
	activeElements.push_back(spawnBar);

	#pragma endregion

	#pragma region LifeBar

	RectangleShape* _lifeBar = new RectangleShape(Vector2f(140.0f, 80.0f));
	Vector2f _lifePos = Vector2f(15.0f, 80.0f);
	vector<string> _pathsLife = { LIFEBAR_FULL, LIFEBAR_EMPTY };
	lifeBar = new MovingBar(_lifeBar, _pathsLife, _lifePos, 150, 150);
	activeElements.push_back(lifeBar);

	//TODO => A faire en sorte que health = actualValue
	
	#pragma endregion

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
		UpdateActiveElements(_event);
		EntityManager::GetInstance().Update();
		Display();
	}
}

void TowerDefense::UpdateActiveElements(Event _event)
{
	for (BasicElement* _element : activeElements)
	{
		if (_element->GetIsDraw()) _element->Update(_event);
	}
}

void TowerDefense::Spawn()
{
	if (spawnBar->actualValue - 10 < 10)
	{
		return;
	}

	Spawner _spawn;
	_spawn.Spawn();

	spawnBar->actualValue -= 10;
}

void TowerDefense::Spell()
{
	//TODO
}

void TowerDefense::Pause()
{
	//TODO
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

	WINDOW.draw(*character);

	WINDOW.display();
}
