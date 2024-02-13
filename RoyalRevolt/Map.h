#pragma once
#include <SFML/Graphics.hpp>
#include "IManagable.h"
#include "Macro.h"

using namespace sf;

class Map : public IManagable<string>
{

public:
	Map(const string& _name);

};

