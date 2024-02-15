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

	MapCreatorInformations()
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
				_cell->cellShape->setFillColor(Color::White);
				_cell->cellShape->setOutlineThickness(1.0f);
				_cell->cellShape->setOutlineColor(Color::Black);
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
