/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: balrog.cpp, Assignment 15.1
*/
#include "balrog.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	balrog::balrog() : demon()
	{
	}






	balrog::balrog(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints)
	{
	}






	int balrog::getDamage() const
	{
		int damage;

		cout << "The balrog";
		damage = demon::getDamage();

		// Balrogs are so fast they get to attack twice
	
		int damage2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage += damage2;
		
		return damage;
	}






	string balrog::getSpecies() const
	{
		return "balrog";
	}
}