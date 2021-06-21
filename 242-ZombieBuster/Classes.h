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
	int maxLife;
	int ammunition;
	int kills;
public:
	Warrior() : Entity() { life = 0; ammunition = 0; maxLife = 0; kills = 0; }
	Warrior(int s, int c, int l, int a) : Entity(s, c) { life = l; ammunition = a; maxLife = l; kills = 0; }
	int getLife() { return life; }
	int getAmmo() { return ammunition; }
	int getMaxLife() { return maxLife; }
	void setLife(int l) { life = l; }
	void setAmmo(int a) { ammunition = a; }
	void updateAmmo(int ammo) { ammunition -= ammo; }
	void incKills() { kills++; }
	int getKills() { return kills; }
};

class Derick : public Warrior
{
public:
	Derick() : Warrior(1, 'D', 100, 30) {}
};

class Chichonne : public Warrior
{
public:
	Chichonne() : Warrior(1, 'C', 100, 25) {}
};



class Zombie : public Entity
{
private:
	int intLife;
	int intDamage;
	int intScore;
	int intMaxLife;
public:
	Zombie() : Entity() { intLife = 0; intDamage = 0; intScore = 0; intMaxLife = 0; }
	Zombie(int s, int c, int life, int dmg, int scr) : Entity(s, c) { intLife = life; intDamage = dmg; intScore = scr; intMaxLife = life; }
	int getZombieLife() { return intLife; }
	int getZombieMaxLife() { return intMaxLife; }
	void setZombieLife(int l) { intLife = l; }
	int getZombieDamage() { return intDamage; }
	void setZombieDamage(int l) { intDamage = l; }
	int getZombieScore() { return intScore; }
	void setZombieScorre(int l) { intScore = l; }
};

class LargeZombie : public Zombie
{
public:
	LargeZombie() : Zombie(3, 'L', 12, 8, 100) {};
};

class MediumZombie : public Zombie
{
public:
	MediumZombie() : Zombie(2, 'M', 8, 4, 75) {};
};

class SmallZombie : public Zombie
{
public:
	SmallZombie() : Zombie(1, 'S', 4, 2, 50) {};
};

class Resources : public Entity
{
public:
	Resources() : Entity() {};
	Resources(int s, int c) : Entity(s, c) {};
	virtual Chichonne Effect(Chichonne c) = 0;
	virtual Derick Effect(Derick d) = 0;
};

class LargeMedKit : public Resources
{
public:
	LargeMedKit() : Resources(2, '*') {};
	Chichonne Effect(Chichonne c) { c.setLife(c.getLife() + 20); if (c.getLife() > c.getMaxLife()) { c.setLife(c.getMaxLife()); }; return c; }
	Derick Effect(Derick d) { d.setLife(d.getLife() + 20); if (d.getLife() > d.getMaxLife()) { d.setLife(d.getMaxLife()); }; return d; }
};

class SmallMedKit : public Resources
{
public:
	SmallMedKit() : Resources(1, '+') {};
	Chichonne Effect(Chichonne c) { c.setLife(c.getLife() + 10); if (c.getLife() > c.getMaxLife()) { c.setLife(c.getMaxLife()); }; return c; }
	Derick Effect(Derick d) { d.setLife(d.getLife() + 10); if (d.getLife() > d.getMaxLife()) { d.setLife(d.getMaxLife()); }; return d; }
};

class Ammunation : public Resources
{
public:
	Ammunation() : Resources(1, 'A') {};
	Chichonne Effect(Chichonne c) { c.setAmmo(c.getAmmo() + 10); return c;}
	Derick Effect(Derick d) { d.setAmmo(d.getAmmo() + 10); return d; }
};