#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__

#include "Node.h"

class CircularList
{
private:
	Node* tail;
	int listsize;

public:
	CircularList();
	~CircularList();

	Node* getHead();
	Node* getTail();
	void setTail(Node* n);

	bool isEmpty();
	int size();

	int getEntry(int pos);
	void insert(int pos, const int data);
	Node* rmv(int pos);

	void showList();
	void clear();
};

#endif