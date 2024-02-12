#pragma once
#include "Troop.h"
class Archer : public Troop
{

public: 
	Archer(const string& _name, const Vector2f& _position, const Vector2f& _size);

public:
	virtual void Update() override;
};

