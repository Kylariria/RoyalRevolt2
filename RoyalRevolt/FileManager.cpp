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
//C = Casern
//E = Castle




vector<vector<Entity*>> FileManager::CreateEntityFromChar(const string& _path)
{
	vector<Entity*> _allEntitiesInLine;
	vector<vector<Entity*>> _allEntities;


   /* map<EntityType, string> _mapChar = {
    {"#",R_GRASS}, {" ",ENTITY_NONE},{"F",TDB_FENCE},
    {"T",R_TREE},{"R",R_ROCK},{"P",ENTITY_NONE},
    {"C",ENTITY_NONE},{"E",TDB_CASTLE} };*/


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


            //CreateAndAddEntity<Removable>(_allEntitiesInLine, "Hero", Vector2f(_posX, _posY) * _size.x, "Hero.png", _size);

            if (_line[_index]== 'P')
            {
                //CreateAndAddEntity<Hero>(_allEntitiesInLine,"Hero",Vector2f(_posX, _posY)* _size.x, "Hero.png", _size);
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

	map<EntityType, string> _mapChar = { 
        { ENTITY_NONE, "#"}, {ENTITY_NONE, " "},{ENTITY_NONE, "F"},
        {ENTITY_NONE, "T"},{ENTITY_NONE, "R"},{ENTITY_NONE, "P"},
        {ENTITY_NONE, "C"},{ENTITY_NONE, "E"} };
	// voir si possible d utiliset un vector de char
    // Probleme les enum d'EntityType sont pas dans lordre

    for (vector<Entity*> _entityInLine: _map)
    {
        for (Entity* _entity : _entityInLine)
        {
            _stream << _mapChar[_entity->GetEntityData()->type];
        }
        _stream << endl;
    }

}


	





















