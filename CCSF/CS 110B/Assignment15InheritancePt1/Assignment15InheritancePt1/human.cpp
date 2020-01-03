/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: human.cpp, Assignment 15.1
*/
#include "human.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	human::human() : creature()
	{
	}






	human::human(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
	{
	}






	int human::getDamage() const
	{
		int damage;

		// All creatures inflict damage which is a random number up to their strength
		damage = creature::getDamage();
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

		return damage;
	}






	string human::getSpecies() const
	{
		return "human";
	}
}
