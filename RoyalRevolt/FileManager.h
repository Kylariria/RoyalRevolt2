#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"
#include "Map.h"
#include "Macro.h"
#include <fstream>

using namespace std;

//enum EntType
//{
//	GRASS,
//	PATH,
//	FENCE,
//	TREE,
//	ROCK,
//	PLAYER,
//	CASERN,
//	CASTLE
//};

class FileManager : public Singleton<FileManager>
{

	void ResetFill(const string& _path)
	{

		ifstream _ifstream;
		_ifstream = ifstream(_path);

	}

public:
	vector<vector<Entity*>> CreateEntityFromChar( const string& _path);
	Vector2f GetSizeFill( const string& _path);



	template<typename T>
	void SaveMap(const vector<vector<Cell*>> _map, const string& _path)
    {
        ResetFill(_path);

        ofstream _stream(_path);
        if (!_stream)
        {
            cerr << "Erreur lors de l'ouverture du fichier " << _path << endl;
            return;
        }

        map<string, char> _mapChar = {
            {"Grass", '#'}, {"Path", ' '},{"Fence", 'F'},
            { "Tree", 'T'},{ "Rock", 'R'},{"Hero", 'P'},
            {"Casern", 'C'},{ "Castle", 'E'}};
            // voir si possible d utiliset un vector de char
            // Probleme les enum d'EntityType sont pas dans lordre
		bool _IsSameName;

        for (vector<Cell*> _entityInLine : _map)
        {
            for (Cell* _entity : _entityInLine)
            {
                for (auto _pair: _mapChar)
                {
					_IsSameName = IsSameName(_pair.first, _entity->entityOnCell->GetEntityData()->name);
                }


                _stream << _mapChar[_entity->entityOnCell];
            }
            _stream << endl;
        }

    }


	template <typename T, typename... Args>
	void CreateAndAddEntity(vector<Entity*>& _allElements, Args... _args)
	{
		T* _newElement = new T(Args(_args)...);

		_allElements.push_back(_newElement);
	}
};

