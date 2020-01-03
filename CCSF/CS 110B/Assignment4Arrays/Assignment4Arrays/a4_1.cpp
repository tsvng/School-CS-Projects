/*
Student: William Tsang
Date: February 15, 2016
Class: CS 110B
File Name: a4_1.cpp, Assignment 4
This program is a hand reader for poker. It begins by prompting the user for 5 cards, ranging 
in value from 2 to 9, and stores each value into a spot in the hand array. After the user
has input 5 valid values, the program will then check the values of each card and tell the user
what kind of poker hand they have. The program will output: "High Card!", "One Pair!", "Two Pair!",
"Three of a kind!", "Straight!", "Full House!", or "Four of a kind!" accordingly, based on 
the hand the user input.
*/

#include <iostream>
using namespace std;

const int NUM_CARDS = 5;
const int MIN_CARDVALUE = 2;
const int MAX_CARDVALUE = 9;

bool  containsPair(const int hand[]);
bool  containsTwoPair(const int hand[]);
bool  containsThreeOfaKind(const int hand[]);
bool  containsStraight(const int hand[]);
bool  containsFullHouse(const int hand[]);
bool  containsFourOfaKind(const int hand[]);
int  numMatchingValue(const int hand[], int cardValue);
int  checkStraight(const int hand[], int cardValue);
void printHandType(const int hand[]);



int main() 
{
	int card;
	int hand[NUM_CARDS];

	cout << "Enter five numeric cards, no face cards. Use 2 - 9." << endl;

	for (int count = 0; count < NUM_CARDS; count++)
	{
		cout << "Card " << count + 1 << ": ";
		cin >> card;
		hand[count] = card;
	}

	printHandType(hand);
}






//Checks the user's hand for a pair
bool containsPair(const int hand[])
{
	for (int cardValue = MIN_CARDVALUE; cardValue <= MAX_CARDVALUE; cardValue++)
		if (numMatchingValue(hand, cardValue) == 2)
			return true;

	return false;
}






//Checks the user's hand for two pairs
bool containsTwoPair(const int hand[])
{
	int numPairs = 0;

	for (int cardValue = MIN_CARDVALUE; cardValue <= MAX_CARDVALUE; cardValue++)
		if (numMatchingValue(hand, cardValue) == 2)
			numPairs++;

	return numPairs == 2;
}






//Checks the user's hand for three of a kind
bool containsThreeOfaKind(const int hand[])
{
	for (int cardValue = MIN_CARDVALUE; cardValue <= MAX_CARDVALUE; cardValue++)
		if (numMatchingValue(hand, cardValue) == 3)
			return true;

	return false;
}






//Checks the user's hand for a straight (five consecutive cards)
bool containsStraight(const int hand[])
{
	for (int cardValue = MIN_CARDVALUE; cardValue < 6; cardValue++)
		if (checkStraight(hand, cardValue) == 5)
			return true;

	return false;
}






//Checks the user's hand for a full house (pair + three of a kind)
bool containsFullHouse(const int hand[])
{
	return (containsPair(hand) && containsThreeOfaKind(hand));
}






//Checks the user's hand for four of a kind
bool containsFourOfaKind(const int hand[])
{
	for (int cardValue = MIN_CARDVALUE; cardValue <= MAX_CARDVALUE; cardValue++)
		if (numMatchingValue(hand, cardValue) == 4)
			return true;

	return false;
}






//Checks the user's hand and returns the number of cards that match the given (card)value
int numMatchingValue(const int hand[], int cardValue)
{
	int numMatch = 0;

	for (int i = 0; i < 5; i++)
		if (hand[i] == cardValue)
			numMatch++;

	return numMatch;
}






//Checks to see if there is a straight starting from the given (card)value
int checkStraight(const int hand[], int cardValue)
{
	int consecutiveCards = 0;

	for (int i = 0; i < 5; i++)
		if (numMatchingValue(hand, cardValue + i) == 1)
			consecutiveCards++;
	
	return consecutiveCards;
}






//Tells the user what type of hand they have
void printHandType(const int hand[])
{
	if (containsFourOfaKind(hand))
		cout << "Four of a kind!" << endl;

	else if (containsFullHouse(hand))
		cout << "Full House!" << endl;

	else if (containsStraight(hand))
		cout << "Straight!" << endl;

	else if (containsThreeOfaKind(hand))
		cout << "Three of a kind!" << endl;

	else if (containsTwoPair(hand))
		cout << "Two Pair!" << endl;

	else if (containsPair(hand))
		cout << "One Pair!" << endl;

	else
		cout << "High Card!" << endl;
}

/* SAMPLE OUTPUT
Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 6
Card 3: 7
Card 4: 8
Card 5: 2
One Pair!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 7
Card 2: 6
Card 3: 8
Card 4: 6
Card 5: 7
Two Pair!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 8
Card 2: 5
Card 3: 7
Card 4: 4
Card 5: 6
Straight!
*/