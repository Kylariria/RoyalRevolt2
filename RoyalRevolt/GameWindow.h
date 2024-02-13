#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Singleton.h"

using namespace std;
using namespace sf;

#define WINDOW GameWindow::GetInstance().window

class GameWindow : public Singleton<GameWindow>
{
public:
	RenderWindow window;
	Vector2f windowSize;
	string name;

public:
	GameWindow();
};

