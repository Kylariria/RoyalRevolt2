#include "FileManager.h"
#include <functional>
#include <iostream>
#include <fstream>
#include "Map.h"

#include "Grass.h"
#include "Path.h"
//#include "Fence.h"
#include "Tree.h"
#include "Rock.h"
#include "Hero.h"
//#include "Casern.h"
//#include "Castle.h"


//# = Grass
//' ' = Path  ok
//F = Fence
//T = Tree  ok
//R = Rock  ok
//P = Player  ok
//C = Casern
//E = Castle





vector<Entity*> FileManager::CreateEntityFromChar(const string& _path)
{
	vector<Entity*> _allEntities;

	ifstream _stream(_path);
	//char _sign[] = { ' ', '0', 'F', 'T' , 'R', 'P', 'C', 'E' };
    if (!_stream)
    {
        cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
        return vector<Entity*>();
    }


    Vector2f _size = Map::GetCellSize();



    float _posX = 0.f, _posY = 0.f;
    string _line;
    char _letter = '0';

    while (getline(_stream, _line))
    {
        for (int _index = 0; _index < _line.size(); _index++)
        {

            switch (_line[_index])
            {
            case '#':
                CreateAndAddEntity<Grass>(_allEntities,"Grass",Vector2f(_posX, _posY)* _size.x, "Grass.png", _size);
                break;
            case ' ':
                CreateAndAddEntity<Path>(_allEntities,"Path",Vector2f(_posX, _posY)* _size.x, "Path.png", _size);
                break;
            case 'F':
                //CreateAndAddEntity<Fence>(_allEntities,"Fence",Vector2f(_posX, _posY)*50.0f, PATH, Vector2f(50.0f, 50.0f));
                break;
            case 'T':
                CreateAndAddEntity<Tree>(_allEntities,"Tree",Vector2f(_posX, _posY)* _size.x, "Tree.png", _size);
                break;
            case 'R':
                CreateAndAddEntity<Rock>(_allEntities,"Rock",Vector2f(_posX, _posY)* _size.x, "Rock.png", _size);
                break;
            case 'P':
                CreateAndAddEntity<Hero>(_allEntities,"Hero",Vector2f(_posX, _posY)* _size.x, "Hero.png", _size, ENTITY_HERO);
                break;
            case 'C':
                //CreateAndAddEntity<Casern>(_allEntities,"Casern",Vector2f(_posX, _posY)*50.0f, PATH, Vector2f(50.0f, 50.0f));
                break;
            case 'E':
                //CreateAndAddEntity<Castle>(_allEntities,"Castle",Vector2f(_posX, _posY)*50.0f, PATH, Vector2f(50.0f, 50.0f));
                break;
            default:
                break;
            }
            _posX += 1;
        }
        _posX = 0;
        _posY += 1;
    }







    return _allEntities;

}


	





















