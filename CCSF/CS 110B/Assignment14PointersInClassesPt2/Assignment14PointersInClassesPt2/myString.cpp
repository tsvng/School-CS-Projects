/*
Student: William Tsang
Date: May 4, 2016
Class: CS 110B
Name of File: myString.cpp, Assignment 14.1

There is one private data member, char* word which points to a c-string. It's used in the myString class
as a more convienient way to handle raw c-strings.

word always represents a valid null-terminated c-string.
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






	istream& operator>>(istream& in, myString& target)
	{
		while (isspace(in.peek())) 
			in.ignore();
		
		char temp[128];
		in.getline(temp, 127, ' ');
		delete[] target.word;
		target.word = new char[strlen(temp) + 1];
		strcpy(target.word, temp);
		
		return in;
	}






	void myString::read(istream& in, char delim)
	{
		char temp[128];
		in.getline(temp, 127, delim);
		delete[] word;
		word = new char[strlen(temp) + 1];
		strcpy(word, temp);
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






	myString operator+(const myString &left, const myString &right)
	{
		myString concatenated;

		delete[] concatenated.word;
		concatenated.word = new char[strlen(left.word) + strlen(right.word) + 1];
		strcpy(concatenated.word, left.word);
		strcat(concatenated.word, right.word);

		return concatenated;
	}






	myString myString::operator+=(const myString& right)
	{
		*this = *this + right;
		return *this;
	}

}