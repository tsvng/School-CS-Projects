#include <iostream>
#include <cctype>
#include <locale>
#include <cstring>
using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
int findSubstring(const char* inString, const char substring[]);
bool isPalindrome(const char* inString);
void toUpper(char* inString);
int numLetters(const char* inString);

int main()
{
	char testString[] = "Sally sold seashells by the seashore";
	char target = 's';
	char replacementChar = 'e';
	char testSubstring[] = "seashells";

	cout << target << " last appeared at the index " << lastIndexOf(testString, target) << endl;
	reverse(testString);
	cout << "The reverse of test is " << endl;
	cout << replace(testString, target, replacementChar) << endl;
	cout << testSubstring << " is found at the index " << findSubstring(testString, testSubstring) << endl;
	if (isPalindrome(testString))
	{
		cout << "This is a palindrome" << endl;
	}
	toUpper(testString);
	cout << "The string all capitalized is: " << endl;
	cout << "Letters in string: " << numLetters(testString) << endl;
}






/*
lastIndexOf searches though the cstring parameter,
inString for the character parameter,target and then
returns the index of where the character is located.
If the parameter target is not found, the function
will return 0.
*/
int lastIndexOf(const char* inString, char target)
{
	int counter = 0;
	int index = -1;

	while (inString[counter] != '\0')
	{
		if (inString[counter] == target)
		{
			index = counter;
			counter++;
		}
	}
	return index;
}






/*
The function reverse takes the cstring parameter, inString
and reverses all the values so that everything is backwards.
The first value will become the last one,etc.
*/
void reverse(char* inString)
{
	for (int counter = 0; counter < (strlen(inString) / 2); counter++)
	{
		swap(inString[counter], inString[strlen(inString) - (counter + 1)]);
	}
}






/*
The function replace, replaces the character parameter, target with
the new character paramenter, replacementChar in the cstring inString.
If nothing is replace, the function will return 0.
*/
int replace(char* inString, char target, char replacementChar)
{
	int amount = 0;

	for (int counter = 0; inString[counter] != '\0'; counter++)
	{
		if (inString[counter] == target)
		{
			inString[counter] = replacementChar;
			amount++;
		}
	}
	return amount;
}






/*
The function, findSubstring searches inside the parameter inString for
the parameter substring. If substring is found, the function will return
the value 2. It will return -1 if it is not found.
*/
int findSubstring(const char* inString, const char substring[])
{
	int same = 0;
	
	for (int counter = 0; inString[counter] != '\0'; counter++)
	{
		if (inString[counter] == substring[0])
		{
			for (int counter2 = 1; counter2 < strlen(substring); counter2++)
			{
				if (inString[counter + counter2] == substring[counter2])
				{
					same++;
					if (same == strlen(substring) - 1)
					{
						return counter;
					}
				}
			}
		}
	}
	return -1;
}






/*
This function, isPalindrome takes the parameter, inString and
sees if it is a parameter.It compares the first value and the
last value, then the second value and the the secondto last
value and so on. It only needs to do it for half the cstring
if it is a palindrom.
*/
bool isPalindrome(const char* inString)
{
	int matches = 0;

	for (int counter = 0; counter < (strlen(inString) / 2); counter++)
	{
		if (inString[counter] == inString[strlen(inString) - counter - 1])
		{
			matches++;
		}
	}
	return matches == (strlen(inString) / 2);
}






/*
The function toupper changes everything from the cstring
parameter, inString to uppercase.
*/
void toUpper(char* inString)
{
	int counter = 0;

	while (inString[counter] != '\0')
	{
		inString[counter] = char(toupper(inString[counter]));
		counter++;
	}
}






/*
The function numLetters goes through the cstring
paramenter, inString and returns the amount of letters
that are in the parameter.
*/
int numLetters(const char* inString)
{
	int amountLetters = 0;

	for (int counter = 0; inString[counter] != '\0'; counter++)
	{
		if (isalpha(inString[counter]))
		{
			amountLetters++;
		}
	}
	return amountLetters;
}
