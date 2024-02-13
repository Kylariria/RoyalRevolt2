#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;
using namespace sf;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800

#define S_ID(name) name + to_string(GetUniqueID())
static void Normalize(Vector2f& _vector)
{
	// length = x * x + y * y
	const float _length = sqrtf(static_cast<float>(pow(_vector.x, 2) + pow(_vector.y, 2)));

	// normVec = vec / length
	_vector /= _length;
}
static int GetUniqueID()
{
	static int _id = 0;
	return _id++;
}

static int Random(const int _max, const int _min = 0)
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
	_shape->setOrigin(_shape->getGlobalBounds().width / 2, _shape->getGlobalBounds().height / 2);
}

