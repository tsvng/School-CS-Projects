/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: human.h, Assignment 16.1
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
			string getSpecies() const;
	};
}
#endif