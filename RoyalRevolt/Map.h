#pragma once
#include <SFML/Graphics.hpp>
#include "IManagable.h"
#include "Macro.h"
#include "Entity.h"
#include <vector>

using namespace sf;
using namespace std;

struct Cell
{
	Shape* cellShape;
	Entity* entityOnCell;
	bool isRoad;
	
	Cell(const Vector2f& _cellSize)
	{
		cellShape = new RectangleShape(_cellSize);
		entityOnCell = nullptr;
		isRoad = false;
	}
};

class Map : public IManagable<string>
{
	static Vector2f cellSize;
	Vector2f cellCount;
	Shape* background;

protected:
	vector<vector<Cell*>> cells;

public:
	static Vector2f GetCellSize() 
	{
		return cellSize;
	}
	vector<Drawable*> GetCellsDrawables() const
	{
		vector<Drawable*> _drawables;

		_drawables.push_back(background);

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
	Map(const string& _name,const Vector2f& _mapSize);

public:
	void Init();
	virtual void Register() override;

};

