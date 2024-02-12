#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include "TextureManager.h"
#include "FontManager.h"
#include "InputManager.h"

#define FONT_PATH ""

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
	}
	BasicElement(Shape* _shape, const string& _path,
		const Vector2f& _position, const bool _isDraw = true)
	{
		shape = _shape;
		paths = vector<string>();
		paths.push_back(_path);
		isDraw = _isDraw;

		shape->setPosition(_position);
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

	virtual void Update(Event _event) = 0;
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
	Button(Shape* _shape, const vector<string> _paths, const Vector2f& _position,
		const string& _text,function<void()> _callback, const bool _isDraw = true)
		: BasicElement(_shape,_paths,_position,_isDraw)
	{
		callback = _callback;
		text = Text();
		activateCallback = false;
	}
	template <class Class, typename RType = void, typename... Args>
	Button(Shape* _shape, const vector<string> _paths, const Vector2f& _position,
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
	}
	
	void InitText(const string& _text,Vector2f _textPosition)
	{
		text.setString(_text);
		FontManager::GetInstance().Load(&text, FONT_PATH);
		
		if (_textPosition == Vector2f())
		{
			const Vector2f& _size = shape->getGlobalBounds().getSize() / 2.0f;
			_textPosition = _size;
		}
		text.setPosition(_textPosition);
	}

	virtual void Update(Event _event) override
	{
		const Vector2f& _mousePosition = InputManager::GetInstance().GetMousePosition();
		if (shape->getGlobalBounds().contains(_mousePosition))
		{
			shape->setOutlineColor(Color::Blue);
			shape->setOutlineThickness(2.0f);

			if (_event.type == Event::MouseButtonPressed)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					shape->setFillColor(Color::Red);
					activateCallback = true;
				}
			}
			if (_event.type == Event::MouseButtonReleased)
			{
				shape->setFillColor(Color::White);

				if (activateCallback)
				{
					callback();
					activateCallback = false;
				}
			}
		}
		else
		{
			if (shape->getOutlineThickness() != 0.0f)
				shape->setOutlineThickness(0.0f);
		}
	}

	void ChangeTexture()
	{
		//TODO
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
	}

	void InitSpecialText()
	{
		shape->setFillColor(Color(0, 0, 0, 100));
		const Vector2f& _origin = shape->getGlobalBounds().getSize() / 2.0f;
		text.setOrigin(_origin);
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
		backgroundShape = _shape;
		initialValue = _initialValue;
		actualValue = _actualValue;

		backgroundShape->setPosition(_position);

		//InitMovingBarTexture();
		backgroundShape->setFillColor(Color::Red);

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