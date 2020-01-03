//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
Listing 9-2.
@file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "ListPositionOutOfRangeException.h"
#include "ListException.h"

template<typename ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr; // Pointer to first node in the chain;
							 // (contains the first entry in the list)
	int itemCount;           // Current count of list items 

							 // Locates a specified node in this linked list.
							 // @pre  position is the number of the desired node;
							 //       position >= 1 and position <= itemCount.
							 // @post  The node is found and a pointer to it is returned.
							 // @param position  The number of the node to locate.
							 // @return  A pointer to the node at the given position.
	Node<ItemType>* getNodeAt(int position) const;

public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();

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

	int replace(ItemType& oldValue, ItemType& newValue);

	/** Checks and verifies if two lists have the same values in the same order.
	@post  Current object and aList will have been compared to see if they are equal.
	@param aList  The list you are comparing the current list to.
	@return True if aList == current list, else returns false. */
	bool equals(const LinkedList<ItemType>& aList) const;
};

#include "linkedlist.cpp"
#endif 
