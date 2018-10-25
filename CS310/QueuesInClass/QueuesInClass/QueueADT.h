#pragma once

template <class t>
class QueueADT {
public:
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual void initialize() = 0;
	virtual t front() const = 0;
	virtual t back() const = 0;
	virtual void enqueue(const t& queueElement) = 0;
	virtual void dequeue() = 0;
};