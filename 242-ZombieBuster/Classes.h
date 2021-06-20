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

class Warrior : Entity
{
private:
	int life;
	int ammunition;
public:
	Warrior() { life = 0; ammunition = 0; }
	Warrior(int l, int a) { life = l; ammunition = a; }
	int getLife() { return life; }
	int getAmmo() { return ammunition; }
	void setLife(int l) { life = l; }
	void setAmmo(int a) { ammunition = a; }
	void updateAmmo(int ammo) { ammunition -= ammo; }
};

class Derick : Warrior
{
public:
	Derick() { this->setAmmo(30); this->setLife(100); this->setSymbol('D'); this->setSize(1); }
};

class Chichonne : Warrior
{
public:
	Chichonne() { this->setAmmo(25); this->setLife(100); this->setSymbol('C'); this->setSize(1); }
};



class Zombie : Entity
{
private:
	int intLife;
	int intDamage;
	int intScore;
};

class Resources : Entity
{
public:
	void Effect(Chichonne c, char effect) { c.updateAmmo(); }
	void Effect(Derick d, char effect) { cout << "No"; }
};