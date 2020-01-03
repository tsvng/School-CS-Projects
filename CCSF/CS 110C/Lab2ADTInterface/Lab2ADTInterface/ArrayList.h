//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Array-based implementation.
Listing 9-1.
@file ArrayList.h */


#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"

template<typename ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int MAX_LIST = 100;
	ItemType items[MAX_LIST];      // Array of list items
	int itemCount;                                // Current count of list items 

public:
	ArrayList();
	// Copy constructor and destructor are supplied by compiler

	bool isEmpty() const;
	int getLength() const;

	/**  @throw ListPositionOutOfRangeException if newPosition out of range
	@throw ListException if list is full. */
	void insert(int newPosition, const ItemType& newEntry);

	/**  @throw ListPositionOutOfRangeException if newPosition out of range. */
	void remove(int position);

	void clear();

	/**  @throw ListPositionOutOfRangeException if newPosition out of range. */
	ItemType getEntry(int position) const;

	/**  @throw ListPositionOutOfRangeException if newPosition out of range. */
	void setEntry(int position, const ItemType& newEntry);

	bool isInAscendingOrder() const;
};

/*Interchange commenting lines 51 and 52 to swap between isInAscendingOrder() 
independent of implementation and no List memeber function calls, respectively*/

#include "ArrayListIndependent.cpp"
//#include "ArrayList.cpp"

#endif 
