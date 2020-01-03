/*
Student: William Tsang
Date: March 22, 2016
Class: CS 110B
Name of File: a9_1.cpp, Assignment 9.1
This program is an introduction to classes and object oriented programing in C++.
As an intro, we create a fraction class that has 7 member functions and practice 
initializing them properly using class scope and ::, the scope resolution operator. 
In the member function's definitions we also utilize the fraction class' data members
numerator and denominator extensively to write out all our functions. Finally, the 
7 public member functions get tested by the client program provided in the assignemnt,
as seen in the main() fucntion.
*/
#include <iostream>
using namespace std;

/*
Header File:
The fraction class essentially acts like a fraction by carrying two private data members (both int),
a numerator and a denominator. Fractions are not reduced to their simplest form.

The public member functions are:

set() takes two ints, a numerator and a denominator, and sets them for the calling object
pre: numerator and denominator are ints
post: The calling object's numerator and denominator are set to the two values respectively

print() displays the fraction
pre: numerator and denominator of the calling object have been assigned value (have been set)
post: the fraction is displayed as "numerator/denominator"

isEqualTo() checks to see if two fractions are equal in value to each other
pre: both the calling object and the fraction argument have been set
post: returns true if the two fractions are of equal value, otherwise it returns false

addedTo() adds the calling oject and the fraction argument together
pre: both the calling object and the fraction argument have been set
post: returns a fraction that is equal to the sum of the calling object and the argument

subtract() subtracts the fraction argument from the calling object
pre: both the calling object and the fraction argument have been set
post: returns a fraction that is equal to the difference between the calling object and the argument

multipliedBy() multiplies the calling object by the fraction argument
pre: both the calling object and the fraction argument have been set
post: returns a fraction that is equal to the product of the calling object and the argument

dividedBy() divides the calling object by the fraction argument
pre: both the calling object and the fraction argument have been set
post: returns a fraction that is equal to the quotient of the calling object divided by the argument

Implementation File:
The private members are: int numerator and int denominator, which come together to form a fraction. 

These two are given a value by the set() function which takes in two arguments and assigns their 
values to numerator and denominator respectively.
The other 6 member functions use these data members too.
print() displays the numerator and denominator in a cout statement.
isEqualTo() utilize their values the see if the two fractions are equal.
The four arithmetic functions utilize them to find the sums, differences, products, and quotients
of the calling object the the member functions' argument (which is a fraction).

Fraction objects will always be stored as they are set, in their purest form and left unsimplified.
*/
class fraction
{
	public:
		void set(int numerator, int denominator);
		void print();
		bool isEqualTo(fraction compare);
		fraction addedTo(fraction addend);
		fraction subtract(fraction subtrahend);
		fraction multipliedBy(fraction factor);
		fraction dividedBy(fraction divisor);

	private:
		int numerator;
		int denominator;
};






/*This function takes two int arguments, and using them, sets the values of the calling
object's numerator and denominator.

pre: numerator and denominator are ints
*/
void fraction::set(int inNum, int inDen)
{
	numerator = inNum;
	denominator = inDen;
}






/*This function prints out the calling object's numerator and denominator 
in such a way that it looks like a fraction. 

pre: numerator and denominator of the calling object have been assigned value (have been set)
*/
void fraction::print()
{
	cout << numerator << "/" << denominator;
}






/*This function takes in a fraction as an arguement, 
returns a boolean that holds whether or not the calling object and the argument
are equal to one another. 

pre: both the calling object and the fraction argument have been set
*/
bool fraction::isEqualTo(fraction compare)
{
	return (numerator * compare.denominator) == (denominator * compare.numerator);
}






/*This function takes in a fraction as an arguement,
returns a fraction equal to the sum of the calling object and the argument.

pre: both the calling object and the fraction argument have been set
*/
fraction fraction::addedTo(fraction addend)
{
	fraction sum;

	sum.numerator = (numerator * addend.denominator) + (addend.numerator * denominator);
	sum.denominator = (denominator * addend.denominator);
	
	return sum;
}






/*This function takes in a fraction as an arguement,
returns a fraction equal to the difference between the calling object and the argument.

pre: both the calling object and the fraction argument have been set
*/
fraction fraction::subtract(fraction subtrahend)
{
	fraction difference;

	difference.numerator = (numerator * subtrahend.denominator) - (subtrahend.numerator * denominator);
	difference.denominator = (denominator * subtrahend.denominator);

	return difference;
}






/*This function takes in a fraction as an arguement,
returns a fraction equal to the product of the calling object and the argument.

pre: both the calling object and the fraction argument have been set
*/
fraction fraction::multipliedBy(fraction factor)
{
	fraction product;

	product.numerator = (numerator * factor.numerator);
	product.denominator = (denominator * factor.denominator);

	return product;
}






/*This function takes in a fraction as an arguement,
returns a fraction equal to the quotient of the calling object divided by the argument.

pre: both the calling object and the fraction argument have been set
*/
fraction fraction::dividedBy(fraction divisor)
{
	fraction quotient;

	quotient.numerator = (numerator * divisor.denominator);
	quotient.denominator = (denominator * divisor.numerator);

	return quotient;
}






int main()
{
	fraction f1;
	fraction f2;
	fraction result;

	f1.set(9, 8);
	f2.set(2, 3);

	cout << "The product of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.multipliedBy(f2);
	result.print();
	cout << endl;

	cout << "The quotient of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.dividedBy(f2);
	result.print();
	cout << endl;

	cout << "The sum of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.addedTo(f2);
	result.print();
	cout << endl;

	cout << "The difference of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.subtract(f2);
	result.print();
	cout << endl;

	if (f1.isEqualTo(f2)) {
		cout << "The two fractions are equal." << endl;
	}
	else {
		cout << "The two fractions are not equal." << endl;
	}
}

/*SAMPLE OUTPUT
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.
*/