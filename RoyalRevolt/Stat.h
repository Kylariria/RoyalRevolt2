#pragma once

struct Stat
{
	int health;
	int damage;
public :
	Stat(const int _health, const int _damage)
	{
		health = _health;
		damage = _damage;
	}
};

