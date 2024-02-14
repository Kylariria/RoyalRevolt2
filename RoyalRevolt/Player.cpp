#include "Player.h"
#include "Hero.h"
#include "Map.h"
#include "TimerManager.h"
#include "EntityManager.h"
#define PATH_HERO "Hero.png"

Vector2f Player::savedMousePosition;

Player::Player()
{
	hero = new Hero("Hero", Vector2f(), Map::GetCellSize(), PATH_HERO, ENTITY_PLAYER);
	upgradesCounts = UpgradeCounts();
	spawner = new Spawner();
	level = 1;
	Init();
}

void Player::Init()
{
#pragma region Timer
	function<void()> _addCoinCallback = [&]() {data.money += upgradesCounts.money; };
	new Timer("AddCoin", _addCoinCallback, seconds(1.0f), true, true);

	function<void()> _addDiamondCallback = [&]() {data.diamond += upgradesCounts.diamond; };
	new Timer("AddDiamond", _addDiamondCallback, seconds(1.0f), true, true);

	function<void()> _addBreadCallback = [&]() {data.bread += upgradesCounts.bread; };
	new Timer("AddBread", _addBreadCallback, seconds(1.0f), true, true);

#pragma endregion
	//inputmanager click
	new ActionMap("Interaction", { ActionData("Select", this, &Player::Actions, {Event::MouseButtonPressed, Mouse::Left}, {Event::KeyPressed, Keyboard::Space}) });
}

void Player::Actions()
{
	spawner->Update();
	savedMousePosition = InputManager::GetInstance().GetMousePosition();

		// Si le player est dans TD :
		if (true /*TODO : Etat Player*/)
		{
			for (Entity* _entityHero : EntityManager::GetInstance().GetAllValues())
			{
				if (Hero* _hero = dynamic_cast<Hero*>(_entityHero))
				{
					_hero->GetMovementComponent()->SetDestination(savedMousePosition);
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

}
