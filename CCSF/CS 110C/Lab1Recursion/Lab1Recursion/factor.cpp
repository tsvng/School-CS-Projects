/*
@file: factor.cpp, Lab Assignment 1, CS 110C
This program is used to find all the prime factors of a given integer and outputs them in descending order
@author: William Tsang
@date: September 10, 2016
*/
#include <iostream>
using namespace std;





/*Finds all the prime factors of a given integer and outputs them in descending order
	using recursion
@param: number: the  integer which will be factored 
	factor: the number of factors "number" has
@pre: User provides a positive integer for number
	User can call showFactors with one parameter (number)
@post: displays all the prime factors of number (excluding 1)
	Both number and factor are changed as the program recursively calls itself
*/
void showFactors(int number, int factor = 2)
{
	if (number == 1)
		return;

	else if (number % factor == 0)
	{
		showFactors(number / factor, factor);
		cout << factor << " ";
	}
	else
		showFactors(number, factor + 1);
}





int main()
{
	int response;

	do 
	{
		cout << "Enter a number, and I will display its prime factors in descending order" << endl;
		cout << "(enter 0 to exit program): ";
		cin >> response;

		if (response != 0)
		{
			if (response == 1)
				cout << "The factors for " << response << ": 1" << endl << endl;
			else
			{
				cout << "The factors for " << response << ": ";
				showFactors(response);
				cout << endl << endl;
			}	
		}

	} while (response != 0);

	if (response == 0)
		cout << "Goodbye!" << endl;
}