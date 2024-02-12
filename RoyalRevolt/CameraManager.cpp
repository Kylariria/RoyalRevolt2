#include "CameraManager.h"
#include "Macro.h"

void CameraManager::Update(RenderWindow _window, const Vector2f& _position)
{
	CameraData* _camera = GetCurrent();
	_camera->SetCenter(_position);
}
