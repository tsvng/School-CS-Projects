/*
Student: William Tsang
Date: April 5, 2016
Class: CS 110B
Name of File: fraction.cpp, Assignment 10.1

The private members are: int numerator and int denominator, which come together to form a fraction.

These two ints are given a value by the constructors. 
The default constructor fraction() takes no arguments and assigns the default values of numerator 
and denominator to a fraction.
The other constructor fraction(int numerator, int denominator) takes in two arguments and assigns 
their values to the numerator and denominator of the fraction.

The 7 member functions also use the data members.
print() displays the numerator and denominator in a cout statement.
isEqualTo() utilize their values the see if the two fractions are equal.
The four arithmetic functions utilize them to find the sums, differences, products, and quotients
of the calling object the the member functions' argument (which is a fraction).
simplify() modifies the calling object's numerator and denominator and reduces them until
the fraction is in its simplest form.

Fraction objects will be returned and displayed in their simplest form.
*/
#include <iostream>
#include "fraction.h"
using namespace std;

fraction::fraction()
{
	numerator = 0;
	denominator = 1;
}






fraction::fraction(int inNum, int inDen)
{
	numerator = inNum;
	denominator = inDen;
}






void fraction::print() const
{
	fraction placeHolder;

	placeHolder.numerator = numerator;
	placeHolder.denominator = denominator;
	placeHolder.simplify();

	cout << placeHolder.numerator << "/" << placeHolder.denominator;
}






bool fraction::isEqualTo(fraction compare) const
{
	return (numerator * compare.denominator) == (denominator * compare.numerator);
}






fraction fraction::addedTo(fraction addend) const
{
	fraction sum;

	sum.numerator = (numerator * addend.denominator) + (addend.numerator * denominator);
	sum.denominator = (denominator * addend.denominator);
	sum.simplify();

	return sum;
}






fraction fraction::subtract(fraction subtrahend) const
{
	fraction difference;

	difference.numerator = (numerator * subtrahend.denominator) - (subtrahend.numerator * denominator);
	difference.denominator = (denominator * subtrahend.denominator);
	difference.simplify();

	return difference;
}






fraction fraction::multipliedBy(fraction factor) const
{
	fraction product;

	product.numerator = (numerator * factor.numerator);
	product.denominator = (denominator * factor.denominator);
	product.simplify();

	return product;
}






fraction fraction::dividedBy(fraction divisor) const
{
	fraction quotient;

	quotient.numerator = (numerator * divisor.denominator);
	quotient.denominator = (denominator * divisor.numerator);
	quotient.simplify();

	return quotient;
}






/*This function simplifies by checking for all possible common factors. 
When a common factor is found, both the numerator and denominator get
divided by it.*/
void fraction::simplify()
{
	int gcf;

	if (numerator < denominator)
		gcf = numerator;
	else
		gcf = denominator;

	for (gcf; gcf > 1; gcf--)
		if ((numerator % gcf == 0) && (denominator % gcf == 0))
		{
			numerator = numerator / gcf;
			denominator = denominator / gcf;
		}
}