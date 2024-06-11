#include "CircleQ.h"

Queue::Queue() {
	front = rear = 0;
}

Queue::~Queue() {}

bool Queue::isEmpty() {
	return front == rear;
}

bool Queue::isFull() {
	return front == (rear+1) % MAX_QUEUE_SIZE;
}

void Queue::enqueue(char e) {
	if (isFull()) {
		cout << "Queue is Full" << endl;
	} else {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		data[rear] = e;
	}
}

char Queue::dequeue() {
	if (isEmpty()) {
		return '\0';
	} else {
		front = (front+1) % MAX_QUEUE_SIZE;
	}
}

char Queue::peek() {
	if (isEmpty()) {
		return '\0';
	} else {
		return data[(front+1) % MAX_QUEUE_SIZE];
	}
}

int Queue::size() {
	return (rear+MAX_QUEUE_SIZE-front)%MAX_QUEUE_SIZE;
	if (rear < front) rear += MAX_QUEUE_SIZE;
	return rear - front; 
}

void Queue::display() {
	if (isEmpty()) cout << "Queue is Empty";
	else {
		int rearA;
		if (rear < front) rearA = rear + MAX_QUEUE_SIZE;
		for (int i = front+1; i <= rearA; i++) {
			cout << data[i%MAX_QUEUE_SIZE];
		}
	}
}