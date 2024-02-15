#include "FileManager.h"
#include <functional>
#include <iostream>
#include <fstream>
#include "Map.h"
#include "Hero.h"
#include "Removable.h"
#include "TowerDefenseBuilding.h"


//# = Grass
//' ' = Path  ok
//F = Fence
//T = Tree  ok
//R = Rock  ok
//P = Player  ok
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
                CreateAndAddEntity<Removable>(_allEntitiesInLine,"Grass",Vector2f(_posX, _posY)* _size.x, ENTITY_DESTROYABLE, R_GRASS, _size, "Grass.png");
                break;
            case ' ':
                CreateAndAddEntity<Removable>(_allEntitiesInLine, "Path", Vector2f(_posX, _posY) * _size.x, ENTITY_DESTROYABLE, R_PATH, _size, "Path.png");
                break;
            case 'F':
                CreateAndAddEntity<TowerDefenseBuilding>(_allEntitiesInLine, "Fence", Vector2f(_posX, _posY) * _size.x, ENTITY_BUILDINGS, nullptr, 50, 0, TDB_FENCE, _size, "Fence.png");
                break;
            case 'T':
                CreateAndAddEntity<Removable>(_allEntitiesInLine, "Tree", Vector2f(_posX, _posY) * _size.x, ENTITY_DESTROYABLE, R_TREE, _size, "Tree.png");
                break;
            case 'R':
                CreateAndAddEntity<Removable>(_allEntitiesInLine, "Rock", Vector2f(_posX, _posY) * _size.x, ENTITY_DESTROYABLE, R_ROCK, _size, "Rock.png");
                break;
            case 'P':
                CreateAndAddEntity<Hero>(_allEntitiesInLine,"Hero",Vector2f(_posX, _posY)* _size.x, _size, "Hero.png", 150, 40);
                break;
            case 'C':
                CreateAndAddEntity<TowerDefenseBuilding>(_allEntitiesInLine, "Casern", Vector2f(_posX, _posY) * _size.x, ENTITY_BUILDINGS, nullptr, 200, 0, TDB_CASERN, _size, "Casern.png");
                break;
            case 'E':
                CreateAndAddEntity<TowerDefenseBuilding>(_allEntitiesInLine, "Castle", Vector2f(_posX, _posY) * _size.x, ENTITY_BUILDINGS, nullptr, 200, 0, TDB_CASTLE, _size, "Castle.png");
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

void FileManager::SaveMap(const vector<vector<Entity*>> _map, const string& _path)
{
    ResetFill(_path);

    ofstream _stream(_path);
    if (!_stream)
    {
        cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
        return;
    }

	/*map<EntType, char> _mapChar = { 
        { GRASS, '#'}, {PATH, " "},{FENCE, "F"},
        {TREE, "T"},{ROCK, "R"},{PLAYER, "P"},
        {CASERN, "C"},{CASTLE, "E"} };*/
	// voir si possible d utiliset un vector de char
    // Probleme les enum d'EntityType sont pas dans lordre

    for (vector<Entity*> _entityInLine: _map)
    {
        for (Entity* _entity : _entityInLine)
        {
            //_stream << _mapChar[_entity->GetEntityData()->type];
        }
        _stream << endl;
    }

}


	





















