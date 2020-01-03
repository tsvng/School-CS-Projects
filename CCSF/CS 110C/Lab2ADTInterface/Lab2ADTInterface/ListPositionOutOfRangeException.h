// Modified from Carrano, Data Abstraction & Problem Solving with C++, Fifth Edition, 
//   Pearson Education, 2007, page 162.
#ifndef _LIST_POSITION_OUT_OF_RANGE_EXCEPTION
#define _LIST_POSITION_OUT_OF_RANGE_EXCEPTION

#include <stdexcept>
#include <string>

using namespace std;

class ListPositionOutOfRangeException : public logic_error
{
public:
	ListPositionOutOfRangeException(const string & message = "")
		: logic_error(message.c_str())
	{ }
};

#endif
