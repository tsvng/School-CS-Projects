/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: demon.cpp, Assignment 16.1
*/
#include "demon.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	demon::demon() : creature()
	{
	}






	demon::demon(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
	{
	}






	int demon::getDamage() const
	{
		int damage;

		// All creatures inflict damage which is a random number up to their strength
		damage = creature::getDamage();

		// Demons can inflict damage of 50 with a 25% chance
		if (rand() % 4 == 0) 
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}

		return damage;
	}






	string demon::getSpecies() const
	{
		return "demon";
	}
}