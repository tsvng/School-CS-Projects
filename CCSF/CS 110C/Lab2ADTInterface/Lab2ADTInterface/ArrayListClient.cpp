/*
@file: ArrayListClient.cpp, Lab Assignment 2, CS 110C
This program is used as a driver to test the isInAscendingOrder() function in the modified List ADT
@author: William Tsang
@date: October 5, 2016
*/
#include <iostream>
#include <sstream>

#include "ArrayList.h"

using namespace std;

int main()
{
	ArrayList<int> intList;

	stringstream ss;
	int number;
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
		
		intList.isInAscendingOrder();
		intList.clear();

		cout << "Do you want to continue (y/n): ";
		getline(cin, input);
		ss << input;
		cout << endl;
		ss.clear();

	 } while(input == "y");
}
