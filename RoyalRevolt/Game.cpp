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
	InputManager::GetInstance().Update(window,_event);
	UpdateWindow();
}

void Game::UpdateWindow()
{
	window.clear(Color::Green);

	//window.draw();
	window.display();
}

void Game::Stop()
{
	cout << "End of " << name << endl;
	window.close();
}
