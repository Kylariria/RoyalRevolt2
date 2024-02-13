#include "Game.h"
#include <iostream>
#include "InputManager.h"
#include "TowerDefense.h"
#include "GameInstance.h"
#include "Macro.h"
#include "EntityManager.h"

Game::Game()
{
	windowSize = Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT);
	name = "Royal Revolt";
	player = new Player();
}

void Game::Launch()
{
	GameInstance::GetInstance().LaunchVillage();

	//Start();

	//Update();
}

void Game::Start()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x), static_cast<unsigned>(windowSize.y)), name);
}

void Game::Update()
{
	while (window.isOpen())
	{
		UpdateEvent();
	}
}

void Game::UpdateEvent()
{
	Event _event;

	while (window.pollEvent(_event))
	{
		if (_event.type == Event::Closed) Stop();
	}
	UpdateInputs(_event);
	UpdateWindow();
}

void Game::UpdateWindow()
{
	window.clear(Color::Green);
	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		window.draw(*_entity->GetShape());
	}
	window.display();
}

void Game::UpdateInputs(const Event& _event)
{
	InputManager::GetInstance().Update(window, _event);
}

void Game::Stop()
{
	cout << "End of " << name << endl;
	window.close();
}
