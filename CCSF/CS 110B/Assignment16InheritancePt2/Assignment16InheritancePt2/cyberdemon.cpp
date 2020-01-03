/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: cyberdemon.cpp, Assignment 16.1
*/
#include "cyberdemon.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	cyberdemon::cyberdemon() : demon()
	{
	}






	cyberdemon::cyberdemon(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints)
	{
	}






	string cyberdemon::getSpecies() const
	{
		return "cyberdemon";
	}
}