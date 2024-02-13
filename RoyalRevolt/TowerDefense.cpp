#include "TowerDefense.h"
#include "Macro.h"

TowerDefense::TowerDefense(const string& _name,const Vector2f& _mapSize) : Map(_name, _mapSize)
{

}

void TowerDefense::Launch()
{
	Update();
}

void TowerDefense::Update()
{
	while (WINDOW.isOpen())
	{
		Event _event;
		while (WINDOW.pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW.close();
		}
		Display();
	}
}

void TowerDefense::Display()
{
	WINDOW.clear(Color::Black);

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}

	WINDOW.display();
}
