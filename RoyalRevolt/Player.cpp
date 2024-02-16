#include "Player.h"
#include "Hero.h"
#include "Map.h"
#include "TimerManager.h"
#include "EntityManager.h"
#include "GameInstance.h"

#define PATH_HERO "Hero.png"

Vector2f Player::savedMousePosition;

Player::Player()
{
	GameInstance::GetInstance().SetPlayer(this);
	upgradesCounts = UpgradeCounts();
	spawner = new Spawner();
	data = RessourcesData();
	level = 1;
	Init();
}

void Player::Init()
{
#pragma endregion

	//inputmanager click
	new ActionMap("Interaction", { ActionData("Select", this, &Player::Actions, {Event::MouseButtonPressed, Mouse::Left}, {Event::KeyPressed, Keyboard::Space}) });
}

void Player::Actions()
{
	savedMousePosition = InputManager::GetInstance().GetMousePosition();

	// Si le player est dans TD :
	if (hero)
	{
		hero->GetMovementComponent()->SetDestination(savedMousePosition);
	}

	//if (GetEtat() == ETAT_VILLAGE)


	//if (GetEtat() == ETAT_EDITOR)

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

}
