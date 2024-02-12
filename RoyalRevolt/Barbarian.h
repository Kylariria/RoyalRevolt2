#pragma once
#include "Troop.h"

class Barbarian : public Troop
{

public:
	Barbarian(const string& _name, const Vector2f& _position, const Vector2f& _size);

public:
	virtual void Update() override;

};