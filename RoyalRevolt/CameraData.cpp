#include "CameraData.h"
#include "CameraManager.h"
#include "Macro.h"

CameraData::CameraData(const string& _id) : IManagable(_id)
{
	view = View();
	center = Vector2f();

	Init();
}

void CameraData::Init()
{
	const Vector2f& _screenSize = Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);

	view = View(center, _screenSize);
}

void CameraData::SetCenter(const Vector2f& _center)
{
	view.setCenter(_center);
}

void CameraData::Register()
{
	CameraManager::GetInstance().Add(id, this);
}
