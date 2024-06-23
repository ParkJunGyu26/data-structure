#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

#include "Node.h"

class LinkedStack
{
private:
	Node* top;

public:
	LinkedStack();
	~LinkedStack();

	bool isEmpty();
	void push(int data);
	Node* pop();
	int peek();
	void display();
};

#endif