#include "Entity.h"
#include "EntityManager.h"
#include "TextureManager.h"
#include "TimerManager.h"
#include "Component.h"
#include "Macro.h"

Entity::Entity(const EntityData& _data) : IManagable(S_ID(_data.name))
{
	Register();

	shape = new RectangleShape(_data.size);
	shape->setPosition(_data.position);
	TextureManager::GetInstance().Load(shape, _data.path);
}

Entity::~Entity()
{
	delete shape;

	for (Component* _component : components)
	{
		delete _component;
	}
}

void Entity::Register()
{
	EntityManager::GetInstance().Add(id, this);
}

void Entity::Update()
{
	for (Component* _component : components)
	{
		const float _deltaTime = TimerManager::GetInstance().GetDeltaTime();
		_component->Update(_deltaTime);
	}
}
