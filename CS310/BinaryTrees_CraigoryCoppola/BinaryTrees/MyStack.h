#ifndef H_MyStack
#define H_MyStack

#include<iostream>
#include<cassert>

#include "StackADT.h"

using namespace std;

template<class t>
class MyStack : public StackADT<t> {
public:
	const MyStack<t>& operator=(const MyStack<t>&);
	//Overload assignment operator
	void initializeStack();
	//ClearStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	t top() const;
	void push(const t& newItem);
	void pop();

	bool operator==(const MyStack<t>& otherStack) const;

	MyStack(int stackSize = 100);
	~MyStack(); //Destructor

private:
	int maxStackSize;
	int stackTop;
	t *list;

	void copyStack(const MyStack<t>& otherStack);
};

template<class t>
const MyStack<t>& MyStack<t>::operator=(const MyStack<t>& otherStack)
{
	if (this != &otherStack) { //Avoid Self Copy
		copyStack(otherStack);
	}
	return *this;
}

template<class t>
void MyStack<t>::initializeStack()
{
	stackTop = 0;
}

template<class t>
bool MyStack<t>::isEmptyStack() const
{
	return stackTop == 0;
}

template<class t>
bool MyStack<t>::isFullStack() const
{
	return stackTop == maxStackSize;
}

template<class t>
t MyStack<t>::top() const
{
	assert(stackTop != 0);
	return list[stackTop - 1];
}

template<class t>
void MyStack<t>::push(const t & newItem)
{
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}

}

template<class t>
void MyStack<t>::pop()
{
	if (!isEmptyStack()) {
		stackTop--;
	}
	else {
		cout << "You cannot pop an empty stack";
	}
}

template<class t>
bool MyStack<t>::operator==(const MyStack<t>& otherStack) const
{
	if (this == &otherStack) {
		return true;
	}
	else if (maxStackSize != otherStack.maxStackSize || stackTop != otherStack.stackTop) {
		return false;
	}
	else {
		for (int i = 0; i < stackTop; i++)
		{
			if (list[i] != otherStack.list[i]) {
				return false;
			}
		}
		return true;
	}
}

template<class t>
MyStack<t>::MyStack(int stackSize)
{
	if (stackSize <= 0) {
		cout << "You cannot declare a negative or zero stacksize!";
		stackSize = 100;
	}

	maxStackSize = stackSize;

	stackTop = 0;
	list = new t[maxStackSize];

}

template<class t>
MyStack<t>::~MyStack()
{
	delete[] list;
}

template<class t>
void MyStack<t>::copyStack(const MyStack<t>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;

	list = new t[maxStackSize];

	for (int i = 0; i < stackTop; i++)
	{
		list[i] = otherStack.list[i];
	}
}
#endif