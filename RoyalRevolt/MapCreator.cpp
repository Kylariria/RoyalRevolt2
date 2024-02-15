#include "MapCreator.h"
#include "EntityManager.h"
#include "Grass.h"

MapCreator::MapCreator(const string& _name, const Vector2f& _mapSize) : Map(_name, _mapSize)
{

	for (int _index = 0; _index < _mapSize.x; _index++)
	{
		for (int _i = 0; _i < _mapSize.y; _i++)
		{
			Grass* _grass= new Grass("Grass", Vector2f(100.0f, 20.0f), Vector2f(50.0f, 50.0f), "Grass.png");
			cells[_index][_i]->entityOnCell = _grass;
			_grass->GetShape()->setPosition(cells[_index][_i]->cellShape->getPosition());
			_grass->GetShape()->setScale(cells[_index][_i]->cellShape->getScale());
			cells[_index][_i]->cellShape = _grass->GetShape();
		}

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
		Event _event;
		while (WINDOW.pollEvent(_event))
		{

		}

		Display();
	}

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