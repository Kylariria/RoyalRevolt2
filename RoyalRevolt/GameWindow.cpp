#include "GameWindow.h"
#include "Macro.h"

GameWindow::GameWindow()
{
	windowSize = Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
	name = "Royal Revolt";
	window.create(VideoMode(static_cast<int>(windowSize.x),static_cast<int>(windowSize.y)), name);
}
