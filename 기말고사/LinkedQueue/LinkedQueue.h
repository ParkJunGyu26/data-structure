#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

#include "Node.h"

class LinkedQueue
{
private:
	Node* front;
	Node* rear;

public:
	LinkedQueue();
	~LinkedQueue();

	bool isEmpty();
	void enqueue(int data);
	Node* dequeue();

	int peek();
	void display();
};

#endif