#pragma once
#include "GameInstance.h"
#include "Map.h"
#include "Interface.h"

class Menu : public Map
{
	vector<BasicElement*> elements;

public:
	vector<Drawable*> GetDrawables() const
	{
		vector<Drawable*> _drawables;

		_drawables.push_back(background);

		for (BasicElement* _element : elements)
		{
			_drawables.push_back(_element->GetShape());
		}

		return _drawables;
	}
public:
	Menu();
	~Menu();

public:
	void Launch();

	void Update();
	void UpdateElements(const Event& _event);

	void Display();
};

