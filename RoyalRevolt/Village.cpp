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
	buildings = new VillageInformations();

	activeElements = vector<BasicElement*>();
	passiveElements = vector<BasicElement*>();
	elementsInformations = ElementsInformations();
}

void Village::Launch()
{
	InitUI();
	AddBuilding();
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

	function<int()> _levelDisplayCallback = [&]() {return PLAYER->GetLevel(); };
	passiveElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(60.0f, 60.0f)), LEVEL_PATH, elementsInformations.LevelIconPosition,
		new RectangleShape(Vector2f(150.0f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.LevelTextPosition,to_string(PLAYER->GetLevel()), _levelDisplayCallback));

	function<void()> _battleCallback = [&]() {cout << "Battle !"; Battle(); };
	function<void()> _upgradeCallback = [&]() {cout << "Upgrade !"; MapCreator();	};

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), BATTLE_BUTTON_PATH, elementsInformations.battleButtonPosition,
		"", _battleCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), UPGRADE_BUTTON_PATH, elementsInformations.upgradeButtonPosition,
		"", _upgradeCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), TAVERN_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.4f), "", [&]() {buildings->selectedBuilding = buildings->tavern ; TogglePurchasePanel(); }));
	
	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), FARM_PATH, Vector2f(SCREEN_WIDTH * 0.6f, SCREEN_HEIGHT * 0.6f), "", [&]() {buildings->selectedBuilding = buildings->farm; TogglePurchasePanel();; }));
	
	activeElements.push_back(new Button(new RectangleShape(Vector2f(100.0f, 100.f)), CASERN_PATH, Vector2f(SCREEN_WIDTH * 0.4f, SCREEN_HEIGHT * 0.6f), "", [&]() {buildings->selectedBuilding = buildings->casern; TogglePurchasePanel();; }));

	vector<PlayerRessources*> _panelElements;
	vector<function<int()>> _callbackElements;

	_callbackElements.push_back([&]() {UpgradeSelectedElement(); return 0; });

	_panelElements.push_back(new PlayerRessources(new RectangleShape(Vector2f(50.0f, 50.0f)), GOLD_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f),
		new RectangleShape(Vector2f(50.0f, 50.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.4f), "", [&]() { return 0; }));

	activeElements.push_back(new SelectionPanel(new RectangleShape(Vector2f(400.0f, 400.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f),
		_panelElements, _callbackElements,new RectangleShape(Vector2f(100.f,50.0f)),FONT_TEXTURE_PATH,Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f),"Purchase",false));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(200.0f, 50.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.45f, SCREEN_HEIGHT * 0.6f), "", false));

	passiveElements.push_back(new SpecialText(new RectangleShape(Vector2f(200.0f, 50.0f)), FONT_TEXTURE_PATH, Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.2f), "You don't have enough gold", false));
}

void Village::AddBuilding()
{
	new Timer("GoldTimer", [&]() {PLAYER->AddMoney(buildings->tavern->GetLevel() * 2); }, seconds(2.0f), false, true);
	buildings->farm = new VillageBuilding("Farm", Vector2f(), ENTITY_BUILDINGS, [&]() {PLAYER->UpdateBreadLimit(); }, VB_FARM, "Farm", Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
	buildings->tavern = new VillageBuilding("Tavern", Vector2f(), ENTITY_BUILDINGS, [&]() {TimerManager::GetInstance().Get("GoldTimer")->Start(); }, VB_TAVERN, "Tavern", Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
	buildings->casern = new VillageBuilding("Casern", Vector2f(), ENTITY_BUILDINGS, [&]() {; }, VB_CASERN, "Casern", Vector2f(100.0f, 100.0f), FARM_PATH, 0, false);
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
	SelectionPanel* _panel = dynamic_cast<SelectionPanel*>(activeElements[5]);
	_panel->title.text.setString(buildings->selectedBuilding->GetName() + " : " + to_string(buildings->selectedBuilding->GetLevel()));
	
	_panel->SetDrawAllElements(!activeElements[5]->isDraw);


	SpecialText* _text = dynamic_cast<SpecialText*>(passiveElements[4]);
	_text->text.setString("Price : " + to_string(buildings->selectedBuilding->GetLevel() * 30 + 10));

	_text->isDraw = !_text->isDraw;

}

void Village::Battle()
{
	GameInstance::GetInstance().LaunchTD();
}

void Village::MapCreator()
{
	GameInstance::GetInstance().LaunchMapCreator();
}


void Village::UpgradeSelectedElement()
{
	const int _value = buildings->selectedBuilding->GetLevel() * 30 + 10;
	if (PLAYER->GetMoney() >= _value)
	{
		PLAYER->RemoveGold(_value);
		buildings->selectedBuilding->UpgradeLevel();
	}
	else
	{
		ShowInfoText();
	}

	TogglePurchasePanel();
}

void Village::ShowInfoText()
{
	passiveElements[5]->isDraw = true;
	new Timer("hideText", [&]() {passiveElements[5]->isDraw = false; }, seconds(3.0f));
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
