#pragma once
#include "Map.h"
#include "Interface.h"
#include "EntityManager.h"

struct BuildingInformations
{
	Vector2f position;
	bool isBuild;
	int level;
	function<void()> callback;

	BuildingInformations()
	{
		position = Vector2f();
		isBuild = false;
		level = 0;
		callback = nullptr;
	}
	BuildingInformations(const Vector2f& _position,const bool _isBuild,
		const int _level,const function<void()>& _callback)
	{
		position = _position;
		isBuild = _isBuild;
		level = _level;
		callback = _callback;
	}
};

struct VillageInformations
{
	BuildingInformations farm;
	bool addFarm;

	BuildingInformations tavern;
	bool addTavern;

	VillageInformations()
	{
		farm = BuildingInformations();
		addFarm = false;

		tavern = BuildingInformations();
		addTavern = false;
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

	ElementsInformations()
	{
		goldIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.05f);
		goldTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.05f);

		diamondIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.15f);
		diamondTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.15f);

		breadIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.25f);
		breadTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.25f);

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

		vector<Drawable*> _cellDrawables = GetCellsDrawables();
		vector<Drawable*> _entityDrawables = EntityManager::GetInstance().GetDrawables();

		_drawables.insert(_drawables.begin(), _entityDrawables.begin(), _entityDrawables.end());
		_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());

		for (BasicElement* _element : activeElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}
		for (BasicElement* _element : passiveElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}

		return _drawables;
	}

public:
	Village(const string& _name);

public:
	void Launch();
	void InitUI();

	void Update();
	void UpdateEvent();
	void UpdateActiveElements(Event _event);
	void AddBuilding(Cell* _cell);
	void UpdatePassiveElements();
	void TogglePurchasePanel();
	void AddFarm();
	void AddTavern();

	void Display();
};

