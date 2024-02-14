#pragma once
#include "Map.h"
#include "GameWindow.h"

class TowerDefense : public Map
{
	vector<string> allLevel;
	Vector2f mapSize;
	int level;


	vector<vector<Entity*>> map;
public:
	TowerDefense(const string& _name, const Vector2f& _mapSize, const int _level);

	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;

		for (vector<Cell*> _cells : cells)
		{
			for (Cell* _cell : _cells)
			{
				_drawables.push_back(_cell->cellShape);
			}
		}
		return _drawables;
	}

public:
	void Launch();
	
	void Update();

	void Display();
};

