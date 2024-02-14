#include "Game.h"
#include "TowerDefense.h"
#include "FileManager.h"
#include "Grass.h"

int main()
{
	/*Game _game;
	_game.Launch();*/

	/*TowerDefense _td= TowerDefense("a", Vector2f(5.0f,5.0f));
	_td.Launch();*/


	vector<Entity*> _entities;
	_entities.push_back(new Grass("Grass", Vector2f(0.0f, 0.0f), Vector2f(0.0f, 0.0f), "Grass.png"));

	vector<vector<Entity*>> _entities2;
	_entities2.push_back(_entities);

	FileManager _fileManager;
	_fileManager.SaveMap(_entities2, "LevelEditor/Level3.txt");



	return 0;
}