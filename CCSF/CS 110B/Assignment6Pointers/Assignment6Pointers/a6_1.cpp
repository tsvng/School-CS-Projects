/*
Student: William Tsang
Date: February 23, 2016
Class: CS 110B
Name of File: a6_1.cpp, Assignment 6.1
This program is simply following the instructions outlined on the Assignment 6 page in which
we must code a sequence of loosely-related tasks to practice using pointers.
*/

#include <iostream>
using namespace std;

void noNegatives(int *x);
void swap(int *num1, int *num2);



int main()
{
	//Tasks 1-8
	int x, y, *p1; 

	p1 = &x; 
	*p1 = 99;

	cout << x << endl; 
	cout << *p1 << endl;

	p1 = &y;
	*p1 = -300;

	//Task 9-13
	int temp, *p2; 

	p2 = &x;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	noNegatives(&x); 
	noNegatives(&y);

	cout << "x is: " << *p2 << endl; 
	p2 = p1;
	cout << "y is: " << *p2 << endl;

	//Task 14-20
	int a[2]; 

	p2 = &a[0];
	p2[0] = x; 
	p2[1] = y;

	cout << "The address of a[0] is: " << &a[0] << endl;
	cout << "The address of a[1] is: " << &a[1] << endl;

	p1 = &a[0];
	p2 = &a[1];

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	cout << a[0] << ", " << a[1] << endl;

	//Task 22
	swap(&x, &y); 
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;

	//Task 23
	swap(&a[0], &a[1]); 
	cout << "a[0] is: " << a[0] << endl;
	cout << "a[1] is: " << a[1] << endl;
}






/* This function receives a pointer to an integer, *x. If the value of the integer it is
pointing to is negative then it will set it to a value of zero.*/
void noNegatives(int *x)
{
	if (*x < 0)
		*x = 0;
}






/* This function receives two pointers to two integers as arguements, *num1 and *num2.
By using int temp to store *num1's value, the values of *num1 and *num2 are able to be 
swapped.*/
void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/* SAMPLE OUTPUT
99
99
x is: 0
y is: 99
The address of a[0] is: 0018FBE0
The address of a[1] is: 0018FBE4
99, 0
x is: 99
y is: 0
a[0] is: 0
a[1] is: 99
*/