/*
* -------------------
* These functions are designed to help you test your myString objects,
* as well as show the client usage of the class.
*
* The BasicTest function builds an array of strings using various
* constructor options and prints them out.  It also uses the String
* stream operations to read some strings from a data file.
*
* The RelationTest function checks out the basic relational operations
* (==, !=, <, etc) on Strings and char *s.
*
* The ConcatTest functions checks the overloaded + and += operators that
* do string concatenation.
*
* The CopyTest tries out the copy constructor and assignment operators
* to make sure they do a true deep copy.
*
* Although not exhaustive, these tests will help you to exercise the basic
* functionality of the class and show you how a client might use it.
*
* While you are developing your myString class, you might find it
* easier to comment out functions you are ready for, so that you don't
* get lots of compile/link complaints.
*/

#include "mystring.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <string>     
#include <cassert>
#include <iostream>
using namespace std;
using namespace cs_mystring;

bool eof(istream& in);
void BasicTest();
void RelationTest();
void ConcatTest();
void CopyTest();
myString AppendTest(const myString& ref, myString val);
string boolString(bool convertMe);


int main()
{
	BasicTest();
	RelationTest();
	ConcatTest();
	CopyTest();
}



bool eof(istream& in)
{
	char ch;
	in >> ch;
	in.putback(ch);
	return !in;
}

string boolString(bool convertMe) {
	if (convertMe) {
		return "true";
	}
	else {
		return "false";
	}
}


void BasicTest()
{
	myString s;
	cout << "----- Testing basic String creation & printing" << endl;

	const myString strs[] =
	{ myString("Wow"), myString("C++ is neat!"),
		myString(""), myString("a-z") };


	for (int i = 0; i < 4; i++) {
		cout << "string [" << i << "] = " << strs[i] << endl;
	}



	cout << endl << "----- Now reading myStrings from file" << endl;

	cout << endl << "----- first, word by word" << endl;
	ifstream in("mystring.txt");
	assert(in);
	while (in.peek() == '#') {
		in.ignore(128, '\n');
	}
	in >> s;
	while (in) {
		cout << "Read string = " << s << endl;
		in >> s;
	}
	in.close();



	cout << endl << "----- now, line by line" << endl;
	ifstream in2("mystring.txt");
	assert(in2);
	while (in2.peek() == '#') {
		in2.ignore(128, '\n');
	}
	s.read(in2, '\n');
	while (in2) {
		cout << "Read string = " << s << endl;
		s.read(in2, '\n');
	}




	cout << endl << "----- Testing access to characters (using const)" << endl;
	const myString s1("abcdefghijklmnopqsrtuvwxyz");
	cout << "Whole string is " << s1 << endl;
	cout << "now char by char: ";
	for (int i = 0; i < s1.length(); i++) {
		cout << s1[i];
	}



	cout << endl << "----- Testing access to characters (using non-const)" << endl;
	myString s2("abcdefghijklmnopqsrtuvwxyz");
	cout << "Start with " << s2;
	for (int i = 0; i < s2.length(); i++) {
		s2[i] = toupper(s2[i]);
	}
	cout << " and convert to " << s2 << endl;
}









void RelationTest()
{
	cout << "\n----- Testing relational operators between myStrings\n";

	const myString strs[] =
	{ myString("app"), myString("apple"), myString(""),
		myString("Banana"), myString("Banana") };

	for (int i = 0; i < 4; i++) {
		cout << "Comparing " << strs[i] << " to " << strs[i + 1] << endl;
		cout << "\tIs left < right? " << boolString(strs[i] < strs[i + 1]) << endl;
		cout << "\tIs left <= right? " << boolString(strs[i] <= strs[i + 1]) << endl;
		cout << "\tIs left > right? " << boolString(strs[i] > strs[i + 1]) << endl;
		cout << "\tIs left >= right? " << boolString(strs[i] >= strs[i + 1]) << endl;
		cout << "\tDoes left == right? " << boolString(strs[i] == strs[i + 1]) << endl;
		cout << "\tDoes left != right ? " << boolString(strs[i] != strs[i + 1]) << endl;
	}

	cout << "\n----- Testing relations between myStrings and char *\n";
	myString s("he");
	const char *t = "hello";
	cout << "Comparing " << s << " to " << t << endl;
	cout << "\tIs left < right? " << boolString(s < t) << endl;
	cout << "\tIs left <= right? " << boolString(s <= t) << endl;
	cout << "\tIs left > right? " << boolString(s > t) << endl;
	cout << "\tIs left >= right? " << boolString(s >= t) << endl;
	cout << "\tDoes left == right? " << boolString(s == t) << endl;
	cout << "\tDoes left != right ? " << boolString(s != t) << endl;

	myString u("wackity");
	const char *v = "why";
	cout << "Comparing " << v << " to " << u << endl;
	cout << "\tIs left < right? " << boolString(v < u) << endl;
	cout << "\tIs left <= right? " << boolString(v <= u) << endl;
	cout << "\tIs left > right? " << boolString(v > u) << endl;
	cout << "\tIs left >= right? " << boolString(v >= u) << endl;
	cout << "\tDoes left == right? " << boolString(v == u) << endl;
	cout << "\tDoes left != right ? " << boolString(v != u) << endl;

}




void ConcatTest()
{
	cout << "\n----- Testing concatentation on myStrings\n";

	const myString s[] =
	{ myString("outrageous"), myString("milk"), myString(""),
		myString("cow"), myString("bell") };

	for (int i = 0; i < 4; i++) {
		cout << s[i] << " + " << s[i + 1] << " = " << s[i] + s[i + 1] << endl;
	}

	cout << "\n----- Testing concatentation between myString and char *\n";

	const myString a("abcde");
	const char *b = "XYZ";
	cout << a << " + " << b << " = " << a + b << endl;
	cout << b << " + " << a << " = " << b + a << endl;

	cout << "\n----- Testing shorthand concat/assign on myStrings\n";

	myString s2[] =
	{ myString("who"), myString("what"), myString("WHEN"),
		myString("Where"), myString("why") };

	for (int i = 0; i < 4; i++) {
		cout << s2[i] << " += " << s2[i + 1] << " = ";
		cout << (s2[i] += s2[i + 1]) << "and";
		cout << s2[i] << endl;
	}

	cout << "\n----- Testing shorthand concat/assign using char *\n";
	myString u("I love ");
	const char *v = "programming";
	cout << u << " += " << v << " = ";
	cout << (u += v) << endl;
}









myString AppendTest(const myString& ref, myString val)
{
	val[0] = 'B';
	return val + ref;
}







void CopyTest()
{
	cout << "\n----- Testing copy constructor and operator= on myStrings\n";

	myString orig("cake");


	myString copy(orig);    // invoke copy constructor

	copy[0] = 'f';  // change first letter of the *copy*
	cout << "original is " << orig << ", copy is " << copy << endl;


	myString copy2;      // makes an empty string

	copy2 = orig;        // invoke operator=
	copy2[0] = 'f';      // change first letter of the *copy*
	cout << "original is " << orig << ", copy is " << copy2 << endl;

	copy2 = "Copy Cat";
	copy2 = copy2;        // copy onto self and see what happens
	cout << "after self assignment, copy is " << copy2 << endl;


	cout << "Testing pass & return myStrings by value and ref" << endl;
	myString val = "winky";
	myString sum = AppendTest("Boo", val);
	cout << "after calling Append, sum is " << sum << endl;
	cout << "val is " << val << endl;
	val = sum;
	cout << "after assign,  val is " << val << endl;

}