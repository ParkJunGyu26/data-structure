#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#define MAX_STACK_SIZE 100

using namespace std;

class Stack
{
private:
    int top;
    int data[MAX_STACK_SIZE];

public:
    Stack();
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int e);
    int pop();
    int peek();
    void display();
};

#endif