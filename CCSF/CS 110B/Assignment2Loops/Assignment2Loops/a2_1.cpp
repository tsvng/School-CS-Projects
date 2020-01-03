/*
Student: William Tsang
Class: CS 110B
Date: January 31, 2016
Instructor: David Harden
Name of File: a2_1.cpp
This program is a basic Blackjack (21) emulator that gives the player two starting cards and grants
them the choice of adding another card to their total. It utilizes a random number generator with
values of 1-10 when drawing cards. The player can keep drawing new cards until their total exceeds 21.
If their total exceeds 21 they are given the choice to play again and start a new game. This is done by
generating new "first cards" and changing the total back to the sum of the new first cards.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	char response;
	int card1 = rand() % 10 + 1;
	int card2 = rand() % 10 + 1;
	int total = card1 + card2;

	cout << "First cards: " << card1 << ", " << card2 << endl;
	cout << "Total : " << total << endl;

	do
	{
		cout << "Do you want another card? (y/n): ";
		cin >> response;

		if (response == 'y')
		{
			int newCard = rand() % 10 + 1;
			total = total + newCard;

			cout << "Card: " << newCard << endl;
			cout << "Total : " << total << endl;
		}
		else
		{
			cout << "Would you like to play again? (y/n): ";
			cin >> response;

			if (response == 'y') //Play-Again function, resets initial variables
			{
				card1 = rand() % 10 + 1;
				card2 = rand() % 10 + 1;
				total = card1 + card2;
				cout << endl << "First cards: " << card1 << ", " << card2 << endl;
				cout << "Total : " << total << endl;
			}

		}

		if (total > 21)
		{
			cout << "Bust." << endl;
			cout << "Would you like to play again? (y/n): ";
			cin >> response;

			if (response == 'y') //Play-Again function, resets initial variables
			{
				card1 = rand() % 10 + 1;
				card2 = rand() % 10 + 1;
				total = card1 + card2;
				cout << endl << "First cards: " << card1 << ", " << card2 << endl;
				cout << "Total : " << total << endl;
			}

		}

		if (total == 21)
		{
			cout << "Blackjack!" << endl;
			cout << "Would you like to play again? (y/n): ";
			cin >> response;

			if (response == 'y') //Play-Again function, resets initial variables
			{
				card1 = rand() % 10 + 1;
				card2 = rand() % 10 + 1;
				total = card1 + card2;
				cout << endl << "First cards: " << card1 << ", " << card2 << endl;
				cout << "Total : " << total << endl;
			}

		}
	} while (response == 'y' && total < 22);
}

/* SAMEPLE OUTPUT
First cards: 8, 1
Total : 9
Do you want another card? (y/n): y
Card: 2
Total : 11
Do you want another card? (y/n): y
Card: 10
Total : 21
Do you want another card? (y/n): n
Would you like to play again? (y/n): y

First cards: 2, 9
Total : 11
Do you want another card? (y/n): y
Card: 4
Total : 15
Do you want another card? (y/n): y
Card: 6
Total : 21
Blackjack!
Would you like to play again? (y/n): y

First cards: 2, 4
Total : 6
Do you want another card? (y/n): y
Card: 4
Total : 10
Do you want another card? (y/n): y
Card: 9
Total : 19
Do you want another card? (y/n): y
Card: 6
Total : 25
Bust.
Would you like to play again? (y/n): n
Press any key to continue . . .
*/