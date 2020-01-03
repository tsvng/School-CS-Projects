/*
Student: William Tsang
Date: March 14, 2016 Happy Pi Day!
Class: CS 110B
Name of File: a8_1.cpp, Assignment 8.1
This program records scores and names and organizes them in descending order, with the
highest score first. It does this by utilizing a struct, highscore, which has two members. 
One member is a char array that holds the names, and the other is an int that holds the scores. 
The program starts by asking the user how many scores they'd like to input. It will then 
allocate an appropirately sized array of highscore structs into memory. Using selection sort, 
the program will sort the scores and then outputs them in descending order in such a fashion: "NAME: THEIR SCORE".
*/

#include <iostream>
#include <string>

using namespace std;

struct highscore
{
	char name[24];
	int score;
};

void initializeArrays(highscore scores[], int size);
void sortData(highscore scores[], int size);
int indexOfLargest(const highscore scores[], int startingIndex, int size);
void displayData(const highscore scores[], int size);

int main()
{
	int arraySize;

	cout << "How many scores will you enter?: ";
	cin >> arraySize;

	highscore *scoreNamePair = new highscore[arraySize];

	initializeArrays(scoreNamePair, arraySize);
	sortData(scoreNamePair, arraySize);
	displayData(scoreNamePair, arraySize);
	delete[] scoreNamePair;
}






/*This function receives an array of highscore structs, scores, and an int, size.
Using a for loop (from 0 to size), it promts the user to input a name and a score (both of which
are members of the highscore struct), and stores the data with the scores[] array.*/
void initializeArrays(highscore scores[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i + 1 << " (up to 23 chars): ";
		cin >> scores[i].name;
		cout << "Enter the score for score #" << i + 1 << ": ";
		cin >> scores[i].score;
	}

	cout << endl;
}






/*This function receives an array of highscore structs, scores, and an int, size.
It works in conjunction with the indexOfLargest function to make a selection sort that
sorts the highscore structs into descending order based on their scores.*/
void sortData(highscore scores[], int size)
{
	for (int i = 0; i < size - 1; i++) 
		swap(scores[i], scores[indexOfLargest(scores, i, size)]);
}






/*This function receives an array of highscore structs, scores, and two ints, startIndex and size.
Using a for loop, it checks the score values of the highscore struct scores to determine what index
holds the largest score value. After looping through the entire highscore array, it returns an integer holding 
the index of the largest score value.*/
int indexOfLargest(const highscore scores[], int startIndex, int size)
{
	int targetIndex = startIndex;

	for (int count = startIndex + 1; count < size; count++) 
		if (scores[count].score > scores[targetIndex].score )
			targetIndex = count;

	return targetIndex;
}






/*This function receives an array of highscore structs, scores, and an int, size.
By using a for loop that runs through the indices of the highscore array
(from 0 to size), it prints names and scores stored within.*/
void displayData(const highscore scores[], int size)
{
	cout << "Top Scorers:" << endl;

	for (int i = 0; i < size; i++)
		cout << scores[i].name << ": " << scores[i].score << endl;
}

/* SAMPLE OUTPUT
How many scores will you enter?: 6
Enter the name for score #1 (up to 23 chars): meme
Enter the score for score #1: 0
Enter the name for score #2 (up to 23 chars): a
Enter the score for score #2: 61
Enter the name for score #3 (up to 23 chars): DAMN
Enter the score for score #3: 12342346
Enter the name for score #4 (up to 23 chars): is
Enter the score for score #4: 8885
Enter the name for score #5 (up to 23 chars): dead
Enter the score for score #5: 42
Enter the name for score #6 (up to 23 chars): DANIEL
Enter the score for score #6: 99999

Top Scorers:
DAMN: 12342346
DANIEL: 99999
is: 8885
a: 61
dead: 42
meme: 0
*/