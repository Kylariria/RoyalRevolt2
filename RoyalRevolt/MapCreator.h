#pragma once
#include "Map.h"
#include "GameWindow.h"

class MapCreator : public Map
{
	vector<vector<Entity*>> map;


public:
	vector<Drawable*> GetDrawables()
	{
		vector<Drawable*> _drawables;

		vector<Drawable*> _cellDrawables = GetCellsDrawables();
		_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());

		for (vector<Cell*> _cells : cells)
		{
			for (Cell* _cell : _cells)
			{
				//_cell->cellShape->setFillColor(Color(255, 255, 255, 0));
				_cell->cellShape->setOutlineThickness(1.0f);
				_drawables.push_back(_cell->cellShape);
			}
		}

		return _drawables;
	}

public:
	MapCreator(const string& _name, const Vector2f& _mapSize);

public:
	void Launch();
	void Update();
	void Display();


	template<typename T>
	void AddBuilding(Cell* _cell)
	{
		Vector2f _size = Map::GetCellSize();
		_cell->entityOnCell = new T(to_string(T), Vector2f(0.0f,0.0f), to_string(T)+".png", _size);
	};


};
