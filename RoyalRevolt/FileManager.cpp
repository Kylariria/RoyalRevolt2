#include "FileManager.h"
#include <functional>
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Rock.h"
#include "Path.h"

#define PATH ""


// path == #
// Rock == R
// Tree == T

vector<Entity*> FileManager::CreateEntityFromChar(const string& _path)
{
	vector<Entity*> allEntities;

	ifstream _stream(_path);
	char _sign[] = { '0', 'R', 'T'};
    if (!_stream)
    {
        cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
        return vector<Entity*>();
    }

    float _posX = 0.f, _posY = 0.f;
    string _line;
    char _letter = '0';

    while (getline(_stream, _line))
    {
        for (int _index = 0; _index < _line.size(); _index++)
        {
            switch (_line[_index])
            {
            case ' ':
                CreateAndAddEntity<Path>("Path",Vector2f(_posX, _posY)*50.0f, PATH, Vector2f(50.0f, 50.0f));
                break;
            default:
                break;
            }
            allEntities.back()->GetShape()->setPosition(_posX, _posY);
            _posX += 1;
        }
        _posX = 0;
        _posY += 1;
    }







    return vector<Entity*>();

}


	





















