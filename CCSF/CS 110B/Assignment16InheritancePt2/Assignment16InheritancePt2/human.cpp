/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: human.cpp, Assignment 16.1
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






	string human::getSpecies() const
	{
		return "human";
	}
}
