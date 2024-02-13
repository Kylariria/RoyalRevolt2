#include "Player.h"
#include "Hero.h"

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
	// Si le player est dans TD :
	// 
	//
	// On récup la position de la souris
	const Vector2f& _mousePosition = InputManager::GetInstance().GetMousePosition();


	// La shape se déplace à la position de la souris
	//Hero _hero;
	//_hero.GetShape().move(_mousePosition.x, _mousePosition.y);

	//// si HERO rencontre obstacle >> STOP
	//if (_hero)
	//{

	//}

	//for (Button* _button : Menu::GetButtons())
	//{
	//	//if contains mouse position
	//	if (_button->GetShape()->getGlobalBounds().contains(_mousePosition))
	//	{
	//		//call action
	//		_button->ExecuteCallback();
	//	}
	//}

};