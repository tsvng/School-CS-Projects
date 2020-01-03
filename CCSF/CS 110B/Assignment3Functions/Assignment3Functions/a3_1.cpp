/*
Student: William Tsang
Class: CS 110B
Date: February 6, 2016
Instructor: David Harden
Name of File: a3_1.cpp
This program is a number guessing game which tries to guess the number the user has chosen.
The user is prompted to choose, but not input,a number between 1 and 100. The program will
then start to guess the user's number by using a binary search method. It will guess a number
between 1 and 100, then adjust it's guess accordingly based on the user's response.
*/
#include <iostream>

using namespace std;

int getMidpoint(int low, int high);
void getUserResponse(int guess, char& result);
void playOneGame();

const int MAX_NUM = 100;

int main()
{
	char response;

	cout << "Ready to play (y/n)? ";
	cin >> response;

	while (response == 'y')
	{
		playOneGame();
		cout << "Great! Do you want to play again (y/n)? ";
		cin >> response;
		cout << endl;
	}

}






//Takes 2 integers and finds the midpoint between them by finding the average.
int getMidpoint(int low, int high)
{
	return (low + high) / 2;
}






/*Takes in an int that functions as a guess, in this case it's getMidpoint, and asks the user if
their number is greater than, less than, or equal to the guess.*/
void getUserResponse(int guess, char& result)
{
	cout << "Is it " << guess << " (h/l/c)? ";
	cin >> result;
}






/*Is the game/ binary search function. While the guess isn't equal to the user's number it will
continually adjust the domain in which the user's number can be in by changing the low and high
values. This will effect the number getMidpoint() will output, as well as the guess 
getUserResponse() asks.*/
void playOneGame()
{
	int low = 1;
	int high = MAX_NUM;
	char result;

	cout << "Think of a number between 1 and 100." << endl;

	do
	{
		int guess = getMidpoint(low, high);
		getUserResponse(guess, result);

		if (result == 'l')
		{
			high = guess - 1;
		}
		else
		{
			low = guess + 1;
		}

	} while (result != 'c');

}

/* SAMPLE OUTPUT FIRST RUN # is 77, SECOND RUN # is 17
Ready to play (y/n)? y
Think of a number between 1 and 100.
Is it 50 (h/l/c)? h
Is it 75 (h/l/c)? h
Is it 88 (h/l/c)? l
Is it 81 (h/l/c)? l
Is it 78 (h/l/c)? l
Is it 76 (h/l/c)? h
Is it 77 (h/l/c)? c
Great! Do you want to play again (y/n)? y

Think of a number between 1 and 100.
Is it 50 (h/l/c)? l
Is it 25 (h/l/c)? l
Is it 12 (h/l/c)? h
Is it 18 (h/l/c)? l
Is it 15 (h/l/c)? h
Is it 16 (h/l/c)? h
Is it 17 (h/l/c)? c
Great! Do you want to play again (y/n)?
*/