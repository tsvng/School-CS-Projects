/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: human.h, Assignment 15.1
*/
#pragma once
#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class human : public creature
	{
		public:
			human();
			human(int newStrength, int newHitpoints);
			int getDamage() const;
			string getSpecies() const;
	};
}
#endif