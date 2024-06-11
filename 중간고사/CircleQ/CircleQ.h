#ifndef __CIRCLEQ_H__
#define __CIRCLEQ_H__

#include <iostream>
#define MAX_QUEUE_SIZE 7

using namespace std;

class Queue
{
private:
	int front;
	int rear;
	char data[MAX_QUEUE_SIZE];

public:
	Queue();
	~Queue();

	bool isEmpty();
	bool isFull();
	void enqueue(char e);
	char dequeue();
	char peek();
	int size();
	void display();
};

#endif