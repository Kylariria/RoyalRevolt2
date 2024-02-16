#pragma once
#include "Map.h"
#include "GameWindow.h"
#include "Interface.h"
#include "FileManager.h"


struct MapCreatorInformations
{
	Vector2f pathIconPosition;
	Vector2f pathTextPosition;
	int pathSize;
	int pathSizeMax;

	Vector2f towerIconPosition;
	Vector2f towerTextPosition;
	int towerCount;
	int towerCountMax;

	Vector2f trapIconPosition;
	Vector2f trapTextPosition;
	int trapCount;
	int trapCountMax;

	Vector2f pathButtonPosition;
	Vector2f towerButtonPosition;
	Vector2f trapButtonPosition;

	MapCreatorInformations()
	{
		pathIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.05f);
		pathTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.05f);
		pathSize = 0;
		pathSizeMax = 15;

		towerIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.15f);
		towerTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.15f);
		towerCount = 0;
		towerCountMax = 5;


		trapIconPosition = Vector2f(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.25f);
		trapTextPosition = Vector2f(SCREEN_WIDTH * 0.125f, SCREEN_HEIGHT * 0.25f);
		trapCount = 0;
		trapCountMax = 5;
	}
};



class MapCreator : public Map
{
	FileManager fileManager;
	Entity* currentEntity;

	vector<BasicElement*> passiveElements;
	vector<BasicElement*> activeElements;

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
				_cell->cellShape->setFillColor(Color::Transparent);
				_cell->cellShape->setOutlineThickness(1.0f);
				_cell->cellShape->setOutlineColor(Color::Black);
				_drawables.push_back(_cell->cellShape);

				if (_cell->entityOnCell != nullptr)
				{
					_drawables.push_back(_cell->entityOnCell->GetShape());
				}
			}
		}

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
	MapCreator(const string& _name, const Vector2f& _mapSize);
	~MapCreator();

public:
	void Launch();
	void Update();
	void UpdateEvent();
	void UpdateElements(const Event& _event);
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
