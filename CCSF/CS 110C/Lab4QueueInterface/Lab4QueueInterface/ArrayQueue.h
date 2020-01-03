//  Modified from the following:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT Queue: Array-based implementation.
Listing 7-1
@file ArrayQueue.h */

#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

#include "QueueInterface.h"
#include "QueueException.h"

const int MAX_QUEUE = 100;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	ItemType items[MAX_QUEUE];   // Array of Queue items
	int front;                                           // Index to front of Queue
	int back;                                           // Index to back of Queue
	int count;                                          // Number of items currently in the Queue

public:
	ArrayQueue();
	// Copy constructor and destructor are supplied by the compiler

	bool isEmpty() const;

	/** @throw QueueException if Queue is full. */
	void enqueue(const ItemType& newEntry);

	/** @throw QueueException if Queue is initially empty. */
	void dequeue();

	/** @throw QueueException if Queue is empty. */
	ItemType peekFront() const;
};

#include "ArrayQueue.cpp"
#endif
