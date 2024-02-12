#pragma once

class Entity;

class Component
{
protected:
	Entity* owner;

public:
	Component(Entity* _owner);

public:
	virtual void Update(const float _deltaTime) = 0;
};

