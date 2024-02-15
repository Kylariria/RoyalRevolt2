#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"
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
	void SaveMap(const vector<vector<Entity*>> _map, const string& _path);


	template <typename T, typename... Args>
	void CreateAndAddEntity(vector<Entity*>& _allElements, Args... _args)
	{
		T* _newElement = new T(Args(_args)...);

		_allElements.push_back(_newElement);
	}
};

