#pragma once
#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

using namespace std;

class FileManager : public Singleton<FileManager>, public IManager<string,string>
{




public:
	vector<Entity*> CreateEntityFromChar( const string& _path);
	template <typename T, typename... Args>
	void CreateAndAddEntity(const string& _name, const string& _position, const string& _path, const Vector2f& _size, Args... _args)
	{
		T* _newElement = new T(_name, _position, _path, _size, Args(_args)...);

		allElements.push_back(_newElement);
	}

};

