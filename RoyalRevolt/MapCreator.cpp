#include "MapCreator.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "GameInstance.h"
#include "Removable.h"
#include "TowerDefenseBuilding.h"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"
#define PATH_OBSTACLES "UI/Obstacle.png"
#define PATH_TOWERS "UI/Tower.png"
#define PATH_PATH "UI/Path.png"

#define PATH_BUTTON_OBSTACLES "UI/ButtonObstacle.png"
#define PATH_BUTTON_TOWERS "UI/ButtonTower.png"
#define PATH_BUTTON_PATH "UI/ButtonPath.png"

MapCreator::MapCreator(const string& _name, const Vector2f& _mapSize) : Map(_name, _mapSize)
{
	ifstream _stream("LevelEditor/MyLevel.txt");
	if (_stream)
	{
		vector<vector<Entity*>> _map = _fileManager.CreateEntityFromChar("LevelEditor/MyLevel.txt");
		for (int _i = 0; _i < _map.size(); _i++)
		{
			for (int _index = 0; _index < _map[0].size(); _index++)
			{

				_map[_i][_index]->GetShape()->setPosition(cells[_i][_index]->cellShape->getPosition());
				cells[_i][_index]->entityOnCell = _map[_i][_index];
			}
		}
	}

	mapCreatorInformations = MapCreatorInformations();
	passiveElements = vector<BasicElement*>();
	activeElements = vector<BasicElement*>();
	InitUI();
}

MapCreator::~MapCreator()
{
	for (BasicElement* _element : activeElements)
	{
		delete _element;
	}

	for (BasicElement* _element : passiveElements)
	{
		delete _element;
	}
}

void MapCreator::Launch()
{
	Update();
}

void MapCreator::Update()
{
	// similaire au village sauf qu au lieu que se soit des ferme, etc ... c les REMOVABLE
	//quand on depose sa enrgiste dans le map qui est constituer

	while (WINDOW.isOpen())
	{
		UpdateEvent();
		Display();
		//_fileManager.SaveMap(cells, "LevelEditor/MyLevel.txt");
	}

}

void MapCreator::UpdateEvent()
{
	Event _event;
	while (WINDOW.pollEvent(_event))
	{
		if (_event.type == Event::Closed)
		{
			_fileManager.SaveMap(cells, "LevelEditor/MyLevel.txt");
			WINDOW.close();
		}
		InputManager::GetInstance().Update(WINDOW, _event);
		UpdateElements(_event);
		PlaceEntityOnTheCell();
	}
}

void MapCreator::UpdateElements(const Event& _event)
{
	for (BasicElement* _element : passiveElements)
	{
		if (_element->GetIsDraw()) _element->Update(_event);
	}

	for (BasicElement* _element : activeElements)
	{
		if (_element->GetIsDraw()) _element->Update(_event);
	}
}

void MapCreator::Display()
{
	WINDOW.clear(Color::Black);
	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		WINDOW.draw(*_entity->GetShape());
	}

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}


	WINDOW.display();
}

void MapCreator::InitUI()
{
	function<int()> _pathDisplayCallback = [&]() {return (mapCreatorInformations.pathSize); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_PATH, mapCreatorInformations.pathIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.pathTextPosition, to_string(mapCreatorInformations.pathSize), _pathDisplayCallback));

	function<int()> _towerDisplayCallback = [&]() {return mapCreatorInformations.towerCount; };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_TOWERS, mapCreatorInformations.towerIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.towerTextPosition, to_string(mapCreatorInformations.towerCount), _towerDisplayCallback));

	function<int()> _trapDisplayCallback = [&]() {return mapCreatorInformations.trapCount; };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_OBSTACLES, mapCreatorInformations.trapIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.trapTextPosition, to_string(mapCreatorInformations.trapCount), _trapDisplayCallback));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(350.0f, 60.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.2f), "Add a bew Building", false));
	

	#pragma region Buttons

	function<void()> _pathCallback = [&]() { cout << "Path" << endl; };
	activeElements.push_back(new Button(new RectangleShape(Vector2f(110.0f, 110.0f)), PATH_BUTTON_PATH, Vector2f(1050.0f, 200.0f),
		"", _pathCallback));

	function<void()> _towerCallback = [&]() { cout << "Tower" << endl; };
	activeElements.push_back(new Button(new RectangleShape(Vector2f(110.0f, 110.0f)), PATH_BUTTON_TOWERS, Vector2f(1050.0f, 350.0f),
		"", _towerCallback));

	function<void()> _obstacleCallback = [&]() { cout << "Obstacle" << endl; };
	activeElements.push_back(new Button(new RectangleShape(Vector2f(110.0f, 110.0f)), PATH_BUTTON_OBSTACLES, Vector2f(1050.0f, 500.0f),
		"", _obstacleCallback));

	#pragma endregion
}

Cell* MapCreator::CellWhoContainsMouss()
{

	for (vector<Cell*> _cells : cells)
	{
		for (Cell* _cell : _cells)
		{
			if (_cell->cellShape->getGlobalBounds().contains(InputManager::GetInstance().GetMousePosition()))
			{
				return _cell;
			}
		}
	}
	return nullptr;
}

void MapCreator::PlaceEntityOnTheCell()
{
	Cell* _cell = CellWhoContainsMouss();

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (_cell!= nullptr)
		{
			cout << _cell->cellShape->getPosition().x << _cell->cellShape->getPosition().y << endl;

			//TODO recevoir se qu on veut placer

			//if (_cell !=)
			//{
			//	//_cell=
			//
			//
			//	switch (/*type de se qu on veut placer*/)
			//	{
			//	case R_PATH:
			//		mapCreatorInformations.pathSize += 1;
			//		break;
			//	case TDB_TOWER:
			//		mapCreatorInformations.towerCount += 1;
			//		break;
			//	case TDB_FENCE:
			//		mapCreatorInformations.trapCount += 1;
			//		break;
			//	case TDB_TRAP:
			//		mapCreatorInformations.trapCount += 1;
			//		break;
			//	default:
			//		break;
			//	}
			//}
		}
	}
}
