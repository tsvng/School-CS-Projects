// Modified from Carrano, Data Abstraction & Problem Solving with C++, Fifth Edition, 
//   Pearson Education, 2007, pages 162-163.
#ifndef _LIST_EXCEPTION
#define _LIST_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class ListException : public logic_error
{
public:
	ListException(const string & message = "")
		: logic_error(message.c_str())
	{ }
};

#endif
