/*
Student: William Tsang
Date: February 23, 2016
Class: CS 110B
Name of File: a6_2.cpp, Assignment 6.2
This program records scores and names and organizes them in descending order, with the
highest score first. The program starts by asking the user how many scores they'd like to 
input. It will then allocate appropirately sized arrays to store names and scores into 
memory. Using bubble sort, the program will sort the scores and then output them in descending 
order. It will also output the user who got the corresponding score, in such a fashion: "NAME: THEIR SCORE".
*/

#include <iostream>
#include <string>
using namespace std;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);



int main()
{
	int arraySize;

	cout << "How many scores will you enter?: ";
	cin >> arraySize;

	string *names = new string[arraySize];
	int *scores = new int[arraySize];

	initializeArrays(names, scores, arraySize);
	sortData(names, scores, arraySize);
	displayData(names, scores, arraySize);
	delete [] names;
	delete [] scores;
}






/*This function receives a string array, names, an int array, scores, and an int, size.
Using a for loop (from 0 to size), it promts the user to input a name and a score, then 
stores the data into two arrays: names[] and scores[].*/
void initializeArrays(string names[], int scores[], int size)
{
	string user;
	int points;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i + 1 << ": ";
		cin >> user;
		names[i] = user;
		cout << "Enter the score for score #" << i + 1 << ": ";
		cin >> points;
		scores[i] = points;
	}

	cout << endl;
}






/*This function receives a string array, names, an int array, scores, and an int, size.
It takes the names and scores arrays and then, using a for loop (from 0 to size - 1) and 
the swap function, it makes up a bubble sort function that sorts the scores into descending order.
The names are also sorted accordingly, based on who scored what (according to what the user input).*/
void sortData(string names[], int scores[], int size)
{
	//Bubble Sort
	bool swapped;
	
	do
	{
		swapped = false;

		for (int i = 0; i < size - 1; i++)
		{
			if (scores[i] < scores[i + 1])
			{
				swap(names[i], names[i + 1]);
				swap(scores[i], scores[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}






/*This function receives a string array, names, an int array, scores, and an int, size.
By using a for loop that runs through the indices of the names and scores arrays 
(from 0 to size), it prints the contents of the two arrays.*/
void displayData(const string names[], const int scores[], int size)
{
	cout << "Top Scorers:" << endl;

	for (int i = 0; i < size; i++)
		cout << names[i] << ": " << scores[i] << endl;
}

/* SAMPLE OUTPUT
How many scores will you enter?: 6
Enter the name for score #1: Stussy
Enter the score for score #1: 1982
Enter the name for score #2: Vans
Enter the score for score #2: 2502
Enter the name for score #3: KeepinIt
Enter the score for score #3: 100
Enter the name for score #4: White
Enter the score for score #4: 3134
Enter the name for score #5: DANIEL
Enter the score for score #5: 8765
Enter the name for score #6: DAAAAAAAAAAAAAMN
Enter the score for score #6: 999999

Top Scorers:
DAAAAAAAAAAAAAMN: 999999
DANIEL: 8765
White: 3134
Vans: 2502
Stussy: 1982
KeepinIt: 100
*/