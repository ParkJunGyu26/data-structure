#include "CircleQ.h"

CircleQ::CircleQ() {
	front = rear = 0;
}

CircleQ::~CircleQ() {}

bool CircleQ::isEmpty() {
	return front == rear;
}

bool CircleQ::isFull() {
	return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void CircleQ::enqueue(char e) {
	if (isFull()) {
		cout << "Queue is Full" << endl;
	} else {
		rear = (rear+1) % MAX_QUEUE_SIZE;
		queue[rear] = e;
	}
}

char CircleQ::dequeue() {
	if (isEmpty()) {
		cout << "Queue is Empty";
		return -1;
	} else {
		front = (front + 1) % MAX_QUEUE_SIZE;
		return queue[front];
	}
}

char CircleQ::peek() {
	if (isEmpty()) {
		cout << "Queue is Empty";
		return -1;
	} else {
		return queue[(front+1) % MAX_QUEUE_SIZE];
	}
}

// 배열을 합쳐준다.
void CircleQ::display() {
	if (isEmpty()) {
		cout << "Queue is Empty";
	} else {
		int max_i;
		if (front > rear) 
			max_i = rear + MAX_QUEUE_SIZE;
		else
			max_i = rear;

		for (int i = front+1; i <= max_i; i++) {
			cout << queue[i%MAX_QUEUE_SIZE] << " ";
		}
		cout << endl;
	}
}