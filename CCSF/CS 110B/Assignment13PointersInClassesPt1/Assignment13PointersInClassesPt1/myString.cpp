/*
Student: William Tsang
Date: April 27, 2016
Class: CS 110B
Name of File: myString.cpp, Assignment 13.1
*/
#include <iostream>
#include "mystring.h"
#include <cassert>
#include <cstring>
#pragma warning( disable : 4996 18) //ignoring Visual Studio's strcpy_s() error + unsigned/signed error

using namespace std;

namespace cs_mystring
{
	myString::myString()
	{
		word = new char[1];
		strcpy(word, "");
	}






	myString::myString(const char *inWord)
	{
		word = new char[strlen(inWord) + 1];
		strcpy(word, inWord);
	}






	myString::myString(const myString& right)
	{
		word = new char[strlen(right.word) + 1];
		strcpy(word, right.word);
	}






	myString::~myString()
	{
		delete[] word;
	}






	myString myString::operator=(const myString& right)
	{
		if (this != &right)
		{
			delete[] word;
			word = new char[strlen(right.word) + 1];
			strcpy(word, right.word);
		}

		return *this;
	}






	int myString::length() const
	{
		return strlen(word);
	}






	ostream& operator<<(ostream& out, const myString& source)
	{
		out << source.word;
		return out;
	}






	char myString::operator[](int index) const
	{
		assert(index >= 0 && index < strlen(word));
		return word[index];
	}






	char& myString::operator[](int index)
	{
		assert(index >= 0 && index < strlen(word));
		return word[index];
	}






	bool operator<(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) < 0);
	}






	bool operator<=(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) <= 0);
	}






	bool operator>(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) > 0);
	}






	bool operator>=(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) >= 0);
	}






	bool operator==(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) == 0);
	}






	bool operator!=(const myString &left, const myString &right)
	{
		return (strcmp(left.word, right.word) != 0);
	}
}