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
	Vector2f position;
	Vector2f size;
	string path;

	EntityData(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path = "")
	{
		name = _name;
		position = _position;
		size = _size;
		path = _path;
	}
};

class Entity : public IManagable<string>
{
protected:
	Shape* shape;
	vector<Component*> components;

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

public:
	Entity(const EntityData& _data);
	~Entity();

private:
	virtual void Register() override;

public:
	void Update();
};