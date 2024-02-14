#include "MapCreator.h"
#include "EntityManager.h"

MapCreator::MapCreator(const string& _name, const Vector2f& _mapSize) : Map(_name, _mapSize)
{
	map = vector<vector<Entity*>>();
	vector<Entity*> _line;

	for (int _i = 0; _i < _mapSize.x; _i++)
	{
		_line.push_back(nullptr);

	}
	for (int _i = 0; _i < _mapSize.y; _i++)
	{
		map.push_back(_line);
	}
}

void MapCreator::Launch()
{
	Update();
}

void MapCreator::Update()
{
	// similaire au village sauf qu au lieu que se soit des ferme, etc ... c les REMOVABLE


	//quand on depose sa enrgiste dans le map qui est constituer

	while (WINDOW.isOpen())
	{
		Display();
	}

	cout << map.size();
	cout << map[0].size();

}

void MapCreator::Display()
{
	WINDOW.clear(Color::Black);

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}

	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		WINDOW.draw(*_entity->GetShape());
	}

	WINDOW.display();
}