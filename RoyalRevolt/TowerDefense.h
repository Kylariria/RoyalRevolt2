#pragma once
#include "Map.h"
#include "GameWindow.h"
#include "Interface.h"

class TowerDefense : public Map
{
	vector<string> allLevel;
	Vector2f mapSize;
	int level;

	MovingBar* spawnBar;
	MovingBar* lifeBar;

	Shape* character;

	vector<BasicElement*> activeElements;
	vector<BasicElement*> passiveElements;

public:
	TowerDefense(const string& _name, const Vector2f& _mapSize, const int _level);

	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;

		vector<Drawable*> _cellDrawables = GetCellsDrawables();
		_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());

		for (BasicElement* _element : activeElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}

		return _drawables;
	}

	~TowerDefense()
	{
		delete lifeBar;
		delete spawnBar;

		for (BasicElement* _element : activeElements)
		{
			delete _element;
		}
	};

public:
	void Launch();
	void InitUI();
	
	void Update();
	void UpdateActiveElements(Event _event);

	void Spawn();
	void Spell();
	void Pause();

	void Display();
};

