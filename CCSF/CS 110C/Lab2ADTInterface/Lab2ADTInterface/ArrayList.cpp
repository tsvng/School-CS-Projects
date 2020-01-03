//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class ArrayList.
@file ArrayList.cpp */

#include "ListException.h"
#include "ListPositionOutOfRangeException.h"
#include <iostream>

template<typename ItemType>
ArrayList<ItemType>::ArrayList() : itemCount(0)
{
}


template<typename ItemType>
bool ArrayList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<typename ItemType>
int ArrayList<ItemType>::getLength() const
{
	return itemCount;
}

/**  @throw ListPositionOutOfRangeException if newPosition out of range
@throw ListException if list is full. */
template<typename ItemType>
void ArrayList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	if (newPosition < 1 || newPosition > itemCount + 1)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: insert position out of range");
	else if (itemCount >= MAX_LIST)
		throw ListException("ListException: list full on insert");
	else
	{
		// Make room for new entry by shifting all entries at
		// positions >= newPosition toward the end of the array
		// (no shift if newPosition == itemCount + 1)
		for (int pos = itemCount; pos >= newPosition; pos--)
			items[pos] = items[pos - 1];

		// Insert new entry
		items[newPosition - 1] = newEntry;
		itemCount++;
	}
}


/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
void ArrayList<ItemType>::remove(int position)
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: remove position out of range");
	else
	{
		// Remove entry by shifting all entries after the one at
		// position toward the beginning of the array
		// (no shift if position == itemCount)
		for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < itemCount;
		fromIndex++, toIndex++)
			items[toIndex] = items[fromIndex];

		itemCount--;
	}
}

template<typename ItemType>
void ArrayList<ItemType>::clear()
{
	itemCount = 0;
}

/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: getEntry position out of range");
	else
		return items[position - 1];
}

/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
void ArrayList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: setEntry position out of range");
	else
		items[position - 1] = newEntry;
}

//Does not call List member functions
template<typename ItemType>
bool ArrayList<ItemType>::isInAscendingOrder() const
{
	bool ascending = true;

	for (int pos = 1; pos < itemCount; pos++)
		if (!(items[pos - 1] <= items[pos]))
			ascending = false;
	
	if(ascending)
		cout << "Your list of integers is in ascending order." << endl;
	else
		cout << "Your list of integers is not in ascending order." << endl;
		
	return ascending;
}