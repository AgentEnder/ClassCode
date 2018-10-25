#ifndef H_StackADT
#define H_StackADT

template <class Type>
class StackADT {
public:
	virtual void initializeStack() = 0;
	//Init Stack, postcondition: Empty the Stack (Stack.Clear())
	virtual bool isEmptyStack() const = 0;
	//Postcondition: Return True if empty, false otherwise
	virtual void push(const Type& newItem) = 0;
	//Postcondition: newItem on top of stack
	virtual Type top() const = 0;
	//
	virtual void pop() = 0;
};

#endif