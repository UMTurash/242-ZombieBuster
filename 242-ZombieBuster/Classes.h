#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>   
using namespace std;
struct GridCell
{
	char symbol = '_';
	int index = -1;
	bool hidden = true;
	bool occupied = false;
};
class Grid
{
private:
	int size, zombieNum, medNum, resNum;
	GridCell** cells;
	int* indexList;
public:
	Grid(int n)
	{
		size = n;
		zombieNum = 2 * (n * n / 25);
		medNum = 3 * (n * n / 25);
		resNum = 2 * (n * n / 25);
		int Z = zombieNum;
		int M = medNum;
		int R = resNum;
		cells = new GridCell* [size];
		for (int i = 0; i < size; ++i)
			cells[i] = new GridCell[size];
		indexList = (int*)malloc(sizeof(int) * n * n);
		int currentIndex = 0;
		while (!(Z == 0 && M == 0 && R == 0))
		{
			int positionX = rand() % size;
			int positionY = rand() % size;

			if (cells[positionX][positionY].occupied == true)
				continue;
			if (Z != 0)
			{
				/*
				0 = small zombie
				1 = medium zombie
				2 = large zombie
				*/
				int zType = rand() % 3;
				if (zombieNum == 2)
				{
					if (Z == 2)
						zType = 0;
					else if(Z == 1)
						zType = 1;
				}
				if (zombieNum == 3)
				{
					if (Z == 3)
						zType = 0;
					else if (Z == 2)
						zType = 1;
					else if (Z == 1)
						zType = 2;
				}

				/*Make Zombies*/
				/* Orientation of angle adjustments. Consider origin as (x,y)
				-1,1	0,1		1,1
				-1,0	0,0		1,0
				-1,-1	0,-1	1,-1
				*/
				if (zType == 0)
				{
					cells[positionX][positionY].symbol = 'S';
					cells[positionX][positionY].index = currentIndex;
					cells[positionX][positionY].occupied = true;
					currentIndex++;
				}
				else if (zType == 1)
				{
					int angleX = rand() % 3 -1;
					int angleY = rand() % 3 -1;
					if ((angleX == 0 && angleY == 0) || (cells[positionX+angleX][positionY+angleY].occupied == true))
						continue;
					cells[positionX][positionY].symbol = 'M';
					cells[positionX][positionY].index = currentIndex;
					cells[positionX][positionY].occupied = true;
					cells[positionX+angleX][positionY+angleY].symbol = 'M';
					cells[positionX+angleX][positionY+angleY].index = currentIndex;
					cells[positionX+angleX][positionY+angleY].occupied = true;
					currentIndex++;
				}
				else if (zType == 2)
				{
					int angleX = rand() % 3 - 1;
					int angleY = rand() % 3 - 1;
					int angleX1 = rand() % 3 - 1;
					int angleY1 = rand() % 3 - 1;
					if ((angleX == 0 && angleY == 0) || (cells[positionX + angleX][positionY + angleY].occupied == true))
						continue;
					if ((angleX1 == 0 && angleY1 == 0) || (cells[positionX + angleX1][positionY + angleY1].occupied == true))
						continue;
					cells[positionX][positionY].symbol = 'L';
					cells[positionX][positionY].index = currentIndex;
					cells[positionX][positionY].occupied = true;
					cells[positionX + angleX][positionY + angleY].symbol = 'L';
					cells[positionX + angleX][positionY + angleY].index = currentIndex;
					cells[positionX + angleX][positionY + angleY].occupied = true;
					cells[positionX + angleX1][positionY + angleY1].symbol = 'L';
					cells[positionX + angleX1][positionY + angleY1].index = currentIndex;
					cells[positionX + angleX1][positionY + angleY1].occupied = true;
					currentIndex++;
				}
				Z--;
			}
			else if (M != 0)
			{	
				/*
				0 = small MedKit
				1 = medium MedKit
				*/
				int mType = rand() % 2;

				/*Make Medkits*/
				/* Orientation of angle adjustments. Consider origin as (x,y)
				-1,1	0,1		1,1
				-1,0	0,0		1,0
				-1,-1	0,-1	1,-1
				*/
				if (mType == 0)
				{
					cells[positionX][positionY].symbol = '+';
					cells[positionX][positionY].index = currentIndex;
					cells[positionX][positionY].occupied = true;
					currentIndex++;
				}
				else if (mType == 1)
				{
					int angleX = rand() % 3 - 1;
					int angleY = rand() % 3 - 1;
					if ((angleX == 0 && angleY == 0) || (cells[positionX + angleX][positionY + angleY].occupied == true))
						continue;
					cells[positionX][positionY].symbol = '*';
					cells[positionX][positionY].index = currentIndex;
					cells[positionX][positionY].occupied = true;
					cells[positionX + angleX][positionY + angleY].symbol = '*';
					cells[positionX + angleX][positionY + angleY].index = currentIndex;
					cells[positionX + angleX][positionY + angleY].occupied = true;
					currentIndex++;
				}
				M--;
			}
			else if (R != 0)
			{
				cells[positionX][positionY].symbol = '+';
				cells[positionX][positionY].index = currentIndex;
				cells[positionX][positionY].occupied = true;
				currentIndex++;
				R--;
			}
		}
	}

	int moveGrid(int direction)
	{

	}
	char searchIndex(int index)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (cells[i][j].index == index)
				{
					return cells[i][j].symbol;
				}
			}
		}
	}
	void killIndex(int index)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (cells[i][j].index == index)
				{
					cells[i][j].symbol = 'X';
				}
			}
		}
	}
	void printGrid() 
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if(cells[i][j].hidden == true)
					printf("\t_\t");
				else
					printf("\t%c\t", cells[i][j].symbol);
			}
			printf("\n");
		}
	}
};
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