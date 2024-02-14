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
	player = new Player();
}

void Game::Launch()
{
	TowerDefense _yeepi = TowerDefense("starfoullah",Vector2f(10.0f,8.0f), 1);
	//_yeepi.Launch();
 
	GameInstance::GetInstance().LaunchVillage();

	Update();
}

void Game::Start()
{
	//window.create(VideoMode(static_cast<unsigned>(windowSize.x), static_cast<unsigned>(windowSize.y)), name);
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
