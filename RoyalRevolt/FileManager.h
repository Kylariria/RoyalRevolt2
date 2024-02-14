#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"
#include <fstream>

using namespace std;

class FileManager : public Singleton<FileManager>, public IManager<string,string>
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
	void CreateAndAddEntity(vector<Entity*>& _allElements, const string& _name, const Vector2f& _position, const string& _path, const Vector2f& _size, Args... _args)
	{
		T* _newElement = new T(_name, _position, _size, _path, Args(_args)...);

		_allElements.push_back(_newElement);
	}
};

