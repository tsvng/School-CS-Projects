/*
   Name: Simon Zhen
   Class: CS 110B
   Date: 5/17/2016
   Instructor: David Harden
   Name of file: balrog.cpp
   Assignment 16.1
   Description: Introduction to inheritance, role playing game program. Battle Arena!
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "creature.h"
#include "demon.h"
#include "human.h"
#include "cyberdemon.h"
#include "balrog.h"
#include "elf.h"

using namespace std;
using namespace cs_creature;

void battleArena(creature &creature1, creature& creature2);

int main() 
{
    srand(time(0));

    human h1;
    elf e1;
    cyberdemon c1;
    balrog b1;
    
    human h(20, 30);
    elf e(40, 80);
    cyberdemon c(85, 85);
    balrog b(90, 90);
	
	
    // Default constructor stat fight
    battleArena(h1, e1);
    battleArena(h1, c1);
    battleArena(h1, b1);
    battleArena(e1, c1);
    battleArena(e1, b1);
    battleArena(c1, b1);
    battleArena(b1, c1);

    // Stat fight from original client program
    battleArena(h, e);
    battleArena(h, c);
    battleArena(h, b);
    battleArena(e, c);
    battleArena(e, b);
    battleArena(c, b);
    battleArena(b, c);
}






void battleArena(creature &creature1, creature& creature2)
{
    int maxHP1 = creature1.getHitpoints();
    int maxHP2 = creature2.getHitpoints();
    int counter = 1;
    bool roundOver = false;

    cout << "The " << creature1.getSpecies() << " and the " << creature2.getSpecies() << " are fighting" << endl;
    cout << "The " << creature1.getSpecies() << " begins with " << creature1.getHitpoints() << " and " << creature1.getStrength() << " strength." << endl;
    cout << "The " << creature2.getSpecies() << " begins with " << creature2.getHitpoints() << " and " << creature2.getStrength() << " strength." << endl;

    do
    {
	cout << endl << "Round " << counter << " Begin!" << endl;
		
	int creatureDamage1 = creature1.getDamage();
	int creatureDamage2 = creature2.getDamage();
	cout << "The " << creature1.getSpecies() << " does " << creatureDamage1 << endl;
	cout << "The " << creature2.getSpecies() << " does " << creatureDamage2 << endl;

	creature2.setHitpoints(creature2.getHitpoints() - creatureDamage1);
	creature1.setHitpoints(creature1.getHitpoints() - creatureDamage2);

	cout << "The " << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints remaining." << endl;
	cout << "The " << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hitpoints remaining." << endl;

	if ((creature1.getHitpoints() <= 0) && (creature2.getHitpoints() <= 0))
	{
	    cout << " It's a tie!!" << endl << endl;

	    roundOver = true;
	}
			
	else if ((creature1.getHitpoints() <= 0) || (creature2.getHitpoints() <= 0))
	{
	    cout << " The round is over! ";

	    if (creature1.getHitpoints() > creature2.getHitpoints())
	    {
	        cout << creature1.getSpecies() << " is the winner!" << endl;
	        cout << endl;
	    }
	    else
	    {
	    cout << creature2.getSpecies() << " is the winner!" << endl;
	    cout << endl;
	    }

	    roundOver = true;
	}
        counter++;
    } while (!roundOver);

    creature1.setHitpoints(maxHP1); 
    creature2.setHitpoints(maxHP2);
}

