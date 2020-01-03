/*
Student: William Tsang
Date: March 7, 2016
Class: CS 110B
Name of File: a7_1.cpp, Assignment 7.1
This program is a compilation of seven functions we were instructed to make to which play around with C-Strings. 
In the main function, we are testing out the functions in order to demonstrate that they work as intended.

A brief description of what these 7 functions do:
1. lastIndexOf: returns the index of the last time the specified char was found, -1 if not found.
2. reverse: reverses a string.
3. replace: replaces a specified character with another, returns the number of replacements made.
4. findSubstring: returns the starting index of the specified substring, -1 if not found.
5. isPalindrome: checks if a string is a palindrome, (includes spaces and punctuation).
6. toUpper: capitalizes a string.
7. numLetters: returns the number of letters in a string. ex. numLetters("1234five") returns 4 (five has 4 letters).
*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char *inString); 
int replace(char* inString, char target, char replacementChar);
int findSubstring(const char* inString, const char substring[]);
bool isPalindrome(const char* inString);
void toUpper(char* inString);
int numLetters(const char* inString);
void tester(char* inString, char target, char replacementChar, char substring[]);

int main()
{
	//Test 1
	char testString[] = "How much wood could a woodchuck chuck if a woodchuck could chuck wood? Maybe 981 planks.";
	char testSubstring[] = "chuck if";
	char target = 'o';
	char replacementChar = 'e';

	tester(testString, target, replacementChar, testSubstring); 

	//2
	strcpy(testString, "amanaplanacanalpanama");
	strcpy(testSubstring, "stars");
	target = 'a';
	replacementChar = 'i';

	tester(testString, target, replacementChar, testSubstring);

	//3
	strcpy(testString, "They all had the runs");
	strcpy(testSubstring, "ad");
	target = 'r';
	replacementChar = 'g';

	tester(testString, target, replacementChar, testSubstring);

	//4
	strcpy(testString, "The quick brown fox jumps over the lazy dog");
	strcpy(testSubstring, "ump");
	target = 'i';
	replacementChar = 'a';

	tester(testString, target, replacementChar, testSubstring);

	//5
	strcpy(testString, "Star comeD yby Democ ratS");
	strcpy(testSubstring, "emo");
	target = 'c';
	replacementChar = 'n';
	
	tester(testString, target, replacementChar, testSubstring);
}






/*This function takes in a c-string and a char, inString and target respectively. It scans through the c-string
searching for the index of target. It returns the index of target's last appearance in the c-string.
If target never appears in the c-string it returns -1.*/
int lastIndexOf(const char* inString, char target)
{
	int i = 0;
	int lastIndex = -1;

	while (inString[i] != '\0')
	{
		if (inString[i] == target)
			lastIndex = i;

		i++;
	}

	return lastIndex;
}






/*This function takes in a c-string, inString, and reverses it using a for loop and a swap function.*/
void reverse(char *inString)
{
	for (int i = 0; i < (strlen(inString)/ 2); i++)
			swap(inString[i], inString[strlen(inString) - 1 - i]);	
}






/*This function takes in a c-string and two chars, inString, target, and replacementChar respectively.
It scanes through the c-string looking for target. If it finds target, it replaces target with
replacementChar. After scanning through the entire c-string it returns the number of replacements made.*/
int replace(char* inString, char target, char replacementChar)
{
	int i = 0;
	int numReplaced = 0;

	while (inString[i] != '\0')
	{
		if (inString[i] == target)
		{
			inString[i] = replacementChar;
			numReplaced++;
		}
			
		i++;
	}
	
	return numReplaced;
}






/*This function takes in two c-strings, inString and substring. It scans through the c-string searching for the
substring within it. It returns the starting index of the substring within inString. If the substring isn't found
it returns -1.*/
int findSubstring(const char* inString, const char substring[])
{
	int i = 0;
	int matches = 0;

	while (inString[i] != '\0')
	{
		if (inString[i] == substring[0]) //If the start of the substring is found
		{
			for (int j = 1; j < strlen(substring); j++) //Check to see if the rest of the substring follows
			{
				if (inString[i + j] == substring[j])	//For every subsequent match of inString and substring
				{										//matches++;
					matches++;							
					if (matches == strlen(substring) - 1) //If the rest of the substring is found, return the
						return i;						  //starting index of the substring (i).
				}
			}		
		}
			
		i++;
	}

	return -1;
}






