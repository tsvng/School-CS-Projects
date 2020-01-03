/*
@file: LinkedListReplaceClient.cpp, Lab Assignment 3, CS 110C
This program is used as a driver to test the replace function in the modified List ADT
@author: William Tsang
@date: October 6, 2016
*/
#include <iostream>
#include <sstream>

#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> intList;

	stringstream ss;
	int number;
	int oldValue;
	int newValue;
	int numReplacements;

	string input;

	do
	{
		int pos = 1;
		cout << "Input a list of integers: ";
		getline(cin, input);
		ss << input;

		while (ss >> number)
		{
			intList.insert(pos, number);
			pos++;
		}

		cout << "Enter a value to be modified: ";
		cin >> oldValue;
		cout << "Enter replacement value: ";
		cin >> newValue;
		numReplacements = intList.replace(oldValue, newValue);
		
		cout << "Modified List: ";
		for (int position = 1; position <= intList.getLength(); position++)
			cout << intList.getEntry(position) << " ";

		cout << endl << "Number of items replaced: " << numReplacements << endl;
		intList.clear();

		cin.ignore();
		cout << "Would you like to modify another list (y/n)?: ";
		getline(cin, input);
		ss << input;
		cout << endl;
		ss.clear();

	} while (input == "y");
}


