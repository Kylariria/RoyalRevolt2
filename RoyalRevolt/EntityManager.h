#pragma once

#include "Singleton.h"
#include "IManager.h"
#include "Entity.h"

using namespace std;

//typedef int ID;

class EntityManager : public Singleton<EntityManager>, public IManager<string, Entity>
{
public:
	vector<Drawable*> GetDrawables() const
	{
		vector<Drawable*> _drawables;

		for (Entity* _entity : GetAllValues())
		{
			_drawables.push_back(_entity->GetShape());
		}

		return _drawables;
	}

public:
	void Update();
};