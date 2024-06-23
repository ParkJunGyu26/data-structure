#ifndef __DOUBLYLIST_H__
#define __DOUBLYLIST_H__

#include "Node.h"

class DoublyList
{
private:
	Node head;
	int listsize;

public:
	DoublyList();
	~DoublyList();

	Node* getHead();

	bool isEmpty();
	int size();

	int getEntry(int pos);
	void insert(int pos, const int data);
	Node* rmv(int pos);

	void showList();
	void clear();
};

#endif