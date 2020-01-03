/*
Student: William Tsang
Date: April 13, 2016
Class: CS 110B
Name of File: fraction.cpp, Assignment 11.1
*/
#include <iostream>
#include <string>
#include <cassert>
#include "fraction.h"

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