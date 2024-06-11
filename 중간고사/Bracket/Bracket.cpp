#include "Bracket.h"

Stack::Stack() {
	top = -1;
}

Stack::~Stack() {}

bool Stack::isEmpty() {
	return top == -1;
}

bool Stack::isFull() {
	return MAX_STACK_SIZE-1 == top;
}

void Stack::push(char c) {
	if(isFull()) {
		cout << "Stack is Full" << endl;
	} else {
		data[++top] = c;
	}
}

char Stack::pop() {
	if (isEmpty()) {
		return '\0';
	} else {
		return data[top--];
	}
}

char Stack::peek() {
	if (isEmpty()) {
		return '\0';
	} else {
		return data[top];
	}
}

int Stack::size() {
	return top+1;
}