#include<iostream>
#include<string>

#include "MyStack.h"

using namespace std;

string str(bool x) {
	if ((x != false) && (x != NULL)) {
		return "True";
	}
	else {
		return "False";
	}
}

///Summary///
//This function is my code, not what was typed from professor source. We were told to write an example driver source file which utilized our stacks, and compared two for equality.
int main() {
	MyStack<string> _stack = MyStack<string>(4);
	_stack.push("Craigory.");
	_stack.push("is");
	_stack.push("name");
	_stack.push("My");

	for (int i = 0; i < 4; i++)
	{
		cout << _stack.top() << " ";
		_stack.pop();
	}

	getchar();
	return 0;
}