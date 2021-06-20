#pragma once

#include <iostream>
using namespace std;
class Entity
{
private:
	int size;
	char representation;
public:
	Entity(){ size = 0; representation = '0'; }
	Entity(int s, int c) { size = s; representation = c; }
	int getSize() { return size; }
	char getSymbol() { return representation; }
	void setSize(int s) { size = s; }
	void setSymbol(char c) { representation = c; }
};

class Warrior : public Entity
{
private:
	int life;
	int ammunition;
public:
	Warrior() : Entity() { life = 0; ammunition = 0; }
	Warrior(int s, int c, int l, int a) : Entity(s, c) { life = l; ammunition = a; }
	int getLife() { return life; }
	int getAmmo() { return ammunition; }
	void setLife(int l) { life = l; }
	void setAmmo(int a) { ammunition = a; }
	void updateAmmo(int ammo) { ammunition -= ammo; }
};

class Derick : public Warrior
{
public:
	Derick() : Warrior('D', 1, 100, 30) {}
};

class Chichonne : public Warrior
{
public:
	Chichonne() : Warrior('C', 1, 100, 25) {}
};



class Zombie : public Entity
{
private:
	int intLife;
	int intDamage;
	int intScore;
};

class Resources : public Entity
{
public:
	void Effect(Chichonne c, char effect) { c.updateAmmo(2); }
	void Effect(Derick d, char effect) { cout << "No"; }
};