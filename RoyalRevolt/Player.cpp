#include "Player.h"
#include "Hero.h"
#include "Map.h"

#define PATH_HERO "Hero.png"

Player::Player()
{
	hero = new Hero("Hero", ENTITY_PLAYER, Vector2f(), Map::GetCellSize(), PATH_HERO);
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
	hero->GetMovementComponent()->Move();
	cout << "bite" << endl;
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