#pragma once

#include<cassert>
#include<iostream>

using namespace std;

template< typename t >
struct Node {
	t info;
	Node<t> * nextNode;
};

template<class t>
class LinkedList {
private:
	int length = 0;
	Node<t> * head;

public:
	LinkedList();
	~LinkedList();

	void push_front(t info);
	void push_back(t info);
	void pop_front();
	void pop_back();

	void insertion_sort();

	void print();

	int get_length();
	t * as_array();
};

template<class t>
inline LinkedList<t>::LinkedList()
{
	head = NULL;
}

template<class t>
inline LinkedList<t>::~LinkedList()
{
	while (length > 0)
		pop_front();
}

template<class t>
inline void LinkedList<t>::push_front(t info)
{
	length++;
	Node<t> * temp = new Node<t>;
	temp->info = info;
	temp->nextNode = head;
	head = temp;
}

template<class t>
inline t * LinkedList<t>::as_array()
{
	t * arr = new t[length];
	t * counter = arr;
	Node<t> * current = head;
	while (current != NULL) {
		*counter = current->info;
		current = current->nextNode;
		++counter;
	}
	return arr;
}

template<class t>
inline void LinkedList<t>::push_back(t info)
{
	length++;
	if (head == NULL) {
		head = new Node<t>;
		head->info = info;
		head->nextNode = NULL;
	}
	else {
		Node<t> * current;
		current = head;
		while (current->nextNode != NULL)
			current = current->nextNode;
		current->nextNode = new Node<t>;
		current = current->nextNode;
		current->info = info;
		current->nextNode = NULL;
	}
	
}

template<class t>
inline void LinkedList<t>::pop_front()
{
	assert(head != NULL);
	Node<t> * temp = head;
	head = head->nextNode;
	delete temp;
	--length;
}

template<class t>
inline void LinkedList<t>::pop_back()
{
	Node<t> current = head;
	while (current->nextNode != NULL)
	{
		current = current->nextNode;
	}
	delete current;
	--length;
}

template<class t>
inline void LinkedList<t>::insertion_sort()
{
	Node<t> * lastInOrder;
	Node<t> * firstOutOfOrder;
	Node<t> * current;
	Node<t> * trailCurrent;

	lastInOrder = head;
	if (head == NULL)
		cerr << "You cannot sort an empty list";
	else if (head->nextNode == NULL)
		return;
	else {
		while (lastInOrder->nextNode != NULL)
		{
			firstOutOfOrder = lastInOrder->nextNode;

			if (firstOutOfOrder->info < head->info)
			{
				lastInOrder->nextNode = firstOutOfOrder->nextNode;
				firstOutOfOrder->nextNode = head;
				head = firstOutOfOrder;
			}
			else {
				trailCurrent = head;
				current = head->nextNode;

				while (current->info < firstOutOfOrder->info) {
					trailCurrent = current;
					current = current->nextNode;
				}

				if (current != firstOutOfOrder)
				{
					lastInOrder->nextNode = firstOutOfOrder->nextNode;
					firstOutOfOrder->nextNode = current;
					trailCurrent->nextNode = firstOutOfOrder;
				}
				else {
					lastInOrder = lastInOrder->nextNode;
				}
			}
		}
	}
}

template<class t>
inline void LinkedList<t>::print()
{
	cout << "[";

	Node<t> * current = head;
	while (current != NULL) {
		cout << current->info << ",";
		current = current->nextNode;
	}
	cout << "]" << endl;
}

template<class t>
inline int LinkedList<t>::get_length() {
	return length;
}
