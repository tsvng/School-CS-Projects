/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: creature.cpp, Assignment 16.1
*/
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	creature::creature()
	{
		strength = 10;
		hitpoints = 10;
	}






	creature::creature(int newStrength, int newHitpoints)
	{
		strength = newStrength;
		hitpoints = newHitpoints;
	}






	int creature::getDamage() const
	{
		int damage;

		// All creatures inflict damage which is a random number up to their strength
		damage = (rand() % strength) + 1;
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

		return damage;
	}
	





	void creature::setStrength(int newStrength)
	{
		strength = newStrength;
	}






	void creature::setHitpoints(int newHitpoints)
	{
		hitpoints = newHitpoints;
	}
	





	int creature::getStrength() const
	{
		return strength;
	}






	int creature::getHitpoints() const
	{
		return hitpoints;
	}
}