/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: balrog.h, Assignment 15.1
*/
#pragma once
#ifndef BALROG_H
#define BALROG_H
#include "demon.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class balrog : public demon
	{
		public:
			balrog();
			balrog(int newStrength, int newHitpoints);
			int getDamage() const;
			string getSpecies() const;
	};
}
#endif