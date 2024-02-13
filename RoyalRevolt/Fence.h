#pragma once
#include "Removable.h"
class Fence : public Removable
{
public:
	Fence(const string& _name, const Vector2f& _position, const Vector2f& _size, const string& _path);

public:
	virtual void Update() override;
};

