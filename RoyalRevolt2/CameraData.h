#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "IManagable.h"

using namespace sf;
using namespace std;

class CameraData : public IManagable<string>
{
	View view;
	Vector2f center;

public:
	CameraData(const string& _id);

private:
	void Init();

public:
	void SetCenter(const Vector2f& _center);
	virtual void Register() override;

};
