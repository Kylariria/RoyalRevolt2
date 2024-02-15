#pragma once

struct Stat
{
	int health;
	int damage;
public:
	Stat(int _health, int _damage)
	{
		health = _health;
		damage = _damage;
	}
};

