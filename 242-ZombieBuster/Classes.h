#pragma once

#include <iostream>

class Entity
{
};

class Warrior
{
};

class Derrik : Warrior
{
};

class Chichonne : Warrior
{
public:
	void updateAmmo() { std::cout << "Yes"; }
};


//My Part
class Zombie
{
private:
	int intLife;
	int intDamage;
	int intScore;
};

class Resources
{
public:
	void Effect(Chichonne c, char effect) { c.updateAmmo(); }
	void Effect(Derrik d, char effect) { std::cout << "No"; }
};