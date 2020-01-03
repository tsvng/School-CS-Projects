/*
Student: William Tsang
Date: April 20, 2016
Class: CS 110B
Name of File: fraction.cpp, Assignment 12.1

The private members are: int numerator and int denominator, which come together to form a fraction.
These two ints are given a value by the constructor.
The private members are utilized by 20 different public member functions: 2 use them for output/input
6 use them for comparing values, and 12 use them for basic arithmetic.

They're also used in the private member function, simplify(), which modifies the calling object's 
numerator and denominator and reduces them until the fraction is in its simplest form.

Fraction objects will be returned, stored, and displayed in their simplest form. A fraction's 
denominator will never be negative.
*/
#include <iostream>
#include "fraction.h"
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

namespace cs_fraction
{
	fraction::fraction(int inNum, int inDen)
	{
		assert(inDen != 0);
		numerator = inNum;
		denominator = inDen;
		simplify();
	}






	/*pre: out is outstream, printMe is the fraction calling object
	post: returns out, calling object is printed in a mixed number form if improper
	The overloaded operator returns the calling object (fraction right of << operator)
	in mixed numer form if applicable, else it's just a proper fraction. It first checks
	if denominator is 1 or if the numerator is 0, if that is true it just returns the
	numerator. Then checks if the absolute value of the calling object's numerator
	is less than the denominator. If this is true then this is not an improper fraction,
	thus returns a plain fraction. If neither condition holds, it returns a mixed number.*/
	ostream& operator<<(ostream& out, const fraction &right)
	{

		if (right.denominator == 1 || right.numerator == 0)
		{
			out << right.numerator;
			return out;
		}
		else if (abs(right.numerator) < right.denominator)
		{
			out << right.numerator << "/" << right.denominator;
			return out;
		}
		else
		{
			out << right.numerator / right.denominator << "+" << abs(right.numerator % right.denominator);
			out << "/" << right.denominator;
			return out;
		}
	}






	/*pre: in is instream, right is the fraction calling object
	post: returns in, input is saved into the calling object in a simplified form
	This overloaded operator reads through a given data file and stores the values
	of the fractions into the calling object (right of the >> operator).*/
	istream& operator>>(std::istream& in, fraction &right)
	{
		
		char fwdSlash;
		int temp;
		in >> temp;

		if (in.peek() == '+') 
		{
			in >> right.numerator >> fwdSlash >> right.denominator;

			if (temp < 0) 
				right.numerator = -(abs(temp * right.denominator) + right.numerator);
			else 
				right.numerator = (temp * right.denominator) + right.numerator;
			
			right.simplify();
			return in;
		}

		else if (in.peek() == '/') 
		{
			right.numerator = temp;
			in >> fwdSlash >> right.denominator;

			right.simplify();
			return in;
		}

		else 
			right = temp;
		
		return in;
	}





	bool operator<(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) < (right.numerator * left.denominator);
	}






	bool operator<=(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) <= (right.numerator * left.denominator);
	}






	bool operator>(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) > (right.numerator * left.denominator);
	}






	bool operator>=(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) >= (right.numerator * left.denominator);
	}






	bool operator==(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) == (right.numerator * left.denominator);
	}






	bool operator!=(const fraction &left, const fraction &right)
	{
		return (left.numerator * right.denominator) != (right.numerator * left.denominator);
	}






	fraction operator+(const fraction &left, const fraction &right)
	{
		fraction sum;

		sum.numerator = (left.numerator * right.denominator) + (right.numerator * left.denominator);
		sum.denominator = (left.denominator * right.denominator);
		sum.simplify();

		return sum;
	}






	fraction operator-(const fraction &left, const fraction &right)
	{
		fraction difference;

		difference.numerator = (left.numerator * right.denominator) - (right.numerator * left.denominator);
		difference.denominator = (left.denominator * right.denominator);
		difference.simplify();

		return difference;
	}






	fraction operator*(const fraction &left, const fraction &right)
	{
		fraction product;

		product.numerator = (left.numerator * right.numerator);
		product.denominator = (left.denominator * right.denominator);
		product.simplify();

		return product;
	}






	fraction operator/(const fraction &left, const fraction &right)
	{
		fraction quotient;

		quotient.numerator = (left.numerator * right.denominator);
		quotient.denominator = (left.denominator * right.numerator);
		quotient.simplify();

		return quotient;
	}






	fraction fraction::operator+=(const fraction &right)
	{
		*this = *this + right;
		return *this;
	}






	fraction fraction::operator-=(const fraction &right)
	{
		*this = *this - right;
		return *this;
	}






	fraction fraction::operator*=(const fraction &right)
	{
		*this = *this * right;
		return *this;
	}






	fraction fraction::operator/=(const fraction &right)
	{
		*this = *this / right;
		return *this;
	}






	fraction fraction::operator++()
	{
		numerator = numerator + denominator;
		return *this;
	}






	fraction fraction::operator--()
	{
		numerator = numerator - denominator;
		return *this;
	}






	fraction fraction::operator++(int)
	{
		fraction temp(numerator, denominator);
		numerator = numerator + denominator;
		return temp;
	}






	fraction fraction::operator--(int)
	{
		fraction temp(numerator, denominator);
		numerator = numerator - denominator;
		return temp;
	}






	/*post: simplifies the fraction calling object, the denominator is never negative
	The function checks to see if the calling object has a negative denominator, if it does it moves
	the negative to the numerator instead.
	It simplifies by looping through ALL possible greatest common factors between the numerator
	and denominator. When a gcf is found, divide both numerator and denominator by that value.*/
	void fraction::simplify()
	{
		if (denominator < 0)
		{
			denominator *= -1;
			numerator *= -1;
		}

		for (int gcf = denominator; gcf > 1; gcf--)
			if ((abs(numerator) % gcf == 0) && (denominator % gcf == 0))
			{
				numerator = numerator / gcf;
				denominator = denominator / gcf;
			}
	}
}