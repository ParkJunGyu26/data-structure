#ifndef __NODE_H__
#define __NODE_H__

#include <iostream>

using namespace std;

class Node
{
private:
	int data;
	Node* next;
	
public:
	Node();
	~Node();
	Node(const int& data);

	void setData(const int& data);
	int getData();

	void setNext(Node* next);
	Node* getNext();
};

#endif