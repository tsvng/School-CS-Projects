/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: cyberdemon.cpp, Assignment 15.1
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






	int cyberdemon::getDamage() const
	{
		int damage;

		cout << "The cyberdemon";
		damage = demon::getDamage();

		return damage;
	}






	string cyberdemon::getSpecies() const
	{
		return "cyberdemon";
	}
}