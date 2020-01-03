/*
@file: LinkedListEqualsClient.cpp, Lab Assignment 3, CS 110C
This program is used as a driver to test the equals function in the modified List ADT.
@author: William Tsang
@date: October 6, 2016
*/
#include <iostream>
#include <sstream>

#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> intList1;
	LinkedList<int> intList2;

	stringstream ss;
	int number1;
	int number2;
	string input;

	do
	{
		int pos1 = 1;
		int pos2 = 1;
		ss.clear();
		cout << "Enter first list to be compared: ";
		getline(cin, input);
		ss << input;
		while (ss >> number1)
		{
			intList1.insert(pos1, number1);
			pos1++;
		}
		ss.clear();
		cout << "Enter second list to be compared: ";
		getline(cin, input);
		ss << input;
		while (ss >> number2)
		{
			intList2.insert(pos2, number2);
			pos2++;
		}

		intList1.equals(intList2);

		intList1.clear();
		intList2.clear();

		cout << "Would you like to compare two more lists (y/n)?: ";
		getline(cin, input);
		ss << input;
		cout << endl;
		ss.clear();

	} while (input == "y");
}


