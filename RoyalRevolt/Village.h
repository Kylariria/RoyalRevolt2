#pragma once
#include "Map.h"
#include "Interface.h"
#include "EntityManager.h"

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
	}
};

class Village : public Map
{
	ElementsInformations elementsInformations;
	vector<BasicElement*> activeElements;
	vector<BasicElement*> passiveElements;

public:
	vector<Drawable*> GetDrawables() const
	{
		vector<Drawable*> _drawables;

		vector<Drawable*> _cellDrawables = GetCellsDrawables();
		vector<Drawable*> _entityDrawables = EntityManager::GetInstance().GetDrawables();

		_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());
		_drawables.insert(_drawables.begin(), _entityDrawables.begin(), _entityDrawables.end());


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
	void UpdatePassiveElements();

	void Display();
};

