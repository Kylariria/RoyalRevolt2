#include "Player.h"

Player::Player()
{
	Init();
}

void Player::Init()
{
	//inputmanager click
	new ActionMap("Interaction", { ActionData("Select", this, &Player::Actions, {Event::MouseButtonPressed, Mouse::Left}, {Event::KeyPressed, Keyboard::Space}) });
}

void Player::Actions()
{
	const Vector2f& _mousePosition = InputManager::GetInstance().GetMousePosition();

	//for (Button* _button : Menu::GetButtons())
	//{
	//	//if contains mouse position
	//	if (_button->GetShape()->getGlobalBounds().contains(_mousePosition))
	//	{
	//		//call action
	//		_button->ExecuteCallback();
	//	}
	//}
}