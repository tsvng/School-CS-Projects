/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: elf.h, Assignment 15.1
*/
#pragma once
#ifndef ELF_H
#define ELF_H
#include "creature.h"
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class elf : public creature
	{
		public:
			elf();
			elf(int newStrength, int newHitpoints);
			int getDamage() const;
			string getSpecies() const;
	};
}
#endif