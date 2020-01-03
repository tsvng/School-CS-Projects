/*
Student: William Tsang
Date: May 4, 2016
Class: CS 110B
Name of File: myString.h, Assignment 14.1

The myString class allows use to easily handle sequences of characters easier and more convienient
than it would be to handle a traditional c-string. Because myString utilizes a pointer data member
char* word, it uses dynamically allocated arrays to store the c-string thus the client can declare
and use myString without the worry of its size. The myString class can handle the construction of
strings, reading/printing, access characters in the string, extract characters into myString, a read
function that specifies the delimiter, and can concatenate with an overloaded + and += function.

myString();
post: calling object is created and initialized to an empty string

myString(const char *inWord);
pre: inWord points to a c-string
post: calling object is created and initialized to "inWord"

myString(const myString& right);
pre: right is a myString class address
post: calling object is created and initialized to "right"

~myString();
post: deallocates the memory that the calling object is pointing to

myString operator=(const myString& right);
pre: right is a myString class address
post: copies right's word into the calling object's word 

int length() const;
post: returns the number of characters in the string

friend ostream& operator<<(ostream& out, const myString& source);
pre: out is the outsteam, source is the myString calling object
post: returns out, calling object's word is printed on screen

friend istream& operator>>(istream& in, myString& target);
pre: in is the instream, target is the myString calling object
post: returns in, input is copied into the calling object's word

void read(istream& in, char delim);
pre: in is the instream, delim is the delimiting character of getline()
post: word is copied with a string that stops at the delimiting character

char operator[](int index) const;
pre: 0 <= index < length()
post: character at position "index" is returned

char& operator[](int index);
pre: 0 <= index < length()
post: character at position "index" is returned

friend bool operator<(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is less than right, else false

friend bool operator<=(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is less than or equal to right, else false

friend bool operator>(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is greater than right, else false

friend bool operator>=(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is greater than or equal to right, else false

friend bool operator==(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is equal to right, else false

friend bool operator!=(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: return true if ASCII value of left is not equal to right, else false

friend myString operator+(const myString &left, const myString &right);
pre: left and right are myStrings or c-strings
post: returns a myString with a word equal to the concatination of left and right's words

myString operator+=(const myString& right);
pre: left of += is a myString, right can be myString or c-string
post: returns a myString with a word equal to the concatenation of its own word and right's word
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
			friend istream& operator>>(istream& in, myString& target);
			void read(istream& in, char delim);
			char operator[](int index) const;
			char& operator[](int index);
			friend bool operator<(const myString &left, const myString &right);
			friend bool operator<=(const myString &left, const myString &right);
			friend bool operator>(const myString &left, const myString &right);
			friend bool operator>=(const myString &left, const myString &right);
			friend bool operator==(const myString &left, const myString &right);
			friend bool operator!=(const myString &left, const myString &right);
			friend myString operator+(const myString &left, const myString &right);
			myString operator+=(const myString& right);
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

----- Now reading myStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

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

----- Testing concatentation on myStrings
outrageous + milk = outrageousmilk
milk +  = milk
+ cow = cow
cow + bell = cowbell

----- Testing concatentation between myString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on myStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on myStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return myStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
*/