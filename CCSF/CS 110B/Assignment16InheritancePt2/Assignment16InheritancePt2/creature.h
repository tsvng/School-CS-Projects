/*
Student: William Tsang
Date: May 18, 2016
Class: CS 110B
Name of File: creature.h, Assignment 16.1
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
			virtual int getDamage() const;         // returns the amount of damage this Creature inflicts in one round of combat
			virtual string getSpecies() const = 0; // returns the type of the species
			
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
The human attacks for 5 points!
Total damage = 5

The human attacks for 9 points!
Total damage = 9

The human attacks for 16 points!
Total damage = 16

The human attacks for 5 points!
Total damage = 5

The human attacks for 16 points!
Total damage = 16

The human attacks for 10 points!
Total damage = 10

The human attacks for 11 points!
Total damage = 11

The human attacks for 4 points!
Total damage = 4

The human attacks for 19 points!
Total damage = 19

The human attacks for 12 points!
Total damage = 12


Examples of elf damage:
The elf attacks for 2 points!
Magical attack inflicts 2 additional damage points!
Total damage = 4

The elf attacks for 3 points!
Magical attack inflicts 3 additional damage points!
Total damage = 6

The elf attacks for 29 points!
Magical attack inflicts 29 additional damage points!
Total damage = 58

The elf attacks for 25 points!
Total damage = 25

The elf attacks for 20 points!
Total damage = 20

The elf attacks for 10 points!
Total damage = 10

The elf attacks for 7 points!
Total damage = 7

The elf attacks for 12 points!
Total damage = 12

The elf attacks for 8 points!
Magical attack inflicts 8 additional damage points!
Total damage = 16

The elf attacks for 11 points!
Total damage = 11


Examples of cyberdemon damage:
The cyberdemon attacks for 49 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 99

The cyberdemon attacks for 57 points!
Total damage = 57

The cyberdemon attacks for 20 points!
Total damage = 20

The cyberdemon attacks for 50 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 100

The cyberdemon attacks for 44 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 94

The cyberdemon attacks for 60 points!
Total damage = 60

The cyberdemon attacks for 35 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 85

The cyberdemon attacks for 30 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 80

The cyberdemon attacks for 33 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 83

The cyberdemon attacks for 4 points!
Demonic attack inflicts 50 additional damage points!
Total damage = 54


Examples of balrog damage:
The balrog attacks for 66 points!
Balrog speed attack inflicts 34 additional damage points!
Total damage = 100

The balrog attacks for 44 points!
Balrog speed attack inflicts 14 additional damage points!
Total damage = 58

The balrog attacks for 72 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 12 additional damage points!
Total damage = 134

The balrog attacks for 18 points!
Balrog speed attack inflicts 6 additional damage points!
Total damage = 24

The balrog attacks for 48 points!
Balrog speed attack inflicts 19 additional damage points!
Total damage = 67

The balrog attacks for 19 points!
Balrog speed attack inflicts 70 additional damage points!
Total damage = 89

The balrog attacks for 12 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 68 additional damage points!
Total damage = 130

The balrog attacks for 30 points!
Balrog speed attack inflicts 5 additional damage points!
Total damage = 35

The balrog attacks for 11 points!
Balrog speed attack inflicts 35 additional damage points!
Total damage = 46

The balrog attacks for 3 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 16 additional damage points!
Total damage = 69


---The human and elf are battling!---
The human starts with 10 hitpoints and 10 strength.
The elf starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The human attacks for 1 points!
Total human damage = 1
The elf attacks for 7 points!
Magical attack inflicts 7 additional damage points!
Total elf damage = 14
The human has -4 hitpoints remaining.
The elf has 9 hitpoints remaining.
~~~The battle is over, elf wins!~~~

---The human and cyberdemon are battling!---
The human starts with 10 hitpoints and 10 strength.
The cyberdemon starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The human attacks for 3 points!
Total human damage = 3
The cyberdemon attacks for 9 points!
Total cyberdemon damage = 9
The human has 1 hitpoints remaining.
The cyberdemon has 7 hitpoints remaining.

Round 2 FIGHT!
The human attacks for 10 points!
Total human damage = 10
The cyberdemon attacks for 7 points!
Demonic attack inflicts 50 additional damage points!
Total cyberdemon damage = 57
The human has -56 hitpoints remaining.
The cyberdemon has -3 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The human and balrog are battling!---
The human starts with 10 hitpoints and 10 strength.
The balrog starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The human attacks for 7 points!
Total human damage = 7
The balrog attacks for 4 points!
Balrog speed attack inflicts 10 additional damage points!
Total balrog damage = 14
The human has -4 hitpoints remaining.
The balrog has 3 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The elf and cyberdemon are battling!---
The elf starts with 10 hitpoints and 10 strength.
The cyberdemon starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The elf attacks for 6 points!
Total elf damage = 6
The cyberdemon attacks for 2 points!
Demonic attack inflicts 50 additional damage points!
Total cyberdemon damage = 52
The elf has -42 hitpoints remaining.
The cyberdemon has 4 hitpoints remaining.
~~~The battle is over, cyberdemon wins!~~~

---The elf and balrog are battling!---
The elf starts with 10 hitpoints and 10 strength.
The balrog starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The elf attacks for 6 points!
Magical attack inflicts 6 additional damage points!
Total elf damage = 12
The balrog attacks for 2 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 3 additional damage points!
Total balrog damage = 55
The elf has -45 hitpoints remaining.
The balrog has -2 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The cyberdemon and balrog are battling!---
The cyberdemon starts with 10 hitpoints and 10 strength.
The balrog starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The cyberdemon attacks for 10 points!
Demonic attack inflicts 50 additional damage points!
Total cyberdemon damage = 60
The balrog attacks for 8 points!
Balrog speed attack inflicts 8 additional damage points!
Total balrog damage = 16
The cyberdemon has -6 hitpoints remaining.
The balrog has -50 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The balrog and cyberdemon are battling!---
The balrog starts with 10 hitpoints and 10 strength.
The cyberdemon starts with 10 hitpoints and 10 strength.

Round 1 FIGHT!
The balrog attacks for 10 points!
Balrog speed attack inflicts 3 additional damage points!
Total balrog damage = 13
The cyberdemon attacks for 6 points!
Total cyberdemon damage = 6
The balrog has 4 hitpoints remaining.
The cyberdemon has -3 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The human and elf are battling!---
The human starts with 30 hitpoints and 20 strength.
The elf starts with 50 hitpoints and 40 strength.

Round 1 FIGHT!
The human attacks for 5 points!
Total human damage = 5
The elf attacks for 31 points!
Magical attack inflicts 31 additional damage points!
Total elf damage = 62
The human has -32 hitpoints remaining.
The elf has 45 hitpoints remaining.
~~~The battle is over, elf wins!~~~

---The human and cyberdemon are battling!---
The human starts with 30 hitpoints and 20 strength.
The cyberdemon starts with 70 hitpoints and 60 strength.

Round 1 FIGHT!
The human attacks for 2 points!
Total human damage = 2
The cyberdemon attacks for 59 points!
Total cyberdemon damage = 59
The human has -29 hitpoints remaining.
The cyberdemon has 68 hitpoints remaining.
~~~The battle is over, cyberdemon wins!~~~

---The human and balrog are battling!---
The human starts with 30 hitpoints and 20 strength.
The balrog starts with 90 hitpoints and 80 strength.

Round 1 FIGHT!
The human attacks for 16 points!
Total human damage = 16
The balrog attacks for 38 points!
Balrog speed attack inflicts 74 additional damage points!
Total balrog damage = 112
The human has -82 hitpoints remaining.
The balrog has 74 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The elf and cyberdemon are battling!---
The elf starts with 50 hitpoints and 40 strength.
The cyberdemon starts with 70 hitpoints and 60 strength.

Round 1 FIGHT!
The elf attacks for 4 points!
Magical attack inflicts 4 additional damage points!
Total elf damage = 8
The cyberdemon attacks for 5 points!
Demonic attack inflicts 50 additional damage points!
Total cyberdemon damage = 55
The elf has -5 hitpoints remaining.
The cyberdemon has 62 hitpoints remaining.
~~~The battle is over, cyberdemon wins!~~~

---The elf and balrog are battling!---
The elf starts with 50 hitpoints and 40 strength.
The balrog starts with 90 hitpoints and 80 strength.

Round 1 FIGHT!
The elf attacks for 12 points!
Total elf damage = 12
The balrog attacks for 77 points!
Balrog speed attack inflicts 77 additional damage points!
Total balrog damage = 154
The elf has -104 hitpoints remaining.
The balrog has 78 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The cyberdemon and balrog are battling!---
The cyberdemon starts with 70 hitpoints and 60 strength.
The balrog starts with 90 hitpoints and 80 strength.

Round 1 FIGHT!
The cyberdemon attacks for 35 points!
Total cyberdemon damage = 35
The balrog attacks for 53 points!
Balrog speed attack inflicts 65 additional damage points!
Total balrog damage = 118
The cyberdemon has -48 hitpoints remaining.
The balrog has 55 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The balrog and cyberdemon are battling!---
The balrog starts with 90 hitpoints and 80 strength.
The cyberdemon starts with 70 hitpoints and 60 strength.

Round 1 FIGHT!
The balrog attacks for 44 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 49 additional damage points!
Total balrog damage = 143
The cyberdemon attacks for 21 points!
Total cyberdemon damage = 21
The balrog has 69 hitpoints remaining.
The cyberdemon has -73 hitpoints remaining.
~~~The battle is over, balrog wins!~~~

---The human and elf are battling!---
The human starts with 50 hitpoints and 50 strength.
The elf starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The human attacks for 36 points!
Total human damage = 36
The elf attacks for 33 points!
Magical attack inflicts 33 additional damage points!
Total elf damage = 66
The human has -16 hitpoints remaining.
The elf has 14 hitpoints remaining.
~~~The battle is over, elf wins!~~~

---The human and cyberdemon are battling!---
The human starts with 50 hitpoints and 50 strength.
The cyberdemon starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The human attacks for 49 points!
Total human damage = 49
The cyberdemon attacks for 32 points!
Total cyberdemon damage = 32
The human has 18 hitpoints remaining.
The cyberdemon has 1 hitpoints remaining.

Round 2 FIGHT!
The human attacks for 21 points!
Total human damage = 21
The cyberdemon attacks for 19 points!
Total cyberdemon damage = 19
The human has -1 hitpoints remaining.
The cyberdemon has -20 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The human and balrog are battling!---
The human starts with 50 hitpoints and 50 strength.
The balrog starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The human attacks for 50 points!
Total human damage = 50
The balrog attacks for 21 points!
Balrog speed attack inflicts 50 additional damage points!
Total balrog damage = 71
The human has -21 hitpoints remaining.
The balrog has 0 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The elf and cyberdemon are battling!---
The elf starts with 50 hitpoints and 50 strength.
The cyberdemon starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The elf attacks for 19 points!
Total elf damage = 19
The cyberdemon attacks for 25 points!
Total cyberdemon damage = 25
The elf has 25 hitpoints remaining.
The cyberdemon has 31 hitpoints remaining.

Round 2 FIGHT!
The elf attacks for 48 points!
Total elf damage = 48
The cyberdemon attacks for 32 points!
Demonic attack inflicts 50 additional damage points!
Total cyberdemon damage = 82
The elf has -57 hitpoints remaining.
The cyberdemon has -17 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The elf and balrog are battling!---
The elf starts with 50 hitpoints and 50 strength.
The balrog starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The elf attacks for 48 points!
Magical attack inflicts 48 additional damage points!
Total elf damage = 96
The balrog attacks for 19 points!
Balrog speed attack inflicts 39 additional damage points!
Total balrog damage = 58
The elf has -8 hitpoints remaining.
The balrog has -46 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The cyberdemon and balrog are battling!---
The cyberdemon starts with 50 hitpoints and 50 strength.
The balrog starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The cyberdemon attacks for 23 points!
Total cyberdemon damage = 23
The balrog attacks for 5 points!
Balrog speed attack inflicts 44 additional damage points!
Total balrog damage = 49
The cyberdemon has 1 hitpoints remaining.
The balrog has 27 hitpoints remaining.

Round 2 FIGHT!
The cyberdemon attacks for 36 points!
Total cyberdemon damage = 36
The balrog attacks for 48 points!
Balrog speed attack inflicts 29 additional damage points!
Total balrog damage = 77
The cyberdemon has -76 hitpoints remaining.
The balrog has -9 hitpoints remaining.
~~~The battle resulted in a tie!~~~

---The balrog and cyberdemon are battling!---
The balrog starts with 50 hitpoints and 50 strength.
The cyberdemon starts with 50 hitpoints and 50 strength.

Round 1 FIGHT!
The balrog attacks for 27 points!
Balrog speed attack inflicts 25 additional damage points!
Total balrog damage = 52
The cyberdemon attacks for 27 points!
Total cyberdemon damage = 27
The balrog has 23 hitpoints remaining.
The cyberdemon has -2 hitpoints remaining.
~~~The battle is over, balrog wins!~~~
*/