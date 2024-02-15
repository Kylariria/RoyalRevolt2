#include "Village.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "GameInstance.h"
#include "TimerManager.h"

#define GOLD_PATH "UI/Gold_Texture.png"
#define DIAMOND_PATH "UI/Diamond_Texture.png"
#define BREAD_PATH "UI/Bread_Texture.png"

#define FARM_PATH "UI/Farm_Texture.png"
#define TAVERN_PATH "UI/Tavern_Texture.png"
#define CASERN_PATH "UI/Casern_Texture.png"

#define BATTLE_BUTTON_PATH "UI/Battle_Button.png"
#define UPGRADE_BUTTON_PATH "UI/Upgrade_Button.png"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"

#define LEVEL_PATH "UI/Level.png"

int Player::level = 1;

Village::Village(const string& _name) : Map(_name, Vector2f(4.0f, 4.0f))
{
	buildings = VillageInformations();

	activeElements = vector<BasicElement*>();
	passiveElements = vector<BasicElement*>();
	elementsInformations = ElementsInformations();
}

void Village::Launch()
{
	InitUI();
	Update();
	AddBuilding();
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

	function<int()> _levelDisplayCallback = [&]() {return PLAYER->GetLevel(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), LEVEL_PATH, elementsInformations.LevelIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.LevelTextPosition,to_string(PLAYER->GetLevel()), _levelDisplayCallback));

	//passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, elementsInformations.tavernPriceTextInPurchasePanel, to_string(10 + (buildings.farm.level * 30)) + " Coins", false));
	//passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(150.0f, 60.0f)), FONT_TEXTURE_PATH, elementsInformations.farmPriceTextInPurchasePanel, to_string(10 + (buildings.farm.level * 30)) + " Coins", false));


	function<void()> _battleCallback = [&]() {cout << "Battle !"; Battle(); };
	function<void()> _upgradeCallback = [&]() {cout << "Upgrade !";	};

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), BATTLE_BUTTON_PATH, elementsInformations.battleButtonPosition,
		"", _battleCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), UPGRADE_BUTTON_PATH, elementsInformations.upgradeButtonPosition,
		"", _upgradeCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), TAVERN_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.4f), "", [&]() {; }));
	activeElements[2]->shape->setFillColor(Color(255, 255, 255, 100));
	
	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), FARM_PATH, Vector2f(SCREEN_WIDTH * 0.6f, SCREEN_HEIGHT * 0.6f), "", [&]() {; }));
	activeElements[3]->shape->setFillColor(Color(255, 255, 255, 100));
	
	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), CASERN_PATH, Vector2f(SCREEN_WIDTH * 0.4f, SCREEN_HEIGHT * 0.6f), "", [&]() {; }));
	activeElements[4]->shape->setFillColor(Color(255, 255, 255, 100));
}

void Village::AddBuilding()
{
	buildings.farm = new VillageBuilding("Farm", Vector2f(), ENTITY_BUILDINGS, nullptr, VB_FARM, Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
	buildings.tavern = new VillageBuilding("Tavern", Vector2f(), ENTITY_BUILDINGS, nullptr, VB_TAVERN, Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
	buildings.casern = new VillageBuilding("Casern", Vector2f(), ENTITY_BUILDINGS, nullptr, VB_CASERN, Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
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
	for (BasicElement* _element : activeElements)
	{
		if (_element->GetIsDraw()) _element->Update(_event);
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

void Village::Battle()
{
	GameInstance::GetInstance().LaunchTD();
}

void Village::AddFarm()
{
	TogglePurchasePanel();
	passiveElements[3]->isDraw = true;
}

void Village::AddTavern()
{
	TogglePurchasePanel();
	passiveElements[3]->isDraw = true;
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
