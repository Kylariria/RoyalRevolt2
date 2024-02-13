#pragma once 
#include "SFML/Graphics.hpp"

using namespace sf;

class Spawner
{
	int numberOfEntity;
public:
	Spawner();

public:
	void Spawn();
	void Update();
};

