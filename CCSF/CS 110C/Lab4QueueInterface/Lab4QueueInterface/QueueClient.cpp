/*
@file: QueueClient.cpp, Lab Assignment 4, CS 110C
This program is used to utilize the QueueInterface ADT by enqueuing and dequeuing the footnotes
within a given input textfile, then outputting a better-formatted output textfile.
@author: William Tsang
@date: November 15, 2016
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "ArrayQueue.h"

int main()
{
	ArrayQueue<string> footnoteQueue;

	string footnote;
	char output;
	char footnoteChar;
	int numFootnotes = 0;
	int counter = 1;
	bool withinFootnote = false;

	ifstream myFile("sampleInput.txt");
	ofstream outputFile("sampleOutput.txt");

	if (!myFile.is_open())
	{
		cout << "Cannot open the file";
		return -1;
	}
	if (!outputFile.is_open())
	{
		cout << "Cannot open the file";
		return -1;
	}

	if (myFile.is_open() && outputFile.is_open())
	{
		while (myFile >> noskipws >> output)
		{
			if (output == '{')
				withinFootnote = true;

			if (withinFootnote)
			{
				if (output != '{' && output != '}')
					footnote += output;
				if (output == '}')
				{
					footnoteQueue.enqueue(footnote);
					footnote.clear();
					numFootnotes++;
					outputFile << "(" << numFootnotes << ")";
					withinFootnote = false;
				}
			}
			else
				outputFile << output;
		}

		outputFile << endl << "Endnotes:" << endl << endl; //Footnote output
		while (!footnoteQueue.isEmpty())
		{
			outputFile << counter << ") " << footnoteQueue.peekFront() << endl << endl;
			footnoteQueue.dequeue();
			counter++;
		}

		myFile.close();
		outputFile.close();
	}
}