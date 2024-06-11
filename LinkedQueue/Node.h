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
	Node(const int& data); // data의 주소값을 매개변수로

	void setData(const int& data);
	int getData();

	void setNext(Node* next);
	Node* getNext();
};

#endif