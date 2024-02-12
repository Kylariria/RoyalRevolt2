#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "CameraData.h"

class CameraManager : public Singleton<CameraManager>, public IManager<string,CameraData>
{

public:
	void Update(RenderWindow _window,const Vector2f& _position);
};

