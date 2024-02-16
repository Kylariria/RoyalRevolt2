#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"

#define FONT_PATH "Assets/Font/Revolt.otf"

using namespace std;
using namespace sf;

struct BasicElement
{
	Shape* shape;
	vector<string> paths;
	bool isDraw;

public:
	Shape* GetShape() const
	{
		return shape;
	}
	bool GetIsDraw() const
	{
		return isDraw;
	}

public:
	BasicElement()
	{
		shape = nullptr;
		paths = vector<string>();
		isDraw = false;
	}
	BasicElement(Shape* _shape,const vector<string> _paths,
		const Vector2f& _position,const bool _isDraw = true)
	{
		shape = _shape;
		paths = _paths;
		isDraw = _isDraw;

		shape->setPosition(_position);
		SetTexture();
	}
	BasicElement(Shape* _shape, const string& _path,
		const Vector2f& _position, const bool _isDraw = true)
	{
		shape = _shape;
		paths = vector<string>();
		paths.push_back(_path);
		isDraw = _isDraw;

		shape->setPosition(_position);
		SetTexture();
	}

public:
	void SetTexture()
	{
		TextureManager::GetInstance().Load(shape, paths[0]);
	}
	void SetOrigin()
	{
		const Vector2f& _size = shape->getGlobalBounds().getSize();
		shape->setOrigin(_size / 2.0f);
	}
	void SetIsDraw(const bool _isDraw)
	{
		isDraw = _isDraw;
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) = 0;
	virtual void Update(Event _event = Event()) = 0;
};

struct Button : public BasicElement
{
	function<void()> callback;
	Text text;
	bool activateCallback;

	Button() : BasicElement()
	{
		callback = nullptr;
		text = Text();
		activateCallback = false;
	}
	Button(Shape* _shape, const string& _paths, const Vector2f& _position,
		const string& _text, function<void()> _callback, Vector2f _textPosition = Vector2f(), const bool _isDraw = true)
		: BasicElement(_shape,_paths,_position,_isDraw)
	{
		callback = _callback;
		text = Text();
		activateCallback = false;

		InitText(_text, _textPosition);
		SetOrigin();
	}
	template <class Class, typename RType = void, typename... Args>
	Button(Shape* _shape, const string& _paths, const Vector2f& _position,
		const string& _text,
		Class* _owner, RType(Class::* _callback)(Args...),Vector2f _textPosition = Vector2f(), const bool _isDraw = true, Args... _args)
		: BasicElement(_shape, _paths, _position, _isDraw)
	{
		callback = [_callback, _owner, _args...]() {
			return (_owner->*_callback)(_args...);
			};
		text = Text();
		activateCallback = false;

		InitText(_text, _textPosition);
		SetOrigin();
	}
	
	void InitText(const string& _text,Vector2f _textPosition)
	{
		text.setString(_text);
		FontManager::GetInstance().Load(&text, FONT_PATH);
		
		if (_textPosition == Vector2f())
		{
			const Vector2f& _position = shape->getGlobalBounds().getPosition();
			_textPosition = _position;
		}
		text.setPosition(_textPosition);
		text.setOrigin(text.getGlobalBounds().getSize() / 2.0f);
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) override
	{
		_drawables.push_back(shape);
		_drawables.push_back(&text);
	}

	virtual void Update(Event _event) override
	{
		const Vector2f& _mousePosition = InputManager::GetInstance().GetMousePosition();
		if (shape->getGlobalBounds().contains(_mousePosition))
		{
			if (_event.type == Event::MouseButtonPressed)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					shape->setFillColor(Color(255,255,255,100));
					activateCallback = true;
				}
			}
			if (_event.type == Event::MouseButtonReleased)
			{
				if (activateCallback)
				{
					shape->setFillColor(Color::White);
					callback();
					activateCallback = false;
				}
			}
		}
		else
		{
			if (shape->getFillColor() != Color::White)
				shape->setFillColor(Color::White);
		}
	}
};

struct SpecialText : public BasicElement
{
	Text text;

	SpecialText() : BasicElement()
	{
		text = Text();
	}
	SpecialText(Shape* _shape, const string& _path,
		const Vector2f& _position, const string& _text, const bool _isDraw = true)
		: BasicElement(_shape,_path,_position,_isDraw)
	{
		text = Text();
		text.setString(_text);
		FontManager::GetInstance().Load(&text, FONT_PATH);

		InitSpecialText();
		SetOrigin();
	}

