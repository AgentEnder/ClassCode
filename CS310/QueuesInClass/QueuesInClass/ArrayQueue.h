#pragma once
#include<assert.h>
#include "QueueADT.h"

using namespace std;

template <class t>
class ArrayQueue : public QueueADT<t> {
public:
	const ArrayQueue<t>& operator=(const ArrayQueue<t>&);
	//OverloadAssignment
	bool isEmpty() const; //PowerPoint & Book Function: isEmptyQueue
	bool isFull() const; //PowerPoint & Book Function: isFullQueue
	void initialize(); //PowerPoint & Book Function: initializeQueue
	t front() const;
	t back const();
	void enqueue(const t& element); //PowerPoint & Book Function: addQueue
	void dequeue(); //PowerPoint & Book Function: deleteQueue
	ArrayQueue(int queueSize = 100);
	ArrayQueue(const ArrayQueue<t>& otherQueue);
	//Copy Constructor
	~ArrayQueue();
	//Destructor
private:
	int maxQueueSize;
	int count;
	int queueFront; //Index of first element
	int queueBack; //Index of last element
	t * list; //Pointer to array.

};

template<class t>
inline bool ArrayQueue<t>::isEmpty() const
{
	return count == 0;
}

template<class t>
inline bool ArrayQueue<t>::isFull() const
{
	return (count == maxQueueSize);
}

template<class t>
inline void ArrayQueue<t>::initialize()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}

template<class t>
inline t ArrayQueue<t>::front() const
{
	assert(!isEmptyQueue());
	return list[queueFront];
}

template<class t>
inline t ArrayQueue<t>::back const()
{
	assert(!isEmptyQueue());
	return list[queueRear];
}

template<class t>
inline void ArrayQueue<t>::enqueue(const t & element)
{
	if (!isFullQueue()) {
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
		list[queueRear] = newElement;
	}
	else {
		cout << "Cannot add to a full queue!" << endl;
	}
}

template<class t>
inline void ArrayQueue<t>::dequeue()
{
	if (!isEmptyQueue) {
		count--;
		queueFront = (queueFront + 1 % maxQueueSize);

	}
	else {
		cout << "Cannot Remove from Empty Queue!" << endl;
	}
}

template<class t>
inline ArrayQueue<t>::ArrayQueue(int queueSize)
{
	if (queueSize <= 0) {
		cout << "Size of the array to hold the queue must be positive!" << endl;
		cout << "Creating an array of size 100." << endl;
		queueSize = 100;
	}
	maxQueueSize = queueSize;

	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new t[maxQueueSize];

}

template<class t>
inline ArrayQueue<t>::~ArrayQueue()
{
	delete[] list;
}
