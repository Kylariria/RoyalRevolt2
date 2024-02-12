#pragma once
#include "IManagable.h"
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Component;

struct EntityData
{
	string name;
	Vector2f position;
	Vector2f size;
	string path;

	EntityData(const string& _name, const Vector2f& _position, const Vector2f& _size,
		const string& _path = "")
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
	vector<Component*> components;
	Shape* shape;

public:

	template <typename T>
	T* GetComponent() const
	{
		for (Component* _currentComponent : components)
		{
			if (T* _component = dynamic_cast<T*>(_currentComponent))
			{
				return _component;
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