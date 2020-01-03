/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: elf.cpp, Assignment 15.1
*/
#include "elf.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	elf::elf() : creature()
	{
	}






	elf::elf(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
	{
	}






	int elf::getDamage() const
	{
		int damage;

		// All creatures inflict damage which is a random number up to their strength
		damage = creature::getDamage();
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

		// Elves inflict double magical damage with a 50% chance
		if ((rand() % 2) == 0) 
		{
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage *= 2;
		}
		
		return damage;
	}






	string elf::getSpecies() const
	{
		return "elf";
	}
}