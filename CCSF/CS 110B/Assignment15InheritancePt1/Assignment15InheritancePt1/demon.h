/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: demon.h, Assignment 15.1
*/
#pragma once
#ifndef DEMON_H
#define DEMON_H
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class demon : public creature
	{
		public:
			demon();
			demon(int newStrength, int newHitpoints);
			int getDamage() const;
			string getSpecies() const;
	};
}
#endif
