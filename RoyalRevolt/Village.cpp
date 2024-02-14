#include "Village.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "GameInstance.h"
#include "TimerManager.h"
#include "Farm.h"
#include "Tavern.h"

#define GOLD_PATH "UI/Gold_Texture.png"
#define DIAMOND_PATH "UI/Diamond_Texture.png"
#define BREAD_PATH "UI/Bread_Texture.png"

#define FARM_PATH "UI/Farm_Texture.png"
#define TAVERN_PATH "UI/Tavern_Texture.png"
#define MINE_PATH "UI/Mine_Texture.png"

#define BATTLE_BUTTON_PATH "UI/Battle_Button.png"
#define UPGRADE_BUTTON_PATH "UI/Upgrade_Button.png"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"

Village::Village(const string& _name) : Map(_name, Vector2f(4.0f, 4.0f))
{
	buildings = VillageInformations();

	activeElements = vector<BasicElement*>();
	elementsInformations = ElementsInformations();
}

void Village::Launch()
{
	InitUI();
	Update();
}

void Village::InitUI()
{
	function<int()> _goldDisplayCallback = [&]() {return PLAYER->GetMoney(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), GOLD_PATH, elementsInformations.goldIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.goldTextPosition, to_string(PLAYER->GetMoney()), _goldDisplayCallback));

	function<int()> _diamondDisplayCallback = [&]() {return PLAYER->GetDiamond(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), DIAMOND_PATH, elementsInformations.diamondIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.diamondTextPosition, to_string(PLAYER->GetMoney()), _diamondDisplayCallback));

	function<int()> _breadDisplayCallback = [&]() {return PLAYER->GetBread(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), BREAD_PATH, elementsInformations.breadIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.breadTextPosition, to_string(PLAYER->GetMoney()), _breadDisplayCallback));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(350.0f, 60.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.2f), "Add a bew Building", false));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, elementsInformations.tavernPriceTextInPurchasePanel, to_string(10 + (buildings.farm.level * 30)) + " Coins", false));
	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, elementsInformations.farmPriceTextInPurchasePanel, to_string(10 + (buildings.farm.level * 30)) + " Coins", false));


	function<void()> _battleCallback = [&]() {cout << "Battle !"; };
	function<void()> _upgradeCallback = [&]() {cout << "Upgrade !";	TogglePurchasePanel(); };

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), BATTLE_BUTTON_PATH, elementsInformations.battleButtonPosition,
		"", _battleCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), UPGRADE_BUTTON_PATH, elementsInformations.upgradeButtonPosition,
		"", _upgradeCallback));


	vector<PlayerRessources*> _ressourcesToPurchase;
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
		_ressourcesToPurchase, _allCallback, new RectangleShape(Vector2f(100.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.purchaseTitlePosition, "Achat", false));
}

void Village::Update()
{
	while (WINDOW.isOpen())
	{
		UpdateEvent();
		Display();
	}
}

void Village::UpdateEvent()
{
	Event _event;
	while (WINDOW.pollEvent(_event))
	{
		if (_event.type == Event::Closed) WINDOW.close();

		InputManager::GetInstance().Update(WINDOW, _event);
		UpdateActiveElements(_event);
	}
	TimerManager::GetInstance().Update();
	UpdatePassiveElements();
}

void Village::UpdateActiveElements(Event _event)
{
	bool _status = false;
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (buildings.addFarm || buildings.addTavern)
		{
			_status = true;
			for (vector<Cell*> _cells : cells)
			{
				for (Cell* _cell : _cells)
				{
					if (_cell->cellShape->getGlobalBounds().contains(InputManager::GetInstance().GetMousePosition()))
					{
						AddBuilding(_cell);
					}
				}
			}
		}		
		if (_status)
		{
			passiveElements[3]->isDraw = false;
			buildings.addFarm = false;
			buildings.addTavern = false;
		}
	}

	for (BasicElement* _element : activeElements)
	{
		if (_element->GetIsDraw()) _element->Update(_event);
	}
}

void Village::AddBuilding(Cell* _cell)
{
	if (buildings.addFarm)
	{
		_cell->entityOnCell = new Farm("Farm", _cell->cellShape->getPosition(), GetCellSize(), FARM_PATH, 0, function<void()>());
		buildings.farm.isBuild = true;
		buildings.farm.level = 1;
	}
	else if (buildings.addTavern)
	{
		_cell->entityOnCell = new Tavern("Tavern", _cell->cellShape->getPosition(), GetCellSize(), TAVERN_PATH, 0, function<void()>());
		buildings.tavern.isBuild = true;
		buildings.tavern.level = 1;
	}
}

void Village::UpdatePassiveElements()
{
	for (BasicElement* _element : passiveElements)
	{
		if (_element->GetIsDraw()) _element->Update(Event());
	}
}

void Village::TogglePurchasePanel()
{
	SelectionPanel* _panel = dynamic_cast<SelectionPanel*>(activeElements[2]);

	_panel->SetDrawAllElements(!activeElements[2]->isDraw);

	passiveElements[4]->isDraw = !passiveElements[4]->isDraw;
	passiveElements[5]->isDraw = !passiveElements[5]->isDraw;

}

void Village::AddFarm()
{
	TogglePurchasePanel();
	passiveElements[3]->isDraw = true;
	buildings.addFarm = true;
}

void Village::AddTavern()
{
	TogglePurchasePanel();
	passiveElements[3]->isDraw = true;
	buildings.addTavern = true;
}

void Village::Display()
{
	WINDOW.clear(Color::Blue);

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}

	WINDOW.display();
}
