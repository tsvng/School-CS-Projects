//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Interface for the ADT list
Listing 8-1
@file ListInterface.h */

#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<typename ItemType>
class ListInterface
{
public:
	/** Sees whether this list is empty.
	@return True if the list is empty; otherwise returns false. */
	virtual bool isEmpty() const = 0;

	/** Gets the current number of entries in this list.
	@return The integer number of entries currently in the list. */
	virtual int getLength() const = 0;

	/** Inserts an entry into this list at a given position.
	@pre  1 <= position <= getLength() + 1
	@post  newEntry is at the given position in the list,
	other entries are renumbered accordingly.
	@param newPosition  The list position at which to insert newEntry.
	@param newEntry  The entry to insert into the list.
	@throw ListPositionOutOfRangeException if newPosition out of range
	@throw ListException if list is full. */
	virtual void insert(int newPosition, const ItemType& newEntry) = 0;

	/** Removes the entry at a given position from this list.
	@pre  1 <= position <= getLength()
	@post  the entry at the given position in the list is removed, other
	items are renumbered accordingly.
	@param position  The list position of the entry to remove.
	@throw ListPositionOutOfRangeException if position out of range. */
	virtual void remove(int position) = 0;

	/** Removes all entries from this list.
	@post  List contains no entries and the count of items is 0. */
	virtual void clear() = 0;

	/** Gets the entry at the given position in this list.
	@pre  1 <= position <= getLength().
	@post  The desired entry has been returned.
	@param position  The list position of the desired entry.
	@return  The entry at the given position.
	@throw ListPositionOutOfRangeException if position out of range. */
	virtual ItemType getEntry(int position) const = 0;

	/** Replaces the entry at the given position in this list.
	@pre  1 <= position <= getLength().
	@post  The entry at the given position is newEntry.
	@param position  The list position of the entry to replace.
	@param newEntry  The replacement entry.
	@throw ListPositionOutOfRangeException if position out of range. */
	virtual void setEntry(int position, const ItemType& newEntry) = 0;

	/** Replaces each occurence of oldValue in the list with newValue.
	@post  Every instance of oldValue has been replaced by newValue.
	@param oldValue  The item you want to replace.
	@param newValue  The new item you want to replace oldValue with.
	@return  Number of items replaced. */
	virtual int replace(ItemType& oldValue, ItemType& newValue) = 0;
};
#endif
