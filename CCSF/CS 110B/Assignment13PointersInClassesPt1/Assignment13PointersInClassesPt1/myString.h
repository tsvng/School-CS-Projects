/*
Student: William Tsang
Date: April 27, 2016
Class: CS 110B
Name of File: myString.h, Assignment 13.1
*/
#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

namespace cs_mystring 
{
	class myString
	{
		public:
			myString();
			myString(const char *inWord);
			myString(const myString& right);
			~myString();
			myString operator=(const myString& right);
			int length() const;
			friend ostream& operator<<(ostream& out, const myString& source);
			char operator[](int index) const;
			char& operator[](int index);
			friend bool operator<(const myString &left, const myString &right);
			friend bool operator<=(const myString &left, const myString &right);
			friend bool operator>(const myString &left, const myString &right);
			friend bool operator>=(const myString &left, const myString &right);
			friend bool operator==(const myString &left, const myString &right);
			friend bool operator!=(const myString &left, const myString &right);
		private:
			char *word;
	};
}

#endif
/*SAMPLE OUTPUT
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between myStrings
Comparing app to apple
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing apple to
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing  to Banana
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing Banana to Banana
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between myStrings and char *
Comparing he to hello
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing why to wackity
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true

----- Testing copy constructor and operator= on myStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return myStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
*/