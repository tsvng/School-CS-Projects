/*
Student: William Tsang
Date: April 13, 2016
Class: CS 110B
Name of File: fraction.h, Assignment 11.1
*/
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

namespace cs_fraction
{
	class fraction
	{
		public:
			fraction(int numerator = 0, int denominator = 1);
			friend std::ostream& operator<<(std::ostream& out, const fraction &printMe);
			//relational
			friend bool operator<(const fraction &left, const fraction &right);
			friend bool operator<=(const fraction &left, const fraction &right);
			friend bool operator>(const fraction &left, const fraction &right);
			friend bool operator>=(const fraction &left, const fraction &right);
			friend bool operator==(const fraction &left, const fraction &right);
			friend bool operator!=(const fraction &left, const fraction &right);
			//basic arithmetic
			friend fraction operator+(const fraction &left, const fraction &right);
			friend fraction operator-(const fraction &left, const fraction &right);
			friend fraction operator*(const fraction &left, const fraction &right);
			friend fraction operator/(const fraction &left, const fraction &right);
			//shorthand
			fraction operator+=(const fraction &right);
			fraction operator-=(const fraction &right);
			fraction operator*=(const fraction &right);
			fraction operator/=(const fraction &right);
			fraction operator++();
			fraction operator--();
			fraction operator++(int);
			fraction operator--(int);

		private:
			int numerator;
			int denominator;
			void simplify();
	};
}


#endif
