/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: cyberdemon.h, Assignment 16.1
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
			string getSpecies() const;
	};
}
#endif