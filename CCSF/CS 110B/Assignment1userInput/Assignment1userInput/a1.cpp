//William Tsang, CS 110B, 1/24/16, Harden, a1.cpp
#include <iostream>
using namespace std;

int main()
{
	int numAmpersand;
	char response;

	cout << "Would you like me to print ampersands (Y/N)?" << endl;
	cin >> response;
	while (response != 'N')
	{
		cout << "How many ampersands would you like to print?" << endl;
		cin >> numAmpersand;

		for (int i = 0; i < numAmpersand; i++)
		{
			cout << "&";
		}
		cout << endl;

		cout << "Would you like me to print ampersands (Y/N)?" << endl;
		cin >> response;
	}
}

/*An output example:
Would you like me to print ampersands (Y/N)?
Y
How many ampersands would you like to print?
3
&&&
Would you like me to print ampersands (Y/N)?
N
Press any key to continue . . .
*/