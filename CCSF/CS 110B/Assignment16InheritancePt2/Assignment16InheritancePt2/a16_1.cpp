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

int main() {
	srand(time(0));

	human h1;
	elf e1;
	cyberdemon c1;
	balrog b1;

	human h(20, 30);
	elf e(40, 50);
	cyberdemon c(60, 70);
	balrog b(80, 90);


	cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
	cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
	cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
	cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
	cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
	cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
	cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
	cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
	cout << endl << endl;

	cout << "Examples of " << h.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = h.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << e.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = e.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << c.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = c.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
	



	cout << "Examples of " << b.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++) {
		int damage = b.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;

	//Default constructor stat fight
	battleArena(h1, e1);
	battleArena(h1, c1);
	battleArena(h1, b1);
	battleArena(e1, c1);
	battleArena(e1, b1);
	battleArena(c1, b1);
	battleArena(b1, c1);

	//Given (from original client program) stat fight
	battleArena(h, e);
	battleArena(h, c);
	battleArena(h, b);
	battleArena(e, c);
	battleArena(e, b);
	battleArena(c, b);
	battleArena(b, c);
	
	//"Balanced" stat fight
	human hBal(50, 50);
	elf eBal(50, 50);
	cyberdemon cBal(50, 50);
	balrog bBal(50, 50);

	battleArena(hBal, eBal);
	battleArena(hBal, cBal);
	battleArena(hBal, bBal);
	battleArena(eBal, cBal);
	battleArena(eBal, bBal);
	battleArena(cBal, bBal);
	battleArena(bBal, cBal);


}

void battleArena(creature &creature1, creature& creature2)
{
	int temp1HP = creature1.getHitpoints();
	int temp2HP = creature2.getHitpoints();
	int n = 1;
	bool battleOver = false;

	cout << "---The " << creature1.getSpecies() << " and " << creature2.getSpecies() << " are battling!---" << endl;
	cout << "The " << creature1.getSpecies() << " starts with " << creature1.getHitpoints() << " hitpoints and " << creature1.getStrength() << " strength." << endl;
	cout << "The " << creature2.getSpecies() << " starts with " << creature2.getHitpoints() << " hitpoints and " << creature2.getStrength() << " strength." << endl;

	do
	{
		cout << endl << "Round " << n << " FIGHT!" << endl;
		
		int creature1Dmg = creature1.getDamage();
		cout << " Total " << creature1.getSpecies() << " damage = " << creature1Dmg << endl;

		int creature2Dmg = creature2.getDamage();
		cout << " Total " << creature2.getSpecies() << " damage = " << creature2Dmg << endl;

		creature2.setHitpoints(creature2.getHitpoints() - creature1Dmg);
		creature1.setHitpoints(creature1.getHitpoints() - creature2Dmg);

		cout << "The " << creature1.getSpecies() << " has " << creature1.getHitpoints() << " hitpoints remaining." << endl;
		cout << "The " << creature2.getSpecies() << " has " << creature2.getHitpoints() << " hitpoints remaining." << endl;

		if ((creature1.getHitpoints() <= 0) && (creature2.getHitpoints() <= 0))
		{
			cout << "~~~The battle resulted in a tie!~~~" << endl << endl;

			battleOver = true;
		}
			
		else if ((creature1.getHitpoints() <= 0) || (creature2.getHitpoints() <= 0))
		{
			cout << "~~~The battle is over, ";

			if (creature1.getHitpoints() > creature2.getHitpoints())
				cout << creature1.getSpecies() << " wins!~~~" << endl << endl;
			else
				cout << creature2.getSpecies() << " wins!~~~" << endl << endl;

			battleOver = true;
		}

		n++;
	} while (!battleOver);

	//restores creature's HP for the next battle
	creature1.setHitpoints(temp1HP); 
	creature2.setHitpoints(temp2HP);
}