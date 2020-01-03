/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: cyberdemon.h, Assignment 15.1
*/
#pragma once
#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "demon.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class cyberdemon : public demon
	{
		public:
			cyberdemon();
			cyberdemon(int newStrength, int newHitpoints);
			int getDamage() const;
			string getSpecies() const;
	};
}
#endif