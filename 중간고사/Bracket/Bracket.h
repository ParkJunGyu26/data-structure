#ifndef __BRACKET_H__
#define __BRACKET_H__

#include <iostream>
#include <string>

using namespace std;
#define MAX_STACK_SIZE 100

class Stack
{
private:
	int top;
	char data[MAX_STACK_SIZE];

public:
	Stack();
	~Stack();
	bool isEmpty();
	bool isFull();
	void push(char c);
	char pop();
	char peek();
	int size();
};

#endif