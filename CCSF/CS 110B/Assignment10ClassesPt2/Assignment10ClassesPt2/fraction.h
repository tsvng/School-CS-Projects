/*
Student: William Tsang
Date: April 5, 2016
Class: CS 110B
Name of File: fraction.h, Assignment 10.1

The fraction class is used to represent a fraction by carrying two private data members (both int),
a numerator and a denominator, expressed as a ratio of numerator/denominator.


It has two constructors:

fraction()
The default constructor which assigns the default values of numerator and denominator to a fraction

fraction(int numerator, int denominator)
This constructor takes in two arguments and assigns their values to numerator and denominator respectively

The public member functions are:

print() displays the fraction
pre: numerator and denominator of the calling object have been assigned value
post: the fraction is displayed as "numerator/denominator"

isEqualTo() checks to see if two fractions are equal in value to each other
pre: both the calling object and the fraction argument assigned values in numerator and denominator
post: returns true if the two fractions are of equal value, otherwise it returns false

addedTo() adds the calling oject and the fraction argument together
pre: both the calling object and the fraction argument assigned values in numerator and denominator
post: returns a fraction that is equal to the sum of the calling object and the argument

subtract() subtracts the fraction argument from the calling object
pre: both the calling object and the fraction argument assigned values in numerator and denominator
post: returns a fraction that is equal to the difference between the calling object and the argument

multipliedBy() multiplies the calling object by the fraction argument
pre: both the calling object and the fraction argument assigned values in numerator and denominator
post: returns a fraction that is equal to the product of the calling object and the argument

dividedBy() divides the calling object by the fraction argument
pre: both the calling object and the fraction argument assigned values in numerator and denominator
post: returns a fraction that is equal to the quotient of the calling object divided by the argument

simplify() simplifies the calling object into its simplest form
pre: calling object has a numerator and denominator
post: returns the simplest form of the calling object
*/
#ifndef FRACTION_H
#define FRACTION_H

class fraction
{
	public:
		fraction();
		fraction(int numerator, int denominator);
		void print() const;
		bool isEqualTo(fraction compare) const;
		fraction addedTo(fraction addend) const;
		fraction subtract(fraction subtrahend) const;
		fraction multipliedBy(fraction factor) const;
		fraction dividedBy(fraction divisor) const;
		void simplify();

	private:
		int numerator;
		int denominator;
};

#endif
/*SAMPLE OUTPUT
The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.
The product of 3/2 and 2/3 is 1/1
*/