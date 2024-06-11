#include "Postfix.h"

Stack::Stack() {
	top = -1;
}

Stack::~Stack() {}

bool Stack::isEmpty() {
	return top == -1;
}

bool Stack::isFull() {
	return top == (MAX_STACK_SIZE);
}

void Stack::push(char c) {
	if (isFull()) {
		cout << "Stack is Full";
	} else {
		data[++top] = c;
	}
}

char Stack::pop() {
	if (!isEmpty()) {
		return data[--top];
	}
}

char Stack::peek() {
	if (!isEmpty()) {
		return data[top];
	}
}

void Stack::display() {
	if (!isEmpty()) {
		cout << "Stack : [";
		for (int i = 0; i <= top; i++) {
			if (i == top) {
				cout << data[i];
			} else {
				cout <<data[i] << ", ";
			}
		}
		cout << "]";
		cout << endl;
	}
}