/*This function takes in a c-string, inString, and checks if it's a palindrome. This is done by comparing the first
char to the last char, second char to the second last char, and so on until it has checked each index within the c-string.
Each time the two characters match, countMatches increases by 1. If countMatches is equal to half the length of inString
then it is a palindrome. Therefore it returns countMatches == (strlen(inString) / 2), which is true if inString is a palindrome,
and false if inString isn't.*/
bool isPalindrome(const char* inString)
{
	int countMatches = 0;

	for (int i = 0; i < (strlen(inString) / 2); i++)
		if (inString[i] == inString[strlen(inString) - 1 - i])
			countMatches++;

	return countMatches == (strlen(inString) / 2);
}






/*This function takes in a c-string, inString, and capitalizes it using the toupper() function in the <cctype> library.*/
void toUpper(char* inString)
{
	int i = 0;
	
	while (inString[i] != '\0')
	{
		inString[i] = char(toupper(inString[i]));
		i++;
	}
}






/*This function takes in a c-string, inString, and counts how many letters are within it by using the isalpha()
with in <cctype> library.*/
int numLetters(const char* inString)
{
	int i = 0;
	int count = 0;

	while (inString[i] != '\0')
	{
		if (isalpha(inString[i]))
			count++;

		i++;
	}

	return count;
}






/*This function takes in two c-strings and two chars. testString, testSubstring, target, and replamentChar
respectively. It may look complicated but if you look closely you'll see that it simply uses cout to show that 
the 7 functions above work properly.*/
void tester(char* testString, char target, char replacementChar, char testSubstring[])
{
	cout << "\"" <<testString << "\" has " << numLetters(testString) << " letters" << endl; //numLetters

	if (isPalindrome(testString)) //isPalindrome
		cout << "The string is a palindrome!" << endl;
	else
		cout << "The string isn't a palindrome. :(" << endl;

	cout << "The last index of the targetted char \'" << target << "\' is: " << lastIndexOf(testString, target) << endl; //lastIndexOf
	cout << "The substring \"" << testSubstring << "\" is found at index: " << findSubstring(testString, testSubstring) << endl; //findSubstring
	cout << replace(testString, target, replacementChar) << " replacement(s) of \'" << target << "\' to \'" << replacementChar << "\' occured." << endl; //replace
	cout << "The new string is: " << testString << endl;

	reverse(testString); //reverse
	cout << "The string reversed is: " << testString << endl;
	reverse(testString);

	toUpper(testString); // toUpper
	cout << "The string capitalized is: " << testString << endl << endl;
}
/* SAMPLE OUTPUT
"How much wood could a woodchuck chuck if a woodchuck could chuck wood? Maybe 981 planks." has 68 letters
The string isn't a palindrome. :(
The last index of the targetted char 'o' is: 67
The substring "chuck if" is found at index: 26
11 replacement(s) of 'o' to 'e' occured.
The new string is: Hew much weed ceuld a weedchuck chuck if a weedchuck ceuld chuck weed? Maybe 981 planks.
The string reversed is: .sknalp 189 ebyaM ?deew kcuhc dluec kcuhcdeew a fi kcuhc kcuhcdeew a dluec deew hcum weH
The string capitalized is: HEW MUCH WEED CEULD A WEEDCHUCK CHUCK IF A WEEDCHUCK CEULD CHUCK WEED? MAYBE 981 PLANKS.

"amanaplanacanalpanama" has 21 letters
The string is a palindrome!
The last index of the targetted char 'a' is: 20
The substring "stars" is found at index: -1
10 replacement(s) of 'a' to 'i' occured.
The new string is: iminiplinicinilpinimi
The string reversed is: iminiplinicinilpinimi
The string capitalized is: IMINIPLINICINILPINIMI

"They all had the runs" has 17 letters
The string isn't a palindrome. :(
The last index of the targetted char 'r' is: 17
The substring "ad" is found at index: 10
1 replacement(s) of 'r' to 'g' occured.
The new string is: They all had the guns
The string reversed is: snug eht dah lla yehT
The string capitalized is: THEY ALL HAD THE GUNS

"The quick brown fox jumps over the lazy dog" has 35 letters
The string isn't a palindrome. :(
The last index of the targetted char 'i' is: 6
The substring "ump" is found at index: 21
1 replacement(s) of 'i' to 'a' occured.
The new string is: The quack brown fox jumps over the lazy dog
The string reversed is: god yzal eht revo spmuj xof nworb kcauq ehT
The string capitalized is: THE QUACK BROWN FOX JUMPS OVER THE LAZY DOG

"Star comeD yby Democ ratS" has 21 letters
The string is a palindrome!
The last index of the targetted char 'c' is: 19
The substring "emo" is found at index: 16
2 replacement(s) of 'c' to 'n' occured.
The new string is: Star nomeD yby Demon ratS
The string reversed is: Star nomeD yby Demon ratS
The string capitalized is: STAR NOMED YBY DEMON RATS
*/