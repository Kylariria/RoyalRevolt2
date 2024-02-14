#include "Player.h"
#include "Hero.h"
#include "Map.h"
#include "EntityManager.h"

#define PATH_HERO "Hero.png"

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
	if (true /*TODO : Etat Player*/)
	{
		for (Entity* _entityHero : EntityManager::GetInstance().GetAllValues())
		{
			if (dynamic_cast<Hero*>(_entityHero))
			{
				Hero* _hero = dynamic_cast<Hero*>(_entityHero);

				_hero->GetMovementComponent()->Move();
			}
		}
	}


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