#pragma once

#include<assert.h>

#include"QueueADT.h"

using namespace std;

template <class t>
struct nodeType {
	t info;
	nodeType<t> * link;
};

template <class t>
class LinkedQueue : public QueueADT<t> {
public:
	const LinkedQueue<t> & operator=(const LinkedQueue<t>&);
	bool isEmpty() const;
	bool isFull() const { return false; }
	void initialize();
	t front() const;
	t back() const;
	void enqueue(const t& element);
	void dequeue();
	LinkedQueue();
	LinkedQueue(const LinkedQueue<t>& otherQueue);
	~LinkedQueue();
private:
	nodeType<t> * queueFront;
	nodeType<t> * queueRear;

};

template<class t>
inline const LinkedQueue<t>& LinkedQueue<t>::operator=(const LinkedQueue<t>&otherQueue)
{
	return LinkedQueue<t>(otherQueue);
}

template<class t>
inline bool LinkedQueue<t>::isEmpty() const
{
	return (queueFront == NULL);
}

template<class t>
inline void LinkedQueue<t>::initialize()
{
	nodeType<t> *temp;
	while (queueFront != NULL) {
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
	}
	queueRear = NULL;
}

template<class t>
inline t LinkedQueue<t>::front() const
{
	assert(queueFront != NULL);
	return queueFront->info;
}

template<class t>
inline t LinkedQueue<t>::back() const
{
	assert(queueRear != NULL);
	return queueRear->info;
}

template<class t>
inline void LinkedQueue<t>::enqueue(const t & element)
{
	nodeType<t> * newNode;
	newNode = new nodeType<t>;
	newNode->info = element;
	newNode->link = NULL;
	if (queueFront == NULL) {
		queueFront = newNode;
		queueRear = newNode;
	}
	else {
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}

template<class t>
inline void LinkedQueue<t>::dequeue()
{
	nodeType<t> * temp;
	if (!isEmpty()) {
		temp = queueFront;
		queueFront = queueFront->link;
		delete temp;
		if (queueFront == NULL) { queueRear = NULL; }
	}
	else {
		cout << "Cannot remove from an empty queue!" << endl;
	}
}

template<class t>
inline LinkedQueue<t>::LinkedQueue()
{
	queueFront = NULL;
	queueRear = NULL;
}

template<class t>
inline LinkedQueue<t>::LinkedQueue(const LinkedQueue<t>& otherQueue)
{
	if (this != &otherQueue) { //Avoid Self Copy
		if (!isEmpty()) {
			initialize(); //Clear own queue
		}
		nodeType<t> * temp_other = otherQueue.queueFront; //Grab first element of other queue
		assert(temp_other != NULL); //crash if copy null queue
		nodeType<t> * temp_self = new nodeType<t>(); //newNode for self
		temp_self->link = NULL; //Is last node in LinkedList
		temp_self->info = temp_other->info; //Get info from otherqueue
		queueFront = temp_self; //Set head node to newly copied node
		while (temp_other->link != NULL) { //OtherQueue contains more nodes
			temp_other = temp_other->link; //Advance list crawler
			temp_self->link = new nodeType<t>(); //Create a new node in this list
			temp_self = temp_self->link; //Advance list crawler
			temp_self->info = temp_other->info; //Grab info from otherqueue
		}
	}

}

template<class t>
inline LinkedQueue<t>::~LinkedQueue()
{
	while (queueFront!=NULL)
	{
		dequeue();
	}
}
