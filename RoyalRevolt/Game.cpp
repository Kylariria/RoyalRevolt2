#include "Game.h"
#include <iostream>
#include "InputManager.h"
#include "TowerDefense.h"
#include "GameInstance.h"
#include "Macro.h"	

Game::Game()
{
	windowSize = Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT);
	name = "Royal Revolt";
	new Player();
}

void Game::Launch()
{
	GameInstance::GetInstance().LaunchMenu();

	//GameInstance::GetInstance().LaunchMapCreator();

	//GameInstance::GetInstance().LaunchVillage();
	
	//GameInstance::GetInstance().LaunchTD();

	Update();
}

void Game::Update()
{
	while (WINDOW.isOpen())
	{
		UpdateEvent();
		EntityManager::GetInstance().Update();
	}
}

void Game::UpdateEvent()
{
	Event _event;

	while (WINDOW.pollEvent(_event))
	{
		if (_event.type == Event::Closed) Stop();
	}
	UpdateInputs(_event);
	UpdateWindow();
}

void Game::UpdateWindow()
{
	WINDOW.clear(Color::Black);
	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		WINDOW.draw(*_entity->GetShape());
	}
	WINDOW.display();
}

void Game::UpdateInputs(const Event& _event)
{
	InputManager::GetInstance().Update(WINDOW, _event);
}

void Game::Stop()
{
	cout << "End of " << name << endl;
	WINDOW.close();
}
