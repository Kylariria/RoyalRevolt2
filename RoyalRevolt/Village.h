#pragma once
#include "Map.h"
#include "Interface.h"
#include "EntityManager.h"


struct VillageInformations
{
	Farm* farm;

	Tavern* tavern;

	VillageInformations()
	{
		farm = nullptr;

		tavern = nullptr;
	}
};

struct ElementsInformations
{
	Vector2f goldIconPosition;
	Vector2f goldTextPosition;

	Vector2f diamondIconPosition;
	Vector2f diamondTextPosition;

	Vector2f breadIconPosition;
	Vector2f breadTextPosition;

	Vector2f battleButtonPosition;
	Vector2f upgradeButtonPosition;

	Vector2f tavernInPurchasePanel;
	Vector2f tavernTextInPurchasePanel;
	Vector2f tavernPriceTextInPurchasePanel;

	Vector2f farmInPurchasePanel;
	Vector2f farmTextInPurchasePanel;
	Vector2f farmPriceTextInPurchasePanel;

	Vector2f purchasePanelPosition;
	Vector2f purchaseTitlePosition;

	Vector2f LevelTextPosition;
	Vector2f LevelIconPosition;

	ElementsInformations()
	{
		goldIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.05f);
		goldTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.05f);

		diamondIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.15f);
		diamondTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.15f);

		breadIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.25f);
		breadTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.25f);

		LevelTextPosition = Vector2f(SCREEN_WIDTH * 0.9f, SCREEN_HEIGHT * 0.05f);
		LevelIconPosition = Vector2f(SCREEN_WIDTH * 0.83f, SCREEN_HEIGHT * 0.045f);

		battleButtonPosition = Vector2f(SCREEN_WIDTH * 0.9f, SCREEN_HEIGHT * 0.9f);
		upgradeButtonPosition = Vector2f(SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.9f);

		purchasePanelPosition = Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		purchaseTitlePosition = Vector2f(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f);

		tavernInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.5f);
		tavernTextInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.6f);
		tavernPriceTextInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.4f);

		farmInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.65, SCREEN_HEIGHT * 0.5f);
		farmTextInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.6f);
		farmPriceTextInPurchasePanel = Vector2f(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.4f);

	}
};

class Village : public Map
{
	VillageInformations buildings;

	ElementsInformations elementsInformations;

	vector<BasicElement*> activeElements;
	vector<BasicElement*> passiveElements;

public:
	vector<Drawable*> GetDrawables() const
	{
		vector<Drawable*> _drawables;

		_drawables.push_back(background);

		vector<Drawable*> _entityDrawables = EntityManager::GetInstance().GetDrawables();

		_drawables.insert(_drawables.begin(), _entityDrawables.begin(), _entityDrawables.end());

		for (BasicElement* _element : activeElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}
		for (BasicElement* _element : passiveElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}

		_drawables.push_back(buildings.farm.)

		return _drawables;
	}

public:
	Village(const string& _name);

public:
	void Launch();
	void InitUI();
	void AddBuilding();

	void Update();
	void UpdateEvent();
	void UpdateActiveElements(Event _event);
	void UpdatePassiveElements();
	void TogglePurchasePanel();
	void Battle();
	void AddFarm();
	void AddTavern();

	void Display();
};

