#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
#define MAX_QUEUE_SIZE 6

using namespace std;

class CircleQ
{
private:
	int front, rear;
	char queue[MAX_QUEUE_SIZE];

public:
	CircleQ();
	~CircleQ();
	bool isEmpty();
	bool isFull();
	void enqueue(char e);
	char dequeue();
	char peek();
	void display();
};

#endif