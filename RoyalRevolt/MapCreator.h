#pragma once
#include "Map.h"
#include "GameWindow.h"
#include "Interface.h"


struct MapCreatorInformations
{
	Vector2f goldIconPosition;
	Vector2f goldTextPosition;

	Vector2f diamondIconPosition;
	Vector2f diamondTextPosition;

	Vector2f breadIconPosition;
	Vector2f breadTextPosition;


	MapCreatorInformations()
	{
		goldIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.05f);
		goldTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.05f);

		diamondIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.15f);
		diamondTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.15f);

		breadIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.25f);
		breadTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.25f);

	}
};



class MapCreator : public Map
{
	Entity* _currentEntity;
	vector<BasicElement*> passiveElements;
	MapCreatorInformations mapCreatorInformations;
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
				_cell->cellShape->setFillColor(Color(255, 255, 255, 0));
				_cell->cellShape->setOutlineThickness(1.0f);
				_cell->cellShape->setOutlineColor(Color(0.0f, 0.0f, 0.0f));
				_drawables.push_back(_cell->cellShape);
			}
		}

		for (BasicElement* _element : passiveElements)
		{
			if (_element->GetIsDraw()) _element->PutInDrawables(_drawables);
		}

		return _drawables;
	}

public:
	MapCreator(const string& _name, const Vector2f& _mapSize);

public:
	void Launch();
	void Update();
	void UpdateEvent();
	void Display();
	void InitUI();


	Cell* CellWhoContainsMouss();
	void PlaceEntityOnTheCell();


	template<typename T>
	void AddBuilding(Cell* _cell)
	{
		Vector2f _size = Map::GetCellSize();
		_cell->entityOnCell = new T(to_string(T), Vector2f(0.0f,0.0f), to_string(T)+".png", _size);
	};


};
