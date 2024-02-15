#include "MapCreator.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "GameInstance.h"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"
#define PATH_BUTTON_OBSTACLES "UI/ButtonObstacles.png"
#define PATH_BUTTON_TOWERS "UI/ButtonTowers.png"


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

	}
	mapCreatorInformations = MapCreatorInformations();
	InitUI();*/
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
	}

}

void MapCreator::UpdateEvent()
{
	Event _event;
	while (WINDOW.pollEvent(_event))
	{
		if (_event.type == Event::Closed) WINDOW.close();
		InputManager::GetInstance().Update(WINDOW, _event);

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

	function<int()> _goldDisplayCallback = [&]() {return PLAYER->GetMoney(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.goldIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.goldTextPosition, to_string(PLAYER->GetMoney()), _goldDisplayCallback));

	function<int()> _diamondDisplayCallback = [&]() {return PLAYER->GetDiamond(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), PATH_BUTTON_TOWERS, mapCreatorInformations.diamondIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.diamondTextPosition, to_string(PLAYER->GetMoney()), _diamondDisplayCallback));

	function<int()> _breadDisplayCallback = [&]() {return PLAYER->GetBread(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), "UI/ButtonObstacles.png", mapCreatorInformations.breadIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.breadTextPosition, to_string(PLAYER->GetMoney()), _breadDisplayCallback));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(350.0f, 60.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.2f), "Add a bew Building", false));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.tavernPriceTextInPurchasePanel, to_string(10) + " Coins", false));
	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, mapCreatorInformations.farmPriceTextInPurchasePanel, to_string(10) + " Coins", false));

	/*vector<PlayerRessources*> _ressourcesToPurchase;
	function<int()> _tavernCallback = [&]() {cout << "Purchase Tavern" << endl; AddTavern(); return 0; };
	function<int()> _farmCallback = [&]() {cout << "Purchase Farm" << endl; AddFarm(); return 0; };

	vector<function<int()>> _allCallback;
	_allCallback.push_back(_tavernCallback);
	_allCallback.push_back(_farmCallback);

	_ressourcesToPurchase.push_back(new PlayerRessources(new RectangleShape(Vector2f(100.0f, 100.0f)), TAVERN_PATH, elementsInformations.tavernInPurchasePanel,
		new RectangleShape(Vector2f(100.f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.tavernTextInPurchasePanel, "Tavern", _tavernCallback));

	_ressourcesToPurchase.push_back(new PlayerRessources(new RectangleShape(Vector2f(100.0f, 100.0f)), FARM_PATH, elementsInformations.farmInPurchasePanel,
		new RectangleShape(Vector2f(100.f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.farmTextInPurchasePanel, "Farm", _farmCallback));

	activeElements.push_back(new SelectionPanel(new RectangleShape(Vector2f(600.0f, 400.0f)), "", elementsInformations.purchasePanelPosition,
		_ressourcesToPurchase, _allCallback, new RectangleShape(Vector2f(100.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.purchaseTitlePosition, "Achat", false));*/

	
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

}
