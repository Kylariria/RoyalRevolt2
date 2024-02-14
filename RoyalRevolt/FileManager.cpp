#include "FileManager.h"
#include <functional>
#include <iostream>
#include <fstream>
#include "Map.h"

#include "Grass.h"
#include "Path.h"
#include "Fence.h"
#include "Tree.h"
#include "Rock.h"
#include "Hero.h"
#include "Casern.h"
#include "Castle.h"


//# = Grass
//' ' = Path  ok
//F = Fence
//T = Tree  ok
//R = Rock  ok
//P = Player  ok
//C = Casern
//E = Castle




vector<vector<Entity*>> FileManager::CreateEntityFromChar(const string& _path)
{
	vector<Entity*> _allEntitiesInLine;
	vector<vector<Entity*>> _allEntities;

	ifstream _stream(_path);
	//char _sign[] = { ' ', '0', 'F', 'T' , 'R', 'P', 'C', 'E' };
    if (!_stream)
    {
        cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
        return vector<vector<Entity*>>();
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
                CreateAndAddEntity<Grass>(_allEntitiesInLine,"Grass",Vector2f(_posX, _posY)* _size.x, "Grass.png", _size);
                break;
            case ' ':
                CreateAndAddEntity<Path>(_allEntitiesInLine,"Path",Vector2f(_posX, _posY)* _size.x, "Path.png", _size);
                break;
            case 'F':
                CreateAndAddEntity<Fence>(_allEntitiesInLine,"Fence",Vector2f(_posX, _posY)*50.0f, "Fence.png", Vector2f(50.0f, 50.0f));
                break;
            case 'T':
                CreateAndAddEntity<Tree>(_allEntitiesInLine,"Tree",Vector2f(_posX, _posY)* _size.x, "Tree.png", _size);
                break;
            case 'R':
                CreateAndAddEntity<Rock>(_allEntitiesInLine,"Rock",Vector2f(_posX, _posY)* _size.x, "Rock.png", _size);
                break;
            case 'P':
                CreateAndAddEntity<Hero>(_allEntitiesInLine,"Hero",Vector2f(_posX, _posY)* _size.x, "Hero.png", _size, ENTITY_HERO);
                break;
            case 'C':
                CreateAndAddEntity<Casern>(_allEntitiesInLine,"Casern",Vector2f(_posX, _posY)*50.0f, "Tent.png", Vector2f(50.0f, 50.0f));
                break;
            case 'E':
                CreateAndAddEntity<Castle>(_allEntitiesInLine,"Castle",Vector2f(_posX, _posY)*50.0f, "Castle.png", Vector2f(50.0f, 50.0f));
                break;
            default:
                break;
            }
            _posX += 1;
        }

        _allEntities.push_back(_allEntitiesInLine);
        _allEntitiesInLine = vector<Entity*>();
        _posX = 0;
        _posY += 1;
    }







    return _allEntities;

}

Vector2f FileManager::GetSizeFill(const string& _path)
{
    ifstream _stream(_path);
    if (!_stream)
    {
        cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
        return Vector2f();
    }

    string _line;
    float _lineX=0;
    float _lineY=0;

    while (getline(_stream, _line))
    {
        _lineY++;
        if (_lineX < _line.size())
        {
            _lineX =static_cast<float>( _line.size());
        }
    }

    return Vector2f(_lineY, _lineX);
}


	





















