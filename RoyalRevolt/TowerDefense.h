#pragma once
#include "Map.h"
#include "GameWindow.h"
#include "Interface.h"

class TowerDefense : public Map
{
	vector<string> allLevel;
	Vector2f mapSize;
	int level;

	MovingBar* movingBar;

	vector<BasicElement*> activeElements;
	vector<BasicElement*> passiveElements;

public:
	TowerDefense(const string& _name, const Vector2f& _mapSize, const int _level);

	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;

		vector<Drawable*> _cellDrawables = GetCellsDrawables();
		_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());

		for (vector<Cell*> _cells : cells)
		{
			for (Cell* _cell : _cells)
			{
				_drawables.push_back(_cell->cellShape);
			}
		}

		for (BasicElement* _element : activeElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}

		return _drawables;
	}

	~TowerDefense()
	{
		delete movingBar;

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

