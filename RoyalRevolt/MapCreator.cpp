#include "MapCreator.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "GameInstance.h"
#include "Removable.h"
#include "TowerDefenseBuilding.h"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"
#define PATH_BUTTON_OBSTACLES "UI/ButtonObstacle.png"
#define PATH_BUTTON_TOWERS "UI/ButtonTower.png"
#define PATH_BUTTON_PATH "UI/ButtonPath.png"


MapCreator::MapCreator(const string& _name, const Vector2f& _mapSize) : Map(_name, _mapSize)
{
	/*_currentEntity = new Grass("Grass", Vector2f(100.0f, 20.0f), Vector2f(50.0f, 50.0f), "Grass.png");

	for (int _index = 0; _index < _mapSize.x; _index++)
	{
		for (int _i = 0; _i < _mapSize.y; _i++)
		{
			Grass* _grass= new Grass("Grass", Vector2f(100.0f, 20.0f), Vector2f(50.0f, 50.0f), "Grass.png");
			cells[_index][_i]->entityOnCell = _grass;
			_grass->GetShape()->setPosition(cells[_index][_i]->cellShape->getPosition());
			_grass->GetShape()->setScale(cells[_index][_i]->cellShape->getScale());
			cells[_index][_i]->cellShape = _grass->GetShape();
		}

	}*/


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
	InitUI();
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
		UpdatePassiveElements();
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

		PlaceEntityOnTheCell();
		

	}
}

void MapCreator::UpdatePassiveElements()
{
	for (BasicElement* _element : passiveElements)
	{
		if (_element->GetIsDraw()) _element->Update(Event());
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
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_BUTTON_PATH, mapCreatorInformations.pathIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.pathTextPosition, to_string(PLAYER->GetMoney()), _pathDisplayCallback));

	function<int()> _towerDisplayCallback = [&]() {return mapCreatorInformations.towerCount; };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_BUTTON_TOWERS, mapCreatorInformations.towerIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.towerTextPosition, to_string(PLAYER->GetMoney()), _towerDisplayCallback));

	function<int()> _trapDisplayCallback = [&]() {return mapCreatorInformations.trapCount; };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_BUTTON_OBSTACLES, mapCreatorInformations.trapIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.trapTextPosition, to_string(PLAYER->GetMoney()), _trapDisplayCallback));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(350.0f, 60.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.2f), "Add a bew Building", false));
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
