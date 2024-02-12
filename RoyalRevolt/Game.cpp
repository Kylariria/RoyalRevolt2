#include "Game.h"
#include <iostream>

Game::Game()
{
	windowSize = Vector2f(SREEN_HEIGHT, SCREEN_WIDTH);
	name = "Royal Revolt";
}

void Game::Launch()
{
	Start();
	Update();
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
	UpdateWindow();
}

void Game::UpdateWindow()
{
	window.clear();
	
	for (Entity* _entity : EntityManager::GetInstance().GetAllValues())
	{
		window.draw(*_entity->GetShape());
	}

	window.display();
}

void Game::Stop()
{
	cout << "End of " << name << endl;
	window.close();
}
