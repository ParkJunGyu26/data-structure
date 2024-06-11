#include "stack.h"

int i;

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {}

bool Stack::isEmpty() {
    return top == -1;
}


bool Stack::isFull() {
    return top == MAX_STACK_SIZE-1;
}


void Stack::push(int e) {
    if (isFull()) {
        cout << "Stack is Full";
    } else {
        data[++top] = e;
    }
}


int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is Empty";
        return -1;
    } else {
        return data[top--];
    }
}


int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is Empty";
        return -1;
    } else {
        return data[top];
    }
}

void Stack::display() {
    if (isEmpty()) {
        cout << "Stack is Empty";
    } else {
        for (i = 0; i <= top; i++) {
            cout << data[i];
        }
    }
}