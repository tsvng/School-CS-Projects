/*
Student: William Tsang
Date: February 21, 2016
Class: CS 110B
File Name: a5_1.cpp, Assignment 5
This program records scores and names and organizes them in descending order, with the 
highest score first. The program starts by prompting the user to input five name + score
pairs. It will then store each name and score into memory using arrays. Using bubble sort,
the program will sort the scores and then output them in descending order. It will also
output the user who got the corresponding score, in such a fashion: "NAME: THEIR SCORE".
*/

#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 5;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);


int main()
{
	string names[ARRAY_SIZE];
	int scores[ARRAY_SIZE];

	initializeArrays(names, scores, ARRAY_SIZE);
	sortData(names, scores, ARRAY_SIZE);
	displayData(names, scores, ARRAY_SIZE);
}






/*Promts the user to input five names and five scores, then stores the data into two arrays:
names[] and scores[].*/
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






/*Takes the names[] and scores[] arrays and then, using bubble sort, sorts the scores into
descending order. The names are also sorted accordingly, based on who scored what (according
to what the user input).*/
void sortData(string names[], int scores[], int size)
{
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






//Prints out the sorted arrays of names and scores
void displayData(const string names[], const int scores[], int size)
{
	cout << "Top Scorers:" << endl;

	for (int i = 0; i < size; i++)
		cout << names[i] << ": " << scores[i] << endl;
}

/* SAMEPLE OUTPUT
Enter the name for score #1: Vickee
Enter the score for score #1: 1738
Enter the name for score #2: Hai
Enter the score for score #2: 141
Enter the name for score #3: Alk
Enter the score for score #3: 9001
Enter the name for score #4: Wallt
Enter the score for score #4: 750
Enter the name for score #5: Kira
Enter the score for score #5: 2700

Top Scorers:
Alk: 9001
Kira: 2700
Vickee: 1738
Wallt: 750
Hai: 141
*/