	void InitSpecialText()
	{
		shape->setFillColor(Color(0, 0, 0, 100));
		text.setPosition(shape->getGlobalBounds().getPosition());
		const Vector2f& _newOrigin = Vector2f(text.getGlobalBounds().getSize().x /2.0f, (text.getGlobalBounds().getSize().y / 2.0f) + shape->getGlobalBounds().getSize().y / 6.0f);
		text.setOrigin(_newOrigin);
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) override
	{
		_drawables.push_back(shape);
		_drawables.push_back(&text);
	}

	void Update(Event _event = Event())
	{

	}
};

struct MovingBar : public BasicElement
{
	Shape* backgroundShape;
	float initialValue;
	float actualValue;

	MovingBar() : BasicElement()
	{
		backgroundShape = nullptr;
		initialValue = 0;
		actualValue = 0;
	}
	MovingBar(Shape* _shape, const vector<string> _paths,
		const Vector2f& _position, const float _initialValue,
		const float _actualValue = 0, const bool _isDraw = true)
		: BasicElement(_shape,_paths,_position,isDraw)
	{
		backgroundShape = new RectangleShape(_shape->getGlobalBounds().getSize());
		initialValue = _initialValue;
		actualValue = _actualValue;

		backgroundShape->setPosition(_position);

		InitMovingBarTexture();
		//backgroundShape->setFillColor(Color::Red);

		Update();
	}

	void InitMovingBarTexture()
	{
		SetTexture();
		TextureManager::GetInstance().Load(backgroundShape, paths[1]);
	}
	void ChangeActualValue(const float _value)
	{
		actualValue = _value;

		Update();
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) override
	{
		_drawables.push_back(shape);
		_drawables.push_back(backgroundShape);
	}

	virtual void Update(Event _event = Event()) override
	{
		Vector2f _scale = Vector2f(1.0f, 1.0f);
		const float _percent = initialValue / actualValue;

		if (actualValue <= 0.0f)
			_scale = Vector2f();
		else
			_scale.x /= _percent;
		
		shape->setScale(_scale);
	}
};

struct PlayerRessources : public BasicElement
{
	SpecialText text;
	int value;
	function<int()> callback;

	PlayerRessources() : BasicElement()
	{
		text = SpecialText();
		value = 0;
		callback = nullptr;
	}
	PlayerRessources(Shape* _shape, const string& _paths,const Vector2f& _position,
		Shape* _specialShape, const string& _specialPaths,const Vector2f& _specialPosition,
		const string& _text,const function<int()>& _callback, const bool _isDraw = true)
		: BasicElement(_shape, _paths, _position, _isDraw)
	{
		text = SpecialText(_specialShape, _specialPaths, _specialPosition, _text, _isDraw);
		callback = _callback;
		value = 0;
		SetOrigin();
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) override
	{
		text.PutInDrawables(_drawables);

		_drawables.push_back(shape);
	}

	void Update(Event _event = Event())
	{
		//int _value = value + callback();
		text.text.setString(to_string(callback()));
	}
};

struct SelectionPanel : public BasicElement
{
	vector<PlayerRessources*>allElements;
	vector<function<int()>> allCallbacks;
	SpecialText title;

	SelectionPanel() : BasicElement()
	{
		allElements = vector<PlayerRessources*>();
		allCallbacks = vector <function<int()>>();
		title = SpecialText();
	}
	SelectionPanel(Shape* _shape, const string& _paths,
		const Vector2f& _position,
		const vector<PlayerRessources*>& _allElements, const vector <function<int()>>& _allCallback,
		Shape* _shapeText, const string& _pathText, const Vector2f& _positionText, const string& _text,
		const bool _isDraw = true) : BasicElement(_shape, _paths, _position, _isDraw)
	{
		allElements = _allElements;
		allCallbacks = _allCallback;
		title = SpecialText(_shapeText, _pathText, _positionText, _text, _isDraw);

		shape->setFillColor(Color::Blue);

		SetOrigin();
	}

	void SetDrawAllElements(const bool _status)
	{
		isDraw = _status;
		for (PlayerRessources* _ressources : allElements)
		{
			_ressources->isDraw = _status;
		}
		title.isDraw = _status;
	}

	virtual void PutInDrawables(vector<Drawable*>& _drawables) override
	{
		_drawables.push_back(shape);
		for (PlayerRessources* _ressources : allElements)
		{
			_ressources->PutInDrawables(_drawables);
		}
		title.PutInDrawables(_drawables);
	}
	virtual void Update(Event _event = Event()) override
	{
		int _index = 0;
		const Vector2f& _mousePosition = InputManager::GetInstance().GetMousePosition();
		if (shape->getGlobalBounds().contains(_mousePosition))
		{
			for (PlayerRessources* _ressource : allElements)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (_ressource->shape->getGlobalBounds().contains(_mousePosition))
					{
						allCallbacks[_index]();
					}
				}				
				_index++;
			}
		}
	}
};
