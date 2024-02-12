#pragma once
#include <iostream>

using namespace std;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define S_ID(string) GetUniqueID(string)

static string GetUniqueID(const string& _name)
{
	static int _id;
	return _name + to_string(++_id);
}

static int Random(const int _max, const int _min = 0)
{
	return rand() % _min + _max;
}