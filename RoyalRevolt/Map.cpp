#include "Map.h"

Map::Map(const RenderWindow& _window,const string& _name) : IManagable(S_ID(_name))
{
	windowSize = Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT);
	name = _name;
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), name);

}
