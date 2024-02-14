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
#define MINE_PATH "UI/Mine_Texture.png"

#define BATTLE_BUTTON_PATH "UI/Battle_Button.png"
#define UPGRADE_BUTTON_PATH "UI/Upgrade_Button.png"

#define FONT_TEXTURE_PATH "UI/Text_Background.png"

Village::Village(const string& _name) : Map(_name, Vector2f(4.0f,4.0f))
{
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


	function<void()> _battleCallback = [&]() {cout << "Battle !"; };
	function<void()> _upgradeCallback = [&]() {cout << "Upgrade !";	OpenPurchasePanel(); };

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), BATTLE_BUTTON_PATH, elementsInformations.battleButtonPosition,
		"", _battleCallback));

	activeElements.push_back(new Button(new RectangleShape(Vector2f(150.0f, 150.0f)), UPGRADE_BUTTON_PATH, elementsInformations.upgradeButtonPosition,
		"", _upgradeCallback));


	vector<PlayerRessources*> _ressourcesToPurchase;
	function<int()> _tavernCallback = [&]() {cout << "Purchase Tavern"; return 0; };
	function<int()> _farmCallback = [&]() {cout << "Purchase Farm"; return 0; };

	vector<function<int()>> _allCallback;
	_allCallback.push_back(_tavernCallback);
	_allCallback.push_back(_farmCallback);

	_ressourcesToPurchase.push_back(new PlayerRessources(new RectangleShape(Vector2f(100.0f, 100.0f)), TAVERN_PATH, elementsInformations.tavernInPurchasePanel,
		new RectangleShape(Vector2f(100.f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.tavernTextInPurchasePanel, "Tavern", _tavernCallback));

	_ressourcesToPurchase.push_back(new PlayerRessources(new RectangleShape(Vector2f(100.0f, 100.0f)), FARM_PATH, elementsInformations.farmInPurchasePanel,
		new RectangleShape(Vector2f(100.f, 50.0f)), FONT_TEXTURE_PATH, elementsInformations.farmTextInPurchasePanel, "Farm", _farmCallback));

	activeElements.push_back(new SelectionPanel(new RectangleShape(Vector2f(600.0f, 400.0f)), "", elementsInformations.purchasePanelPosition,
		_ressourcesToPurchase, _allCallback,new RectangleShape(Vector2f(100.0f,50.0f)),FONT_TEXTURE_PATH,elementsInformations.purchaseTitlePosition,"Achat",false));
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

void Village::OpenPurchasePanel()
{
	activeElements[2]->isDraw = !activeElements[2]->isDraw;
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
