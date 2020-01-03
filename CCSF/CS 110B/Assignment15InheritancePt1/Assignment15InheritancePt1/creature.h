/*
Student: William Tsang
Date: May 11, 2016
Class: CS 110B
Name of File: creature.h, Assignment 15.1
*/
#pragma once
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <string>

using namespace std;

namespace cs_creature
{
	class creature 
	{
		public:
			creature();             // initialize to human, 10 strength, 10 hitpoints
			creature(int newStrength, int newHitpoints);
			int getDamage() const;         // returns the amount of damage this Creature inflicts in one round of combat
			string getSpecies() const; // returns the type of the species
			
			void setStrength(int newStrength);
			void setHitpoints(int newHitpoints);
			
			int getStrength() const;
			int getHitpoints() const;
									   // also include appropriate accessors and mutators    
		private:
			int strength;           // how much damage this creature inflicts
			int hitpoints;          // how much damage this creature can sustain	   
	};
}
#endif
/*SAMPLE OUTPUT
default human strength/hitpoints: 10/10
default elf strength/hitpoints: 10/10
default cyberdemon strength/hitpoints: 10/10
default balrog strength/hitpoints: 10/10
non-default human strength/hitpoints: 20/30
non-default elf strength/hitpoints: 40/50
non-default cyberdemon strength/hitpoints: 60/70
non-default balrog strength/hitpoints: 80/90


Examples of human damage:
The human attacks for 11 points!
Total damage = 11

The human attacks for 16 points!
Total damage = 16

The human attacks for 6 points!
Total damage = 6

The human attacks for 14 points!
Total damage = 14

The human attacks for 4 points!
Total damage = 4

The human attacks for 9 points!
Total damage = 9

The human attacks for 11 points!
Total damage = 11

The human attacks for 11 points!
Total damage = 11

The human attacks for 8 points!
Total damage = 8

The human attacks for 16 points!
Total damage = 16


Examples of elf damage:
The elf attacks for 5 points!
Magical attack inflicts 5 additional damage points!
Total damage = 10

The elf attacks for 19 points!
Magical attack inflicts 19 additional damage points!
Total damage = 38

The elf attacks for 39 points!
Total damage = 39

The elf attacks for 15 points!
Magical attack inflicts 15 additional damage points!
Total damage = 30

The elf attacks for 34 points!
Magical attack inflicts 34 additional damage points!
Total damage = 68

The elf attacks for 39 points!
Total damage = 39

The elf attacks for 12 points!
Magical attack inflicts 12 additional damage points!
Total damage = 24

The elf attacks for 26 points!
Magical attack inflicts 26 additional damage points!
Total damage = 52

The elf attacks for 3 points!
Total damage = 3

The elf attacks for 38 points!
Magical attack inflicts 38 additional damage points!
Total damage = 76


Examples of cyberdemon damage:
The cyberdemon attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 61

The cyberdemon attacks for 18 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 68

The cyberdemon attacks for 60 points!
Total damage = 60

The cyberdemon attacks for 14 points!
Total damage = 14

The cyberdemon attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 61

The cyberdemon attacks for 1 points!
Total damage = 1

The cyberdemon attacks for 14 points!
Total damage = 14

The cyberdemon attacks for 59 points!
Total damage = 59

The cyberdemon attacks for 22 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 72

The cyberdemon attacks for 56 points!
Total damage = 56


Examples of balrog damage:
The balrog attacks for 41 points!
Balrog speed attack inflicts 37 additional damage points!
Total damage = 78

The balrog attacks for 11 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 63 additional damage points!
Total damage = 124

The balrog attacks for 78 points!
Balrog speed attack inflicts 71 additional damage points!
Total damage = 149

The balrog attacks for 63 points!
Balrog speed attack inflicts 64 additional damage points!
Total damage = 127

The balrog attacks for 51 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 3 additional damage points!
Total damage = 104

The balrog attacks for 76 points!
Balrog speed attack inflicts 11 additional damage points!
Total damage = 87

The balrog attacks for 10 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 23 additional damage points!
Total damage = 83

The balrog attacks for 13 points!
Balrog speed attack inflicts 63 additional damage points!
Total damage = 76

The balrog attacks for 16 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 64 additional damage points!
Total damage = 130

The balrog attacks for 43 points!
Balrog speed attack inflicts 1 additional damage points!
Total damage = 44
*/