#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node* next;
	Node* prev;

public:
	Node();
	Node(const int val);
	~Node();

	void setData(const int val);
	int getData();

	void setNext(Node* next);
	Node* getNext();

	void setPrev(Node* prev);
	Node* getPrev();
};

#endif