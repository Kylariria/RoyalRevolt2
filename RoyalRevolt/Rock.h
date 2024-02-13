#pragma once
#include "Removable.h"

class Rock : public Removable
{
public :
	Rock(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
};

