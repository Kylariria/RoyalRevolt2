#pragma once

#include "IManagable.h"
#include "EntityType.h"
#include "IManagable.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Component;

using namespace std;
using namespace sf;

struct EntityData
{
	string name;
	EntityType type;
	Vector2f position;
	Vector2f size;
	string path;

	EntityData(const string& _name, const EntityType& _type, const Vector2f& _position,
		const Vector2f& _size, const string& _path = "")
	{
		name = _name;
		type = _type;
		position = _position;
		size = _size;
		path = _path;
	}

	EntityType GetType() const
	{
		return type;
	}
};

class Entity : public IManagable<string>
{
protected:
	Shape* shape;
	vector<Component*> components;
	EntityData* data;

public:
	template<typename T>
	T* GetComponent()const
	{
		for (Component* _component : components)
		{
			if (T* _components = dynamic_cast<T*>(_component))
			{
				return _components;
			}
		}

		return nullptr;
	}

	Shape* GetShape() const
	{
		return shape;
	}
	Vector2f GetShapePosition() const
	{
		if (!shape) return Vector2f();
		return shape->getPosition();
	}
	EntityData* GetEntityData() const
	{
		return data;
	}

public:
	Entity(const EntityData& _data);
	~Entity();

private:
	virtual void Register() override;

public:
	void Update();
};