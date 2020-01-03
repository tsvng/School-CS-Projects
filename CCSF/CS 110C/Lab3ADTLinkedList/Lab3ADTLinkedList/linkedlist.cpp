//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
@file LinkedList.cpp */


template<typename ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}

template<typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) :
	itemCount(aList.itemCount)
{
	// Points to nodes in original chain
	Node<ItemType>* origChainPtr = aList.headPtr;


	if (origChainPtr == nullptr)
		headPtr = nullptr; // Original list is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();
		}
	}
}

template<typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template<typename ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}


template<typename ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

/**  @throw ListPositionOutOfRangeException if newPosition out of range
@throw ListException if list is full. */
template<typename ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
	if (newPosition < 1 || newPosition > itemCount + 1)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: insert position out of range");
	else
	{
		try   // try to allocate a new node
		{
			Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

			// Attach new node to chain
			if (newPosition == 1)
			{
				// Insert new node at beginning of chain
				newNodePtr->setNext(headPtr);
				headPtr = newNodePtr;
			}
			else
			{
				// Find node that will be before new node
				Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

				// Insert new node after node to which prevPtr points
				newNodePtr->setNext(prevPtr->getNext());
				prevPtr->setNext(newNodePtr);
			}

			itemCount++;
		}
		catch (bad_alloc e)
		{
			throw ListException("ListException: cannot allocate memory on insert");
		}
	}
}

/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
void LinkedList<ItemType>::remove(int position)
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: remove position out of range");
	else
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that is before the one to delete
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
		}

		// Return node to system
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		itemCount--;
	}
}

template<typename ItemType>
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}


/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: getEntry position out of range");
	else
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
}

/*  @throw ListPositionOutOfRangeException if position out of range. */
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: setEntry position out of range");
	else
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
}

/**  @throw ListPositionOutOfRangeException if position out of range. */
template<typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	if (position < 1 || position > itemCount)
		throw ListPositionOutOfRangeException(
			"ListPositionOutOfRangeException: remove position out of range");
	else
	{
		// Count from the beginning of the chain
		Node<ItemType>* curPtr = headPtr;

		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();

		return curPtr;
	}
}

template<typename ItemType>
int LinkedList<ItemType>::replace(ItemType& oldValue, ItemType& newValue)
{
	int numReplaced = 0;
	Node<ItemType>* nodePtr = headPtr;

	for (int position = 1; position <= itemCount; position++)
	{
		if (nodePtr->getItem() == oldValue)
		{
			nodePtr->setItem(newValue);
			numReplaced++;
		}
		nodePtr = nodePtr->getNext();
	}

	return numReplaced;
}



template<typename ItemType>
bool LinkedList<ItemType>::equals(const LinkedList<ItemType>& aList) const
{
	bool listsEqual = true;
	Node<ItemType>* nodePtr = headPtr;
	Node<ItemType>* nodePtr2 = aList.headPtr;

	if (itemCount == aList.itemCount)
	{
		for (int position = 1; position <= itemCount; position++)
		{
			if (!(nodePtr->getItem() == nodePtr2->getItem()))
				listsEqual = false;
			nodePtr = nodePtr->getNext();
			nodePtr2 = nodePtr2->getNext();
		}
	}
	else
		listsEqual = false;

	if (listsEqual)
		cout << "The two lists are equal." << endl;
	else
		cout << "The two lists are not equal." << endl;

	return listsEqual;
}
