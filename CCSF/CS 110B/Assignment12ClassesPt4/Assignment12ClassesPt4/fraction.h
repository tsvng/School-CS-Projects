/*
Student: William Tsang
Date: April 20, 2016
Class: CS 110B
Name of File: fraction.h, Assignment 12.1

The fraction class is used to represent a fraction by carrying two private data members (both int),
a numerator and a denominator, expressed as a ratio of numerator/denominator.

fraction(int numerator = 0, int denominator = 1);
	post:calling object with no arguments is assigned value of 0
	calling object with one argument is assigned a numerator of that value and denominator of 1
	calling object with two arguments is has numerator and denominator assigned those values respectively

friend std::ostream& operator<<(std::ostream& out, const fraction &printMe);
	pre: out is outstream, printMe is the fraction calling object
	post: returns out, calling object is printed in a mixed number form if improper

friend std::istream& operator>>(std::istream& in, fraction &input);
	pre: in is instream, right is the fraction calling object
	post: returns in, input is saved into the calling object in a simplified form

friend bool operator<(const fraction &left, const fraction &right);
	pre:left and right of < are fractions or ints
	post: returns true if left fraction is less than right, else returns false

friend bool operator<=(const fraction &left, const fraction &right);
	pre:left and right of <= are fractions or ints
	post: returns true if left fraction is less than or equal to right, else returns false

friend bool operator>(const fraction &left, const fraction &right);
	pre:left and right of > are fractions or ints
	post: returns true if left fraction is greater than right, else returns false

friend bool operator>=(const fraction &left, const fraction &right);
	pre:left and right of >= are fractions or ints
	post: returns true if left fraction is geater than or equal to right, else returns false

friend bool operator==(const fraction &left, const fraction &right);
	pre:left and right of == are fractions or ints
	post: returns true if left fraction is equal to right, else returns false

friend bool operator!=(const fraction &left, const fraction &right);
	pre:left and right of != are fractions or ints
	post: returns true if left fraction not equal to right, else returns false

friend fraction operator+(const fraction &left, const fraction &right);
	pre: left and right of + are fractions or ints
	post: returns the simplified sum of two fractions (or ints, or fraction + int)

friend fraction operator-(const fraction &left, const fraction &right);
	pre: left and right of - are fractions or ints
	post: returns the simplified difference of two fractions (or ints, or fraction - int)

friend fraction operator*(const fraction &left, const fraction &right);
	pre: left and right of * are fractions or ints
	post: returns the simplified product of two fractions (or ints, or fraction*int)

friend fraction operator/(const fraction &left, const fraction &right);
	pre: left and right of / are fractions or ints
	post: returns the simplified quotient of two fractions (or ints, or fraction/int)

fraction operator+=(const fraction &right);
	pre: left of += is a fraction, right can be fraction or int
	post: returns the simplified sum of the left and right fractions

fraction operator-=(const fraction &right);
	pre: left of -= is a fraction, right can be fraction or int
	post: returns the simplified difference of the left and right fractions

fraction operator*=(const fraction &right);
	pre: left of *= is a fraction, right can be fraction or int
	post: returns the simplified product of the left and right fractions

fraction operator/=(const fraction &right);
	pre: left of /= is a fraction, right can be fraction or int
	post: returns the simplified quotient of the left and right fractions

fraction operator++();
	post: returns calling object incremented by 1

fraction operator--();
	post: returns calling object decremented by 1

fraction operator++(int);
	pre: there's an fraction to the right of the operator
	post: returns the calling object, increment the calling object by 1

fraction operator--(int);
	pre: there's an fraction to the right of the operator
	post: returns the calling object, decrements the calling object by 1
*/
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

namespace cs_fraction
{
	class fraction
	{
		public:
			fraction(int numerator = 0, int denominator = 1);
			friend std::ostream& operator<<(std::ostream& out, const fraction &printMe);
			friend std::istream& operator>>(std::istream& in, fraction &input);
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
/*SAMPLE OUTPUT

----- Testing basic fraction creation & printing
(fractions should be in reduced form, and as mixed numbers.)
fraction [0] = 1/2
fraction [1] = -5/7
fraction [2] = 10
fraction [3] = -4
fraction [4] = 0
fraction [5] = 4+2/3
fraction [6] = 0

----- Now reading fractions from file
Read fraction = 1/3
Read fraction = 1/2
Read fraction = 3/4
Read fraction = -4/5
Read fraction = 6
Read fraction = 5
Read fraction = -8
Read fraction = 1+2/5
Read fraction = -16+2/3
Read fraction = 1+1/4
Read fraction = 2
Read fraction = -4+1/4
Read fraction = -10+5/6

----- Testing relational operators between fractions
Comparing 1/2 to 1/2
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false
Comparing 1/2 to -1/2
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing -1/2 to 1/10
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing 1/10 to 0
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing 0 to 0
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between fractions and integers
Comparing -1/2 to 2
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing -3 to 1/4
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true

----- Testing binary arithmetic between fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
*/