#include "Village.h"
#include "GameWindow.h"
#include "InputManager.h"
#include "EntityManager.h"

Village::Village(const string& _name,const Vector2f& _mapSize) : Map(_name, _mapSize)
{

}

void Village::Launch()
{
	Update();
}

void Village::Update()
{	
	while (WINDOW.isOpen())
	{
		Event _event;
		while (WINDOW.pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW.close();

			InputManager::GetInstance().Update(WINDOW, _event);
		}
		Display();
	}
}

void Village::Display()
{
	WINDOW.clear(Color::Black);

	vector<Drawable*> _drawables;
	vector<Drawable*> _cellDrawables = GetDrawables();
	vector<Drawable*> _entityDrawables = EntityManager::GetInstance().GetDrawables();

	_drawables.insert(_drawables.begin(), _entityDrawables.begin(), _entityDrawables.end());
	_drawables.insert(_drawables.begin(), _cellDrawables.begin(), _cellDrawables.end());

	for (Drawable* _drawable : _drawables)
	{
		WINDOW.draw(*_drawable);
	}

	WINDOW.display();
}
