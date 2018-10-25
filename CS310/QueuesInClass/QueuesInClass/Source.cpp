#include<iostream>

#include "LinkedQueue.h"

using namespace std;

int main() {
	LinkedQueue<int> intQueue = LinkedQueue<int>();
	for (int i = 0; i < 5; i++)
	{
		intQueue.enqueue(i);
	}
	LinkedQueue<int> copyTest = intQueue;
	for (int i = 0; i < 5; i++) {
		cout << copyTest.front();
		copyTest.dequeue();
	}
	getchar();
}
