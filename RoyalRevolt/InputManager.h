#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include <string>
#include "Singleton.h"
#include "IManagable.h"
#include "IManager.h"

using namespace std;
using namespace sf;

typedef Event::EventType ActionType;

struct InputData
{
	ActionType type;
	int key;
};

struct ActionData
{
	string name;
	vector<InputData> keys;
	function<void()> callback;

	ActionData()
	{
		name = "Unknown";
		callback = function<void()>();
	}

	template <class Class, typename RType = void, typename... Args>
	ActionData(const string& _name, Class* _owner, RType(Class::* _callback)(Args...), const InputData _primaryKey, const InputData _secondaryKey = -1, Args... _args)
	{
		name = _name;
		keys.push_back(_primaryKey);
		keys.push_back(_secondaryKey);
		callback = [_owner, _callback, _args...]() {
			return (_owner->*_callback)(_args...);
		};
		//callback = bind(_callback, _owner, _args);
	}


	bool operator !()const
	{
		return name == "Unknown";
	}
};

struct Action : public IManagable<string>
{
	ActionData data;
	string actionMap;

	// ctrl / alt / win / shift	

	Action(const ActionData& _data, const string& _actionMap) : IManagable(_data.name)
	{
		if (!_data)
		{
			toRemove = true;
		}
		data = _data;
		actionMap = _actionMap;
		Register();
	}

public:
	virtual void Register() override;
	void Execute();
};

struct ActionMap : public IManager<string, Action>, public IManagable<string>
{
	vector<Action*> actions;

	ActionMap(const string& _name, const vector<ActionData>& _actionsData = vector<ActionData>()) : IManagable(_name)
	{
		Register();

		for (const ActionData& _actionData : _actionsData)
		{
			actions.push_back(new Action(_actionData, id));
		}
	}

private:
	virtual void Register() override;

public:
	void Update(const Event& _event);
};

class InputManager : public Singleton<InputManager>, public IManager<string, ActionMap>
{
public:
	Vector2f mousePosition;

public:
	void Update(RenderWindow& _window, const Event& _event);

	Vector2f GetMousePosition() const
	{
		return mousePosition;
	}

private:
	void UpdateInputs(const Event& _event);
};