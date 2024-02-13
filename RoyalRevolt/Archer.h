#pragma once
#include "Troop.h"
class Archer : public Troop
{

public: 
	Archer(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
};

