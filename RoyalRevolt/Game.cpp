#include "Game.h"
#include <iostream>
#include "InputManager.h"

Game::Game()
{
	windowSize = Vector2f(SREEN_HEIGHT, SCREEN_WIDTH);
	name = "Royal Revolt";
}

void Game::Launch()
{
	Start();
	
	InitTest();

	Update();
}

void Game::Start()
{
	window.create(VideoMode(static_cast<unsigned>(windowSize.x), static_cast<unsigned>(windowSize.y)), name);
}

void Game::InitTest()
{
	value = 10.0f;

	function<void()> _callback = [&]() {bar->ChangeActualValue(bar->actualValue + 1); };
	button = new Button(new RectangleShape(Vector2f(100.0f,100.0f)),vector<string>(),Vector2f(800.0f,700.0f),"Bouton", _callback);
	button->text.setFillColor(Color::Blue);

	bar = new MovingBar(new RectangleShape(Vector2f(300.0f, 100.0f)), vector<string>(), Vector2f(100.0f, 100.0f), value, 0.0f);

	text = new SpecialText(new RectangleShape(Vector2f(300.0f, 300.0f)), string(), Vector2f(600.0f, 600.0f), "Victory");
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
	button->Update(_event);
	UpdateWindow();
}

void Game::UpdateWindow()
{
	window.clear(Color::Green);

	window.draw(*button->shape);
	window.draw(button->text);
	window.draw(*bar->shape);
	window.draw(*bar->backgroundShape);
	window.draw(*text->shape);
	window.draw(text->text);

	window.display();
}

void Game::Stop()
{
	cout << "End of " << name << endl;
	window.close();
}
