#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

#define S_ID(name) name + to_string(GetUniqueID())

static Vector2f Normalize(Vector2f& _vector)
{
	// length = x * x + y * y
	const float _length = sqrtf(static_cast<float>(pow(_vector.x, 2) + pow(_vector.y, 2)));

	// normVec = vec / length
	_vector /= _length;
	return _vector;
}

static int GetUniqueID()
{
	static int _id = 0;
	return _id++;
}

template <typename Type>
static Type Random(const Type _max, const Type _min = 0)
{
	return rand() % _max + _min;
}

static void Normalize(Vector2f& _vector, Vector2i& _intVector)
{
	// length = x * x + y * y
	const float _length = sqrtf(static_cast<float>(pow(_vector.x, 2) + pow(_vector.y, 2)));

	// normVec = vec / length
	const int _signX = _vector.x > 0 ? 1 : _vector.x < 0 ? -1 : 0;
	const int _x = static_cast<int>(ceilf(abs(_vector.x) / _length)) * _signX;

	const int _signY = _vector.y > 0 ? 1 : _vector.y < 0 ? -1 : 0;
	const int _y = static_cast<int>(ceilf(abs(_vector.y) / _length)) * _signY;
	_intVector = Vector2i(_x, _y);
}

static void SetOriginAtMiddle(Shape* _shape)
{
	const Vector2f& _origin = _shape->getLocalBounds().getSize();
	_shape->setOrigin(_origin / 2.0f);
}

static Vector2f GetRandomPosition()
{
	return Vector2f(static_cast<float>(Random(SCREEN_WIDTH)), static_cast<float>(Random(SCREEN_HEIGHT)));
}

static bool IsSameName(const string& _name1, const string& _name2)
{
	int _size1 = _name1.size();
	int _size2 = _name2.size();
	int _size = 0;
	bool _isSame = true;

	if (_size1< _size2)
	{
		_size = _size1;
	}
	else
	{
		_size = _size2;
	}

	for (int _i = 0; _i < _size; _i++)
	{

		if (!_isSame)
		{
			return false;
		}

		else if (_name1[_i]== _name2[_i])
		{
			_isSame = true;
		}
	}
	return _isSame;
}